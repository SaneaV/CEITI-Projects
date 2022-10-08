package com.practice.ceiti.services;

import com.practice.ceiti.dao.dto.EmployeeDto;
import com.practice.ceiti.dao.dto.EmployeeDtoImpl;

import java.util.List;

public interface EmployeeService {

    List<EmployeeDto> findAll();

    EmployeeDtoImpl findByEmployeeId(Integer employeeId);

    EmployeeDtoImpl save(EmployeeDto employeeDTO);

    String deleteById(Integer employeeId);

}
