package com.practice.ceiti.UnitTesting;

import com.practice.ceiti.dao.dto.EmployeeDto;
import com.practice.ceiti.dao.dto.EmployeeDtoImpl;
import com.practice.ceiti.dao.models.Department;
import com.practice.ceiti.dao.models.Employee;
import com.practice.ceiti.dao.models.Job;
import com.practice.ceiti.dao.repository.DepartmentRepositoryInterface;
import com.practice.ceiti.dao.repository.EmployeeRepositoryInterface;
import com.practice.ceiti.dao.repository.JobRepositoryInterface;
import com.practice.ceiti.services.impl.EmployeeServiceImpl;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.junit.jupiter.MockitoExtension;
import org.modelmapper.ModelMapper;
import org.springframework.context.annotation.PropertySource;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

import static org.assertj.core.api.Assertions.assertThat;
import static org.mockito.Mockito.doNothing;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.when;

@PropertySource("classpath:application-test.properties")
@ExtendWith(MockitoExtension.class)
public class EmployeeServiceTest {

    @InjectMocks
    EmployeeServiceImpl employeeService;

    @Mock
    EmployeeRepositoryInterface employeeRepository;
    @Mock
    JobRepositoryInterface jobRepositoryInterface;
    @Mock
    DepartmentRepositoryInterface departmentRepositoryInterface;

    @Mock
    ModelMapper modelMapper;

    private static final Job jobExpected1 = new Job(1, "Java Dev", 700, 3000);
    private static final Job jobExpected2 = new Job(2, "C# Dev", 700, 3000);
    private static final Job jobExpected3 = new Job(3, "Tester", 650, 250);

    private static final Department departmentExpected1 = new Department(1, "ENDAVA", "Strada Arborilor 21a, Chișinău 2025");
    private static final Department departmentExpected2 = new Department(2, "CEDACRI", "Centrul de Finanţe şi Business, 171/, Stefan cel Mare si Sfant Boulevard 1, Chișinău");
    private static final Department departmentExpected3 = new Department(3, "UNIFUN", "Bulevardul Decebal 6, Chișinău");

    private static final Employee employeeExpected1 = new Employee(1, "Alexandr", "Vicev", "Basarabeasca K.Marx 162", "069657662", 850, jobExpected1, departmentExpected1);
    private static final Employee employeeExpected2 = new Employee(2, "Artur", "Iancioglo", "Chisinau Decebal 7", "069654775", 850, jobExpected1, departmentExpected1);
    private static final Employee employeeExpected3 = new Employee(3, "Timur", "Vacarenco", "Chisinau Druta 9", "069742115", 650, jobExpected3, departmentExpected1);

    private static final EmployeeDtoImpl employeeDtoImplExpected1 = new EmployeeDtoImpl(
            employeeExpected1.getId(),
            employeeExpected1.getFirstName(),
            employeeExpected1.getLastName(),
            employeeExpected1.getAddress(),
            employeeExpected1.getPhoneNumber(),
            employeeExpected1.getSalary(),
            employeeExpected1.getJob().getJobName(),
            employeeExpected1.getDepartment().getDepartmentName());

    private static final EmployeeDtoImpl employeeDtoImplExpected2 = new EmployeeDtoImpl(
            employeeExpected2.getId(),
            employeeExpected2.getFirstName(),
            employeeExpected2.getLastName(),
            employeeExpected2.getAddress(),
            employeeExpected2.getPhoneNumber(),
            employeeExpected2.getSalary(),
            employeeExpected2.getJob().getJobName(),
            employeeExpected2.getDepartment().getDepartmentName());


    private static final EmployeeDtoImpl employeeDtoImplExpected3 = new EmployeeDtoImpl(
            employeeExpected3.getId(),
            employeeExpected3.getFirstName(),
            employeeExpected3.getLastName(),
            employeeExpected3.getAddress(),
            employeeExpected3.getPhoneNumber(),
            employeeExpected3.getSalary(),
            employeeExpected3.getJob().getJobName(),
            employeeExpected3.getDepartment().getDepartmentName());


    @Test
    void findByEmployeeIdTest() {
        when(employeeRepository.findById(1)).thenReturn(Optional.of(employeeExpected1));
        when(modelMapper.map(employeeExpected1, EmployeeDtoImpl.class)).thenReturn(employeeDtoImplExpected1);

        EmployeeDtoImpl employeeActual = employeeService.findByEmployeeId(1);

        assertThat(employeeActual).isEqualTo(employeeDtoImplExpected1);

        verify(employeeRepository).findById(employeeExpected1.getId());
        verify(modelMapper).map(employeeExpected1, EmployeeDtoImpl.class);
    }

    @Test
    void findAllTest() {
        List<EmployeeDto> employeeDtos = new ArrayList<>();
        employeeDtos.add(employeeDtoImplExpected1);
        employeeDtos.add(employeeDtoImplExpected2);
        employeeDtos.add(employeeDtoImplExpected3);

        List<Employee> employees = new ArrayList<>();
        employees.add(employeeExpected1);
        employees.add(employeeExpected2);
        employees.add(employeeExpected3);

        when(employeeRepository.findAll()).thenReturn(employees);
        when(modelMapper.map(employeeExpected1, EmployeeDtoImpl.class)).thenReturn(employeeDtoImplExpected1);
        when(modelMapper.map(employeeExpected2, EmployeeDtoImpl.class)).thenReturn(employeeDtoImplExpected2);
        when(modelMapper.map(employeeExpected3, EmployeeDtoImpl.class)).thenReturn(employeeDtoImplExpected3);

        List<EmployeeDto> employeeListActual = employeeService.findAll();

        assertThat(employeeDtos).isEqualTo(employeeListActual);

        verify(employeeRepository).findAll();
        verify(modelMapper).map(employeeExpected1, EmployeeDtoImpl.class);
        verify(modelMapper).map(employeeExpected1, EmployeeDtoImpl.class);
        verify(modelMapper).map(employeeExpected1, EmployeeDtoImpl.class);
    }

    @Test
    void saveTest() {
        when(employeeRepository.save(employeeExpected1)).thenReturn(employeeExpected1);

        when(departmentRepositoryInterface.findByDepartmentName(
                employeeExpected1
                        .getDepartment()
                        .getDepartmentName()))
                .thenReturn(Optional.of(departmentExpected1));

        when(jobRepositoryInterface.findByJobName(
                employeeExpected1
                        .getJob()
                        .getJobName()))
                .thenReturn(Optional.of(jobExpected1));

        when(modelMapper.map(employeeDtoImplExpected1, Employee.class)).thenReturn(employeeExpected1);
        when(modelMapper.map(employeeExpected1, EmployeeDtoImpl.class)).thenReturn(employeeDtoImplExpected1);

        EmployeeDtoImpl employeeDto = employeeService.save(employeeDtoImplExpected1);

        assertThat(employeeDto).isEqualTo(employeeDtoImplExpected1);

        verify(employeeRepository).save(employeeExpected1);
        verify(modelMapper).map(employeeDtoImplExpected1, Employee.class);
    }

    @Test
    void deleteByIdTest() {
        doNothing().when(employeeRepository).deleteById(employeeExpected1.getId());

        String actualResult = employeeService.deleteById(employeeExpected1.getId());

        assertThat(actualResult).isEqualTo("Employee " + employeeExpected1.getId() + " was deleted!");

        verify(employeeRepository).deleteById(employeeExpected1.getId());
    }

}
