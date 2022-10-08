package com.practice.ceiti.services.impl;

import com.practice.ceiti.dao.dto.EmployeeDto;
import com.practice.ceiti.dao.dto.EmployeeDtoImpl;
import com.practice.ceiti.dao.models.Employee;
import com.practice.ceiti.dao.repository.DepartmentRepositoryInterface;
import com.practice.ceiti.dao.repository.EmployeeRepositoryInterface;
import com.practice.ceiti.dao.repository.JobRepositoryInterface;
import com.practice.ceiti.services.EmployeeService;
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
public class EmployeeServiceImpl implements EmployeeService {

    private final EmployeeRepositoryInterface employeeRepository;
    private final DepartmentRepositoryInterface departmentRepositoryInterface;
    private final JobRepositoryInterface jobRepositoryInterface;
    private final ModelMapper modelMapper;

    @Transactional
    @Override
    public List<EmployeeDto> findAll() {
        return employeeRepository
                .findAll()
                .stream()
                .map(this::convertToDTO)
                .collect(Collectors.toList());
    }

    @Transactional
    @Override
    public EmployeeDtoImpl findByEmployeeId(Integer employeeId) {
        return convertToDTO(employeeRepository.findById(employeeId).orElse(null));
    }

    @Transactional
    @Override
    public EmployeeDtoImpl save(EmployeeDto employeeDto) {
        Employee employee = convertToEntity(employeeDto);

        employee.setJob(jobRepositoryInterface.findByJobName(employee.getJob().getJobName()).orElse(null));
        employee.setDepartment(departmentRepositoryInterface.findByDepartmentName(employee.getDepartment().getDepartmentName()).orElse(null));
        employeeRepository.save(employee);

        return convertToDTO(employee);
    }

    @Transactional
    @Override
    public String deleteById(Integer employeeId) {
        employeeRepository.deleteById(employeeId);

        return "Employee " + employeeId + " was deleted!";
    }

    public EmployeeDtoImpl convertToDTO(Employee employee) {
        return modelMapper.map(employee, EmployeeDtoImpl.class);
    }

    public Employee convertToEntity(EmployeeDto employeeDTO) {
        return modelMapper.map(employeeDTO, Employee.class);
    }
}
