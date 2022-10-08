INSERT INTO departments (department_name, address)
VALUES ('ENDAVA', 'Strada Arborilor 21a, Chisinau 2025'),
       ('CEDACRI', 'Centrul de Finante si Business, 171/, Stefan cel Mare si Sfant Boulevard 1, Chisinau'),
       ('UNIFUN', 'Bulevardul Decebal 6, Chisinau');


INSERT INTO jobs (job_name, min_salary, max_salary)
VALUES ('Java Dev', 700, 3000),
       ('C# Dev', 700, 3000),
       ('Tester', 650, 2500);


INSERT INTO employees (first_name, last_name, address, phone_number, salary, job_id, department_id)
VALUES ('Alexandr', 'Vicev', 'Basarabeasca K.Marx 162', '069657662', 850, '1', '1'),
       ('Artur', 'Iancioglo', 'Chisinau Decebal 7', '069654775', 850, '1', '1'),
       ('Timur', 'Vacarenco', 'Chisinau Druta 9', '069742115', 650, '3', '1')

