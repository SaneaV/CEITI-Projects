package com.pretestare.airport.dao.repository;

import com.pretestare.airport.dao.model.Passenger;
import org.springframework.data.jpa.repository.JpaRepository;

public interface PassengerRepository extends JpaRepository<Passenger, Long> {
}
