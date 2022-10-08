package com.pretestare.airport.dao.dto.impl;

import com.pretestare.airport.dao.dto.RouteDto;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.Max;
import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;

@AllArgsConstructor
@NoArgsConstructor
@Data
public class RouteDtoImpl implements RouteDto {

    public Long codeRoute;

    @NotBlank(message = "Destination is mandatory")
    public String destination;

    @NotBlank(message = "Class is mandatory")
    public String classType;

    @Min(value = 1, message = "Min price is 1")
    @Max(value = 9999999, message = "Max price is 9999999")
    public int price;

    @NotNull(message = "Passenger code is mandatory")
    public Long passengerCode;
}
