package com.practice.ceiti.services.impl;

import com.practice.ceiti.dao.dto.JobDto;
import com.practice.ceiti.dao.dto.JobDtoImpl;
import com.practice.ceiti.dao.models.Job;
import com.practice.ceiti.dao.repository.JobRepositoryInterface;
import com.practice.ceiti.services.JobService;
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
public class JobServiceImpl implements JobService {

    private final JobRepositoryInterface jobRepository;
    private final ModelMapper modelMapper;

    @Transactional
    @Override
    public List<JobDto> findAll() {
        return jobRepository.findAll()
                .stream()
                .map(this::convertToDTO)
                .collect(Collectors.toList());
    }

    @Transactional
    @Override
    public JobDtoImpl findByJobId(Integer jobId) {
        return convertToDTO(jobRepository.findById(jobId).orElse(null));
    }

    @Transactional
    @Override
    public JobDtoImpl save(JobDto jobDTO) {
        Job job = convertToEntity(jobDTO);

        jobRepository.save(job);

        return convertToDTO(job);
    }

    @Transactional
    @Override
    public String deleteById(Integer jobId) {
        jobRepository.deleteById(jobId);

        return "Job " + jobId + " was deleted!";
    }

    public JobDtoImpl convertToDTO(Job job) {
        return modelMapper.map(job, JobDtoImpl.class);
    }

    public Job convertToEntity(JobDto jobDTO) {
        return modelMapper.map(jobDTO, Job.class);
    }
}
