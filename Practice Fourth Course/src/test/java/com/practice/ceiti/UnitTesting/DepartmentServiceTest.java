package com.practice.ceiti.UnitTesting;

import com.practice.ceiti.dao.dto.DepartmentDto;
import com.practice.ceiti.dao.dto.DepartmentDtoImpl;
import com.practice.ceiti.dao.models.Department;
import com.practice.ceiti.dao.repository.DepartmentRepositoryInterface;
import com.practice.ceiti.services.impl.DepartmentServiceImpl;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.junit.jupiter.MockitoExtension;
import org.modelmapper.ModelMapper;
import org.springframework.context.annotation.PropertySource;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

import static org.assertj.core.api.Assertions.assertThat;
import static org.mockito.Mockito.doNothing;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.when;

@PropertySource("classpath:application-test.properties")
@ExtendWith(MockitoExtension.class)
public class DepartmentServiceTest {

    @InjectMocks
    DepartmentServiceImpl departmentService;

    @Mock
    DepartmentRepositoryInterface departmentRepository;

    @Mock
    ModelMapper modelMapper;

    private static final Department departmentExpected1 = new Department(1, "ENDAVA", "Strada Arborilor 21a, Chișinău 2025");
    private static final Department departmentExpected2 = new Department(2, "CEDACRI", "Centrul de Finanţe şi Business, 171/, Stefan cel Mare si Sfant Boulevard 1, Chișinău");
    private static final Department departmentExpected3 = new Department(3, "UNIFUN", "Bulevardul Decebal 6, Chișinău");

    private static final DepartmentDtoImpl departmentDtoExpected1 = new DepartmentDtoImpl(
            departmentExpected1.getId(),
            departmentExpected1.getDepartmentName(),
            departmentExpected1.getAddress()
    );
    private static final DepartmentDtoImpl departmentDtoExpected2 = new DepartmentDtoImpl(
            departmentExpected2.getId(),
            departmentExpected2.getDepartmentName(),
            departmentExpected2.getAddress()
    );
    private static final DepartmentDtoImpl departmentDtoExpected3 = new DepartmentDtoImpl(
            departmentExpected3.getId(),
            departmentExpected3.getDepartmentName(),
            departmentExpected3.getAddress()
    );

    @Test
    void findByDepartmentIdTest() {
        when(departmentRepository.findById(1)).thenReturn(Optional.of(departmentExpected1));
        when(modelMapper.map(departmentExpected1, DepartmentDtoImpl.class)).thenReturn(departmentDtoExpected1);

        DepartmentDto departmentActual = departmentService.findByDepartmentId(1);

        assertThat(departmentActual).isEqualTo(departmentDtoExpected1);

        verify(departmentRepository).findById(departmentExpected1.getId());
        verify(modelMapper).map(departmentExpected1, DepartmentDtoImpl.class);
    }

    @Test
    void findAllTest() {
        List<DepartmentDto> departmentDtos = new ArrayList<>();
        departmentDtos.add(departmentDtoExpected1);
        departmentDtos.add(departmentDtoExpected2);
        departmentDtos.add(departmentDtoExpected3);

        List<Department> departments = new ArrayList<>();
        departments.add(departmentExpected1);
        departments.add(departmentExpected2);
        departments.add(departmentExpected3);

        when(departmentRepository.findAll()).thenReturn(departments);
        when(modelMapper.map(departmentExpected1, DepartmentDtoImpl.class)).thenReturn(departmentDtoExpected1);
        when(modelMapper.map(departmentExpected2, DepartmentDtoImpl.class)).thenReturn(departmentDtoExpected2);
        when(modelMapper.map(departmentExpected3, DepartmentDtoImpl.class)).thenReturn(departmentDtoExpected3);

        List<DepartmentDto> departmentListActual = departmentService.findAll();

        assertThat(departmentListActual).isEqualTo(departmentDtos);

        verify(departmentRepository).findAll();
        verify(modelMapper).map(departmentExpected1, DepartmentDtoImpl.class);
        verify(modelMapper).map(departmentExpected2, DepartmentDtoImpl.class);
        verify(modelMapper).map(departmentExpected3, DepartmentDtoImpl.class);
    }

    @Test
    void saveTest() {
        when(departmentRepository.save(departmentExpected1)).thenReturn(departmentExpected1);
        when(modelMapper.map(departmentDtoExpected1, Department.class)).thenReturn(departmentExpected1);
        when(modelMapper.map(departmentExpected1, DepartmentDtoImpl.class)).thenReturn(departmentDtoExpected1);

        DepartmentDtoImpl departmentActual = departmentService.save(departmentDtoExpected1);

        assertThat(departmentActual).isEqualTo(departmentDtoExpected1);

        verify(departmentRepository).save(departmentExpected1);
        verify(modelMapper).map(departmentDtoExpected1, Department.class);
    }

    @Test
    void deleteByIdTest() {
        doNothing().when(departmentRepository).deleteById(departmentExpected1.getId());

        String actualResult = departmentService.deleteById(departmentExpected1.getId());

        assertThat(actualResult).isEqualTo("Department " + departmentExpected1.getId() + " was deleted!");

        verify(departmentRepository).deleteById(departmentExpected1.getId());
    }

}
