package com.practice.ceiti.UnitTesting;

import com.practice.ceiti.dao.dto.JobDto;
import com.practice.ceiti.dao.dto.JobDtoImpl;
import com.practice.ceiti.dao.models.Job;
import com.practice.ceiti.dao.repository.JobRepositoryInterface;
import com.practice.ceiti.services.impl.JobServiceImpl;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.junit.jupiter.MockitoExtension;
import org.modelmapper.ModelMapper;
import org.springframework.context.annotation.PropertySource;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

import static org.assertj.core.api.Assertions.assertThat;
import static org.junit.jupiter.api.Assertions.assertAll;
import static org.mockito.Mockito.doNothing;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.when;

@PropertySource("classpath:application-test.properties")
@ExtendWith(MockitoExtension.class)
public class JobServiceTest {

    @InjectMocks
    JobServiceImpl jobService;

    @Mock
    JobRepositoryInterface jobRepository;

    @Mock
    ModelMapper modelMapper;

    private static final Job jobExpected1 = new Job(1, "Java Dev", 700, 3000);
    private static final Job jobExpected2 = new Job(2, "C# Dev", 700, 3000);
    private static final Job jobExpected3 = new Job(3, "Tester", 650, 250);
    private static final JobDtoImpl jobDto1 = new JobDtoImpl(jobExpected1.getId(), jobExpected1.getJobName(), jobExpected1.getMinSalary(), jobExpected1.getMaxSalary());
    private static final JobDtoImpl jobDto2 = new JobDtoImpl(jobExpected1.getId(), jobExpected1.getJobName(), jobExpected1.getMinSalary(), jobExpected1.getMaxSalary());
    private static final JobDtoImpl jobDto3 = new JobDtoImpl(jobExpected1.getId(), jobExpected1.getJobName(), jobExpected1.getMinSalary(), jobExpected1.getMaxSalary());

    @Test
    void findByJobIdTest() {
        when(jobRepository.findById(1)).thenReturn(Optional.of(jobExpected1));
        when(modelMapper.map(jobExpected1, JobDtoImpl.class)).thenReturn(jobDto1);

        JobDtoImpl jobActual = jobService.findByJobId(1);

        assertAll(
                () -> assertThat(jobActual.getId()).isEqualTo(jobExpected1.getId()),
                () -> assertThat(jobActual.getJobName()).isEqualTo(jobExpected1.getJobName()),
                () -> assertThat(jobActual.getMaxSalary()).isEqualTo(jobExpected1.getMaxSalary()),
                () -> assertThat(jobActual.getMinSalary()).isEqualTo(jobExpected1.getMinSalary())
        );

        verify(jobRepository).findById(jobExpected1.getId());
        verify(modelMapper).map(jobExpected1, JobDtoImpl.class);
    }


    @Test
    void findAllTest() {
        List<JobDto> jobListExpected = new ArrayList<>();
        jobListExpected.add(jobDto1);
        jobListExpected.add(jobDto2);
        jobListExpected.add(jobDto3);

        List<Job> jobList = new ArrayList<>();
        jobList.add(jobExpected1);
        jobList.add(jobExpected2);
        jobList.add(jobExpected3);

        when(jobRepository.findAll()).thenReturn(jobList);
        when(modelMapper.map(jobExpected1, JobDtoImpl.class)).thenReturn(jobDto1);
        when(modelMapper.map(jobExpected2, JobDtoImpl.class)).thenReturn(jobDto2);
        when(modelMapper.map(jobExpected3, JobDtoImpl.class)).thenReturn(jobDto3);

        List<JobDto> jobListActual = jobService.findAll();

        assertThat(jobListActual).isEqualTo(jobListExpected);

        verify(jobRepository).findAll();
        verify(modelMapper).map(jobExpected1, JobDtoImpl.class);
        verify(modelMapper).map(jobExpected2, JobDtoImpl.class);
        verify(modelMapper).map(jobExpected3, JobDtoImpl.class);
    }

    @Test
    void saveTest() {
        when(jobRepository.save(jobExpected1)).thenReturn(jobExpected1);
        when(modelMapper.map(jobDto1, Job.class)).thenReturn(jobExpected1);
        when(modelMapper.map(jobExpected1, JobDtoImpl.class)).thenReturn(jobDto1);

        JobDto jobActual = jobService.save(jobDto1);

        assertThat(jobActual).isEqualTo(jobDto1);

        verify(jobRepository).save(jobExpected1);
        verify(modelMapper).map(jobDto1, Job.class);
    }

    @Test
    void deleteByIdTest() {
        doNothing().when(jobRepository).deleteById(jobExpected1.getId());

        String actualResult = jobService.deleteById(jobExpected1.getId());

        assertThat(actualResult).isEqualTo("Job " + jobExpected1.getId() + " was deleted!");

        verify(jobRepository).deleteById(jobExpected1.getId());
    }
}
