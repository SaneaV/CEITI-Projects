package com.practice.ceiti.dao.repository.DataJpa;

import com.practice.ceiti.dao.models.Employee;
import com.practice.ceiti.dao.repository.EmployeeRepositoryInterface;
import org.springframework.context.annotation.Profile;
import org.springframework.data.jpa.repository.JpaRepository;

@Profile("DataJPA")
public interface EmployeeRepository extends JpaRepository<Employee, Integer>, EmployeeRepositoryInterface {
}
