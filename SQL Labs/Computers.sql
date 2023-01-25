create database Computers
go
Use Computers
go

create type AllModel char(4)
go


create table Product(Maker char(1),
                     Model AllModel primary key,
					 TypeProduct varchar(10)
)
go

create table PC(Model AllModel unique references Product(Model),
                Speed int,
				Ram int,
				HD decimal(4,2),
				CD char(3),
				Price int)
go

create table Laptop(Model AllModel unique references Product(Model),
                Speed int,
				Ram int,
				HD decimal(4,2),
				Screen decimal(3,1),
				Price int)
go

create table printer(Model AllModel unique references Product(Model),
                     Color char(1),
					 TypeProductPrinter varchar(7),
					 Price int)
go

drop Table Product
go
drop Table PC
go
drop Table Laptop
go
drop Table printer
go

Select * from Product
go
Select * from PC
go
Select * from Laptop
go
Select * from printer
go

Select Maker
From Product
Where TypeProduct like '%pr%' 

Select Maker
From Product
Where TypeProduct like '%PC%' 

Select Maker
From Product
Where TypeProduct like '%L%' 


Select * 
From Laptop
Where price<=3000

Select * 
From printer
Where price<=3000

Select * 
From PC
Where price<=3000

Select Model, price
From printer 
Where Color='Y' and TypeProductPrinter LIKE '%ink%'




insert into Product (Maker, Model, TypeProduct)
values('A', 1001, 'PC') 
go
insert into Product (Maker, Model, TypeProduct)
values('A', 1002, 'PC') 
go
insert into Product (Maker, Model, TypeProduct)
values('B', 1003, 'PC') 
go
insert into Product (Maker, Model, TypeProduct)
values('B', 1004, 'PC') 
go
insert into Product (Maker, Model, TypeProduct)
values('C', 1005, 'PC') 
go
insert into Product (Maker, Model, TypeProduct)
values('B', 1006, 'PC') 
go
insert into Product (Maker, Model, TypeProduct)
values('C', 1007, 'PC') 
go
insert into Product (Maker, Model, TypeProduct)
values('D', 1008, 'PC') 
go
insert into Product (Maker, Model, TypeProduct)
values('D', 1009, 'PC') 
go
insert into Product (Maker, Model, TypeProduct)
values('D', 1010, 'PC') 
go
insert into Product (Maker, Model, TypeProduct)
values('D', 2001, 'Laptop') 
go
insert into Product (Maker, Model, TypeProduct)
values('D', 2002, 'Laptop') 
go
insert into Product (Maker, Model, TypeProduct)
values('D', 2003, 'Laptop') 
go
insert into Product (Maker, Model, TypeProduct)
values('E', 2004, 'Laptop') 
go
insert into Product (Maker, Model, TypeProduct)
values('F', 2005, 'Laptop') 
go
insert into Product (Maker, Model, TypeProduct)
values('G', 2006, 'Laptop') 
go
insert into Product (Maker, Model, TypeProduct)
values('G', 2007, 'Laptop') 
go
insert into Product (Maker, Model, TypeProduct)
values('E', 2008, 'Laptop') 
go
insert into Product (Maker, Model, TypeProduct)
values('E', 2009, 'Laptop') 
go
insert into Product (Maker, Model, TypeProduct)
values('D', 3001, 'printer') 
go
insert into Product (Maker, Model, TypeProduct)
values('B', 3002, 'printer') 
go
insert into Product (Maker, Model, TypeProduct)
values('D', 3003, 'printer') 
go
insert into Product (Maker, Model, TypeProduct)
values('B', 3004, 'printer') 
go
insert into Product (Maker, Model, TypeProduct)
values('H', 3005, 'printer') 
go
insert into Product (Maker, Model, TypeProduct)
values('I', 3006, 'printer') 
go
insert into Product (Maker, Model, TypeProduct)
values('I', 3007, 'printer') 
go

insert into PC(Model, Speed, Ram, HD, CD, Price)
values (1001, 133, 16, '1.6','6x', 1595)
go
insert into PC(Model, Speed, Ram, HD, CD, Price)
values (1002, 120, 16, '1.6','6x', 1399)
go
insert into PC(Model, Speed, Ram, HD, CD, Price)
values (1003, 166, 24, '2.5',' ', 1899)
go
insert into PC(Model, Speed, Ram, HD, CD, Price)
values (1004, 120, 32, '2.5','8x', 1999)
go
insert into PC(Model, Speed, Ram, HD, CD, Price)
values (1005, 200, 32, '3.1','8x', 2099)
go
insert into PC(Model, Speed, Ram, HD, CD, Price)
values (1006, 200, 32, '3.2','8x', 2349)
go
insert into PC(Model, Speed, Ram, HD, CD, Price)
values (1007, 166, 16, '2','8x', 1999)
go
insert into PC(Model, Speed, Ram, HD, CD, Price)
values (1008, 180, 32, '2.5','8x', 2599)
go
insert into PC(Model, Speed, Ram, HD, CD, Price)
values (1009, 200, 32, '2.5','8x', 3699)
go
insert into PC(Model, Speed, Ram, HD, CD, Price)
values (1010, 160, 16, '1.2','8x', 1499)
go

insert into Laptop(Model, Speed, Ram, HD, Screen, Price)
values (2001, 100, 20, '1.1', '9.5', 1999)
go
insert into Laptop(Model, Speed, Ram, HD, Screen, Price)
values(2002, 117, 12, '0.75', '11.3', 2499)
go
insert into Laptop(Model, Speed, Ram, HD, Screen, Price)
values(2003, 117, 32, '1', '10.4', 3599)
go
insert into Laptop(Model, Speed, Ram, HD, Screen, Price)
values(2004, 133, 16, '1.1', '11.2', 3499)
go
insert into Laptop(Model, Speed, Ram, HD, Screen, Price)
values(2005, 133, 16, '1', '11.3', 2599)
go
insert into Laptop(Model, Speed, Ram, HD, Screen, Price)
values(2006, 120, 80, '0.81', '12.1', 1999)
go
insert into Laptop(Model, Speed, Ram, HD, Screen, Price)
values(2007, 150, 16, '1.35', '12.1', 4799)
go
insert into Laptop(Model, Speed, Ram, HD, Screen, Price)
values(2008, 120, 16, '1.1', '12.1', 2099)
go
insert into Laptop(Model, Speed, Ram, HD, Screen, Price)
values(2009, 205, 16, '1.1', '12.1', 5000)
go


Update Laptop Set Ram = Ram - 15  where Model=2009
go
Update Laptop Set Speed = Speed + 1000) where Model=2009
go



insert into printer(Model, Color, TypeProductPrinter, Price)
values (3001,'Y','ink-jet',275)
go
insert into printer(Model, Color, TypeProductPrinter, Price)
values (3002,'Y','ink-jet',269)
go
insert into printer(Model, Color, TypeProductPrinter, Price)
values (3003,'N','laser',829)
go
insert into printer(Model, Color, TypeProductPrinter, Price)
values (3004,'N','laser',879)
go
insert into printer(Model, Color, TypeProductPrinter, Price)
values (3005,'N','ink-jet',180)
go
insert into printer(Model, Color, TypeProductPrinter, Price)
values (3006,'Y','dry',470)
go
insert into printer(Model, Color, TypeProductPrinter, Price)
values (3007,'Y','dry',879)
go


Select printer.Model
From printer
Where (printer.Price in (Select max(printer.Price)
				From printer))


Select Laptop.Model
From Laptop
Where (Laptop.Speed <Any (Select max(PC.Speed)
						  From Pc))

Select Maker
From Product 
Where Model in (Select Model
				From printer 
				Where (TypeProductPrinter = 'ink-jet') and 
					  (Color = 'Y') and
				      (price <=All (Select price
								   From printer
								   Where (TypeProductPrinter = 'ink-jet') and 
										 (Color = 'Y'))))


Select Maker
From Product 
Where Model in (Select Model
				From Laptop
				Where (Ram <=All (Select Ram
								 From Laptop
								 Where (Speed >All (Select Speed
								        From PC)))) and
					(Speed >All (Select Speed
								        From PC)))




Select AVG(price) as AVGprice
From Laptop
Where price > (Select Sum(price)
			   From printer)

Select speed, AVG(price) as AVGprice
From PC
Where speed in (Select speed
			   From PC)
Group by Speed


Select Maker, Avg(hd) as hd
From Product, PC
Where (TypeProduct = 'PC') and 
      Maker in (Select Maker
               From Product
	           Where TypeProduct = 'Printer')
Group by Maker
