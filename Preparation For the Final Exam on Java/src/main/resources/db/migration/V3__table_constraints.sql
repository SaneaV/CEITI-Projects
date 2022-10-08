alter table route add constraint FK_ROUTE_PASSENGER_CODE
    foreign key (passenger_code) references passenger