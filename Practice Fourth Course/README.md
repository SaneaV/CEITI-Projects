# CRM-Practice-In-The-Fourth-Year-Of-College
This project is my practical assignment, which I completed in my fourth year of college.
<br><br>
Customer Relationship Management (CRM)

Purpose: Creation of a CRM service.
CRM service should provide CRUD functionality over the Employees database table. This service should be able to show a list of workers (JSON), add a new worker (JSON), delete a worker (JSON), and change a worker (JSON). The application must be written in Java using the following technologies:
1. Spring Boot (Tomcat, Spring Core, etc.)
2. Spring Rest
3. MySQL
4. Maven
<br>
Database tables:
<br>

|     Customers        |   |     Job         |   |     Department         |
|----------------------|---|-----------------|---|------------------------|
|     ID               |   |     Id          |   |     Id                 |
|     First_Name       |   |     Job_Name    |   |     Department_Name    |
|     Last_Name        |   |     Address     |   |     Address            |
|     Address          |   |                 |   |                        |
|     Phone_Number     |   |                 |   |                        |
|     Salary           |   |                 |   |                        |
|     Job_Id           |   |                 |   |                        |
|     Department_Id    |   |                 |   |                        |

<br>

The application must have the following architecture: Presentation Layer, Business Layer, Persistence Layer, Database Layer.

Base url: localhost:8080/api/


| GET    | /customers      | list of all employees                  |
|--------|-----------------|----------------------------------------|
| GET    | /customers/{id} | information about the employee with id |
| POST   | /customers      | create a new employee                  |
| PUT    | /customers/{id} | update employee                        |
| DELETE | /customers/{id} | delete an employee                     |

The application should have standard validations: @NotNull, @Size, etc.
<br>

General remarks<br>
It is worth adding to the general remarks that the TK was fully implemented, and additional functions were also implemented:<br>

1. Working with the database is carried out in three different ways:<br>
a. Spring Data JPA<br>
b. Hibernate<br>
c. JDBC<br>
2. The application can be launched with different profiles, in the following combination:<br>
a. develop + DataJPA<br>
b. develop + Hibernate<br>
c. develop + JDBC<br>
d. test + DataJPA<br>
e. test + Hibernate<br>
f. test + JDBC<br>
test - to run tests<br>
develop - to run the application for main use<br>
3. The application has the ability to close and open access using a password and login, as well as roles (Spring Security).
