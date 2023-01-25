CREATE DATABASE ex_Computers
GO

USE ex_Computers
GO
CREATE TABLE Product (
P_Model INT PRIMARY KEY,
P_Maker VARCHAR(20),
P_Type VARCHAR(7) NOT NULL)
GO

CREATE TABLE PC (
Model INT UNIQUE REFERENCES Product(P_Model),
Speed INT, 
Ram INT,
HD DECIMAL(3,2), 
CD VARCHAR(2), 
Price DECIMAL(8,2) CHECK (Price > 0))
GO

CREATE TABLE Laptop(
Model INT UNIQUE REFERENCES Product(P_Model),
Speed INT, 
Ram INT,
HD DECIMAL(3,2), 
Screen DECIMAL(4,2), 
Price DECIMAL(8,2) CHECK (Price > 0))
go

Create table Printer (
Model INT UNIQUE REFERENCES Product(P_Model),
Color BIT, 
Mode VARCHAR(7), 
Price DECIMAL(8,2) CHECK (Price > 0))
go

Insert into Product(P_Maker, P_Model, P_Type) values('A',1001,'pc') 
go 
Insert into Product(P_Maker, P_Model, P_Type) values('A',1002,'pc') 
go 
Insert into Product(P_Maker, P_Model, P_Type) values('A',1003,'pc') 
go 
Insert into Product(P_Maker, P_Model, P_Type) values('B',1004,'pc') 
go 
Insert into Product(P_Maker, P_Model, P_Type) values('C',1005,'pc') 
go 
Insert into Product(P_Maker, P_Model, P_Type) values('B',1006,'pc') 
go 
Insert into Product(P_Maker, P_Model, P_Type) values('C',1007,'pc') 
go 
Insert into Product(P_Maker, P_Model, P_Type) values('D',1008,'pc') 
go 
Insert into Product(P_Maker, P_Model, P_Type) values('D',1009,'pc') 
go 
Insert into Product(P_Maker, P_Model, P_Type) values('D',1010,'pc') 
go 
Insert into Product(P_Maker, P_Model, P_Type) values('D',2001,'laptop') 
go 
Insert into Product(P_Maker, P_Model, P_Type) values('D',2002,'laptop') 
go 
Insert into Product(P_Maker, P_Model, P_Type) values('D',2003,'laptop') 
go 
Insert into Product(P_Maker, P_Model, P_Type) values('E',2004,'laptop') 
go 
Insert into Product(P_Maker, P_Model, P_Type) values('F',2005,'laptop') 
go 
Insert into Product(P_Maker, P_Model, P_Type) values('G',2006,'laptop') 
go 
Insert into Product(P_Maker, P_Model, P_Type) values('G',2007,'laptop') 
go 
Insert into Product(P_Maker, P_Model, P_Type) values('E',2008,'laptop') 
go 
Insert into Product(P_Maker, P_Model, P_Type) values('D',3001,'printer') 
go 
Insert into Product(P_Maker, P_Model, P_Type) values('B',3002,'printer') 
go 
Insert into Product(P_Maker, P_Model, P_Type) values('D',3003,'printer') 
go 
Insert into Product(P_Maker, P_Model, P_Type) values('B',3004,'printer') 
go 
Insert into Product(P_Maker, P_Model, P_Type) values('H',3005,'printer') 
go 
Insert into Product(P_Maker, P_Model, P_Type) values('I',3006,'printer') 
go 

Insert into PC(Model,Speed,Ram,HD,Cd,Price) values(1001,133,16,1.6,'6X',1595)
go
Insert into PC(Model,Speed,Ram,HD,Cd,Price) values(1002,120,16,1.6,'6X',1399)
go
Insert into PC(Model,Speed,Ram,HD,Cd,Price) values(1003,166,24,2.5,'6X',1899)
go
Insert into PC(Model,Speed,Ram,HD,Cd,Price) values(1004,166,32,2.5,'8X',1999)
go
Insert into PC(Model,Speed,Ram,HD,Cd,Price) values(1005,166,16,2,'8X',1999)
go
Insert into PC(Model,Speed,Ram,HD,Cd,Price) values(1006,200,32,3.1,'8X',2099)
go
Insert into PC(Model,Speed,Ram,HD,Cd,Price) values(1007,200,32,3.2,'8X',2349)
go
Insert into PC(Model,Speed,Ram,HD,Cd,Price) values(1008,180,32,2,'8X',3699)
go
Insert into PC(Model,Speed,Ram,HD,Cd,Price) values(1009,200,32,2.5,'8X',2599)
go
Insert into PC(Model,Speed,Ram,HD,Cd,Price) values(1010,160,16,1.2,'8X',1495)
go

Insert into Laptop(Model,Speed,Ram,HD,Screen,Price) values(2001,100,20,1.1,9.5,1999)
go
Insert into Laptop(Model,Speed,Ram,HD,Screen,Price) values(2002,117,12,0.75,11.3,2499)
go
Insert into Laptop(Model,Speed,Ram,HD,Screen,Price) values(2003,117,32,1,10.4,3599)
go
Insert into Laptop(Model,Speed,Ram,HD,Screen,Price) values(2004,133,16,1.1,11.2,3499)
go
Insert into Laptop(Model,Speed,Ram,HD,Screen,Price) values(2005,133,16,1,11.3,2599)
go
Insert into Laptop(Model,Speed,Ram,HD,Screen,Price) values(2006,120,80,0.81,12.1,1999)
go
Insert into Laptop(Model,Speed,Ram,HD,Screen,Price) values(2007,150,16,1.35,12.1,4799)
go
Insert into Laptop(Model,Speed,Ram,HD,Screen,Price) values(2008,120,16,1.1,12.1,2099)
go

Insert into Printer(Model,Color,Mode,Price) values(3001, 1,'ink-jet',275)
go
Insert into Printer(Model,Color,Mode,Price) values(3002,1,'ink-jet',269)
go
Insert into Printer(Model,Color,Mode,Price) values(3003,0,'laser',829)
go
Insert into Printer(Model,Color,Mode,Price) values(3004,0,'laser',879)
go
Insert into Printer(Model,Color,Mode,Price) values(3005,0,'ink-jet',180)
go
Insert into Printer(Model,Color,Mode,Price) values(3006,1,'dry',470)
go

-- VIEW
CREATE VIEW PC_View AS
SELECT Model, P_Maker, Speed, Ram, HD, CD, Price
FROM PC 
LEFT JOIN Product ON PC.Model = Product.P_Model
GO

--PROCEDURE 
CREATE PROCEDURE insert_pc 
	@Model INT,
	@Maker VARCHAR(20),
	@Speed INT, 
	@Ram INT,
	@HD DECIMAL(3,2), 
	@CD VARCHAR(2), 
	@Price DECIMAL(8,2)
AS
BEGIN
	IF (NOT EXISTS (SELECT P_Model from Product where P_Model = @Model))
	BEGIN 
		INSERT INTO Product VALUES(@Model, @Maker, 'pc')
		INSERT INTO PC VALUES(@Model, @Speed, @Ram, @HD, @CD, @Price)
	END
	ELSE 
	PRINT 'THIS MODEL ALREADY EXISTS'
END
GO

exec insert_pc 2323, 'dsd', 11,1,1, 'v3', 1
GO

select * from PC_View
go

-- FUNCTION
CREATE FUNCTION TopPricePc()
RETURNS TABLE
AS
RETURN
SELECT Model
FROM PC
WHERE Price = (SELECT MAX(Price) FROM PC)
GO 

-- TRIGGER AFTER 
CREATE TABLE PC_audit
(
    Id int IDENTITY(1,1) NOT NULL,
    RecordId int NOT NULL, -- Item.Id
    [EventDate] [datetimeoffset](0) NOT NULL, --GetUTCDate()
)
go

CREATE TRIGGER audit_PC on PC
AFTER INSERT
AS
IF @@ROWCOUNT = 1
BEGIN
	DECLARE @Model INT = (SELECT Model from inserted) 
	INSERT INTO PC_audit VALUES(@Model, GETUTCDATE())
END
GO

select * from PC_audit
go