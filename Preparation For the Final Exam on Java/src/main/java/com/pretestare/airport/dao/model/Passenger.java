package com.pretestare.airport.dao.model;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;

@Entity
@Table(name = "passenger")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class Passenger {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    Long passengerCode;

    @NotBlank(message = "Surname is mandatory")
    @Column(name = "surname")
    String surname;

    @NotBlank(message = "Name is mandatory")
    @Column(name = "name")
    String name;

    @Pattern(message = "phoneNumber should start with zero and contain exactly 9 digits",
            regexp = "0\\d{8}")
    @Column(name = "phone")
    String phone;
}
