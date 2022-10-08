package com.practice.ceiti.dao.dto;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.validation.annotation.Validated;

@Data
@NoArgsConstructor
@AllArgsConstructor
@Validated
public class DepartmentDtoImpl implements DepartmentDto {

    private Integer id;
    private String nameDepartment;
    private String address;
}
