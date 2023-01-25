Create database Computers
go

Use Computers
go

--Создание таблиц

Create table PC (PC_model nchar(4) unique references Product(Product_model),
				 PC_speed SMALLINT,
				 PC_ram TINYINT,
				 PC_hd decimal(4,2),
				 PC_cd nvarchar(2),
				 PC_price SMALLINT)
go


Create table Laptop (Laptop_model nchar(4) unique references Product(Product_model),
					 Laptop_speed SMALLINT,
					 Laptop_ram TINYINT,
					 Laptop_hd decimal(4,2),
					 Laptop_screen decimal(4,2),
					 Laptop_price SMALLINT)
go

Create table Printer (Printer_model nchar(4) unique references Product(Product_model),
					  Printer_color BIT,
					  Printer_type nvarchar(10),
					  Printer_price SMALLINT)
go

Create table Product (Product_maker nchar(1) not NULL,
					  Product_model nchar(4) primary key,
					  Product_type nvarchar(10))
go 

--Заполнение таблиц

insert into Product(Product_maker, Product_model, Product_type) values
																('A',1001,'PC'),
																('A',1002,'PC'),
																('B',1003,'PC'),
																('B',1004,'PC'),
																('C',1005,'PC'),
																('B',1006,'PC'),
																('C',1007,'PC'),
																('D',1008,'PC'),
																('D',1009,'PC'),
																('D',1010,'PC'),
																('D',2001,'Laptop'),
																('D',2002,'Laptop'),
																('D',2003,'Laptop'),
																('E',2004,'Laptop'),
																('F',2005,'Laptop'),
																('G',2006,'Laptop'),
																('G',2007,'Laptop'),
																('E',2008,'Laptop'),
																('E',2009,'Laptop'),
																('D',3001,'printer'),
																('B',3002,'printer'),
																('D',3003,'printer'),
																('D',3004,'printer'),
																('B',3005,'printer'),
																('D',3006,'printer'),
																('D',3007,'printer')
go

insert into PC(PC_model, PC_speed, PC_ram, PC_hd, PC_cd, PC_price) values 
														(1001, 120, 16, '1.6','6x', 1399),
														(1002, 120, 16, '1.6','6x', 1399),
														(1003, 166, 24, '2.5',' ', 1899),
														(1004, 120, 32, '2.5','8x', 1999),
														(1005, 200, 32, '3.1','8x', 2099),
														(1006, 200, 32, '3.2','8x', 2349),
														(1007, 166, 16, '2','8x', 1999),
														(1008, 180, 32, '2.5','8x', 2599),
														(1009, 200, 32, '2.5','8x', 3699),
														(1010, 160, 16, '1.2','8x', 1499)
go


insert into Laptop(Laptop_model, Laptop_speed, Laptop_ram, Laptop_hd, Laptop_screen, Laptop_price) values
														(2001, 100, 20, '1.1', '9.5', 1999),
														(2002, 117, 12, '0.75', '11.3', 2499),
														(2003, 117, 32, '1', '10.4', 3599),
														(2004, 133, 16, '1.1', '11.2', 3499),
														(2005, 133, 16, '1', '11.3', 2599),
														(2006, 120, 80, '0.81', '12.1', 1999),
														(2007, 150, 16, '1.35', '12.1', 4799),
														(2008, 120, 16, '1.1', '12.1', 2099),
														(2009, 205, 16, '1.1', '12.1', 5000)
go


insert into Printer(Printer_model, Printer_color, Printer_type, Printer_price) values
														(3001,'1','ink-jet',275),
														(3002,'1','ink-jet',269),
														(3003,'0','laser',829),
														(3004,'0','laser',879),
														(3005,'0','ink-jet',180),
														(3006,'1','dry',470),
														(3007,'1','dry',879)
go

--Создание условий

Alter table PC add constraint CheckPCNumber check (PC_model>=1000 and PC_model<=1999)
go
Alter table Laptop add constraint CheckLaptopNumber check (Laptop_model>=2000 and Laptop_model<=2999)
go
Alter table Printer add constraint CheckPrinterNumber check (Printer_model>=3000 and Printer_model<=3999)
go


Alter table Printer add constraint CheckColor check (Printer_color='1' or Printer_color = '0')
go

--Удаление ограничения
ALTER TABLE 
DROP CONSTRAINT   
GO  


--Вывод на экран 
Select * From Product 
go
Select * From PC
go
Select * From Laptop
go
Select * From Printer
go



--Создание представлений
--Общее представление

Create view ProductAllInfo as
Select  Product_maker, Product_model, Product_type, 
		PC_speed, PC_ram, PC_hd, PC_cd, PC_price,
		Laptop_speed, Laptop_ram, Laptop_hd, Laptop_screen, Laptop_price,
		Printer_color, Printer_type, Printer_price
From Product FULL JOIN Printer on Product_model = Printer_model
			 FULL JOIN PC on Product_model = PC_model
			 FULL JOIN Laptop on Product_model = Laptop_model
go


Select * From ProductAllInfo
go


--Создание пользовательских функций

--Скаляр функция возрат общей стоимости техники

Create function SumProducts(@nTypeProduct nvarchar(10))
returns INT
as
begin

IF(@nTypeProduct = 'PC')
return (Select Sum(PC_price)
		From PC)

IF(@nTypeProduct = 'Printer')
return (Select Sum(Printer_price)
		From Printer)

IF(@nTypeProduct = 'Laptop')
return (Select Sum(Laptop_price)
		From Laptop)

return 0
end
go

Select dbo.SumProducts('Printer') as 'PRODUCT_ALL_PRICE'
go


--Таблица возрат всей техники от одного производителя

Create function MakersProduct(@nMakersName nchar(1))
returns table
as

RETURN 
(Select Product_maker, Product_model, Product_type, 
		PC_speed, PC_ram, PC_hd, PC_cd, PC_price,
		Laptop_speed, Laptop_ram, Laptop_hd, Laptop_screen, Laptop_price,
		Printer_color, Printer_type, Printer_price
From ProductAllInfo
Where Product_maker = @nMakersName)

go

Select * FROM dbo.MakersProduct('D') 
go


--MultiStatment вывести производителя, тип продукта и его стоимость

Create function MakersProductPrice(@nMakersName nchar(1))
returns @MakersProductPriceTable table (Product_maker nchar(1), 
									Product_type nvarchar(10), 
									Product_price SMALLINT)
as
begin

INSERT INTO @MakersProductPriceTable
            SELECT Product_maker, Product_type, PC_price
			From Product inner join PC on Product_model = PC_model
			Where Product_maker = @nMakersName and
				  Product_model = PC_model

INSERT INTO @MakersProductPriceTable
            SELECT Product_maker, Product_type, Laptop_price
			From Product inner join Laptop on Product_model = Laptop_model
			Where Product_maker = @nMakersName and
				  Product_model = Laptop_model

INSERT INTO @MakersProductPriceTable
            SELECT Product_maker, Product_type, Printer_price
			From Product inner join Printer on Product_model = Printer_model
			Where Product_maker = @nMakersName and
				  Product_model = Printer_model
				  

return 
end

go

Select * From MakersProductPrice('D')
go


--Создание хранимых процедур

--Добавление нового продукта (как в таблицу Products так и в PC одновременно) 
--Подобное можно проделать и с другими таблицами

Create procedure AddNewProductPC @Product_maker nchar(1), @Product_model nchar(4), 
								 @PC_speed SMALLINT, @PC_ram TINYINT, @PC_hd decimal(4,2), @PC_cd nvarchar(2), @PC_price SMALLINT
as
begin

insert into Product values (@Product_maker, @Product_model, 'PC')
insert into PC values (@Product_model, @PC_speed, @PC_ram, @PC_hd, @PC_cd, @PC_price)

end
go

execute AddNewProductPC 'A', '1011', 120, 16, '1.5','8x', 1520
go

--Обновление цены у PC/Laptop/Printer по модели

Create procedure UpdateProductPrice @Product_model nchar(4), @ProductPrice SMALLINT
as
begin

if(@Product_model>=1000 and @Product_model<=1999)
Update PC
Set PC_price = @ProductPrice
Where @Product_model = PC_model

if(@Product_model>=2000 and @Product_model<=2999)
Update Laptop
Set Laptop_price = @ProductPrice
Where @Product_model = Laptop_model

if(@Product_model>=3000 and @Product_model<=3999)
Update Printer
Set Printer_price = @ProductPrice
Where @Product_model = Printer_model

end

go

execute UpdateProductPrice '1011', 2000
go


--Удалить продукт из таблицы Product и из таблицы PC/Laptop/Printer по модели

Create Procedure DeleteProduct @Product_model nchar(4)
as
begin 

if(@Product_model>=1000 and @Product_model<=1999)
Delete from PC
Where @Product_model = PC_model

if(@Product_model>=2000 and @Product_model<=2999)
Delete from Laptop
Where @Product_model = Laptop_model

if(@Product_model>=3000 and @Product_model<=3999)
delete from Printer
Where @Product_model = Printer_model

delete from Product
Where @Product_model = Product_model
end

execute DeleteProduct '1011'


--Триггеры

CREATE TABLE History 
(
    ID_Operation INT IDENTITY PRIMARY KEY,
    Product_model char(4) NOT NULL,
    Operation NVARCHAR(200) NOT NULL,
    DateCreation DATETIME NOT NULL DEFAULT GETDATE(),
)
Go

Select * from History

--Триггер на добавление в таблицу Product

CREATE TRIGGER Product_Insert
ON Product
AFTER INSERT
AS
INSERT INTO History (Product_model, Operation)
SELECT Product_model, 'Добавлена новая модель техники: ' + Product_model
FROM INSERTED
go

--Триггер на удаление из таблицы Product

CREATE TRIGGER Product_Delete
ON Product
AFTER DELETE
AS
INSERT INTO History (Product_model, Operation)
SELECT Product_model, 'Удалена модель техники: ' + Product_model
FROM deleted
go


--Триггер на обновление цены в таблице PC

CREATE TRIGGER PC_Delete
on PC 
After Update
as
INSERT INTO History (Product_model, Operation)
SELECT PC_model, 'Обновлена цена: ' + PC_model
FROM delete
go


--ТРИГГЕР FOR Запрещает удаление
Create trigger Stop_Deleting
on PC
FOR DELETE AS
BEGIN

IF @@ROWCOUNT >= (Select count(*) From PC)
	Begin 
	PRINT('Невозможно удалить все данные') 
         ROLLBACK TRANSACTION
	End

END
go

delete
from PC 

--ТРИГГЕР INSTEAD OF Не позволит совершить удаление одной из записей (желательно не использовать, несёт лишь ознакомительный характер)
Create trigger Stop_Deleting
on PC
instead of DELETE AS
BEGIN

print('Тут ничего нельзя удалить')

END
go

delete
from PC 
go

--ТРАНЗАКЦИЯ

BEGIN TRANSACTION

Delete from Laptop
Where Laptop_model = '2001'

Delete from Product
Where Product_model = '2001'

COMMIT TRANSACTION
go

