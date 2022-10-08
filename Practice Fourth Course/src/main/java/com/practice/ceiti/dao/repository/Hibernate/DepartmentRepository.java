package com.practice.ceiti.dao.repository.Hibernate;

import com.practice.ceiti.dao.models.Department;
import com.practice.ceiti.dao.repository.DepartmentRepositoryInterface;
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
public class DepartmentRepository implements DepartmentRepositoryInterface {

    private final EntityManagerFactory entityManagerFactory;
    private final Environment env;


    @Override
    public List<Department> findAll() {
        Session session = entityManagerFactory.unwrap(SessionFactory.class).openSession();
        List<Department> departments;
        departments = session.getSession().createQuery("FROM Department").getResultList();
        session.close();
        return departments;
    }

    @Override
    public Optional<Department> findById(int departmentId) {
        Session session = entityManagerFactory.unwrap(SessionFactory.class).openSession();
        Optional<Department> department;
        department = session.getSession().createQuery("FROM Department WHERE id = " + departmentId)
                .getResultList()
                .stream()
                .findFirst();
        session.close();
        return department;
    }

    @Override
    public Department save(Department department) {
        if (department.getId() < 0) {
            throw new IllegalArgumentException("Department Id has to be greater than zero");
        }
        if (department.getDepartmentName().isBlank()) {
            throw new IllegalArgumentException("Department name is mandatory");
        }
        if (department.getAddress().isBlank()) {
            throw new IllegalArgumentException("Address is mandatory");
        }

        Session session = entityManagerFactory.unwrap(SessionFactory.class).openSession();
        int id = 0;

        if (department.getId() == 0) {
            id = (int) session.save(department);
        } else {
            Transaction txn = session.beginTransaction();
            Query query = session.createQuery("update Department set departmentName = :departmentName," +
                    "address = :address where id = :id");

            query.setParameter("departmentName", department.getDepartmentName());
            query.setParameter("address", department.getAddress());
            query.setParameter("id", department.getId());

            query.executeUpdate();
            txn.commit();
            id = department.getId();
        }

        session.close();
        return findById(id).orElseThrow();
    }

    @Override
    public void deleteById(int departmentId) {
        Session session = entityManagerFactory.unwrap(SessionFactory.class).openSession();

        Query query = session.createQuery("update Employee set department_id = null where department_id = :department_id");

        query.setParameter("department_id", departmentId);

        Transaction txn = session.beginTransaction();
        query.executeUpdate();
        txn.commit();

        query = session.createQuery("delete Department where id = :department_id");

        query.setParameter("department_id", departmentId);

        txn = session.beginTransaction();
        query.executeUpdate();

        String profile = env.getProperty("spring.profiles.active");

        assert profile != null;
        if (profile.contains("test")) {
            txn.rollback();
        } else {
            txn.commit();
        }
    }

    @Override
    public Optional<Department> findByDepartmentName(String departmentName) {
        Session session = entityManagerFactory.unwrap(SessionFactory.class).openSession();
        Optional<Department> department;
        department = session.getSession().createQuery("FROM Department WHERE department_name LIKE '" + departmentName + "'")
                .getResultList()
                .stream()
                .findFirst();
        session.close();
        return department;
    }
}
