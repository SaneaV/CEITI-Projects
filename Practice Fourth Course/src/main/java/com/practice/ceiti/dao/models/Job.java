package com.practice.ceiti.dao.models;

import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.validation.annotation.Validated;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.OneToMany;
import javax.persistence.PreRemove;
import javax.persistence.Table;
import javax.persistence.UniqueConstraint;
import javax.validation.constraints.Max;
import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;
import java.util.List;

@Entity
@Table(name = "jobs",
        uniqueConstraints = {@UniqueConstraint(columnNames = {"job_name"}, name = "UK_JOB_JB_NAME")}
)
@NoArgsConstructor
@Data
@Validated
public class Job {

    @Id
    @Column(name = "id", updatable = false, nullable = false)
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    int id;

    @NotBlank(message = "Job name is mandatory")
    @Column(name = "job_name")
    String jobName;

    @Min(value = 1, message = "Salary must be greater than or equal to 1")
    @Max(value = 99999999, message = "Salary must be less than or equal to 99999999")
    @Column(name = "min_salary")
    int minSalary;

    @Min(value = 2, message = "Salary must be greater than or equal to 2")
    @Max(value = 999999999, message = "Salary must be less than or equal to 999999999")
    @Column(name = "max_salary")
    int maxSalary;

    @OneToMany(fetch = FetchType.LAZY, mappedBy = "job")
    private List<Employee> employees;

    public Job(int id, String jobName, int minSalary, int maxSalary) {
        this.id = id;
        this.jobName = jobName;
        this.minSalary = minSalary;
        this.maxSalary = maxSalary;
    }

    @PreRemove
    private void removeAssociationsWithEmployee() {
        for (Employee e : employees) {
            e.setJob(null);
        }
    }
}
