package com.pretestare.airport.dao.model;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

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
import javax.validation.constraints.Max;
import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;

@Entity
@Table(name = "route")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class Route {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    Long codeRoute;

    @NotBlank(message = "Destination is mandatory")
    @Column(name = "destination")
    String destination;

    @NotBlank(message = "Class is mandatory")
    @Column(name = "class")
    String classType;

    @Min(value = 1, message = "Min price is 1")
    @Max(value = 9999999, message = "Max price is 9999999")
    @Column(name = "price")
    int price;

    @ManyToOne(fetch = FetchType.EAGER)
    @JoinColumn(name = "passenger_code", foreignKey = @ForeignKey(name = "FK_PASSENGER_ID"))
    Passenger passenger;
}
