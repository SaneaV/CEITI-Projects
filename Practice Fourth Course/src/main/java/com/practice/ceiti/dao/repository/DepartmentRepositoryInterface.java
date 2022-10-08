package com.practice.ceiti.dao.repository;

import com.practice.ceiti.dao.models.Department;
import org.springframework.stereotype.Repository;

import java.util.List;
import java.util.Optional;

@Repository
public interface DepartmentRepositoryInterface {

    List<Department> findAll();

    Optional<Department> findById(int departmentId);

    Department save(Department department);

    void deleteById(int departmentId);

    Optional<Department> findByDepartmentName(String departmentName);
}
