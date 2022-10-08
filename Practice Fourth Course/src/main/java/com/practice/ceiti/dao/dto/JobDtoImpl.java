package com.practice.ceiti.dao.dto;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.validation.annotation.Validated;

@Data
@AllArgsConstructor
@NoArgsConstructor
@Validated
public class JobDtoImpl implements JobDto {

    private Integer id;
    private String jobName;
    private Integer minSalary;
    private Integer maxSalary;
}
