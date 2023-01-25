Create database SeaBattle_Exam
go

Use SeaBattle_Exam
go

	Create table Battles
		( CodBat int primary key,
		  NameBat varchar (35),
		  DateStart date,
		  DateEnd date)
go

	INSERT INTO Battles (CodBat, NameBat, DateStart, DateEnd) 
		VALUES ( 10, 'North Atlantic','1941-05-24', '1941-05-27'),
			   ( 20, 'Guadacanal','1942-11-15', '1942-11-15'),
			   ( 30, 'North Cape','1943-12-26', '1943-12-26'),
		   	   ( 40, 'Surigao Strait','1944-10-25','1944-10-25')
go

	SELECT *FROM Battles
go

	Create table Classes
		( CodCl int primary key,
		  NameCl varchar (30),
		  TypeCl char (2),
		  Country varchar (25),
		  NumGuns int,
		  Bore int, 
		  Displacement int)
go

	INSERT INTO Classes (CodCl, NameCl, TypeCl, Country, NumGuns, Bore, Displacement)
		VALUES ( 01, 'Bismark', 'bb', 'Germany', 8, 15, 42000),
			   ( 02, 'Iowa', 'bb', 'USA', 9, 16, 46000),
			   ( 03, 'Kongo', 'bc', 'Japan', 8, 14, 32000),
			   ( 04, 'North California', 'bb', 'USA', 9, 16, 37000),
			   ( 05, 'Renown', 'bc', 'Gt. Britain', 6, 15, 32000),
			   ( 06, 'Revenge', 'bb', 'Gt. Britain', 8, 15, 29000),
			   ( 07, 'Tennessee', 'bb', 'USA', 12, 14, 32000),
			   ( 08, 'Yamato', 'bb', 'Japan', 9, 18, 65000) 
go

	SELECT *FROM Classes
go



	Create table Ships 
		( CodShip int primary key,
		  CodCl int foreign key references Classes(CodCl),
		  NameShip varchar (25),
		  Launched int)
go

	INSERT INTO Ships (CodShip, CodCl, NameShip, Launched)
		VALUES ( 001, 01, 'California', 1921),
			   ( 002, 02, 'Haruna', 1915),
			   ( 003, 03, 'Hiei', 1914),
			   ( 004, 06, 'Iowa', 1943),
			   ( 005, 08, 'Kirishima', 1915),
			   ( 006, 08, 'Komgo', 1913),
			   ( 007, 08, 'Missouri', 1944),
			   ( 008, 06, 'Mussashi', 1942),
			   ( 009, 04, 'New Jersey', 1943), 
			   ( 010, 05, 'North California', 1941),
			   ( 011, 06, 'Ramillies', 1917),
			   ( 012, 07, 'Renown', 1916),
			   ( 013, 07, 'Repulse', 1916),
			   ( 014, 08, 'Resolution', 1916),
			   ( 015, 01, 'Royal Oak', 1916),
			   ( 016, 02, 'Royal Sovereigh', 1916),
			   ( 017, 03, 'Tennesse', 1920),
			   ( 018, 04, 'Washington', 1941),
			   ( 019, 04, 'Wisconsin', 1944),
			   ( 020, 05, 'Yamato', 1941)
go

	SELECT *FROM Ships
go


	Create table Outcomes 
		( CodShip int foreign key references Ships(CodShip),
		  CodBat int foreign key references Battles(CodBat),
		  Result varchar(20))
go
	  
	INSERT INTO Outcomes(CodShip, CodBat, Result)
		VALUES ( 001, 10, 'Sunk'),
			   ( 002, 20, 'Ok'),
			   ( 003, 10, 'Damaged'),
			   ( 004, 10, 'Sunk'),
			   ( 005, 20, 'Sunk'),
			   ( 006, 20, 'Ok'),
			   ( 007, 10, 'Ok'),
			   ( 008, 30, 'Sunk'),
			   ( 009, 40, 'Damaged'),
			   ( 010, 40, 'Damaged'),
			   ( 011, 40, 'Damaged'),
			   ( 012, 30, 'Sunk'),
			   ( 013, 30, 'Ok'),
			   ( 014, 30, 'Ok'),
			   ( 015, 10, 'Damaged')
go

	SELECT *FROM Outcomes
go


--Представления

--1) Корабли и классы. (Вся информация о кораблях)
Select * From Ships
Select * From Classes

Create VIEW InfoShipView AS
Select CodShip, NameShip, Launched, NameCl, TypeCl, Country, NumGuns, Bore, Displacement
From Classes INNER JOIN Ships ON Classes.CodCl = Ships.CodCl
go

Select * From InfoShipView

--2) Сражения и результаты. (Вся информация о сражениях)
Select * From Battles
Select * From Outcomes

Create VIEW InfoBattleView AS
Select NameBat, DateStart, DateEnd, Result, CodShip
From Battles INNER JOIN Outcomes ON Battles.CodBat = Outcomes.CodBat
go

Select * From InfoBattleView

--3) Общее представление. (Включает всю БД)
Select * From InfoShipView
Select * From InfoBattleView

Create VIEW InfoSeaBattlesView AS
Select NameBat, DateStart, DateEnd, Country, NameShip, Launched, NameCl, TypeCl, NumGuns, Bore, Displacement, Result
From InfoShipView INNER JOIN InfoBattleView ON InfoShipView.CodShip = InfoBattleView.CodShip
go

Select * From InfoSeaBattlesView
go
-------------------------------------
--Создание ограничений
Select * From Classes
Select * From Ships
Select * From Battles

Alter table Ships add constraint CheckYear check (Launched >= 1800 and Launched <= 2019)
go
Alter table Battles add constraint CheckDate check (DateStart <= DateEnd)
go
Alter table Classes add constraint CheckClassType check (TypeCl = 'bb' or TypeCl = 'bc')
go

--Удаление ограничения
ALTER TABLE 
DROP CONSTRAINT   
GO 
---------------------------
--Триггеры: добавление, удаление и изменение данных.

CREATE TABLE History 
(
    Id INT IDENTITY PRIMARY KEY,
    CodShip INT NOT NULL,
    Operation NVARCHAR(200) NOT NULL,
    CreateAt DATETIME NOT NULL DEFAULT GETDATE(),
)
Go


--Добаление
CREATE TRIGGER Ship_INSERT
ON Ships
AFTER INSERT
AS
INSERT INTO History (CodShip, Operation)
SELECT CodShip, 'Добавлен новый корабль: ' + NameShip
FROM INSERTED
go

INSERT INTO Ships (CodShip, CodCl, NameShip, Launched)
VALUES(021, 01, 'Louna', 1949)
GO

Select * From Ships
Select * From History

--Удаление
CREATE TRIGGER Ship_DELETE
ON Ships
AFTER DELETE
AS
INSERT INTO History (CodShip, Operation)
SELECT CodShip, 'Удален корабль: ' + NameShip
FROM DELETED
GO

DELETE FROM Ships
WHERE CodShip = 021
go

Select * From Ships
Select * From History

--Изменение
CREATE TRIGGER Ship_UPDATE
ON Ships
AFTER UPDATE
AS
INSERT INTO History (CodShip, Operation)
SELECT CodShip, 'Обновлен корабль: ' + NameShip
FROM INSERTED

UPDATE Ships SET NameShip = 'Yamato'
WHERE NameShip = 'Louna'
GO

Select * From Ships
Select * From History

--ТРИГГЕР FOR Запрещает удаление
Create trigger Stop_Deleting
ON Ships
FOR DELETE AS
BEGIN

IF @@ROWCOUNT >= (Select count(*) From Ships)
	Begin 
	PRINT('Невозможно удалить все данные') 
         ROLLBACK TRANSACTION
	End

END
go

Delete
From Ships 

--ТРИГГЕР INSTEAD OF Не позволит совершить удаление одной из записей (желательно не использовать, несёт лишь ознакомительный характер)
Create trigger Stop_Deleting
on Ships
instead of DELETE AS
BEGIN

print('Тут ничего нельзя удалить')

END
go

delete
from Ships 
go

-----------------------

--Пользовательские функции 

--1) Вывести информацию о кораблях, потопленных в определенном сражении. (Table)
Select * From InfoSeaBattlesView

CREATE FUNCTION InfoSunkShip(@vBattle varchar(35))
	 RETURNS TABLE
		As
		Return
 Select  NameShip, Country, NameCl, TypeCl, NumGuns, Bore, Displacement, Launched
			  From  InfoSeaBattlesView 
			  Where  NameBat = @vBattle and Result = 'Sunk'
			
	go

Select *From InfoSunkShip('North Atlantic')
Go

--2) Вывести количество кораблей определенного типа у определенной страны. (Table)
Select * From InfoShipView

CREATE FUNCTION CountShipByType (@vCountry varchar(25), @TypeShip char(2))
 RETURNS TABLE
	AS
		Return 
			Select Country, Count(*) As CountShips
			From InfoShipView
			Where TypeCl = @TypeShip and Country = @vCountry
			Group by Country
go

Select * From CountShipByType('USA', 'bb')
go

--2.1) Вывести количество кораблей определенного типа у определенной страны. (СКАЛЯР)

CREATE FUNCTION CountShipByType_2 (@vCountry varchar(25), @TypeShip char(2))
 RETURNS int
	AS
	Begin
		Return(
			Select Count(*) As CountShips
			From InfoShipView
			Where TypeCl = @TypeShip and Country = @vCountry)
End
go

Select dbo.CountShipByType_2 ('USA', 'bb') AS CountOfSunkShips
go
--------------------

--Хранимые процедуры 

--1) Удалить информацию о кораблях, потопленных в сражениях до определенного года.
Select * From InfoSeaBattlesView

CREATE PROCEDURE DeleteShipByYear(@iYear int)
		AS
		 DELETE FROM  Ships
			WHERE CodShip IN ( Select CodShip
						From  InfoSeaBattlesView
					Where Result = 'Sunk' and  datepart(YYYY,Data_S) < @iYear)
GO 

	Execute DeleteShipByYear 1941
go

Select * From Ships

--2) Увеличить количество оружий определенного класса.
Select * From Classes

CREATE PROCEDURE GunsUpdate(@vClass varchar(30), @iGunsAdd int)
		AS
		UPDATE Classes
			SET NumGuns = NumGuns + @iGunsAdd
				WHERE NameCl = @vClass
go

	Execute GunsUpdate 'Bismark', 2
go

--3) Добавить новый корабль. 
Select * From Ships
Select * From History

CREATE PROCEDURE InsertNewShip (@iCodShip int, @iCodCl int, @vNameShip varchar(25), @iLaunched int)
		AS
		INSERT INTO Ships 
		Values (@iCodShip, @iCodCl, @vNameShip, @iLaunched)
go
	
	Execute InsertNewShip 021, 01, 'Loudge', 1949
go
------------------------------------------

--ТРАНЗАКЦИЯ

BEGIN TRANSACTION

Delete from Ships
Where CodShip = 021

COMMIT TRANSACTION
go