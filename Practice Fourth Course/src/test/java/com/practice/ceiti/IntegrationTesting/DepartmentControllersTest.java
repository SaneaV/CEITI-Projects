package com.practice.ceiti.IntegrationTesting;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.type.TypeFactory;
import com.practice.ceiti.dao.dto.DepartmentDto;
import com.practice.ceiti.dao.dto.DepartmentDtoImpl;
import com.practice.ceiti.services.DepartmentService;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.ValueSource;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.AutoConfigureMockMvc;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.context.annotation.PropertySource;
import org.springframework.security.test.context.support.WithMockUser;
import org.springframework.test.context.junit.jupiter.SpringExtension;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.test.web.servlet.MvcResult;

import javax.transaction.Transactional;
import java.util.List;

import static org.assertj.core.api.Assertions.assertThat;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.*;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.status;

@SpringBootTest
@AutoConfigureMockMvc
@PropertySource("classpath:application-test.properties")
@ExtendWith(SpringExtension.class)
public class DepartmentControllersTest {

    @Autowired
    private MockMvc mockMvc;

    @Autowired
    private ObjectMapper objectMapper;

    @Autowired
    private DepartmentService departmentService;

    private static final DepartmentDtoImpl DEPARTMENT_NEW_VALID_1 = new DepartmentDtoImpl(null, "Soft Lider", "Bulevardul Moscova 17/A, Chisinau 2068");
    private static final DepartmentDtoImpl DEPARTMENT_NEW_VALID_2 = new DepartmentDtoImpl(null, "IT FED-CO Ltd", "5 Soroceanu Street, Chisinau");
    private static final DepartmentDtoImpl DEPARTMENT_UPDATE_ADDRESS = new DepartmentDtoImpl(1, "ENDAVA", "Strada Arborilor 21, Chisinau 2025");
    private static final DepartmentDtoImpl DEPARTMENT_UPDATE_ID_DOES_NOT_EXIST = new DepartmentDtoImpl(5, "ENDAVA", "Strada Arborilor 21, Chisinau 2025");
    private static final DepartmentDtoImpl DEPARTMENT_NEW_NOT_UNIQUE_DEPARTMENT_NAME = new DepartmentDtoImpl(null, "ENDAVA", "Strada Arborilor 21, Chisinau 2025");
    private static final DepartmentDtoImpl DEPARTMENT_NEW_NOT_UNIQUE_ADDRESS = new DepartmentDtoImpl(null, "ENDAVA", "Strada Arborilor 21/a, Chisinau 2025");
    private static final DepartmentDtoImpl DEPARTMENT_NEW_BLANK_ADDRESS = new DepartmentDtoImpl(null, "ENDAVA", "");
    private static final DepartmentDtoImpl DEPARTMENT_NEW_BLANK_NAME = new DepartmentDtoImpl(null, "", "Strada Arborilor 21/a, Chisinau 2025");

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenFindAllDepartments_thenResponseOk() throws Exception {
        mockMvc.perform(get("/api/departments")
                .contentType("application/json"))
                .andExpect(status().isOk())
                .andReturn();
    }

    @ParameterizedTest()
    @ValueSource(ints = {1, 3, 2})
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenFindByIdDepartment_thenResponseOk(int jobId) throws Exception {
        mockMvc.perform(get("/api/departments/{id}", jobId)
                .contentType("application/json"))
                .andExpect(status().isOk())
                .andReturn();
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenSaveDepartment_thenResponseCreated() throws Exception {
        mockMvc.perform(post("/api/departments")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(DEPARTMENT_NEW_VALID_1)))
                .andExpect(status().isOk())
                .andReturn();
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenUpdateDepartment_thenResponseOk() throws Exception {
        mockMvc.perform(put("/api/departments")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(DEPARTMENT_UPDATE_ADDRESS)))
                .andExpect(status().isOk())
                .andReturn();
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenDeleteDepartment_thenResponseOk() throws Exception {
        int departmentId = 1;

        mockMvc.perform(delete("/api/departments/{id}", departmentId)
                .contentType("application/json"))
                .andExpect(status().isOk())
                .andReturn();
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenFindByIdDepartmentNotExist_thenReturn404AndErrorResponse() throws Exception {
        int jobId = 10;

        MvcResult mvcResult = mockMvc.perform(get("/api/departments/{id}", jobId)
                .contentType("application/json"))
                .andExpect(status().isNotFound())
                .andReturn();

        String actualResponseBody = mvcResult.getResponse().getContentAsString();
        assertThat(actualResponseBody).contains("Department " + jobId + " not found!");
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenUpdateDepartmentNotExist_thenReturn404AndErrorResponse() throws Exception {
        MvcResult mvcResult = mockMvc.perform(put("/api/departments")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(DEPARTMENT_UPDATE_ID_DOES_NOT_EXIST)))
                .andExpect(status().isNotFound())
                .andReturn();

        String actualResponseBody = mvcResult.getResponse().getContentAsString();
        assertThat(actualResponseBody).contains("Department " + DEPARTMENT_UPDATE_ID_DOES_NOT_EXIST.getId() + " not found!");
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenDeleteDepartmentNotExist_thenReturn404AndErrorResponse() throws Exception {
        int departmentId = 10;

        MvcResult mvcResult = mockMvc.perform(delete("/api/departments/{id}", departmentId)
                .contentType("application/json"))
                .andExpect(status().isNotFound())
                .andReturn();

        String actualResponseBody = mvcResult.getResponse().getContentAsString();
        assertThat(actualResponseBody).contains("Department " + departmentId + " not found!");
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenSaveNotUniqueDepartmentName_thenReturn406AndErrorResponse() throws Exception {
        MvcResult mvcResult = mockMvc.perform(post("/api/departments")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(DEPARTMENT_NEW_NOT_UNIQUE_DEPARTMENT_NAME)))
                .andExpect(status().isNotAcceptable())
                .andReturn();

        String actualResponseBody = mvcResult.getResponse().getContentAsString();
        assertThat(actualResponseBody).contains("Constraint error:\n1. Use only unique fields\n2. Check existence of foreign keys");
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenSaveNotUniqueDepartmentAddress_thenReturn406AndErrorResponse() throws Exception {
        MvcResult mvcResult = mockMvc.perform(post("/api/departments")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(DEPARTMENT_NEW_NOT_UNIQUE_ADDRESS)))
                .andExpect(status().isNotAcceptable())
                .andReturn();

        String actualResponseBody = mvcResult.getResponse().getContentAsString();
        assertThat(actualResponseBody).contains("Constraint error:\n1. Use only unique fields\n2. Check existence of foreign keys");
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenSaveBlankDepartmentAddress_thenReturn406AndErrorResponse() throws Exception {
        MvcResult mvcResult = mockMvc.perform(post("/api/departments")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(DEPARTMENT_NEW_BLANK_ADDRESS)))
                .andExpect(status().isNotAcceptable())
                .andReturn();

        String actualResponseBody = mvcResult.getResponse().getContentAsString();
        assertThat(actualResponseBody).contains("Address is mandatory");
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenSaveBlankDepartmentName_thenReturn406AndErrorResponse() throws Exception {
        MvcResult mvcResult = mockMvc.perform(post("/api/departments")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(DEPARTMENT_NEW_BLANK_NAME)))
                .andExpect(status().isNotAcceptable())
                .andReturn();

        String actualResponseBody = mvcResult.getResponse().getContentAsString();
        assertThat(actualResponseBody).contains("Department name is mandatory");
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenSaveValid_thenReturn200AndPostedEntity() throws Exception {
        MvcResult mvcResult = mockMvc.perform(post("/api/departments")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(DEPARTMENT_NEW_VALID_2)))
                .andExpect(status().isOk())
                .andReturn();

        DepartmentDtoImpl actualResponse = objectMapper.
                readValue(mvcResult.
                        getResponse().
                        getContentAsString(), DepartmentDtoImpl.class);

        DepartmentDtoImpl expectedResponse = departmentService.
                findByDepartmentId(actualResponse.getId());

        assertThat(actualResponse)
                .usingRecursiveComparison()
                .ignoringFields("id")
                .isEqualTo(DEPARTMENT_NEW_VALID_2);

        assertThat(actualResponse).isEqualTo(expectedResponse);
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenUpdateValid_thenReturn200AndPutEntity() throws Exception {
        MvcResult mvcResult = mockMvc.perform(put("/api/departments")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(DEPARTMENT_UPDATE_ADDRESS)))
                .andExpect(status().isOk())
                .andReturn();

        DepartmentDtoImpl actualResponse = objectMapper.
                readValue(mvcResult.
                        getResponse().
                        getContentAsString(), DepartmentDtoImpl.class);

        DepartmentDtoImpl expectedResponse = departmentService.
                findByDepartmentId(actualResponse.getId());

        assertThat(actualResponse)
                .isEqualTo(DEPARTMENT_UPDATE_ADDRESS);
        assertThat(actualResponse).isEqualTo(expectedResponse);
    }

    @ParameterizedTest()
    @ValueSource(ints = {1, 3, 2})
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenDeleteValid_thenReturn200AndSuccessString(int id) throws Exception {
        MvcResult mvcResult = mockMvc.perform(delete("/api/departments/{id}", id)
                .contentType("application/json"))
                .andExpect(status().isOk())
                .andReturn();

        assertThat(mvcResult.getResponse().getContentAsString()).isEqualTo("Department " + id + " was deleted!");
    }

    @ParameterizedTest()
    @ValueSource(ints = {1, 3, 2})
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenFindByIdDepartment_thenReturn200AndEmployee(int id) throws Exception {
        MvcResult mvcResult = mockMvc.perform(get("/api/departments/{id}", id)
                .contentType("application/json"))
                .andExpect(status().isOk())
                .andReturn();

        DepartmentDtoImpl actualResponse = objectMapper.readValue(mvcResult.getResponse().getContentAsString(), DepartmentDtoImpl.class);
        DepartmentDtoImpl expectedResponse = departmentService.findByDepartmentId(id);

        assertThat(actualResponse).isEqualTo(expectedResponse);
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenFindAllEmployee_thenReturn200AndEmployee() throws Exception {
        MvcResult mvcResult = mockMvc.perform(get("/api/departments")
                .contentType("application/json"))
                .andExpect(status().isOk())
                .andReturn();

        String content = mvcResult.getResponse().getContentAsString();
        TypeFactory typeFactory = objectMapper.getTypeFactory();
        List<DepartmentDto> actualResponse = objectMapper.readValue(content, typeFactory.constructCollectionType(List.class, DepartmentDtoImpl.class));
        List<DepartmentDto> expectedResponse = departmentService.findAll();

        assertThat(actualResponse).isEqualTo(expectedResponse);
    }

}
