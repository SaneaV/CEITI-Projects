Create database AutoRent
go
Use AutoRent 
go

create table Cars(
 MachineNumberInTheDatabase int primary key,
 GovernmentNumber varchar(10),
 Mark varchar(35),
 BodyType varchar(20),
 NumberOfSeats int,
 Equipment varchar(255),
 FuelType varchar(20),
 Condition varchar(30),
 YearOfIssue int,
 CurrentStatus char(1))
go


create table Clients(
 ClientNumberIntheDatabase int primary key,
 FullName varchar(60),
 PassportDetails int,
 PhoneNumber int,
 HomeAddress varchar(100),
 DrivingExperince int,
 TheNumberOfOrders int)
go

create table Contracts(
 ContratNumber int,
 ClientNumberIntheDatabase int foreign key references Clients(ClientNumberIntheDatabase),
 MachineNumberInTheDatabase int foreign key references Cars(MachineNumberInTheDatabase),
 DateOfTheContract date default '00-00-0000',
 EndDateOfTheContract date default '00-00-0000',
 PriceRentPerDay int,
 RentalDuration int)
go


select * from Cars
go
select * from Clients
go
select * from Contracts 
go

Drop Table Contracts
go


Insert into Cars (MachineNumberInTheDatabase, GovernmentNumber, Mark, BodyType, NumberOfSeats, Equipment, FuelType, Condition, YearOfIssue, CurrentStatus)
values ('1', 'C1000', 'Audi', 'Седан', '4', 'Кондиционер, подогрев сидений','Бензин','Новая','2018','З')
Insert into Cars (MachineNumberInTheDatabase, GovernmentNumber, Mark, BodyType, NumberOfSeats, Equipment,FuelType, Condition, YearOfIssue, CurrentStatus)
values ('2', 'С1010', 'Honda', 'Хэтчбэк', '4', 'GPS', 'Газ', 'В хорошем состоянии', '2016', 'С')
Insert into Cars (MachineNumberInTheDatabase, GovernmentNumber, Mark, BodyType, NumberOfSeats, Equipment,FuelType, Condition, YearOfIssue, CurrentStatus)
values ('3', 'С1020', 'Toyota',	'Универсал', '5', 'Подогрев сидений, GPS, Кондиционер',	'Бензин', 'Утопленик', '2005', 'З')
Insert into Cars (MachineNumberInTheDatabase, GovernmentNumber, Mark, BodyType, NumberOfSeats, Equipment,FuelType, Condition, YearOfIssue, CurrentStatus)
values ('4', 'С1030', 'Reno', 'Лифтбэк', '4', 'Телевизор', 'Электричество', 'После ремонта', '2010', 'З')
Insert into Cars (MachineNumberInTheDatabase, GovernmentNumber, Mark, BodyType, NumberOfSeats, Equipment,FuelType, Condition, YearOfIssue, CurrentStatus)
values ('5', 'С1040', 'BMW', 'Купе', '2', 'Мини-Холодильник', 'Бензин', 'Новая', '2017', 'С')
Insert into Cars (MachineNumberInTheDatabase, GovernmentNumber, Mark, BodyType, NumberOfSeats, Equipment,FuelType, Condition, YearOfIssue, CurrentStatus)
values ('6', 'С1050', 'Mazda', 'Кабриолет', '4', 'Большая аудиосистема', 'Бензин', 'В хорошем состоянии', '2008', 'З')
Insert into Cars (MachineNumberInTheDatabase, GovernmentNumber, Mark, BodyType, NumberOfSeats, Equipment,FuelType, Condition, YearOfIssue, CurrentStatus)
values ('7', 'С1060', 'Lamborghini', 'Родстер', '2', 'Подогрев сидений, кондиционер, GPS', 'Бензин', 'После ДТП', '2007', 'С')
Insert into Cars (MachineNumberInTheDatabase, GovernmentNumber, Mark, BodyType, NumberOfSeats, Equipment,FuelType, Condition, YearOfIssue, CurrentStatus)
values ('8', 'С1070', 'Porshe', 'Тарга', '2', 'Телевизор, мини-холодильник', 'Электричество', 'Новая', '2016', 'С')
Insert into Cars (MachineNumberInTheDatabase, GovernmentNumber, Mark, BodyType, NumberOfSeats, Equipment,FuelType, Condition, YearOfIssue, CurrentStatus)
values ('9', 'С1080', 'Chrysler', 'Лимузин', '8', 'Телевизор, кондиционер, бар', 'Бензин', 'Требуется ремонт', '2000', 'С')
Insert into Cars (MachineNumberInTheDatabase, GovernmentNumber, Mark, BodyType, NumberOfSeats, Equipment,FuelType, Condition, YearOfIssue, CurrentStatus)
values ('10', 'С1090', 'Mercedes', 'Стретч', '10', 'Телевизор, бар, GPS, аудиосистема', 'Бензин', 'Новая', '2016', 'З')
Insert into Cars (MachineNumberInTheDatabase, GovernmentNumber, Mark, BodyType, NumberOfSeats, Equipment,FuelType, Condition, YearOfIssue, CurrentStatus)
values ('11', 'С1100', 'Toyota', 'Внедорожник', '6', 'GPS, подогрев сидений', 'Газ', 'Новая', '2018', 'С')
Insert into Cars (MachineNumberInTheDatabase, GovernmentNumber, Mark, BodyType, NumberOfSeats, Equipment,FuelType, Condition, YearOfIssue, CurrentStatus)
values ('12', 'С1110', 'Nissan', 'Кроссовер', '4', 'Подогрев сидений', 'Газ', 'Утопленик', '2010', 'З')
Insert into Cars (MachineNumberInTheDatabase, GovernmentNumber, Mark, BodyType, NumberOfSeats, Equipment,FuelType, Condition, YearOfIssue, CurrentStatus)
values ('13', 'С1120', 'Jeep', 'Пикап', '4', 'GPS', 'Бензин', 'После ремонта', '2005', 'С')
Insert into Cars (MachineNumberInTheDatabase, GovernmentNumber, Mark, BodyType, NumberOfSeats, Equipment,FuelType, Condition, YearOfIssue, CurrentStatus)
values ('14', 'С1130', 'Peugeot', 'Фургон', '2', 'Аудиосистема', 'Бензин', 'В хорошем состоянии', '2000', 'С')
Insert into Cars (MachineNumberInTheDatabase, GovernmentNumber, Mark, BodyType, NumberOfSeats, Equipment,FuelType, Condition, YearOfIssue, CurrentStatus)
values ('15', 'С1140', 'Nissan', 'Минивэн', '6', 'Подогрев сидений, бар', 'Бензин', 'Новая', '2016', 'З')
Insert into Cars (MachineNumberInTheDatabase, GovernmentNumber, Mark, BodyType, NumberOfSeats, Equipment,FuelType, Condition, YearOfIssue, CurrentStatus)
values ('16', 'С1150', 'Volkswagen', 'Микроавтобус', '20', 'Аудиосистема, бар', 'Бензин', 'Требуется ремонт', '2000', 'С')
Insert into Cars (MachineNumberInTheDatabase, GovernmentNumber, Mark, BodyType, NumberOfSeats, Equipment,FuelType, Condition, YearOfIssue, CurrentStatus)
values ('17', 'С1160', 'Reno', 'Автобус', '30', 'Подогрев сидений, туалет', 'Бензин', 'Новый', '2018', 'З')


Insert into Clients (ClientNumberIntheDatabase, FullName, PassportDetails, PhoneNumber, HomeAddress, DrivingExperince, TheNumberOfOrders)
values ('1', 'Тевосова Александра Серафимовна', '255471', '69657884', 'Студенческая 11', '11', '3')
Insert into Clients (ClientNumberIntheDatabase, FullName, PassportDetails, PhoneNumber, HomeAddress, DrivingExperince, TheNumberOfOrders)
values ('2', 'Сидрова Эмилия Феликсовна', '244712', '68745912', 'Мунчешты 44', '5', '1') 
Insert into Clients (ClientNumberIntheDatabase, FullName, PassportDetails, PhoneNumber, HomeAddress, DrivingExperince, TheNumberOfOrders)
values ('3', 'Григорьева Виктория Никитевна', '248715', '68421697', 'Дечебал 7', '1', '0')
Insert into Clients (ClientNumberIntheDatabase, FullName, PassportDetails, PhoneNumber, HomeAddress, DrivingExperince, TheNumberOfOrders)
values ('4', 'Янзинов Лев Сократович', '244781', '68412489', 'Сармизеджетуса 154', '25', '5')
Insert into Clients (ClientNumberIntheDatabase, FullName, PassportDetails, PhoneNumber, HomeAddress, DrivingExperince, TheNumberOfOrders)
values ('5', 'Заврагин Дементий Юриевич', '244169', '6871264', 'Георге Асаки 188', '5', '1')
Insert into Clients (ClientNumberIntheDatabase, FullName, PassportDetails, PhoneNumber, HomeAddress, DrivingExperince, TheNumberOfOrders)
values ('6', 'Ябурова Бронислава Иосифовна', '288716', '6814732', 'Пушкина 7', '1', '3') 
Insert into Clients (ClientNumberIntheDatabase, FullName, PassportDetails, PhoneNumber, HomeAddress, DrivingExperince, TheNumberOfOrders)
values ('7', 'Бегичев Аристарх Контратиевич', '217945', '69784521', 'Флорилор 111', '2', '10')
Insert into Clients (ClientNumberIntheDatabase, FullName, PassportDetails, PhoneNumber, HomeAddress, DrivingExperince, TheNumberOfOrders)
values ('8', 'Петрова Рената Родионовна', '244487', '67541826', 'Босфортная 78', '5', '5') 
Insert into Clients (ClientNumberIntheDatabase, FullName, PassportDetails, PhoneNumber, HomeAddress, DrivingExperince, TheNumberOfOrders)
values ('9', 'Малыхин Архип Валерьевич', '248769', '61784264', 'Куза-Водэ 6', '6', '2') 
Insert into Clients (ClientNumberIntheDatabase, FullName, PassportDetails, PhoneNumber, HomeAddress, DrivingExperince, TheNumberOfOrders)
values ('10', 'Дмитриева Василиса Евгениевна', '298412', '62484512', 'Троян 8', '15', '32') 


Insert into Contracts (ContratNumber, ClientNumberIntheDatabase, MachineNumberInTheDatabase, DateOfTheContract, EndDateOfTheContract, PriceRentPerDay, RentalDuration)
values (1, 2, 6, '11-05-2018', '13-05-2018', 1500, 3)
Insert into Contracts (ContratNumber, ClientNumberIntheDatabase, MachineNumberInTheDatabase, DateOfTheContract, EndDateOfTheContract, PriceRentPerDay, RentalDuration)
values (2, 4, 1, '12-05-2018', '20-05-2018', 1000, 9)
Insert into Contracts (ContratNumber, ClientNumberIntheDatabase, MachineNumberInTheDatabase, DateOfTheContract, EndDateOfTheContract, PriceRentPerDay, RentalDuration)
values (3, 5, 4, '12-05-2018', '21-05-2018', 1700, 10)
Insert into Contracts (ContratNumber, ClientNumberIntheDatabase, MachineNumberInTheDatabase, DateOfTheContract, EndDateOfTheContract, PriceRentPerDay, RentalDuration)
values (4, 10, 10, '12-05-2018', '12-05-2018', 100000, 1)
Insert into Contracts (ContratNumber, ClientNumberIntheDatabase, MachineNumberInTheDatabase, DateOfTheContract, EndDateOfTheContract, PriceRentPerDay, RentalDuration)
values (5, 7, 12, '14-05-2018', '15-05-2018', 10000, 2)
Insert into Contracts (ContratNumber, ClientNumberIntheDatabase, MachineNumberInTheDatabase, DateOfTheContract, EndDateOfTheContract, PriceRentPerDay, RentalDuration)
values (6, 1, 15, '14-05-2018', '14-06-2018', 4000, 30)
Insert into Contracts (ContratNumber, ClientNumberIntheDatabase, MachineNumberInTheDatabase, DateOfTheContract, EndDateOfTheContract, PriceRentPerDay, RentalDuration)
values (7, 8, 17, '17-05-2018', '18-05-2018', 50000, 2)
Insert into Contracts (ContratNumber, ClientNumberIntheDatabase, MachineNumberInTheDatabase, DateOfTheContract, EndDateOfTheContract, PriceRentPerDay, RentalDuration)
values (8, 8, 17, '18-05-2018', '19-05-2018', 50000, 2)
Insert into Contracts (ContratNumber, ClientNumberIntheDatabase, MachineNumberInTheDatabase, DateOfTheContract, EndDateOfTheContract, PriceRentPerDay, RentalDuration)
values (9, 8, 1, '20-05-2018', '22-05-2018', 1000, 3)
Insert into Contracts (ContratNumber, ClientNumberIntheDatabase, MachineNumberInTheDatabase, DateOfTheContract, EndDateOfTheContract, PriceRentPerDay, RentalDuration)
values (10, 5, 1, '22-05-2018', '23-05-2018', 1000, 1)



//Зная имя клиента вывести всю информацию о его контрактах
Select Contracts.ContratNumber, Contracts.ClientNumberIntheDatabase, Contracts.MachineNumberInTheDatabase, DateOfTheContract, EndDateOfTheContract, PriceRentPerDay, RentalDuration
From Clients, Contracts
Where (Clients.FullName='Дмитриева Василиса Евгениевна') and (Clients.ClientNumberIntheDatabase=Contracts.ClientNumberIntheDatabase)
go

Select Contracts.ContratNumber, Contracts.ClientNumberIntheDatabase, Contracts.MachineNumberInTheDatabase, DateOfTheContract, EndDateOfTheContract, PriceRentPerDay, RentalDuration
from Contracts
Inner join Clients on Clients.ClientNumberIntheDatabase = Contracts.ClientNumberIntheDatabase
Where (Clients.FullName='Дмитриева Василиса Евгениевна') and (Clients.ClientNumberIntheDatabase=Contracts.ClientNumberIntheDatabase)



//Зная имя клиента вывести количество дней, которые он использовал машины в прокат
Select FullName, Sum(RentalDuration) as ' ', 'дней' as Explotation
From Clients, Contracts
Where (Clients.FullName='Петрова Рената Родионовна') and (Clients.ClientNumberIntheDatabase=Contracts.ClientNumberIntheDatabase) 
GROUP BY FullName
go

Select FullName, Sum(RentalDuration) as ' ', 'дней' as Explotation
From Contracts
Inner join Clients on Clients.ClientNumberIntheDatabase = Contracts.ClientNumberIntheDatabase
Where (Clients.FullName='Петрова Рената Родионовна') and (Clients.ClientNumberIntheDatabase=Contracts.ClientNumberIntheDatabase)
GROUP BY FullName



//Вывести имена людей и количество дней, которые они использовали машины в прокат
Select FullName, Sum(RentalDuration) as ' ', 'дней' as Explotation
From Clients, Contracts
Where (Clients.ClientNumberIntheDatabase=Contracts.ClientNumberIntheDatabase) 
GROUP BY FullName
go

Select FullName, Sum(RentalDuration) as ' ', 'дней' as Explotation
From Contracts
Inner join Clients on Clients.ClientNumberIntheDatabase = Contracts.ClientNumberIntheDatabase
Where (Clients.ClientNumberIntheDatabase=Contracts.ClientNumberIntheDatabase)
GROUP BY FullName
go



//Вывести общую сумму заработанную на прокате автомобилей
Select Sum(PriceRentPerDay*RentalDuration) as 'Общий доход'
From Contracts
go


//Вывести сумму, которую клиент потратил на прокат автомобилей за всё время
Select FullName, Sum(PriceRentPerDay*RentalDuration) as 'Клиент заплатил за всё время'
From Contracts, Clients
Where (Clients.FullName='Петрова Рената Родионовна') and (Clients.ClientNumberIntheDatabase=Contracts.ClientNumberIntheDatabase)
GROUP BY FullName
go



//Вывести данные о человеке по номеру контракта
Select Clients.ClientNumberIntheDatabase, FullName, PassportDetails, PhoneNumber, HomeAddress, DrivingExperince, TheNumberOfOrders
From Contracts, Clients
Where (ContratNumber=2) and (Clients.ClientNumberIntheDatabase=Contracts.ClientNumberIntheDatabase)
go


//Вывести машины с определёнными дополнительными условиями, которые на данный момент свободны 
Select MachineNumberInTheDatabase, GovernmentNumber, Mark, BodyType, NumberOfSeats, Equipment,FuelType, Condition, YearOfIssue, CurrentStatus
From Cars
Where Equipment LIKE ('%кондиционер%') and CurrentStatus='С'
go


//Вывести все свободные/занятые машины
Select MachineNumberInTheDatabase, GovernmentNumber, Mark, BodyType, NumberOfSeats, Equipment,FuelType, Condition, YearOfIssue, CurrentStatus
From Cars
Where CurrentStatus='С'
go

Select MachineNumberInTheDatabase, GovernmentNumber, Mark, BodyType, NumberOfSeats, Equipment,FuelType, Condition, YearOfIssue, CurrentStatus
From Cars
Where CurrentStatus='З'
go



//Зная номер машины в базе / гос. номер, вывести всех людей, которые брали данную машину в прокат
Select FullName, COUNT(FullName) as 'Количество раз'
From Contracts
Inner join Clients on Clients.ClientNumberIntheDatabase = Contracts.ClientNumberIntheDatabase
Inner join Cars on Cars.MachineNumberInTheDatabase = Contracts.MachineNumberInTheDatabase
Where (Clients.ClientNumberIntheDatabase=Contracts.ClientNumberIntheDatabase) and GovernmentNumber='С1160'
GROUP BY FullName
go

Select FullName, COUNT(FullName) as 'Количество раз'
From Contracts
Inner join Clients on Clients.ClientNumberIntheDatabase = Contracts.ClientNumberIntheDatabase
Inner join Cars on Cars.MachineNumberInTheDatabase = Contracts.MachineNumberInTheDatabase
Where (Clients.ClientNumberIntheDatabase=Contracts.ClientNumberIntheDatabase) and Cars.MachineNumberInTheDatabase='17'
GROUP BY FullName
go



//Зная имя человека, вывести названия машин, которые он брал в прокат и сколько раз
Select Cars.Mark, COUNT(FullName) as 'Количество раз'
From Contracts
Inner join Clients on Clients.ClientNumberIntheDatabase = Contracts.ClientNumberIntheDatabase
Inner join Cars on Cars.MachineNumberInTheDatabase = Contracts.MachineNumberInTheDatabase
Where (Clients.ClientNumberIntheDatabase=Contracts.ClientNumberIntheDatabase) and FullName='Петрова Рената Родионовна'
GROUP BY FullName, Mark
go

//Зная гос. номер машины вывести ФИО, домашний адрес и номер телефона клиента, который последним брал машину в аренду
Select TOP(1) FullName,  PhoneNumber, HomeAddress
From Contracts
Inner join Clients on Clients.ClientNumberIntheDatabase = Contracts.ClientNumberIntheDatabase
Inner join Cars on Cars.MachineNumberInTheDatabase = Contracts.MachineNumberInTheDatabase
Where GovernmentNumber='C1000' 
ORDER BY [EndDateOfTheContract] DESC;



//Вывести имена людей и общее количество дней, когда они использовали арендованные автомобили, в возрастающем порядке
Select FullName, Sum(RentalDuration) as Дни, 'дней' as Explotation
From Clients, Contracts
Where (Clients.ClientNumberIntheDatabase=Contracts.ClientNumberIntheDatabase) 
GROUP BY FullName
ORDER BY [Дни] DESC;
go

Select FullName, Sum(RentalDuration) as Дни, 'дней' as Explotation
From Contracts
Inner join Clients on Clients.ClientNumberIntheDatabase = Contracts.ClientNumberIntheDatabase
Where (Clients.ClientNumberIntheDatabase=Contracts.ClientNumberIntheDatabase)
GROUP BY FullName
ORDER BY [Дни] DESC;
go

-----------------------------------------------------------------------------------

Create view ClientContractView as
Select FullName, PassportDetails, PhoneNumber, HomeAddress, DrivingExperince, TheNumberOfOrders, ContratNumber, MachineNumberInTheDatabase, DateOfTheContract, EndDateOfTheContract, PriceRentPerDay, RentalDuration
From Clients Inner join Contracts on Clients.ClientNumberIntheDatabase = Contracts.ClientNumberIntheDatabase

Drop view ClientContractView
Select * From ClientContractView

Create view CarsContractView as
Select GovernmentNumber, Mark, BodyType, NumberOfSeats, Equipment,FuelType, Condition, YearOfIssue, CurrentStatus, ClientNumberIntheDatabase, ContratNumber, DateOfTheContract, EndDateOfTheContract, PriceRentPerDay, RentalDuration
From Cars INNER JOIN Contracts on Cars.MachineNumberInTheDatabase = Contracts.MachineNumberInTheDatabase

Drop view CarsContractView
Select * From CarsContractView


Create view AllTablesView as
Select FullName, PassportDetails, PhoneNumber, HomeAddress, DrivingExperince, TheNumberOfOrders, GovernmentNumber, Mark, BodyType, NumberOfSeats, Equipment,FuelType, Condition, YearOfIssue, CurrentStatus, ClientContractView.DateOfTheContract, ClientContractView.EndDateOfTheContract, ClientContractView.PriceRentPerDay, ClientContractView.RentalDuration
From ClientContractView INNER JOIN CarsContractView on ClientContractView.ContratNumber = CarsContractView.ContratNumber

Select * From AllTablesView


--1.	Зная имя клиента вывести всю информацию о его контрактах
Select ContratNumber, MachineNumberInTheDatabase, DateOfTheContract, EndDateOfTheContract, PriceRentPerDay, RentalDuration
From ClientContractView
Where FullName='Дмитриева Василиса Евгениевна'


--2.	Зная имя клиента вывести количество дней, которые он использовал машины в прокат
Select FullName, Sum(RentalDuration) as SumOfDays
From ClientContractView
Where FullName='Дмитриева Василиса Евгениевна'
Group by FullName

--3.	Вывести имена людей и количество дней, которые они использовали машины в прокат
Select FullName, Sum(RentalDuration) as SumOfDays
From ClientContractView
Group by FullName

--5.	Вывести сумму, которую клиент потратил на прокат автомобилей за всё время
Select FullName, Sum(PriceRentPerDay*RentalDuration) as 'Клиент заплатил за всё время'
From ClientContractView
Where FullName='Петрова Рената Родионовна'
GROUP BY FullName

--6.	Вывести данные о человеке по номеру контракта
Select FullName, PassportDetails, PhoneNumber, HomeAddress, DrivingExperince, TheNumberOfOrders
From ClientContractView
Where ContratNumber=2

-- 7.	Зная номер машины в базе / гос. номер, вывести всех людей, которые брали данную машину в прокат
Select FullName, COUNT(FullName) as 'Количество раз'
From AllTablesView
Where GovernmentNumber='С1160'
GROUP BY FullName


--8.	Зная имя человека, вывести названия машин, которые он брал в прокат и сколько раз
Select Mark, COUNT(*) as 'Количество раз'
From AllTablesView
Where FullName='Петрова Рената Родионовна'
GROUP BY Mark

--9.	Зная гос. номер машины вывести ФИО, домашний адрес и номер телефона клиента, который последним брал машину в аренду

Select TOP(1) FullName,  PhoneNumber, HomeAddress
From AllTablesView
Where GovernmentNumber='C1000' 
ORDER BY [EndDateOfTheContract] DESC;


--10.	Вывести имена людей и общее количество дней, когда они использовали арендованные автомобили, в возрастающем порядке
Select FullName, Sum(RentalDuration) as Дни, 'дней' as Explotation
From AllTablesView
GROUP BY FullName
ORDER BY [Дни] DESC;
Go
