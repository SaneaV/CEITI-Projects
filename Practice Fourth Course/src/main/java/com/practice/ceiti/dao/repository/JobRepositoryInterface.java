package com.practice.ceiti.dao.repository;

import com.practice.ceiti.dao.models.Job;
import org.springframework.stereotype.Repository;

import java.util.List;
import java.util.Optional;

@Repository
public interface JobRepositoryInterface {

    List<Job> findAll();

    Optional<Job> findById(int jobId);

    Job save(Job job);

    void deleteById(int jobId);

    Optional<Job> findByJobName(String jobName);

}
