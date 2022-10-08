Create database CarRent
Collate Cyrillic_General_CI_AS
go
Alter Database CarRent Set Recovery Simple

use CarRent
go

--///////////////////////////////////Cars//////////////////////////////////


Create table Car_Marka(Cod_Marka int identity(1,1) primary key,
				   Marka nvarchar(50))
go

Create table Car_Color(Cod_Color int identity(1,1) primary key,
				   Color nvarchar(30))
go


Create table Car_Fuel(Cod_Fuel int identity(1,1) primary key,
					  Fuel nvarchar(60))
go

Create table Car_Transmission(Cod_Transmission int identity(1,1) primary key,
							  Transmission nvarchar(40))
go

Create table Car_Type(Cod_Type int identity(1,1) primary key,
					  NameType nvarchar(40))
go


Create table Cars(Cod_Car int identity(1,1) primary key,
				  Car_Gos_ID nchar(6),
				  Cod_Marka int references Car_Marka(Cod_Marka),
				  Car_Model nvarchar(50),
				  Cod_Color int references Car_Color(Cod_Color),
				  Cod_Fuel int references Car_Fuel(Cod_Fuel),
				  Cod_Transmission int references Car_Transmission(Cod_Transmission),
				  Cod_Type int references Car_Type(Cod_Type),
				  Car_Num_Sit int,
				  Price int,
				  ImageData varbinary(MAX))
go

Create table Reference_Status(Cod_Status int primary key,
							  NameStatus nvarchar(15))
go

Create table Car_Status(Cod_Car int references Cars(Cod_Car) NOT NULL,
						Cod_Status int references Reference_Status(Cod_Status) NOT NULL)
go

Alter table Car_Status
add
Primary key(Cod_Car, Cod_Status)
go

Create table Car_Additionaly(Cod_Car int references Cars(Cod_Car) NOT NULL,
							 Additionaly nvarchar(70) NOT NULL)
go

Alter table Car_Additionaly
add
Primary key(Cod_Car, Additionaly)
go

Create table ArchiveCar(Cod_Car int primary key,
							Car_Gos_ID nchar(6),
							Marka nvarchar(50),
							Car_Model nvarchar(50),
							Color nvarchar(30),
							Fuel nvarchar(60),
							Transmission nvarchar(40),
							NameType nvarchar(40),
							Car_Num_Sit int,
							Price int,
							ImageData varbinary(MAX),
							Additionaly varchar(MAX))
go

--///////////////////////////////////Clients//////////////////////////////////

Create table Clients(Cod_Client int identity(1,1) primary key,
					 Client_Name nvarchar(30),
					 Client_Surname nvarchar(30),
					 Client_PasID nchar(13),
					 Сlient_PhoneNumber nchar(10),
					 Client_Adres nvarchar(70),
					 Client_Birthday nchar(10),
					 ImageData varbinary(MAX))
go

Create table ArchiveClients(Cod_Client int primary key,
							Client_Name nvarchar(30),
							Client_Surname nvarchar(30),
							Client_PasID nchar(13),
							Сlient_PhoneNumber nchar(10),
							Client_Adres nvarchar(70),
							Client_Birthday nchar(10),
							ImageData varbinary(MAX))
go


--///////////////////////////////////WORKERS///////////////////////////////

Create table Worker_LoginTable(Cod_Worker int identity(1,1) primary key,
						 Worker_Login nvarchar(30) NOT NULL,
						 Worker_Password nvarchar(30) NOT NULL,
						 Worker_Mail nvarchar(30) NOT NULL)
go

Create table Positions(Cod_Position int identity(0,1) primary key,
					   Name_Position nvarchar(20))
go


Create table ArchiveWorkers(Cod_Worker int primary key,
							Worker_Login nvarchar(30),
							Worker_Password nvarchar(30),
							Worker_Mail nvarchar(30),
							Worker_Name nvarchar(30),
							Worker_Surname nvarchar(30),
							Worker_PasID nchar(13),
							Worker_PhoneNumber nchar(16),
							Worker_Adres nvarchar(70),
							Worker_Birthday nchar(10),
							ImageData varbinary(MAX),
							Name_Position nvarchar(20))
go

Create table Workers(Cod_Worker int unique references Worker_LoginTable(Cod_Worker) NOT NULL,
					 Worker_Name nvarchar(30) default '',
					 Worker_Surname nvarchar(30) default '',
					 Worker_PasID nchar(13) default '',
					 Worker_PhoneNumber nchar(10) default '',
					 Worker_Adres nvarchar(70) default '',
					 Worker_Birthday nchar(10),
					 ImageData varbinary(MAX),
					 Cod_Position int references Positions(Cod_Position))
go


Alter table Workers
add
primary key(Cod_Worker)
go

--///////////////////////////////////Contracts//////////////////////////////////

Create table Contracts(Cod_Contract int  identity(1,1) primary key,
					   Cod_Client int references Clients(Cod_Client),
					   Cod_Car int references Cars(Cod_Car),
					   Cod_Worker int references Workers(Cod_Worker),
					   DateOfOrder nchar(10),
					   FirstDayOrder nchar(10),
					   LastDayOrder nchar(10),
					   TotalPrice int)
go


Create table ArchiveContracts(Cod_Contract int  primary key,
					   Client nvarchar(50),
					   Car nvarchar(50),
					   Worker nvarchar(50),
					   DateOfOrder nchar(10),
					   FirstDayOrder nchar(10),
					   LastDayOrder nchar(10),
					   TotalPrice int)
go


--///////////////////////////////////DATA//////////////////////////////////


Insert into Positions (Name_Position) values ('Гость')
Insert into Positions (Name_Position) values ('Администратор') 
Insert into Positions (Name_Position) values ('Работник')
Insert into Positions (Name_Position) values ('Директор')
Insert into Positions (Name_Position) values ('Бухгалтер')


INSERT INTO Car_Color (Color) 
			VALUES ('Чёрный'),
				   ('Белый'),
				   ('Красный'),
				   ('Зелёный'),
				   ('Жёлтый'),
				   ('Синий'),
				   ('Коричневый'),
				   ('Оранжевый'),
				   ('Розовый'),
				   ('Серый'),
				   ('Фиолетовый'),
				   ('Салатовый')
go

INSERT INTO Car_Fuel(Fuel) 
			VALUES ('Бензин'),
				   ('Дизель'),
				   ('Газ'),
				   ('Электричество'),
				   ('Гибрид'),
				   ('ГБО')
go

INSERT INTO Car_Marka(Marka)
			VALUES('Audi'),
				('BMW'),
				('Chevrolet'),
				('Mercedes-Benz'),
				('Toyota'),
				('Porshe'),
				('Nissan'),
				('Hyundai'),
				('Ford'),
				('Volkswagen'),
				('Honda'),
				('Mazda'),
				('Jeep'),
				('Volvo'),
				('Suzuki'),
				('Opel'),
				('Mitsubishi'),
				('Peugeot'),
				('Citroen'),
				('Fiat'),
				('Chrysler'),
				('Kia'),
				('Opel'),
				('Renault'),
				('Lada'),
				('Land-Rover'),
				('Subaru'),
				('Saab'),
				('Jaguar'),
				('Skoda'),
				('Cadilac'),
				('AstonMartin'),
				('ALfaRomeo'),
				('Bentley'),
				('Infinity'),
				('Dodge'),
				('Chevrolet'),
				('Pontiac'),
				('Lamborghini'),
				('Acura'),
				('Lexus'),
				('Maserati'),
				('Ferrari'),
				('Mini'),
				('Lotus'),
				('Isuzu'),
				('Lincoln')
go

INSERT INTO Car_Transmission
			VALUES ('Механическая'),
				   ('Автоматическая'),
				   ('Роботизированная'),
				   ('Вариативная')
go


INSERT INTO Car_Type
			VALUES ('Хэтчбек'),
				   ('Седан'),
				   ('Внедорожник'),
				   ('Купе'),
				   ('Универсал'),
				   ('Пикап'),
				   ('Минивэн')
go

INSERT INTO Reference_Status 
			VALUES (1, 'Свободна'),
				   (2, 'Занята'),
				   (3, 'Недоступна')
go



----------------------VIEWS-------------------------

--Представление обо все особенностях машины
Create view ColorCar as
Select Cod_Car, Car_Gos_ID, Cod_Marka, Car_Model, Color, Cod_Fuel, Cod_Transmission, Cod_Type, Car_Num_Sit,  Price, ImageData
From Car_Color INNER JOIN Cars on Car_Color.Cod_Color = Cars.Cod_Color
go

Create view MarkaCar AS
Select Cod_Car, Car_Gos_ID, Marka, Car_Model, Color, Cod_Fuel, Cod_Transmission, Cod_Type, Car_Num_Sit, Price, ImageData
From Car_Marka INNER JOIN ColorCar on Car_Marka.Cod_Marka = ColorCar.Cod_Marka
go

Create view FuelCar As
Select Cod_Car, Car_Gos_ID, Marka, Car_Model, Color, Fuel, Cod_Transmission, Cod_Type, Car_Num_Sit, Price, ImageData
From Car_Fuel INNER JOIN MarkaCar on MarkaCar.Cod_Fuel = Car_Fuel.Cod_Fuel
go

Create view TransmissionCar As
Select Cod_Car, Car_Gos_ID, Marka, Car_Model, Color, Fuel, Transmission, Cod_Type, Car_Num_Sit, Price, ImageData
From Car_Transmission INNER JOIN FuelCar on Car_Transmission.Cod_Transmission = FuelCar.Cod_Transmission
go

Create view TypeCar As
Select Cod_Car, Car_Gos_ID, Marka, Car_Model, Color, Fuel, Transmission, NameType, Car_Num_Sit, Price, ImageData
From Car_Type INNER JOIN TransmissionCar on Car_Type.Cod_Type = TransmissionCar.Cod_Type
go

Create view StatusCar as
Select TypeCar.Cod_Car, Car_Gos_ID, Marka, Car_Model, Color, Fuel, Transmission, NameType, Car_Num_Sit, Price, ImageData, Cod_Status
From Car_Status INNER JOIN TypeCar on Car_Status.Cod_Car = TypeCar.Cod_Car
go

Create view AllInfoCar as
Select Cod_Car, Car_Gos_ID, Marka, Car_Model, Color, Fuel, Transmission, NameType, Car_Num_Sit, Price, ImageData, NameStatus
From Reference_Status INNER JOIN StatusCar on Reference_Status.Cod_Status = StatusCar.Cod_Status
go

create view WorkerLogin as
Select Workers.Cod_Worker, Worker_Name, Worker_Surname, Worker_PasID, Worker_PhoneNumber, Worker_Adres, Worker_Birthday, Cod_Position, Worker_Login, Worker_Password, Worker_Mail
From Workers INNER JOIN Worker_LoginTable on Workers.Cod_Worker = Worker_LoginTable.Cod_Worker
go

create view WorkerData as
Select WorkerLogin.Cod_Worker, Worker_Name, Worker_Surname, Worker_PasID, Worker_PhoneNumber, Worker_Adres, Worker_Birthday, Worker_Login, Worker_Password, Worker_Mail,Name_Position
From WorkerLogin INNER JOIN Positions on WorkerLogin.Cod_Position = Positions.Cod_Position
go

create view ClientContract as
Select Cod_Contract, CONCAT(Client_Name,' ', Client_Surname,' ', Contracts.Cod_Client) as ClientInfo, Cod_Car, Cod_Worker, DateOfOrder, FirstDayOrder, LastDayOrder, TotalPrice
From Contracts INNER JOIN Clients on Contracts.Cod_Client = Clients.Cod_Client
go

create view CarContract as
Select Cod_Contract, ClientInfo, Concat(Marka,' ', Car_Model,' ', AllInfoCar.Cod_Car) as Car, Cod_Worker, DateOfOrder, FirstDayOrder, LastDayOrder, TotalPrice
From ClientContract INNER JOIN AllInfoCar on ClientContract.Cod_Car = AllInfoCar.Cod_Car
go

create view ContractData as
Select Cod_Contract, ClientInfo, Car, Concat(Worker_Name,' ', Worker_Surname,' ', WorkerData.Cod_Worker) as Worker, DateOfOrder, FirstDayOrder, LastDayOrder, TotalPrice
From CarContract INNER JOIN WorkerData on CarContract.Cod_Worker = WorkerData.Cod_Worker
Where Name_Position = 'Работник'
go


--1. Добавить новые логин-данные работника фирмы

Create proc InsertLogData(@Worker_Login nvarchar(30), @Worker_Password nvarchar(30),
						 @Worker_Mail nvarchar(30))
as
insert into Worker_LoginTable values (@Worker_Login, @Worker_Password, @Worker_Mail)

declare @Cod_Worker as int
set @Cod_Worker = (Select Cod_Worker
					From Worker_LoginTable
					Where Worker_Login LIKE @Worker_Login)

insert into Workers values(@Cod_Worker, '','','','','','', 0x ,0)

if @Cod_Worker = 1
begin
update Workers
Set Cod_Position = 1
end

go

--2. Добавить нового клиента фирмы
Create proc InsertClientData(@Client_Name nvarchar(30), @Client_Surname nvarchar(30),
						 @Client_PasID char(13), @Сlient_PhoneNumber char(14), @Client_Adres nvarchar(70),
						 @Client_Birthday nvarchar(10), @ImageData varbinary(MAX))
as

insert into Clients values(@Client_Name, @Client_Surname, @Client_PasID, @Сlient_PhoneNumber, @Client_Adres, @Client_Birthday, @ImageData)
go



--3. Добавить новую машину в базу данных
Create proc AddCar(@Car_Gos_ID nvarchar(8), @Cod_Marka int, @Car_Model nvarchar(50),
				   @Cod_Color int, @Cod_Fuel int, @Cod_Transmission int, @Cod_Type int,
				   @Car_Num_Sit int, @Price int, @ImageData varbinary(MAX))
as

insert into Cars values(@Car_Gos_ID, @Cod_Marka, @Car_Model, @Cod_Color, @Cod_Fuel,
						@Cod_Transmission, @Cod_Type, @Car_Num_Sit, @Price, @ImageData)

declare @Cod_Car as int
set @Cod_Car = (Select Cod_Car
					From Cars
					Where Car_Gos_ID LIKE @Car_Gos_ID)

insert into Car_Status values(@Cod_Car, '3')
go


--4.	Удалить клиента из базы данных
create proc DeleteClient (@Cod_Client int) as
begin

insert into ArchiveClients (Cod_Client, Client_Name, Client_Surname, Client_PasID,
							Сlient_PhoneNumber, Client_Adres, Client_Birthday,
							ImageData) 
Select Cod_Client, Client_Name, Client_Surname, Client_PasID,
							Сlient_PhoneNumber, Client_Adres, Client_Birthday,
							ImageData
from Clients
where Cod_Client = @Cod_Client

delete from Clients
where Cod_Client = @Cod_Client
end
go

--5.	Удалить машину из базы данных
Create proc DeleteCar(@Cod_Car int, @Additionaly varchar(MAX))
as

insert into ArchiveCar (Cod_Car, Car_Gos_ID, Marka, Car_Model,
					  Color, Fuel, Transmission , NameType,
					  Car_Num_Sit, Price, ImageData)
Select Cod_Car, Car_Gos_ID, Marka, Car_Model,
					  Color, Fuel, Transmission , NameType,
					  Car_Num_Sit, Price, ImageData 
From AllInfoCar
Where Cod_Car = @Cod_Car

Update ArchiveCar
Set Additionaly = @Additionaly
Where Cod_Car = @Cod_Car

delete From Car_Additionaly
Where Cod_Car = @Cod_Car

delete From Car_Status
Where Cod_Car = @Cod_Car

delete From Cars
Where Cod_Car = @Cod_Car
go

--6.	Удалить работника из базы данных

create proc DeleteWorker (@Cod_WorkerLocal int) as
begin

insert into ArchiveWorkers (Cod_Worker, Worker_Login, Worker_Password, Worker_Mail,
							Worker_Name, Worker_Surname, Worker_PasID,
							Worker_PhoneNumber, Worker_Adres, Worker_Birthday,
							Name_Position)
Select Cod_Worker, Worker_Login, Worker_Password, Worker_Mail,
							Worker_Name, Worker_Surname, Worker_PasID,
							Worker_PhoneNumber, Worker_Adres, Worker_Birthday,
							Name_Position
from WorkerData
where Cod_Worker = @Cod_WorkerLocal

Update ArchiveWorkers
Set ImageData = (Select ImageData from Workers where Cod_Worker = @Cod_WorkerLocal)
where Cod_Worker = @Cod_WorkerLocal

delete from Workers
Where Cod_Worker = @Cod_WorkerLocal

delete from Worker_LoginTable
Where Cod_Worker = @Cod_WorkerLocal

end
go

--7.Создание нового контракта

Create procedure InsertContract @Cod_Client int, @Cod_Car int, @Cod_Worker int,
								@DateOfOrder nchar(10), @FirstDayOrder nchar(10),
								@LastDayOrder nchar(10), @TotalPrice int AS

Insert into Contracts values (@Cod_Client, @Cod_Car, @Cod_Worker, @DateOfOrder, @FirstDayOrder,
								@LastDayOrder, @TotalPrice)

if @FirstDayOrder=Convert(varchar,GETDATE(),104)
begin
update Car_Status
set Cod_Status = 2
Where Cod_Car = @Cod_Car
end

GO

--8. Установка статусов машин
Create procedure InsertStatusCar 
as

Update Car_Status
Set Cod_Status = 1
Where Cod_Car in (Select distinct Cod_Car 
				 From Contracts
				 Where Convert(datetime,LastDayOrder,104)>Convert(datetime,GETDATE(),104)
						and Convert(datetime,FirstDayOrder,104)>Convert(datetime,GETDATE(),104))

Update Car_Status
Set Cod_Status = 2
Where Cod_Car in (Select distinct Cod_Car 
				 From Contracts
				 Where Convert(datetime,LastDayOrder,104)>=Convert(datetime,GETDATE(),104)
						and Convert(datetime,FirstDayOrder,104)<=Convert(datetime,GETDATE(),104))

GO


--9.Удаление контракта

create proc DeleteContract @Cod_Contract int as

insert into ArchiveContracts (Cod_Contract, Client, Car,
					   Worker, DateOfOrder, FirstDayOrder,
					   LastDayOrder, TotalPrice) 
Select Cod_Contract, ClientInfo, Car,
					   Worker, DateOfOrder, FirstDayOrder,
					   LastDayOrder, TotalPrice
from ContractData
where Cod_Contract = @Cod_Contract

declare @ContractToday as int
Set @ContractToday = (Select Count(*) From Contracts Where Convert(datetime,LastDayOrder,104)>=Convert(datetime,GETDATE(),104)
															and Convert(datetime,FirstDayOrder,104)<=Convert(datetime,GETDATE(),104) and Cod_Contract = @Cod_Contract)

if(@ContractToday=1)
begin

declare @ChangeStatus int 
Set @ChangeStatus =( Select Cod_Car From Contracts Where Cod_Contract = @Cod_Contract)

update Car_Status
Set Cod_Status = 1
Where Cod_Car = @ChangeStatus
end

Delete From Contracts
Where Cod_Contract = @Cod_Contract
go


