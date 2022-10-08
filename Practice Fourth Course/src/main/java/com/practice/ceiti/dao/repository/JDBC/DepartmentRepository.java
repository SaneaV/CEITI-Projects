package com.practice.ceiti.dao.repository.JDBC;

import com.practice.ceiti.dao.models.Department;
import com.practice.ceiti.dao.repository.DepartmentRepositoryInterface;
import lombok.AllArgsConstructor;
import lombok.SneakyThrows;
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

@Profile("JDBC")
@AllArgsConstructor
@Repository
public class DepartmentRepository implements DepartmentRepositoryInterface {

    private final JdbcTemplate jdbcTemplate;
    private final DataSource dataSource;

    @Override
    public List<Department> findAll() {
        return jdbcTemplate.query("select * from departments", this::mapDepartment);
    }

    @Override
    public Optional<Department> findById(int departmentId) {
        return jdbcTemplate.query("select * from departments where id = " + departmentId, this::mapDepartment).stream().findAny();
    }

    @Override
    public Department save(Department department) {
        if (department.getId() < 0) {
            throw new IllegalArgumentException("Department Id has to be greater than zero");
        }
        if (department.getDepartmentName().isBlank()) {
            throw new IllegalArgumentException("Department name is mandatory");
        }
        if (department.getAddress().isBlank()) {
            throw new IllegalArgumentException("Address is mandatory");
        }

        int primaryKey = 0;

        if (department.getId() == 0) {
            GeneratedKeyHolder holder = new GeneratedKeyHolder();
            jdbcTemplate.update(con -> {
                PreparedStatement statement = con.prepareStatement("insert into departments(department_name, address) values(?,?) ", Statement.RETURN_GENERATED_KEYS);
                statement.setString(1, department.getDepartmentName());
                statement.setString(2, department.getAddress());
                return statement;
            }, holder);

            primaryKey = Objects.requireNonNull(holder.getKey()).intValue();
            department.setId(primaryKey);
        } else {
            jdbcTemplate.update(
                    "update departments set department_name = ?, address = ? where id = ?",
                    department.getDepartmentName(),
                    department.getAddress(),
                    department.getId()
            );

            primaryKey = department.getId();
        }

        return findById(primaryKey).orElseThrow();
    }

    @Override
    public void deleteById(int departmentId) {
        jdbcTemplate.update("update employees set department_id = null where department_id = " + departmentId);
        jdbcTemplate.update("delete from departments where id = " + departmentId);
    }

    @Override
    public Optional<Department> findByDepartmentName(String departmentName) {
        return jdbcTemplate.query("select * from departments where department_name LIKE '" + departmentName + "'", this::mapDepartment).stream().findAny();
    }

    @SneakyThrows
    private Department mapDepartment(ResultSet resultSet, int i) {
        return new Department(
                resultSet.getInt("id"),
                resultSet.getString("department_name"),
                resultSet.getString("address")
        );
    }
}
