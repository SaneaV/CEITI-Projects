Create database Cafe1111
go
use Cafe1111
go

Create table TypeOfDish(
					CodType int identity primary key,
					NameType varchar(20))
go

Create table Dishes(CodDish int primary key,
					NameDish varchar(30),
					CodType int foreign key references TypeOfDish(CodType),
					Carriage int,
					Price int)
go
Create table Menu(DataMenu date default '00-00-0000',
					CodDish int foreign key references Dishes(CodDish))
go
Create table OrderedDishes(IDOD int identity primary key,
                    IdAccount int , 
					DataOfOrder date default '00-00-0000', 
					CodDish int foreign key references Dishes(CodDish), 
					NumberOfServings int ) 
go

Insert into TypeOfDish(NameType) values ('Холодные закуски'), 
									    ('Салаты') ,
									    ('Горячие закуски') ,
										('Супы') ,
										('Гратарные блюда') ,
										('Блюда из рыбы') ,
										('Блюда из говявидены') ,
										('Блюда из свинины') ,
										('Блюда из птицы') ,
										('Блюда из яиц') ,
										('Мучные Блюда') ,
										('Блюда из овощей') ,
										('Гарниры') ,
										('Сладкие блюда') ,
										('Горяие напитки') ,
										('Коктейли') ,
										('Спиртное') ,
										('Шоколад') 
go

Insert into Dishes(CodDish,NameDish,CodType,Carriage,Price) values  (1001,'Канапе с черной икрой',1,250,42),
																	(1002,'Осетрина с лимоном',1,400,60),
																	(1003,'Сельд с маслинами',1,400,60),
																	(1004,'Асорти из свежих овощей',2,400,51),
																	(1101,'От шеф-повара',2,400,25),
																	(1102,'Канапе с красной икрой',1,400,27),
																	(1104,'Крабовый',2,250,25),
																	(1105,'Греческий',2,300,29),
																	(1107,'Из свежих овощей',2,300,24),
																	(1201,'Жульен из птицы',3,200,35),
																	(1202,'Жульен из куринной печени',3,200,38),
																	(1204,'Жульен из грибов',3,200,38),
																	(1301,'Зама из птицы',4,200,35),
																	(1303,'Суп вегетарианский',4,200,36),
																	(1304,'Окрошка',4,200,20),
																	(1401,'Осетрина на гратаре',5,200,45),
																	(1404,'Шашлык из свинины',5,200,48),
																	(1405,'Филе куринное на гратаре',5,200,45),
																	(1406,'Шашлык из птицы',5,200,50),
																	(1501,'Филе судака в фольге',6,200,35),
																	(1502,'Филе судака жаренное',6,200,35),
																	(1601,'Говядина с грибами',7,200,38),
																	(1602,'Стэйк с вишней',7,200,38),
																	(1603,'Стэйк с закопченным сыром',7,200,20),
																	(1701,'Отбивная "Нежность"',8,200,20),
																	(1702,'Отбивная с грибами',8,200,20),
																	(1801,'Чулама из циплят',9,200,20),
																	(1802,'Крылышки циплёнка',9,150,25),
																	(1901,'Омлет с пастрамой',10,250,25),
																	(1902,'Яичница с помидорами',10,250,25),
																	(2001,'Чебуреки',11,150,20),
																	(2002,'Пельмени',11,150,20),
																	(2101,'Картофель по-домашнему',12,150,20),
																	(2102,'Грибы в сметанном соусе',12,150,20),
																	(2201,'Рис отварной',13,150,20),
																	(2202,'Картофель отварной',13,150,20),
																	(2301,'Салат фруктовый',14,250,25),
																	(2302,'Мороженное с шоколадом',14,250,25), 
																	(2303,'Мороженное с орехами',14,250,22), 
																	(2401,'Чай',15,250,10), 
																	(2402,'Кофе',15,250,15), 
																	(2501,'Кровавая Мэри',16,250,30), 
																	(2502,'Мороженное с коффе',16,250,30), 
																	(2601,'Пиво',17,500,20), 
																	(2602,'Водка',17,50,15), 
																	(2701,'Корона',18,100,15) 
go



Insert into Menu(DataMenu,CodDish) values ('2020.12.15',1001),
										  ('2019.12.15',1101), 
										  ('2019.12.15',1201),
										  ('2019.12.15',1301), 
										  ('2019.12.15',1401), 
										  ('2019.12.15',1501), 
										  ('2019.12.16',1601), 
										  ('2019.12.16',1701), 
									 	  ('2019.12.16',1801),
										  ('2019.12.16',1901), 
										  ('2019.12.16',2001), 
										  ('2019.12.16',2101), 
										  ('2019.12.17',2201), 
										  ('2019.12.17',2301), 
									  	  ('2019.12.17',2401), 
										  ('2019.12.17',2501), 
										  ('2019.12.17',2601), 
										  ('2019.12.17',2701)
go 


Insert into OrderedDishes(IdAccount,DataOfOrder,CodDish,NumberOfServings) values  (10010001,'2019.12.15',1002,2),
																		(10010001,'2019.12.15',1201,2), 
																		(10010001,'2019.12.15',1301,2), 
																		(11030004,'2019.12.15',1401,2), 
																		(13010005,'2019.12.15',1501,2), 
																		(13020006,'2019.12.16',1601,2), 
																		(14020007,'2019.12.16',1701,4), 
																		(15020008,'2019.12.16',1801,4), 
																		(16010009,'2019.12.16',1901,4), 
																		(20020010,'2019.12.17',2001,1), 
																		(21020011,'2019.12.17',2101,1), 
																		(22020012,'2019.12.17',2201,2)
go


Select * from TypeOfDish go
Select * from Dishes go
Select * from Menu go
Select * from OrderedDishes go

---Представления

create view viewDishesFull as
( Select CodDish,NameDish,NameType,Carriage,Price
  From TypeOfDish inner join Dishes on TypeOfDish.CodType = Dishes.CodType
)
go

create view viewInfoAboutDishesInMenu as
( Select DataMenu,viewDishesFull.CodDish,NameDish,NameType,Carriage,Price
  From viewDishesFull inner join Menu on viewDishesFull.CodDish = Menu.CodDish
)
go

create view viewInfoAboutDishesInOrders 
as
( Select IdAccount,DataOfOrder,viewDishesFull.CodDish,NumberOfServings,NameDish,NameType,Carriage,Price
  From viewDishesFull inner join OrderedDishes on viewDishesFull.CodDish = OrderedDishes.CodDish
)
go

---Ограничения
Alter table Menu add constraint CheckDataMenu check (YEAR(DataMenu) >= 2017 and YEAR(DataMenu) <= YEAR(GETDATE()))
go
Alter table OrderedDishes add constraint CheckDataOrdDishes check (YEAR(DataOfOrder) >= 2017 and YEAR(DataOfOrder) <= YEAR(GETDATE()))
go

---Удаление ограничения(Пример)
ALTER TABLE Menu DROP  CONSTRAINT CheckDataMenu  
GO 


--Создание чека(Хранимая процедура)
--Вспомогательное представление
CREATE VIEW ViewForBill 
AS 
(
SELECT  IdAccount, CodDish, NumberOfServings, ROW_NUMBER() OVER (PARTITION BY IdAccount ORDER BY codDish) AS numRow
FROM OrderedDishes
	)
GO
--Сама процедура
create proc BILL(@IDOrder INT)
AS
begin
DECLARE @i INT
DECLARE @numRows INT
DECLARE @DateO AS DATE
DECLARE @nameDish AS VARCHAR(40)
DECLARE @quantity INT
DECLARE @price DECIMAL(5,2)
DECLARE @X DECIMAL(7,2)

SET @i = 1
SET @numRows = (SELECT COUNT(*)
                FROM OrderedDishes
				WHERE IdAccount = @IDOrder)
SET @DateO =(
	SELECT 
		DISTINCT DataOfOrder
	FROM 
		OrderedDishes
	WHERE 
		IdAccount = @IDOrder)
PRINT 'Number of order - ' + CONVERT(VARCHAR,@IDOrder) + '        Date of order - ' + CONVERT(VARCHAR,@DateO)
PRINT 'Orders:'
WHILE @i <= @numRows
BEGIN
	SET @nameDish =(
	                SELECT NameDish
					FROM Dishes
					WHERE CodDish = ( SELECT CodDish
									  FROM ViewForBill 
									 WHERE IdAccount = @IDOrder 
										   AND numRow = @i))
	SET @price =( SELECT Price
				  FROM Dishes
				  WHERE CodDish = ( SELECT CodDish
								    FROM ViewForBill
								    WHERE IdAccount = @IDOrder 
									      AND numRow = @i))
	SET @quantity =( SELECT NumberOfServings
			   	     FROM   ViewForBill
					 WHERE  IdAccount = @IDOrder 
					        AND numRow = @i)
	SET @X = @price * @quantity
PRINT CONVERT(VARCHAR,@i) + ')' + @nameDish + '   ' + CONVERT(VARCHAR,FLOOR(@price)) + ' lei ' + CONVERT(VARCHAR,PARSENAME(@price,1))+ ' bani  x' + CONVERT(VARCHAR,@quantity) + ' = ' + CONVERT(VARCHAR,FLOOR(@X)) + ' lei ' + CONVERT(VARCHAR,PARSENAME(@X,1))+ ' bani' 
SET @i = @i +1
END
DECLARE @SUM DECIMAL(7,2)
SET @SUM =(
	SELECT 
		SUM(Price * NumberOfServings)
	FROM 
		viewInfoAboutDishesInOrders 
	WHERE  IdAccount = @IDOrder)
PRINT 'Итого - ' + CONVERT(VARCHAR,FLOOR(@SUM)) + ' lei ' + CONVERT(VARCHAR,PARSENAME(@SUM,1))+ ' bani'
END
GO


EXECUTE BILL 10010001
GO

---Добавить блюдо(Хранимая Процедура)

CREATE PROC AddDish
@iCodDish int,
@vNameDish varchar(30),
@iCodType int,
@iCarriage int,
@iPrice int
AS
INSERT INTO Dishes(CodDish, NameDish,CodType,Carriage,Price)
VALUES(@iCodDish,@vNameDish,@iCodType,@iCarriage,@iPrice)
GO

EXEC AddDish 2551,'Цезарь', 50, 500, 50
GO

---Удалить блюдо(Хранимая Процедура)

Create table ##DeletedDishes(CodDish int,
					         NameDish varchar(30),
					         CodType int,
					         Carriage int,
					         Price int)
go

Create Procedure DeleteDishes(@vNameDish varchar(30))
AS
Begin

Insert Into ##DeletedDishes
Select * From Dishes
Where NameDish = @vNameDish

Delete Dishes
Where NameDish = @vNameDish
end
go

exec DeleteDishes 'Крабовый'
select * from ##DeletedDishes go

---Изменить Цену Определенного Блюда(Хранимая Процедура)

create proc ChangePrice @vNameDish varchar(30), @iPrice int
as
begin
update Dishes
set Price = @iPrice
WHERE NameDish = @vNameDish
end
go

EXEC ChangePrice 'Греческий' , 30
Select * from Dishes
where NameDish like 'Греческий'
go

---Сумма цены проданных блюд за день(Скалярная Пользовательская Функция)

CREATE FUNCTION ShowProfit(@date DATE)
RETURNS DECIMAL(8,2)
AS
BEGIN 
DECLARE @profit DECIMAL(8,2)
SET @profit =( SELECT SUM(NumberOfServings * Price)
		       FROM viewInfoAboutDishesInOrders 
                WHERE DataOfOrder = @date)
RETURN @profit
END
GO

Select dbo.ShowProfit('2019-12-16') as Profit
GO

--Вывести меню за определенный день(INLINE Пользовательская Функция)
CREATE FUNCTION ShowMenu(@date DATE)
RETURNS TABLE
AS
RETURN
	SELECT NameDish,Carriage,Price	
	FROM  viewInfoAboutDishesInMenu
	WHERE DataMenu = @date

GO

SELECT * FROM dbo.ShowMenu('2019-12-17')
GO

--Триггеры
CREATE TABLE History
(
Id INT IDENTITY PRIMARY KEY,
Operation NVARCHAR(200) NOT NULL,
NameTable NVARCHAR(30) NOT NULL,
CreateAt DATETIME NOT NULL DEFAULT GETDATE(),
)
go
--Добавление <...>
CREATE TRIGGER insertTrig
ON Dishes
AFTER INSERT
AS
INSERT INTO History (Operation,NameTable)
SELECT 'Добавлено блюдо: ' + CONVERT(varchar(10),CodDish),'Dishes'
FROM INSERTED
go

--Удаление <...>
CREATE TRIGGER deleteTrig
ON Dishes
AFTER DELETE
AS
INSERT INTO History ( Operation,NameTable)
SELECT 'Удаленно блюдо: ' + CONVERT(varchar(10),CodDish), 'Dishes'
FROM DELETED
GO
-- Изменение данных<...>
CREATE TRIGGER updateTrig
ON Dishes
AFTER UPDATE
AS
INSERT INTO History (Operation,NameTable)
SELECT 'Обновлено блюдо: ' + CONVERT(varchar(10),CodDish), 'Dishes'
FROM INSERTED
Go

---Запрет на удаление всех записей
Create trigger Stop_Deleting
on Menu
FOR DELETE AS
BEGIN
IF @@ROWCOUNT >= (Select count(*) From Menu)
	Begin 
	PRINT('Невозможно удалить все данные') 
         ROLLBACK TRANSACTION
	End
END
go

DELETE from Menu
go

---Использование триггера с Instead Of
--Краткое описание. После добавлении информации в новую таблицу Проверка Блюда, данный триггер сначала проверит если блюдо, которое мы хотим добавить
--подходит типу блюд, которые мы предостовляем клиенту. Если же ресторан не предоставляет такой тип блюд
--опперация вставки не будет вставлять информацию о блюде в главную таблицу.

create table DishesApprove
(CodDish int ,
NameDish varchar(30),
CodType int ,
Carriage int,
Price int)

Create TRIGGER InsTrigger
ON DishesApprove
INSTEAD OF INSERT
as
begin
declare @iRowCount int

set @iRowCount =( Select count(*) as R
                  From Dishes)
Insert into Dishes (CodDish,NameDish,CodType,Carriage,Price)
select CodDish,NameDish,CodType,Carriage,Price
from Inserted
where Codtype in ( select CodType
                   from TypeOfDish)
if(@iRowCount < (Select count(*) as R
                 From Dishes) ) print 'Блюдо прошло проверку!'
				 else  print 'Блюдо не подходит по типу!'
				   
end
go

insert into DishesApprove
select 2553,'Цезарь', 30, 500, 50 
go

select * from dishes