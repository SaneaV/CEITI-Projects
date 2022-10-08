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
import javax.validation.constraints.NotBlank;
import java.util.List;

@Entity
@Table(name = "departments",
        uniqueConstraints = {@UniqueConstraint(columnNames = {"address"}, name = "UK_DEPARTMENTS_ADDRESS"),
                @UniqueConstraint(columnNames = {"department_name"}, name = "UK_DEPARTMENTS_DP_NAME")}
)
@NoArgsConstructor
@Data
@Validated
public class Department {

    @Id
    @Column(name = "id", updatable = false, nullable = false)
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    int id;

    @NotBlank(message = "Department name is mandatory")
    @Column(name = "department_name")
    String departmentName;

    @NotBlank(message = "Address is mandatory")
    @Column(name = "address")
    String address;

    @OneToMany(fetch = FetchType.LAZY, mappedBy = "department")
    private List<Employee> employees;

    public Department(int id, String departmentName, String address) {
        this.id = id;
        this.departmentName = departmentName;
        this.address = address;
    }

    @PreRemove
    private void removeAssociationsWithEmployee() {
        for (Employee e : employees) {
            e.setDepartment(null);
        }
    }
}
