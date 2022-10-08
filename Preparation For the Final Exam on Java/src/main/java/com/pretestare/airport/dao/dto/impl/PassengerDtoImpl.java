package com.pretestare.airport.dao.dto.impl;

import com.pretestare.airport.dao.dto.PassengerDto;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;

@NoArgsConstructor
@Data
public class PassengerDtoImpl implements PassengerDto {

    public Long passengerCode;
    @NotBlank(message = "Surname is mandatory")
    public String surname;

    @NotBlank(message = "Name is mandatory")
    public String name;

    @Pattern(message = "phoneNumber should start with zero and contain exactly 8 digits",
            regexp = "0\\d{8}")
    public String phone;

    public int Sum;
}
