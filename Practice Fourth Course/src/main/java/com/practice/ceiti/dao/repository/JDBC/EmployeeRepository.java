package com.practice.ceiti.dao.repository.JDBC;

import com.practice.ceiti.dao.dto.EmployeeDto;
import com.practice.ceiti.dao.dto.EmployeeDtoImpl;
import com.practice.ceiti.dao.models.Employee;
import com.practice.ceiti.dao.repository.EmployeeRepositoryInterface;
import lombok.AllArgsConstructor;
import lombok.SneakyThrows;
import org.modelmapper.ModelMapper;
import org.springframework.context.annotation.Profile;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.support.GeneratedKeyHolder;
import org.springframework.stereotype.Repository;

import javax.sql.DataSource;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.List;
import java.util.Objects;
import java.util.Optional;
import java.util.regex.Pattern;
import java.util.stream.Collectors;

@Profile("JDBC")
@AllArgsConstructor
@Repository
public class EmployeeRepository implements EmployeeRepositoryInterface {

    private final JdbcTemplate jdbcTemplate;
    private final DataSource dataSource;
    private final ModelMapper modelMapper;

    private final JobRepository jobRepository;
    private final DepartmentRepository departmentRepository;

    @Override
    public List<Employee> findAll() {
        return jdbcTemplate.query("select * from employees", this::mapEmployee)
                .stream()
                .map(this::convertToEntity)
                .collect(Collectors.toList());
    }

    @Override
    public Optional<Employee> findById(int employeeId) {
        return jdbcTemplate.query("select * from employees where id = " + employeeId, this::mapEmployee)
                .stream()
                .map(this::convertToEntity)
                .findFirst();
    }

    @Override
    public Employee save(Employee employee) {
        if (employee.getId() < 0) {
            throw new IllegalArgumentException("Job Id has to be greater than zero");
        }
        if (employee.getFirstName().isBlank()) {
            throw new IllegalArgumentException("First name is mandatory");
        }
        if (employee.getLastName().isBlank()) {
            throw new IllegalArgumentException("Last name is mandatory");
        }
        if (employee.getAddress().isBlank()) {
            throw new IllegalArgumentException("Address is mandatory");
        }
        if (employee.getSalary() < 1) {
            throw new IllegalArgumentException("Salary must be greater than or equal to 1");
        }
        if (employee.getSalary() > 99999999) {
            throw new IllegalArgumentException("Salary must be less than or equal to 99999999");
        }
        if (!Pattern.matches("0\\d{8}", employee.getPhoneNumber())) {
            throw new IllegalArgumentException("Phone number should start with zero and contain exactly 9 digits");
        }

        int primaryKey = 0;

        if (employee.getId() == 0) {
            GeneratedKeyHolder holder = new GeneratedKeyHolder();
            jdbcTemplate.update(con -> {
                PreparedStatement statement = con.prepareStatement("insert into employees(first_name, last_name, address, phone_number, salary, job_id, department_id) values(?,?,?,?,?,?,?) ", Statement.RETURN_GENERATED_KEYS);
                statement.setString(1, employee.getFirstName());
                statement.setString(2, employee.getLastName());
                statement.setString(3, employee.getAddress());
                statement.setString(4, employee.getPhoneNumber());
                statement.setInt(5, employee.getSalary());
                statement.setInt(6, employee.getJob().getId());
                statement.setInt(7, employee.getDepartment().getId());
                return statement;
            }, holder);

            primaryKey = Objects.requireNonNull(holder.getKey()).intValue();
            employee.setId(primaryKey);
        } else {
            jdbcTemplate.update(
                    "update employees set first_name = ?, last_name = ?, address = ?, phone_number = ?, salary = ?, job_id = ?, department_id = ? where id = ?",
                    employee.getFirstName(),
                    employee.getLastName(),
                    employee.getAddress(),
                    employee.getPhoneNumber(),
                    employee.getSalary(),
                    employee.getJob().getId(),
                    employee.getDepartment().getId(),
                    employee.getId()
            );

            primaryKey = employee.getId();
        }

        return findById(primaryKey).orElseThrow();
    }

    @Override
    public void deleteById(int employeeId) {
        jdbcTemplate.update("delete from employees where id = " + employeeId);
    }

    @SneakyThrows
    private EmployeeDto mapEmployee(ResultSet resultSet, int i) {
        return new EmployeeDtoImpl(
                resultSet.getInt("id"),
                resultSet.getString("first_name"),
                resultSet.getString("last_name"),
                resultSet.getString("address"),
                resultSet.getString("phone_number"),
                resultSet.getInt("salary"),
                jobRepository.findById(resultSet.getInt("job_id")).orElse(null).getJobName(),
                departmentRepository.findById(resultSet.getInt("department_id")).orElse(null).getDepartmentName()
        );
    }

    public Employee convertToEntity(EmployeeDto employeeDTO) {
        return modelMapper.map(employeeDTO, Employee.class);
    }
}
