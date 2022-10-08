package com.practice.ceiti.dao.repository.DataJpa;

import com.practice.ceiti.dao.models.Job;
import com.practice.ceiti.dao.repository.JobRepositoryInterface;
import org.springframework.context.annotation.Profile;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.Optional;

@Profile("DataJPA")
public interface JobRepository extends JpaRepository<Job, Integer>, JobRepositoryInterface {
    Optional<Job> findByJobName(String jobName);
}
