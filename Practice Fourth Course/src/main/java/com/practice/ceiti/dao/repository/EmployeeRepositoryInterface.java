package com.practice.ceiti.dao.repository;

import com.practice.ceiti.dao.models.Employee;
import org.springframework.stereotype.Repository;

import java.util.List;
import java.util.Optional;

@Repository
public interface EmployeeRepositoryInterface {

    List<Employee> findAll();

    Optional<Employee> findById(int employeeId);

    Employee save(Employee employee);

    void deleteById(int employeeId);

}
