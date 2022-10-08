package com.pretestare.airport.service.impl;

import com.pretestare.airport.dao.dto.PassengerDto;
import com.pretestare.airport.dao.dto.impl.PassengerDtoImpl;
import com.pretestare.airport.dao.model.Passenger;
import com.pretestare.airport.dao.model.Route;
import com.pretestare.airport.dao.repository.PassengerRepository;
import com.pretestare.airport.dao.repository.RouteRepository;
import com.pretestare.airport.service.PassengerService;
import lombok.AllArgsConstructor;
import org.modelmapper.ModelMapper;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.stream.Collectors;

@Service
@AllArgsConstructor
public class PassengerServiceImpl implements PassengerService {

    private final PassengerRepository passengerRepository;
    private final RouteRepository routeRepository;
    private final ModelMapper modelMapper;

    @Override
    public List<PassengerDto> findAll() {
        return passengerRepository
                .findAll()
                .stream()
                .map(this::convertToDTO)
                .collect(Collectors.toList());
    }

    @Override
    public PassengerDtoImpl findById(Long id) {
        return convertToDTO(passengerRepository.findById(id).orElse(null));
    }

    @Override
    public void save(PassengerDtoImpl passengerDto) {
        Passenger passenger = convertToEntity(passengerDto);

        passengerRepository.save(passenger);
    }

    @Override
    public void deleteById(Long id) {
        List<Route> routes = routeRepository.findAllByPassenger(passengerRepository.findById(id).orElse(null));
        for (Route route :
                routes) {
            routeRepository.deleteById(route.getCodeRoute());
        }
        passengerRepository.deleteById(id);
    }

    public PassengerDtoImpl convertToDTO(Passenger passenger) {
        return modelMapper.map(passenger, PassengerDtoImpl.class);
    }

    public Passenger convertToEntity(PassengerDto passengerDto) {
        return modelMapper.map(passengerDto, Passenger.class);
    }
}
