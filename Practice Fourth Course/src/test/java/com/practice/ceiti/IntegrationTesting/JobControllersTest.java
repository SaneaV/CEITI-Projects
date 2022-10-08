package com.practice.ceiti.IntegrationTesting;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.type.TypeFactory;
import com.practice.ceiti.dao.dto.JobDto;
import com.practice.ceiti.dao.dto.JobDtoImpl;
import com.practice.ceiti.services.JobService;
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
public class JobControllersTest {

    public static final JobDtoImpl JOB_NEW_VALID_1 = new JobDtoImpl(null, "Android Dev", 650, 3000);
    public static final JobDtoImpl JOB_NEW_VALID_2 = new JobDtoImpl(null, "GO Dev", 650, 3000);
    public static final JobDtoImpl JOB_UPDATE_JOB_NAME = new JobDtoImpl(1, "Kotlin Dev", 650, 3000);
    public static final JobDtoImpl JOB_NEW_JOB_NAME_NOT_UNIQUE = new JobDtoImpl(null, "C# Dev", 650, 3000);
    public static final JobDtoImpl JOB_NEW_MIN_SALARY_LESS_THAN_1 = new JobDtoImpl(null, "Java AM", 0, 3000);
    public static final JobDtoImpl JOB_NEW_MIN_SALARY_GREATER_THAN_99999999 = new JobDtoImpl(null, "Java AM", 999999999, 3000);
    public static final JobDtoImpl JOB_NEW_MAX_SALARY_LESS_THAN_2 = new JobDtoImpl(null, "Java Dev", 650, 1);
    public static final JobDtoImpl JOB_NEW_MAX_SALARY_GREATER_THAN_999999999 = new JobDtoImpl(null, "Java Dev", 650, Integer.MAX_VALUE);
    public static final JobDtoImpl JOB_NEW_JOB_ID_DOES_NOT_EXIST = new JobDtoImpl(10, "Java AM", 650, 3000);

    @Autowired
    private MockMvc mockMvc;

    @Autowired
    private ObjectMapper objectMapper;

    @Autowired
    private JobService jobService;

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenFindAllJobs_thenResponseOk() throws Exception {
        mockMvc.perform(get("/api/jobs")
                .contentType("application/json"))
                .andExpect(status().isOk())
                .andReturn();
    }

    @ParameterizedTest()
    @ValueSource(ints = {1, 3, 2})
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenFindByIdJob_thenResponseOk(int jobId) throws Exception {
        mockMvc.perform(get("/api/jobs/{id}", jobId)
                .contentType("application/json"))
                .andExpect(status().isOk())
                .andReturn();
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenSaveJob_thenResponseCreated() throws Exception {
        mockMvc.perform(post("/api/jobs")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(JOB_NEW_VALID_1)))
                .andExpect(status().isOk())
                .andReturn();
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenUpdateJob_thenResponseOk() throws Exception {
        mockMvc.perform(put("/api/jobs")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(JOB_UPDATE_JOB_NAME)))
                .andExpect(status().isOk())
                .andReturn();
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenDeleteJob_thenResponseOk() throws Exception {
        int jobId = 1;

        mockMvc.perform(delete("/api/jobs/{id}", jobId)
                .contentType("application/json"))
                .andExpect(status().isOk())
                .andReturn();
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenFindByIdJobNotExist_thenReturn404AndErrorResponse() throws Exception {
        int jobId = 10;

        MvcResult mvcResult = mockMvc.perform(get("/api/jobs/{id}", jobId)
                .contentType("application/json"))
                .andExpect(status().isNotFound())
                .andReturn();

        String actualResponseBody = mvcResult.getResponse().getContentAsString();
        assertThat(actualResponseBody).contains("Job " + jobId + " not found!");
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenUpdateJobNotExist_thenReturn404AndErrorResponse() throws Exception {
        MvcResult mvcResult = mockMvc.perform(put("/api/jobs")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(JOB_NEW_JOB_ID_DOES_NOT_EXIST)))
                .andExpect(status().isNotFound())
                .andReturn();

        String actualResponseBody = mvcResult.getResponse().getContentAsString();
        assertThat(actualResponseBody).contains("Job " + JOB_NEW_JOB_ID_DOES_NOT_EXIST.getId() + " not found!");
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenDeleteJobNotExist_thenReturn404AndErrorResponse() throws Exception {
        int jobId = 10;

        MvcResult mvcResult = mockMvc.perform(delete("/api/jobs/{id}", jobId)
                .contentType("application/json"))
                .andExpect(status().isNotFound())
                .andReturn();

        String actualResponseBody = mvcResult.getResponse().getContentAsString();
        assertThat(actualResponseBody).contains("Job " + jobId + " not found!");
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenSaveNotUniqueJobName_thenReturn406AndErrorResponse() throws Exception {
        MvcResult mvcResult = mockMvc.perform(post("/api/jobs")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(JOB_NEW_JOB_NAME_NOT_UNIQUE)))
                .andExpect(status().isNotAcceptable())
                .andReturn();

        String actualResponseBody = mvcResult.getResponse().getContentAsString();
        assertThat(actualResponseBody).contains("Constraint error:\n1. Use only unique fields\n2. Check existence of foreign keys");
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenSaveMinSalaryLessThanOne_thenReturn406AndErrorResponse() throws Exception {
        MvcResult mvcResult = mockMvc.perform(post("/api/jobs")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(JOB_NEW_MIN_SALARY_LESS_THAN_1)))
                .andExpect(status().isNotAcceptable())
                .andReturn();

        String actualResponseBody = mvcResult.getResponse().getContentAsString();
        assertThat(actualResponseBody).contains("Salary must be greater than or equal to 1");
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenSaveMinSalaryGreaterThan99999999_thenReturn406AndErrorResponse() throws Exception {
        MvcResult mvcResult = mockMvc.perform(post("/api/jobs")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(JOB_NEW_MIN_SALARY_GREATER_THAN_99999999)))
                .andExpect(status().isNotAcceptable())
                .andReturn();

        String actualResponseBody = mvcResult.getResponse().getContentAsString();
        assertThat(actualResponseBody).contains("Salary must be less than or equal to 99999999");
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenSaveMaxSalaryLessThanOne_thenReturn406AndErrorResponse() throws Exception {
        MvcResult mvcResult = mockMvc.perform(post("/api/jobs")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(JOB_NEW_MAX_SALARY_LESS_THAN_2)))
                .andExpect(status().isNotAcceptable())
                .andReturn();

        String actualResponseBody = mvcResult.getResponse().getContentAsString();
        assertThat(actualResponseBody).contains("Salary must be greater than or equal to 2");
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenSaveMaxSalaryGreaterThan99999999_thenReturn406AndErrorResponse() throws Exception {
        MvcResult mvcResult = mockMvc.perform(post("/api/jobs")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(JOB_NEW_MAX_SALARY_GREATER_THAN_999999999)))
                .andExpect(status().isNotAcceptable())
                .andReturn();

        String actualResponseBody = mvcResult.getResponse().getContentAsString();
        assertThat(actualResponseBody).contains("Salary must be less than or equal to 99999999");
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenSaveValid_thenReturn200AndPostedEntity() throws Exception {
        MvcResult mvcResult = mockMvc.perform(post("/api/jobs")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(JOB_NEW_VALID_2)))
                .andExpect(status().isOk())
                .andReturn();

        JobDtoImpl actualResponse = objectMapper.
                readValue(mvcResult.
                        getResponse().
                        getContentAsString(), JobDtoImpl.class);

        JobDtoImpl expectedResponse = jobService.
                findByJobId(actualResponse.getId());

        assertThat(actualResponse)
                .usingRecursiveComparison()
                .ignoringFields("id")
                .isEqualTo(JOB_NEW_VALID_2);

        assertThat(actualResponse).isEqualTo(expectedResponse);
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenUpdateValid_thenReturn200AndPutEntity() throws Exception {
        MvcResult mvcResult = mockMvc.perform(put("/api/jobs")
                .contentType("application/json")
                .content(objectMapper.writeValueAsString(JOB_UPDATE_JOB_NAME)))
                .andExpect(status().isOk())
                .andReturn();

        JobDtoImpl actualResponse = objectMapper.
                readValue(mvcResult.
                        getResponse().
                        getContentAsString(), JobDtoImpl.class);

        JobDtoImpl expectedResponse = jobService.
                findByJobId(actualResponse.getId());

        assertThat(actualResponse)
                .isEqualTo(JOB_UPDATE_JOB_NAME);
        assertThat(actualResponse).isEqualTo(expectedResponse);
    }

    @ParameterizedTest()
    @ValueSource(ints = {1, 3, 2})
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenDeleteValid_thenReturn200AndSuccessString(int id) throws Exception {
        MvcResult mvcResult = mockMvc.perform(delete("/api/jobs/{id}", id)
                .contentType("application/json"))
                .andExpect(status().isOk())
                .andReturn();

        assertThat(mvcResult.getResponse().getContentAsString()).isEqualTo("Job " + id + " was deleted!");
    }

    @ParameterizedTest()
    @ValueSource(ints = {1, 3, 2})
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenFindByIdEmployee_thenReturn200AndEmployee(int id) throws Exception {
        MvcResult mvcResult = mockMvc.perform(get("/api/jobs/{id}", id)
                .contentType("application/json"))
                .andExpect(status().isOk())
                .andReturn();

        JobDtoImpl actualResponse = objectMapper.readValue(mvcResult.getResponse().getContentAsString(), JobDtoImpl.class);
        JobDtoImpl expectedResponse = jobService.findByJobId(id);

        assertThat(actualResponse).isEqualTo(expectedResponse);
    }

    @Test
    @Transactional
    @WithMockUser(roles = {"ADMIN"})
    void whenFindAllEmployee_thenReturn200AndEmployee() throws Exception {
        MvcResult mvcResult = mockMvc.perform(get("/api/jobs")
                .contentType("application/json"))
                .andExpect(status().isOk())
                .andReturn();

        String content = mvcResult.getResponse().getContentAsString();
        TypeFactory typeFactory = objectMapper.getTypeFactory();
        List<JobDto> actualResponse = objectMapper.readValue(content, typeFactory.constructCollectionType(List.class, JobDtoImpl.class));
        List<JobDto> expectedResponse = jobService.findAll();

        assertThat(actualResponse).isEqualTo(expectedResponse);
    }

}
