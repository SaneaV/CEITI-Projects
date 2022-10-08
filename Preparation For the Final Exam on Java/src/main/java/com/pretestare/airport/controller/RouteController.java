package com.pretestare.airport.controller;

import com.pretestare.airport.dao.dto.impl.RouteDtoImpl;
import com.pretestare.airport.service.RouteService;
import lombok.AllArgsConstructor;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.validation.Valid;

@Controller
@RequestMapping("/")
@AllArgsConstructor
public class RouteController {

    private final RouteService routeService;

    @GetMapping(value = "/routes")
    public String findAll(Model model) {
        model.addAttribute("routes", routeService.findAll());
        return "routes/routes";
    }

    @GetMapping(value = "/add-route")
    public String formForAdding(Model model) {
        model.addAttribute("route", new RouteDtoImpl());
        return "routes/add-route";
    }

    @GetMapping(value = "/route-update/{id}")
    public String formForUpdating(@PathVariable("id") Long id, Model model) {
        RouteDtoImpl routeDto = routeService.findById(id);
        model.addAttribute("route", routeDto);
        return "routes/update-route";
    }

    @PostMapping("/routes/add")
    public String create(@Valid RouteDtoImpl routeDto, BindingResult result, Model model) {
        if (result.hasErrors()) {
            model.addAttribute("routes", routeService.findAll());
            return "routes/routes";
        }

        routeDto.setCodeRoute(0L);
        routeService.save(routeDto);
        return "redirect:/routes";
    }

    @GetMapping("/routes/update/{id}")
    public String update(@PathVariable Long id, @Valid RouteDtoImpl routeDto, BindingResult result, Model model) {
        if (result.hasErrors()) {
            model.addAttribute("routes", routeService.findAll());
            return "routes/routes";
        }

        routeDto.setCodeRoute(id);
        routeService.save(routeDto);
        return "redirect:/routes";
    }

    @GetMapping("/routes/delete/{id}")
    public String delete(@PathVariable Long id) {
        routeService.deleteById(id);
        return "redirect:/routes";
    }
}
