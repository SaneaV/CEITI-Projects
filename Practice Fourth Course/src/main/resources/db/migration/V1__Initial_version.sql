create table departments
(
    id              integer auto_increment,
    address         varchar(255),
    department_name varchar(255),
    primary key (id)
);

create table employees
(
    id            integer auto_increment,
    address       varchar(255),
    first_name    varchar(255),
    last_name     varchar(255),
    phone_number  varchar(255),
    salary        integer check (salary <= 99999999 AND salary >= 1),
    department_id integer,
    job_id        integer,
    primary key (id)
);

create table jobs
(
    id         integer auto_increment,
    job_name   varchar(255),
    max_salary integer check (max_salary <= 999999999 AND max_salary >= 2),
    min_salary integer check (min_salary <= 99999999 AND min_salary >= 1),
    primary key (id)
);

alter table departments
    drop constraint if exists UK_departments_address;
alter table departments
    add constraint UK_departments_address unique (address);

alter table departments
    drop constraint if exists UK_departments_dp_name;
alter table departments
    add constraint UK_departments_dp_name unique (department_name);

alter table employees
    drop constraint if exists UK_employees_phone_number;
alter table employees
    add constraint UK_employees_phone_number unique (phone_number);

alter table jobs
    drop constraint if exists UK_jobs_jb_name;
alter table jobs
    add constraint UK_jobs_jb_name unique (job_name);

ALTER TABLE employees
    ADD FOREIGN KEY (job_id) REFERENCES jobs(id);

ALTER TABLE employees
    ADD FOREIGN KEY (department_id) REFERENCES departments(id);
