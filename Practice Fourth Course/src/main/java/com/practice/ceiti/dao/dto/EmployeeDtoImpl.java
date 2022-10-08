package com.practice.ceiti.dao.dto;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.validation.annotation.Validated;

@Data
@NoArgsConstructor
@AllArgsConstructor
@Validated
public class EmployeeDtoImpl implements EmployeeDto {

    private Integer id;
    private String firstName;
    private String lastName;
    private String address;
    private String phoneNumber;
    private Integer salary;
    private String jobName;
    private String departmentName;
}
