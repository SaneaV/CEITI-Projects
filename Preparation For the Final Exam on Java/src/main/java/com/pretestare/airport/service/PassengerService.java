package com.pretestare.airport.service;

import com.pretestare.airport.dao.dto.PassengerDto;
import com.pretestare.airport.dao.dto.impl.PassengerDtoImpl;

import java.util.List;

public interface PassengerService {
    List<PassengerDto> findAll();

    PassengerDtoImpl findById(Long id);

    void save(PassengerDtoImpl passengerDto);

    void deleteById(Long id);
}
