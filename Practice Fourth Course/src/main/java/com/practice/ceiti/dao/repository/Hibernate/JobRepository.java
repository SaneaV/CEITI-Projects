package com.practice.ceiti.dao.repository.Hibernate;

import com.practice.ceiti.dao.models.Job;
import com.practice.ceiti.dao.repository.JobRepositoryInterface;
import lombok.AllArgsConstructor;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.query.Query;
import org.springframework.context.annotation.Profile;
import org.springframework.core.env.Environment;
import org.springframework.stereotype.Repository;

import javax.persistence.EntityManagerFactory;
import java.util.List;
import java.util.Optional;

@Profile("Hibernate")
@AllArgsConstructor
@Repository
public class JobRepository implements JobRepositoryInterface {

    private final EntityManagerFactory entityManagerFactory;
    private final Environment env;

    @Override
    public List<Job> findAll() {
        Session session = entityManagerFactory.unwrap(SessionFactory.class).openSession();
        List<Job> jobs;
        jobs = session.getSession().createQuery("FROM Job").getResultList();
        session.close();
        return jobs;
    }

    @Override
    public Optional<Job> findById(int jobId) {
        Session session = entityManagerFactory.unwrap(SessionFactory.class).openSession();
        Optional<Job> job;
        job = session.getSession().createQuery("FROM Job WHERE id = " + jobId)
                .getResultList()
                .stream()
                .findFirst();
        session.close();
        return job;
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

        Session session = entityManagerFactory.unwrap(SessionFactory.class).openSession();
        int id = 0;

        if (job.getId() == 0) {
            Transaction txn = session.beginTransaction();
            id = (int) session.save(job);
            txn.commit();
        } else {
            Transaction txn = session.beginTransaction();
            Query query = session.createQuery("update Job set jobName = :jobName, minSalary = :minSalary," +
                    "maxSalary = :maxSalary where id = :id");

            query.setParameter("jobName", job.getJobName());
            query.setParameter("minSalary", job.getMinSalary());
            query.setParameter("maxSalary", job.getMaxSalary());
            query.setParameter("id", job.getId());

            query.executeUpdate();
            txn.commit();
            id = job.getId();
        }

        session.close();
        return findById(id).orElseThrow();
    }

    @Override
    public void deleteById(int jobId) {
        Session session = entityManagerFactory.unwrap(SessionFactory.class).openSession();

        Query query = session.createQuery("update Employee set job_id = null where job_id = :jobId");
        query.setParameter("jobId", jobId);

        Transaction txn = session.beginTransaction();
        query.executeUpdate();
        txn.commit();

        query = session.createQuery("delete Job where id = :jobId");
        query.setParameter("jobId", jobId);

        txn = session.beginTransaction();
        query.executeUpdate();

        String profile = env.getProperty("spring.profiles.active");

        assert profile != null;
        if (profile.contains("test")) {
            txn.rollback();
        } else {
            txn.commit();
        }

        session.close();
    }

    @Override
    public Optional<Job> findByJobName(String jobName) {
        Session session = entityManagerFactory.unwrap(SessionFactory.class).openSession();
        Optional<Job> job;
        job = session.getSession().createQuery("FROM Job WHERE job_name LIKE '" + jobName + "'")
                .getResultList()
                .stream()
                .findFirst();
        session.close();
        return job;
    }

}
