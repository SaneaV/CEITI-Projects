package com.practice.ceiti.services.impl;

import com.practice.ceiti.dao.dto.DepartmentDto;
import com.practice.ceiti.dao.dto.DepartmentDtoImpl;
import com.practice.ceiti.dao.models.Department;
import com.practice.ceiti.dao.repository.DepartmentRepositoryInterface;
import com.practice.ceiti.services.DepartmentService;
import lombok.AllArgsConstructor;
import org.modelmapper.ModelMapper;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.EnableTransactionManagement;

import javax.transaction.Transactional;
import java.util.List;
import java.util.stream.Collectors;

@Service
@AllArgsConstructor
@EnableTransactionManagement
public class  DepartmentServiceImpl implements DepartmentService {

    private final DepartmentRepositoryInterface departmentRepository;
    private final ModelMapper modelMapper;

    @Transactional
    @Override
    public List<DepartmentDto> findAll() {
        return departmentRepository
                .findAll()
                .stream()
                .map(this::convertToDTO)
                .collect(Collectors.toList());
    }

    @Transactional
    @Override
    public DepartmentDtoImpl findByDepartmentId(Integer departmentId) {
        return convertToDTO(departmentRepository.findById(departmentId).orElse(null));
    }

    @Transactional
    @Override
    public DepartmentDtoImpl save(DepartmentDto departmentDto) {
        Department department = convertToEntity(departmentDto);

        departmentRepository.save(department);

        return convertToDTO(department);
    }

    @Transactional
    @Override
    public String deleteById(Integer departmentId) {
        departmentRepository.deleteById(departmentId);

        return "Department " + departmentId + " was deleted!";
    }

    public DepartmentDtoImpl convertToDTO(Department department) {
        return modelMapper.map(department, DepartmentDtoImpl.class);
    }

    public Department convertToEntity(DepartmentDto departmentDto) {
        return modelMapper.map(departmentDto, Department.class);
    }
}