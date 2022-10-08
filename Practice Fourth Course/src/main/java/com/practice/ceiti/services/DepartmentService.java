package com.practice.ceiti.services;

import com.practice.ceiti.dao.dto.DepartmentDto;
import com.practice.ceiti.dao.dto.DepartmentDtoImpl;

import java.util.List;

public interface DepartmentService {

    List<DepartmentDto> findAll();

    DepartmentDtoImpl findByDepartmentId(Integer departmentId);

    DepartmentDtoImpl save(DepartmentDto departmentDto);

    String deleteById(Integer departmentId);

}
