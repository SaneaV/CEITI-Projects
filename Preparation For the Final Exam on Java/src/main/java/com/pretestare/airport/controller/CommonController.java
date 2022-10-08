package com.pretestare.airport.controller;

import com.pretestare.airport.dao.dto.PassengerDto;
import com.pretestare.airport.dao.dto.impl.RouteDtoImpl;
import com.pretestare.airport.dao.model.DestinationSumPassengers;
import com.pretestare.airport.service.PassengerService;
import com.pretestare.airport.service.RouteService;
import lombok.AllArgsConstructor;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

@Controller
@AllArgsConstructor
@RequestMapping(value = "/")
public class CommonController {

    private final PassengerService passengerService;
    private final RouteService routeService;

    @GetMapping(value = "/task1/form")
    public String formForTask1() {
        return "task1/task1-form";
    }

    @GetMapping(value = "/task2/form")
    public String formForTask2() {
        return "task2/task2-form";
    }

    @GetMapping(value = "/task1")
    public String findPassengerAndRoutes(@RequestParam(name = "id") String id, Model model) {

        try {
            passengerService.findById(Long.valueOf(id));
        } catch (Exception e) {
            return "redirect:/task1/form";
        }

        model.addAttribute("passengers", passengerService.findById(Long.valueOf(id)));
        model.addAttribute("routes", routeService.findAllByPassenger(passengerService.findById(Long.valueOf(id))));
        return "task1/task1";
    }

    @GetMapping(value = "/task2")
    public String findPassengerByDestinationAndClass(@RequestParam(name = "destination") String destination,
                                                     @RequestParam(name = "class") String typeClass,
                                                     Model model) {
        List<RouteDtoImpl> routeDtoList = routeService.findAllByDestinationAndClass(destination, typeClass);
        Set<PassengerDto> passengerDtos = new HashSet<>();

        for (RouteDtoImpl route :
                routeDtoList) {
            passengerDtos.add(passengerService.findById(route.passengerCode));
        }

        model.addAttribute("routes", routeDtoList);
        model.addAttribute("passengers", passengerDtos);

        return "task2/task2";
    }

    @GetMapping(value = "/task3")
    public String findPassengerAndTotalAmount(Model model) {
        Set<DestinationSumPassengers> destinationSumPassengers = routeService.sumTotalMoneyPerPassenger();

        model.addAttribute("passengers", destinationSumPassengers);

        return "task3/task3";
    }
}
