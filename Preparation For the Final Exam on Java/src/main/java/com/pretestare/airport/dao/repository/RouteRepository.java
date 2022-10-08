package com.pretestare.airport.dao.repository;

import com.pretestare.airport.dao.model.Passenger;
import com.pretestare.airport.dao.model.Route;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;

import java.util.List;

public interface RouteRepository extends JpaRepository<Route, Long> {
    List<Route> findAllByPassenger(Passenger passenger);

    List<Route> findAllByDestinationAndClassType(String destination, String typeClass);

    @Query(nativeQuery = true, value = "select destination, SUM(price) as total_sum, GROUP_CONCAT(DISTINCT CONCAT(name,' ', surname)) as passengers\n" +
            "FROM route INNER JOIN passenger ON route.passenger_code = passenger.passenger_code\n" +
            "group by destination")
    List<Object[]> sumTotalMoneyPerPassenger();
}
