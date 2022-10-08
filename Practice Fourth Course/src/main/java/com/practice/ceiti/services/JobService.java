package com.practice.ceiti.services;

import com.practice.ceiti.dao.dto.JobDto;
import com.practice.ceiti.dao.dto.JobDtoImpl;

import java.util.List;

public interface JobService {

    List<JobDto> findAll();

    JobDtoImpl findByJobId(Integer jobId);

    JobDtoImpl save(JobDto jobDTO);

    String deleteById(Integer jobId);

}
