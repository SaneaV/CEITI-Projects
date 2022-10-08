package com.practice.ceiti.dao.repository.JDBC;

import com.practice.ceiti.dao.models.Job;
import com.practice.ceiti.dao.repository.JobRepositoryInterface;
import lombok.AllArgsConstructor;
import lombok.SneakyThrows;
import org.springframework.context.annotation.Profile;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.support.GeneratedKeyHolder;
import org.springframework.stereotype.Repository;

import javax.sql.DataSource;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.List;
import java.util.Objects;
import java.util.Optional;

@Profile("JDBC")
@AllArgsConstructor
@Repository
public class JobRepository implements JobRepositoryInterface {

    private final JdbcTemplate jdbcTemplate;
    private final DataSource dataSource;

    @Override
    public List<Job> findAll() {
        return jdbcTemplate.query("select * from jobs", this::mapJob);
    }

    @Override
    public Optional<Job> findById(int jobId) {
        return jdbcTemplate.query("select * from jobs where id = " + jobId, this::mapJob).stream().findAny();
    }

    @Override
    public Job save(Job job) {
        if (job.getId() < 0) {
            throw new IllegalArgumentException("Job Id has to be greater than zero");
        }
        if (job.getJobName().isBlank()) {
            throw new IllegalArgumentException("Job name is mandatory");
        }
        if (job.getMinSalary() < 1) {
            throw new IllegalArgumentException("Salary must be greater than or equal to 1");
        }
        if (job.getMinSalary() > 99999999) {
            throw new IllegalArgumentException("Salary must be less than or equal to 99999999");
        }
        if (job.getMaxSalary() < 2) {
            throw new IllegalArgumentException("Salary must be greater than or equal to 2");
        }
        if (job.getMaxSalary() > 999999999) {
            throw new IllegalArgumentException("Salary must be less than or equal to 999999999");
        }
        int primaryKey = 0;

        if (job.getId() == 0) {
            GeneratedKeyHolder holder = new GeneratedKeyHolder();
            jdbcTemplate.update(con -> {
                PreparedStatement statement = con.prepareStatement("insert into jobs(job_name, min_salary, max_salary) values(?,?,?) ", Statement.RETURN_GENERATED_KEYS);
                statement.setString(1, job.getJobName());
                statement.setInt(2, job.getMinSalary());
                statement.setInt(3, job.getMaxSalary());
                return statement;
            }, holder);

            primaryKey = Objects.requireNonNull(holder.getKey()).intValue();
            job.setId(primaryKey);
        } else {
            jdbcTemplate.update(
                    "update jobs set job_name = ?, min_salary = ?, max_salary = ? where id = ?",
                    job.getJobName(),
                    job.getMinSalary(),
                    job.getMaxSalary(),
                    job.getId()
            );

            primaryKey = job.getId();
        }

        return findById(primaryKey).orElseThrow();
    }

    @Override
    public void deleteById(int jobId) {
        jdbcTemplate.update("update employees set job_id = null where job_id = " + jobId);
        jdbcTemplate.update("delete from jobs where id = " + jobId);
    }

    @Override
    public Optional<Job> findByJobName(String jobName) {
        return jdbcTemplate.query("select * from jobs where job_name LIKE '" + jobName + "'", this::mapJob).stream().findAny();
    }


    @SneakyThrows
    private Job mapJob(ResultSet resultSet, int i) {
        return new Job(
                resultSet.getInt("id"),
                resultSet.getString("job_name"),
                resultSet.getInt("min_salary"),
                resultSet.getInt("max_salary")
        );
    }
}
