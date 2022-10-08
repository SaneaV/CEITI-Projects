package com.practice.ceiti.controllers;

import com.practice.ceiti.dao.dto.EmployeeDto;
import com.practice.ceiti.dao.dto.EmployeeDtoImpl;
import com.practice.ceiti.services.EmployeeService;
import lombok.AllArgsConstructor;
import org.springframework.dao.DataIntegrityViolationException;
import org.springframework.dao.InvalidDataAccessApiUsageException;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.security.access.prepost.PreAuthorize;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseStatus;
import org.springframework.web.bind.annotation.RestController;

import javax.validation.ConstraintViolation;
import javax.validation.ConstraintViolationException;
import javax.validation.Valid;
import java.util.List;
import java.util.Set;

@AllArgsConstructor
@RestController
@RequestMapping("/api/employees")
public class EmployeeController {

    private final EmployeeService employeeService;

    @GetMapping("")
    @PreAuthorize("hasAnyAuthority('ROLE_ADMIN', 'ROLE_USER')")
    public List<EmployeeDto> findAllEmployees() {
        return employeeService.findAll();
    }

    @GetMapping("/{id}")
    @PreAuthorize("hasAnyAuthority('ROLE_ADMIN', 'ROLE_USER')")
    public EmployeeDto findByIdEmployee(@PathVariable("id") Integer employeeId) {
        try {
            return employeeService.findByEmployeeId(employeeId);
        } catch (IllegalArgumentException illegalArgumentException) {
            throw new IllegalArgumentException("Employee " + employeeId + " not found!");
        }
    }

    @PostMapping("")
    @PreAuthorize("hasAnyAuthority('ROLE_ADMIN')")
    public ResponseEntity<EmployeeDto> saveEmployee(@Valid @RequestBody EmployeeDtoImpl employeeDTO) {
        employeeDTO.setId(0);

        return ResponseEntity
                .ok()
                .body(employeeService.save(employeeDTO));
    }

    @PutMapping("")
    @PreAuthorize("hasAnyAuthority('ROLE_ADMIN')")
    public EmployeeDto updateEmployee(@Valid @RequestBody EmployeeDtoImpl employeeDTO) {
        try {
            employeeService.findByEmployeeId(employeeDTO.getId());
        } catch (IllegalArgumentException illegalArgumentException) {
            throw new IllegalArgumentException("Employee " + employeeDTO.getId() + " not found!");
        }
        return employeeService.save(employeeDTO);
    }

    @DeleteMapping("/{id}")
    @PreAuthorize("hasAnyAuthority('ROLE_ADMIN')")
    public ResponseEntity<String> deleteEmployee(@PathVariable("id") Integer employeeId) {
        try {
            employeeService.findByEmployeeId(employeeId);
        } catch (IllegalArgumentException illegalArgumentException) {
            throw new IllegalArgumentException("Employee " + employeeId + " not found!");
        }
        return ResponseEntity
                .ok()
                .body(employeeService.deleteById(employeeId));
    }

    @ResponseStatus(HttpStatus.NOT_ACCEPTABLE)
    @ExceptionHandler(ConstraintViolationException.class)
    public ResponseEntity<String> handleValidationExceptions(ConstraintViolationException exception) {

        StringBuilder message = new StringBuilder();
        Set<ConstraintViolation<?>> violations = exception.getConstraintViolations();
        for (ConstraintViolation<?> violation : violations) {
            message.append(violation.getMessage().concat("\n"));
        }
        return ResponseEntity
                .status(HttpStatus.NOT_ACCEPTABLE)
                .body(message.toString());
    }

    @ExceptionHandler(IllegalArgumentException.class)
    @ResponseStatus(HttpStatus.NOT_FOUND)
    public ResponseEntity<String> handleIllegalArgumentException(IllegalArgumentException exception) {
        return ResponseEntity
                .status(HttpStatus.NOT_FOUND)
                .body(exception.getMessage());
    }

    @ExceptionHandler(DataIntegrityViolationException.class)
    @ResponseStatus(HttpStatus.NOT_ACCEPTABLE)
    public ResponseEntity<String> handleConstraintViolationException() {
        return ResponseEntity
                .status(HttpStatus.NOT_ACCEPTABLE)
                .body("Constraint error:\n1. Use only unique fields\n2. Check existence of foreign keys");
    }

    @ExceptionHandler(InvalidDataAccessApiUsageException.class)
    @ResponseStatus(HttpStatus.NOT_ACCEPTABLE)
    public ResponseEntity<String> handleInvalidDataAccessApiUsageException(InvalidDataAccessApiUsageException exception) {
        return ResponseEntity
                .status(HttpStatus.NOT_ACCEPTABLE)
                .body(exception.getMessage());
    }

    @ExceptionHandler(Exception.class)
    @ResponseStatus(HttpStatus.NOT_ACCEPTABLE)
    public ResponseEntity<String> handleException() {
        return ResponseEntity
                .status(HttpStatus.NOT_ACCEPTABLE)
                .body("Unknown error");
    }

}
