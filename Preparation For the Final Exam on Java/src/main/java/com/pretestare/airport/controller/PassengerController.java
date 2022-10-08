package com.pretestare.airport.controller;

import com.pretestare.airport.dao.dto.impl.PassengerDtoImpl;
import com.pretestare.airport.service.PassengerService;
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
@AllArgsConstructor
@RequestMapping(value = "/")
public class PassengerController {

    private final PassengerService passengerService;

    @GetMapping(value = "/passengers")
    public String findAll(Model model) {
        model.addAttribute("passengers", passengerService.findAll());
        return "passengers/passengers";
    }

    @GetMapping(value = "/passenger-add")
    public String formForAdding(Model model) {
        model.addAttribute("passenger", new PassengerDtoImpl());
        return "passengers/add-passenger";
    }

    @GetMapping(value = "/passenger-update/{id}")
    public String formForUpdating(@PathVariable("id") Long id, Model model) {
        PassengerDtoImpl passengerDto = passengerService.findById(id);
        model.addAttribute("passenger", passengerDto);
        return "passengers/update-passenger";
    }

    @PostMapping("/passengers/add")
    public String create(@Valid PassengerDtoImpl passengerDto, BindingResult result, Model model) {
        if (result.hasErrors()) {
            model.addAttribute("passengers", passengerService.findAll());
            return "passengers/passengers";
        }

        passengerDto.setPassengerCode(0L);
        passengerService.save(passengerDto);
        return "redirect:/passengers";
    }

    @GetMapping("/passengers/update/{id}")
    public String update(@PathVariable Long id, @Valid PassengerDtoImpl passengerDto, BindingResult result, Model model) {
        if (result.hasErrors()) {
            model.addAttribute("passengers", passengerService.findAll());
            return "passengers/passengers";
        }

        passengerDto.setPassengerCode(id);
        passengerService.save(passengerDto);
        return "redirect:/passengers";
    }

    @GetMapping("/passengers/delete/{id}")
    public String delete(@PathVariable Long id) {
        passengerService.deleteById(id);
        return "redirect:/passengers";
    }
}
