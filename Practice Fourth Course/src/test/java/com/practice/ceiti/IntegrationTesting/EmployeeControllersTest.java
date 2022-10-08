package com.practice.ceiti.IntegrationTesting;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.type.TypeFactory;
import com.practice.ceiti.dao.dto.EmployeeDto;
import com.practice.ceiti.dao.dto.EmployeeDtoImpl;
import com.practice.ceiti.services.EmployeeService;
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
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.delete;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.get;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.post;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.put;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.status;

@SpringBootTest
@AutoConfigureMockMvc
@PropertySource("classpath:application-test.properties")
@ExtendWith(SpringExtension.class)
public class EmployeeControllersTest {

    private static final EmployeeDtoImpl EMPLOYEE_NEW_VALID_1 = new EmployeeDtoImpl(null, "Igor", "Tonku", "Basarabeasca Naberejnaia 4", "069847552", 100, "Tester", "UNIFUN");
    private static final EmployeeDtoImpl EMPLOYEE_NEW_VALID_2 = new EmployeeDtoImpl(null, "Andrei", "Hadji", "Basarabeasca Chernisevskogo 6", "069741558", 100, "Tester", "UNIFUN");
    private static final EmployeeDtoImpl EMPLOYEE_UPDATE_NAME = new EmployeeDtoImpl(1, "Ivan", "Vicev", "Basarabeasca K.Marx 162", "069657662", 850, "C# Dev", "ENDAVA");
    private static final EmployeeDtoImpl EMPLOYEE_UPDATE_NAME_NOT_EXIST = new EmployeeDtoImpl(10, "Ivan", "Vicev", "Basarabeasca K.Marx 162", "069657662", 850, "Java Dev", "ENDAVA");
    private static final EmployeeDtoImpl EMPLOYEE_NEW_NOT_UNIQUE_PHONE_NUMBER = new EmployeeDtoImpl(10, "Ivan", "Tonku", "Comrat Lenin 5", "069657662", 850, "Java Dev", "ENDAVA");
    private static final EmployeeDtoImpl EMPLOYEE_BLANK_FIRST_NAME = new EmployeeDtoImpl(null, "", "Tonku", "Comrat Lenin 5", "069657662", 850, "Java Dev", "ENDAVA");
    private static final EmployeeDtoImpl EMPLOYEE_BLANK_LAST_NAME = new EmployeeDtoImpl(null, "Igor", "", "Comrat Lenin 5", "069657662", 850, "Java Dev", "ENDAVA");
    private static final EmployeeDtoImpl EMPLOYEE_BLANK_ADDRESS = new EmployeeDtoImpl(null, "Igor", "Tonku", "", "069657662", 850, "Java Dev", "ENDAVA");
    private static final EmployeeDtoImpl EMPLOYEE_PHONE_NUMBER_LESS_THAN_NINE_DIGITS = new EmployeeDtoImpl(null, "Igor", "Tonku", "Comrat Lenin 5", "0696662", 850, "Java Dev", "ENDAVA");
    private static final EmployeeDtoImpl EMPLOYEE_PHONE_NUMBER_DO_NOT_START_WITH_ZERO = new EmployeeDtoImpl(null, "Igor", "Tonku", "Comrat Lenin 5", "306058884", 850, "Java Dev", "ENDAVA");
    private static final EmployeeDtoImpl EMPLOYEE_SALARY_LESS_THAN_ONE = new EmployeeDtoImpl(null, "Igor", "Tonku", "Comrat Lenin 5", "069657662", 0, "Java Dev", "ENDAVA");
    private static final EmployeeDtoImpl EMPLOYEE_SALARY_GREATER_THAN_99999999 = new EmployeeDtoImpl(null, "Igor", "Tonku", "Comrat Lenin 5", "069657662", 999999999, "Java Dev", "ENDAVA");

    @Autowired
    private MockMvc mockMvc;

    @Autowired
    private ObjectMapper objectMapper;

    @Autowired
    private EmployeeService employeeService;

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenFindAllEmployees_thenResponseOk() throws Exception {
        mockMvc.perform(get("/api/employees")
                .contentType("application/json"))
                .andExpect(status().isOk())
                .andReturn();
    }

    @ParameterizedTest()
    @ValueSource(ints = {1, 3, 2})
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenFindByIdEmployee_thenResponseOk(int employeeId) throws Exception {
        mockMvc.perform(get("/api/employees/{id}", employeeId)
                .contentType("application/json"))
                .andExpect(status().isOk())
                .andReturn();
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenSaveEmployee_thenResponseCreated() throws Exception {
        mockMvc.perform(post("/api/employees")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(EMPLOYEE_NEW_VALID_1)))
                .andExpect(status().isOk())
                .andReturn();
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenUpdateEmployee_thenResponseOk() throws Exception {
        mockMvc.perform(put("/api/employees")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(EMPLOYEE_UPDATE_NAME)))
                .andExpect(status().isOk())
                .andReturn();
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenDeleteEmployee_thenResponseOk() throws Exception {
        int employeeId = 1;

        mockMvc.perform(delete("/api/employees/{id}", employeeId)
                .contentType("application/json"))
                .andExpect(status().isOk())
                .andReturn();
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenFindByIdEmployeeNotExist_thenReturn404AndErrorResponse() throws Exception {
        int employeeId = 10;

        MvcResult mvcResult = mockMvc.perform(get("/api/employees/{id}", employeeId)
                .contentType("application/json"))
                .andExpect(status().isNotFound())
                .andReturn();

        String actualResponseBody = mvcResult.getResponse().getContentAsString();
        assertThat(actualResponseBody).contains("Employee " + employeeId + " not found!");
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenUpdateEmployeeNotExist_thenReturn404AndErrorResponse() throws Exception {
        MvcResult mvcResult = mockMvc.perform(put("/api/employees")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(EMPLOYEE_UPDATE_NAME_NOT_EXIST)))
                .andExpect(status().isNotFound())
                .andReturn();

        String actualResponseBody = mvcResult.getResponse().getContentAsString();
        assertThat(actualResponseBody).contains("Employee " + EMPLOYEE_UPDATE_NAME_NOT_EXIST.getId() + " not found!");
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenDeleteEmployeeNotExist_thenReturn404AndErrorResponse() throws Exception {
        int employeeId = 10;

        MvcResult mvcResult = mockMvc.perform(delete("/api/employees/{id}", employeeId)
                .contentType("application/json"))
                .andExpect(status().isNotFound())
                .andReturn();

        String actualResponseBody = mvcResult.getResponse().getContentAsString();
        assertThat(actualResponseBody).contains("Employee " + employeeId + " not found!");
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenSaveEmployeeNotUniquePhoneNumber_thenReturn406AndErrorResponse() throws Exception {
        MvcResult mvcResult = mockMvc.perform(post("/api/employees")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(EMPLOYEE_NEW_NOT_UNIQUE_PHONE_NUMBER)))
                .andExpect(status().isNotAcceptable())
                .andReturn();

        String actualResponseBody = mvcResult.getResponse().getContentAsString();
        assertThat(actualResponseBody).contains("Constraint error:\n1. Use only unique fields\n2. Check existence of foreign keys");
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenSaveFirstNameIsBlank_thenReturn406AndErrorResponse() throws Exception {
        MvcResult mvcResult = mockMvc.perform(post("/api/employees")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(EMPLOYEE_BLANK_FIRST_NAME)))
                .andExpect(status().isNotAcceptable())
                .andReturn();

        String actualResponseBody = mvcResult.getResponse().getContentAsString();
        assertThat(actualResponseBody).contains("First name is mandatory");
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenSaveLastNameIsBlank_thenReturn406AndErrorResponse() throws Exception {
        MvcResult mvcResult = mockMvc.perform(post("/api/employees")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(EMPLOYEE_BLANK_LAST_NAME)))
                .andExpect(status().isNotAcceptable())
                .andReturn();

        String actualResponseBody = mvcResult.getResponse().getContentAsString();
        assertThat(actualResponseBody).contains("Last name is mandatory");
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenSaveAddressIsBlank_thenReturn406AndErrorResponse() throws Exception {
        MvcResult mvcResult = mockMvc.perform(post("/api/employees")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(EMPLOYEE_BLANK_ADDRESS)))
                .andExpect(status().isNotAcceptable())
                .andReturn();

        String actualResponseBody = mvcResult.getResponse().getContentAsString();
        assertThat(actualResponseBody).contains("Address is mandatory");
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenSavePhoneNumberLessThan9Digits_thenReturn406AndErrorResponse() throws Exception {
        MvcResult mvcResult = mockMvc.perform(post("/api/employees")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(EMPLOYEE_PHONE_NUMBER_LESS_THAN_NINE_DIGITS)))
                .andExpect(status().isNotAcceptable())
                .andReturn();

        String actualResponseBody = mvcResult.getResponse().getContentAsString();
        assertThat(actualResponseBody).contains("Phone number should start with zero and contain exactly 9 digits");
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenSavePhoneNumberDoNotStartWithZero_thenReturn406AndErrorResponse() throws Exception {
        MvcResult mvcResult = mockMvc.perform(post("/api/employees")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(EMPLOYEE_PHONE_NUMBER_DO_NOT_START_WITH_ZERO)))
                .andExpect(status().isNotAcceptable())
                .andReturn();

        String actualResponseBody = mvcResult.getResponse().getContentAsString();
        assertThat(actualResponseBody).contains("Phone number should start with zero and contain exactly 9 digits");
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenSaveSalaryLessThanOne_thenReturn406AndErrorResponse() throws Exception {
        MvcResult mvcResult = mockMvc.perform(post("/api/employees")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(EMPLOYEE_SALARY_LESS_THAN_ONE)))
                .andExpect(status().isNotAcceptable())
                .andReturn();

        String actualResponseBody = mvcResult.getResponse().getContentAsString();
        assertThat(actualResponseBody).contains("Salary must be greater than or equal to 1");
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenSaveSalaryGreaterThan99999999_thenReturn406AndErrorResponse() throws Exception {
        MvcResult mvcResult = mockMvc.perform(post("/api/employees")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(EMPLOYEE_SALARY_GREATER_THAN_99999999)))
                .andExpect(status().isNotAcceptable())
                .andReturn();

        String actualResponseBody = mvcResult.getResponse().getContentAsString();
        assertThat(actualResponseBody).contains("Salary must be less than or equal to 99999999");
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenSaveValid_thenReturn200AndPostedEntity() throws Exception {
        MvcResult mvcResult = mockMvc.perform(post("/api/employees")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(EMPLOYEE_NEW_VALID_2)))
                .andExpect(status().isOk())
                .andReturn();

        EmployeeDtoImpl actualResponse = objectMapper.
                readValue(mvcResult.
                        getResponse().
                        getContentAsString(), EmployeeDtoImpl.class);

        EmployeeDtoImpl expectedResponse = employeeService.
                findByEmployeeId(actualResponse.getId());

        assertThat(actualResponse)
                .usingRecursiveComparison()
                .ignoringFields("id")
                .isEqualTo(EMPLOYEE_NEW_VALID_2);

        assertThat(actualResponse).isEqualTo(expectedResponse);
    }


    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenUpdateValid_thenReturn200AndPutEntity() throws Exception {
        MvcResult mvcResult = mockMvc.perform(put("/api/employees")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(EMPLOYEE_UPDATE_NAME)))
                .andExpect(status().isOk())
                .andReturn();

        EmployeeDtoImpl actualResponse = objectMapper.
                readValue(mvcResult.
                        getResponse().
                        getContentAsString(), EmployeeDtoImpl.class);

        EmployeeDtoImpl expectedResponse = employeeService.
                findByEmployeeId(actualResponse.getId());

        assertThat(actualResponse)
                .isEqualTo(EMPLOYEE_UPDATE_NAME);
        assertThat(actualResponse).isEqualTo(expectedResponse);
    }

    @ParameterizedTest()
    @ValueSource(ints = {1, 3, 2})
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenDeleteValid_thenReturn200AndSuccessString(int id) throws Exception {
        MvcResult mvcResult = mockMvc.perform(delete("/api/employees/{id}", id)
                .contentType("application/json"))
                .andExpect(status().isOk())
                .andReturn();

        assertThat(mvcResult.getResponse().getContentAsString()).isEqualTo("Employee " + id + " was deleted!");
    }


    @ParameterizedTest()
    @ValueSource(ints = {1, 3, 2})
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenFindByIdEmployees_thenReturn200AndEmployee(int id) throws Exception {
        MvcResult mvcResult = mockMvc.perform(get("/api/employees/{id}", id)
                .contentType("application/json"))
                .andExpect(status().isOk())
                .andReturn();

        EmployeeDtoImpl actualResponse = objectMapper.readValue(mvcResult.getResponse().getContentAsString(), EmployeeDtoImpl.class);
        EmployeeDtoImpl expectedResponse = employeeService.findByEmployeeId(id);

        assertThat(actualResponse).isEqualTo(expectedResponse);
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenFindAllEmployee_thenReturn200AndEmployee() throws Exception {
        MvcResult mvcResult = mockMvc.perform(get("/api/employees")
                .contentType("application/json"))
                .andExpect(status().isOk())
                .andReturn();

        String content = mvcResult.getResponse().getContentAsString();
        TypeFactory typeFactory = objectMapper.getTypeFactory();
        List<EmployeeDto> actualResponse = objectMapper.readValue(content, typeFactory.constructCollectionType(List.class, EmployeeDtoImpl.class));
        List<EmployeeDto> expectedResponse = employeeService.findAll();

        assertThat(actualResponse).isEqualTo(expectedResponse);
    }
}
