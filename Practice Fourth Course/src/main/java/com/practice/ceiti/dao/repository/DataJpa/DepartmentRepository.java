package com.practice.ceiti.dao.repository.DataJpa;

import com.practice.ceiti.dao.models.Department;
import com.practice.ceiti.dao.repository.DepartmentRepositoryInterface;
import org.springframework.context.annotation.Profile;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.Optional;

@Profile("DataJPA")
public interface DepartmentRepository extends JpaRepository<Department, Integer>, DepartmentRepositoryInterface {
    Optional<Department> findByDepartmentName(String departmentName);
}
