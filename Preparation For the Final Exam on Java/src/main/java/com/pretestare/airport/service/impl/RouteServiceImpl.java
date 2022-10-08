package com.pretestare.airport.service.impl;

import com.pretestare.airport.dao.dto.PassengerDto;
import com.pretestare.airport.dao.dto.RouteDto;
import com.pretestare.airport.dao.dto.impl.PassengerDtoImpl;
import com.pretestare.airport.dao.dto.impl.RouteDtoImpl;
import com.pretestare.airport.dao.model.DestinationSumPassengers;
import com.pretestare.airport.dao.model.Passenger;
import com.pretestare.airport.dao.model.Route;
import com.pretestare.airport.dao.repository.RouteRepository;
import com.pretestare.airport.service.RouteService;
import lombok.AllArgsConstructor;
import org.modelmapper.ModelMapper;
import org.springframework.stereotype.Service;

import java.math.BigInteger;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

@Service
@AllArgsConstructor
public class RouteServiceImpl implements RouteService {

    private final RouteRepository routeRepository;
    private final ModelMapper modelMapper;

    @Override
    public List<RouteDto> findAll() {
        return routeRepository
                .findAll()
                .stream()
                .map(this::convertToDTO)
                .collect(Collectors.toList());
    }

    @Override
    public RouteDtoImpl findById(Long id) {
        return convertToDTO(routeRepository.findById(id).orElse(null));
    }

    @Override
    public void save(RouteDtoImpl routeDto) {
        Route route = convertToEntity(routeDto);

        routeRepository.save(route);
    }

    @Override
    public void deleteById(Long id) {
        routeRepository.deleteById(id);
    }

    @Override
    public List<RouteDto> findAllByPassenger(PassengerDtoImpl passenger) {
        return routeRepository
                .findAllByPassenger(convertToEntityPassenger(passenger))
                .stream()
                .map(this::convertToDTO)
                .collect(Collectors.toList());
    }

    @Override
    public List<RouteDtoImpl> findAllByDestinationAndClass(String destination, String typeClass) {
        return routeRepository
                .findAllByDestinationAndClassType(destination, typeClass)
                .stream()
                .map(this::convertToDTO)
                .collect(Collectors.toList());
    }

    @Override
    public Set<DestinationSumPassengers> sumTotalMoneyPerPassenger() {
        Set<DestinationSumPassengers> destinationSumPassengersSet = new HashSet<>();
        List<Object[]> queryResult = routeRepository.sumTotalMoneyPerPassenger();
        for (Object[] obj : queryResult) {
            String destination = obj[0].toString();
            Long sum = ((BigInteger) obj[1]).longValue();
            String passengers = obj[2].toString();

            DestinationSumPassengers destinationSumPassengers = DestinationSumPassengers.builder()
                    .destination(destination)
                    .sum(sum)
                    .passengers(passengers)
                    .build();
            destinationSumPassengersSet.add(destinationSumPassengers);
        }
        return destinationSumPassengersSet;
    }

    public RouteDtoImpl convertToDTO(Route route) {
        return modelMapper.map(route, RouteDtoImpl.class);
    }

    public Route convertToEntity(RouteDtoImpl routeDto) {
        return modelMapper.map(routeDto, Route.class);
    }

    public Passenger convertToEntityPassenger(PassengerDto passengerDto) {
        return modelMapper.map(passengerDto, Passenger.class);
    }
}
