package com.practice.ceiti.controllers;

import com.practice.ceiti.dao.dto.JobDto;
import com.practice.ceiti.dao.dto.JobDtoImpl;
import com.practice.ceiti.services.JobService;
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
@RequestMapping("/api/jobs")
public class JobController {

    private final JobService jobService;

    @GetMapping("")
    @PreAuthorize("hasAnyAuthority('ROLE_ADMIN', 'ROLE_USER')")
    public List<JobDto> findAllJobs() {
        return jobService.findAll();
    }

    @GetMapping("/{id}")
    @PreAuthorize("hasAnyAuthority('ROLE_ADMIN', 'ROLE_USER')")
    public JobDto findByIdJob(@PathVariable("id") Integer jobId) {
        try {
            return jobService.findByJobId(jobId);
        } catch (IllegalArgumentException illegalArgumentException) {
            throw new IllegalArgumentException("Job " + jobId + " not found!");
        }
    }

    @PostMapping("")
    @PreAuthorize("hasAnyAuthority('ROLE_ADMIN')")
    public ResponseEntity<JobDto> saveJob(@Valid @RequestBody JobDtoImpl jobDto) {
        jobDto.setId(0);

        return ResponseEntity
                .ok()
                .body(jobService.save(jobDto));
    }

    @PutMapping("")
    @PreAuthorize("hasAnyAuthority('ROLE_ADMIN')")
    public JobDto updateJob(@Valid @RequestBody JobDtoImpl jobDto) {
        try {
            jobService.findByJobId(jobDto.getId());
        } catch (IllegalArgumentException illegalArgumentException) {
            throw new IllegalArgumentException("Job " + jobDto.getId() + " not found!");
        }

        return jobService.save(jobDto);
    }

    @DeleteMapping("/{id}")
    @PreAuthorize("hasAnyAuthority('ROLE_ADMIN')")
    public ResponseEntity<String> deleteJob(@PathVariable("id") Integer jobId) {
        try {
            jobService.findByJobId(jobId);
        } catch (IllegalArgumentException illegalArgumentException) {
            throw new IllegalArgumentException("Job " + jobId + " not found!");
        }

        return ResponseEntity
                .ok()
                .body(jobService.deleteById(jobId));
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

    @ExceptionHandler(InvalidDataAccessApiUsageException.class)
    @ResponseStatus(HttpStatus.NOT_ACCEPTABLE)
    public ResponseEntity<String> handleInvalidDataAccessApiUsageException(InvalidDataAccessApiUsageException exception) {
        return ResponseEntity
                .status(HttpStatus.NOT_ACCEPTABLE)
                .body(exception.getMessage());
    }

    @ExceptionHandler(DataIntegrityViolationException.class)
    @ResponseStatus(HttpStatus.NOT_ACCEPTABLE)
    public ResponseEntity<String> handleConstraintViolationException() {
        return ResponseEntity
                .status(HttpStatus.NOT_ACCEPTABLE)
                .body("Constraint error:\n1. Use only unique fields\n2. Check existence of foreign keys");
    }

    @ExceptionHandler(Exception.class)
    @ResponseStatus(HttpStatus.NOT_ACCEPTABLE)
    public ResponseEntity<String> handleException() {
        return ResponseEntity
                .status(HttpStatus.NOT_ACCEPTABLE)
                .body("Unknown error");
    }
}
