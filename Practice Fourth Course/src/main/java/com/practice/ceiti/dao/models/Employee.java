package com.practice.ceiti.dao.models;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.validation.annotation.Validated;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.ForeignKey;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.Table;
import javax.persistence.UniqueConstraint;
import javax.validation.constraints.Max;
import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;

@Entity
@Table(name = "employees",
        uniqueConstraints = {@UniqueConstraint(columnNames = {"phone_number"}, name = "UK_EMPLOYEES_PHONE_NUMBER")}
)
@NoArgsConstructor
@AllArgsConstructor
@Data
@Validated
public class Employee {

    @Id
    @Column(name = "id", updatable = false, nullable = false)
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    int id;

    @NotBlank(message = "First name is mandatory")
    @Column(name = "first_name")
    String firstName;

    @NotBlank(message = "Last name is mandatory")
    @Column(name = "last_name")
    String lastName;

    @NotBlank(message = "Address is mandatory")
    @Column(name = "address")
    String address;

    @Pattern(message = "Phone number should start with zero and contain exactly 9 digits",
            regexp = "0\\d{8}")
    @Column(name = "phone_number")
    String phoneNumber;

    @Min(value = 1, message = "Salary must be greater than or equal to 1")
    @Max(value = 99999999, message = "Salary must be less than or equal to 99999999")
    @Column(name = "salary")
    int salary;

    @ManyToOne(fetch = FetchType.EAGER)
    @JoinColumn(name = "job_id", foreignKey = @ForeignKey(name = "FK_JOB_ID"))
    Job job;

    @ManyToOne(fetch = FetchType.EAGER)
    @JoinColumn(name = "department_id", foreignKey = @ForeignKey(name = "FK_DEPARTMENT_ID"))
    Department department;
}
