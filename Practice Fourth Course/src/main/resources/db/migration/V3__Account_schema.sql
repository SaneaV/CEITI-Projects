create table accounts
(
    id              integer auto_increment,
    username        varchar(255),
    password        varchar(255),
    role            varchar(255),
    primary key (id)
);