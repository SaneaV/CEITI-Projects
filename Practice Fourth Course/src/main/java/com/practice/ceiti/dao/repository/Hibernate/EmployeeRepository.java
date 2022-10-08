package com.practice.ceiti.dao.repository.Hibernate;

import com.practice.ceiti.dao.models.Employee;
import com.practice.ceiti.dao.repository.DepartmentRepositoryInterface;
import com.practice.ceiti.dao.repository.EmployeeRepositoryInterface;
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
import java.util.regex.Pattern;

@Profile("Hibernate")
@AllArgsConstructor
@Repository
public class EmployeeRepository implements EmployeeRepositoryInterface {

    private final EntityManagerFactory entityManagerFactory;
    private final Environment env;

    private final DepartmentRepositoryInterface departmentRepositoryInterface;
    private final JobRepositoryInterface jobRepositoryInterface;

    @Override
    public List<Employee> findAll() {
        Session session = entityManagerFactory.unwrap(SessionFactory.class).openSession();
        List<Employee> employees;
        jobRepositoryInterface.findAll();
        departmentRepositoryInterface.findAll();
        employees = session.getSession().createQuery("FROM Employee").getResultList();
        session.close();
        return employees;
    }

    @Override
    public Optional<Employee> findById(int employeeId) {
        Session session = entityManagerFactory.unwrap(SessionFactory.class).openSession();
        Optional<Employee> employee;
        employee = session.getSession().createQuery("FROM Employee WHERE id = " + employeeId)
                .getResultList()
                .stream()
                .findFirst();
        session.close();
        return employee;
    }

    @Override
    public Employee save(Employee employee) {
        if (employee.getId() < 0) {
            throw new IllegalArgumentException("Job Id has to be greater than zero");
        }
        if (employee.getFirstName().isBlank()) {
            throw new IllegalArgumentException("First name is mandatory");
        }
        if (employee.getLastName().isBlank()) {
            throw new IllegalArgumentException("Last name is mandatory");
        }
        if (employee.getAddress().isBlank()) {
            throw new IllegalArgumentException("Address is mandatory");
        }
        if (employee.getSalary() < 1) {
            throw new IllegalArgumentException("Salary must be greater than or equal to 1");
        }
        if (employee.getSalary() > 99999999) {
            throw new IllegalArgumentException("Salary must be less than or equal to 99999999");
        }
        if (!Pattern.matches("0\\d{8}", employee.getPhoneNumber())) {
            throw new IllegalArgumentException("Phone number should start with zero and contain exactly 9 digits");
        }

        Session session = entityManagerFactory.unwrap(SessionFactory.class).openSession();
        int id = 0;

        Transaction txn = session.beginTransaction();
        if (employee.getId() == 0) {
            id = (int) session.save(employee);
            txn.commit();
        } else {
            Query query = session.createQuery("update Employee set " +
                    "firstName = :firstName, " +
                    "lastName = :lastName," +
                    "address = :address, " +
                    "phoneNumber = :phoneNumber, " +
                    "salary = :salary, " +
                    "job = :job, " +
                    "department = :department " +
                    "where id = :id");

            query.setParameter("firstName", employee.getFirstName());
            query.setParameter("lastName", employee.getLastName());
            query.setParameter("address", employee.getAddress());
            query.setParameter("phoneNumber", employee.getPhoneNumber());
            query.setParameter("salary", employee.getSalary());
            query.setParameter("job", employee.getJob());
            query.setParameter("department", employee.getDepartment());
            query.setParameter("id", employee.getId());

            query.executeUpdate();
            txn.commit();
            id = employee.getId();
        }

        session.close();
        return findById(id).orElseThrow();
    }

    @Override
    public void deleteById(int employeeId) {
        Session session = entityManagerFactory.unwrap(SessionFactory.class).openSession();

        Query query = session.createQuery("delete Employee where id = :employeeId");

        query.setParameter("employeeId", employeeId);

        Transaction txn = session.beginTransaction();
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
}
