Create database GasStation
go

Use GasStation
go

Drop table Reference
Drop table PriceLog
Drop table WorkChange
Drop table Interchange
Drop table Incoming
Drop table Outcoming

Create table Reference(CodFuel int primary key, 
					   Mark varchar(15))
go

Create table PriceLog(CodFuel int foreign key references Reference(CodFuel),
					   Price decimal(5,2),
					   Coef decimal(4,2),
					   DatePrice date default '0000-00-00')
go

Create table WorkChange(CodChange int primary key,
					    NumChange int,
					    DateChange date default '0000-00-00')
go

Create table Interchange(CodFuel int foreign key references Reference(CodFuel),
					     CodChange int foreign key references WorkChange(CodChange),
						 AmountBegin int,
						 AmountEnd int)
go

Create table Incoming(NumDoc nvarchar(30),
					  DataDoc Date Default Convert(date, getdate()),
					  CodFuel int foreign key references Reference(CodFuel),
					  CodChange int foreign key references WorkChange(CodChange),
					  AmountIn int)
go


Create table Outcoming(CodFuel int foreign key references Reference(CodFuel),
					   AmountOut int,
					   DateOut date default '0000-00-00')
go

Insert into Reference(CodFuel, Mark) values	(10, 'AI-72'),
 							(11, 'AI-76'),
 							(12, 'AI-80'),
							(13, 'AI-92'),
 							(14, 'AI-95'),
 							(15, 'AI-98'),
 							(16, 'AI-99'),
 							(17, 'AI-100'),
 							(18, 'DT'),
 							(19, 'DT EURO'),
 							(20, 'METAN'),
 							(21, 'PROPAN')

go

Insert into PriceLog(CodFuel, Price, Coef, DatePrice) values (10, 6.10, 1.3, '2018-09-25'),
															 								  (11, 6.20, 1.3, '2018-09-25'),
																							  (12, 6.30, 1.3, '2018-09-25'),
																							  (13, 7.20, 1.4, '2018-09-25'),
																							  (14, 8.00, 1.4, '2018-09-25'),
															 								  (15, 8.20, 1.5, '2018-09-25'),
															 								  (16, 8.50, 1.6, '2018-09-25'),
															 								  (17, 9.00, 1.7, '2018-09-25'),
															 								  (18, 7.30, 1.5, '2018-09-25'),
															 								  (19, 7.50, 1.5, '2018-09-25'),
															 								  (20, 5.00, 1.4, '2018-09-25'),
															 								  (21, 5.10, 1.4, '2018-09-25'),
															 								  (10, 6.00, 1.4, '2018-10-02'),
															 								  (11, 6.10, 1.4, '2018-10-02'),
																							  (12, 6.20, 1.4, '2018-10-02'),
																							  (13, 7.10, 1.5, '2018-10-02'),
															 								  (14, 8.10, 1.6, '2018-10-02'),
															 								  (15, 8.10, 1.7, '2018-10-02'),
															 								  (16, 8.40, 1.8, '2018-10-02'),
															 								  (17, 9.10, 1.9, '2018-10-02'),
															 								  (18, 7.20, 1.2, '2018-10-02'),
															 								  (19, 7.40, 1.4, '2018-10-02'),
															 								  (20, 5.10, 1.5, '2018-10-02'),
															 								  (21, 5.20, 1.4, '2018-10-02')
go


Insert into WorkChange(CodChange, NumChange, DateChange) values(1001, 1, '2018-09-25'),
															   (1002, 2, '2018-09-26'),
															   (1003, 1, '2018-09-27'),
															   (1004, 2, '2018-09-28'),
															   (1005, 1, '2018-09-29'),
															   (1006, 2, '2018-09-30'),
															   (1007, 1, '2018-10-01'),
															   (1008, 2, '2018-10-02'),
															   (1009, 1, '2018-10-03'),
															   (1010, 2, '2018-10-04'),
															   (1011, 1, '2018-10-05'),
															   (1012, 2, '2018-10-06'),
															   (1013, 1, '2018-10-07'),
															   (1014, 2, '2018-10-08'),
															   (1015, 1, '2018-10-09')
go


Insert into Interchange(CodChange, CodFuel, AmountBegin, AmountEnd) values(1001, 10, 500, 320),
																		  (1001, 11, 550, 310),
																		  (1001, 12, 560, 330),
																		  (1001, 13, 570, 350),
																		  (1001, 14, 580, 370),
																		  (1001, 15, 590, 310),
																		  (1001, 16, 600, 390),
																		  (1001, 17, 610, 440),
																		  (1001, 18, 510, 400),
																		  (1001, 19, 550, 520),
																		  (1001, 20, 540, 520),
																		  (1001, 21, 590, 360),
																		  (1002, 13, 500, 250),
																		  (1003, 14, 650, 200),
																		  (1004, 14, 450, 250),
																		  (1005, 14, 200, 100),
																		  (1006, 14, 220, 100),
																		  (1007, 15, 650, 250),
																		  (1008, 15, 400, 200),
																		  (1009, 15, 250, 200),
																		  (1010, 15, 220, 110),
																		  (1011, 16, 250, 100),
																		  (1012, 16, 500, 250),
																		  (1013, 18, 250, 200),
																		  (1014, 18, 500, 250),
																		  (1015, 19, 350, 100),
																		  (1015, 10, 500, 320),
																		  (1015, 11, 550, 310),
																		  (1015, 12, 560, 330),
																		  (1015, 13, 570, 350),
																		  (1015, 14, 580, 370),
																		  (1015, 15, 590, 310),
																		  (1015, 16, 600, 390),
																		  (1015, 17, 610, 440),
																		  (1015, 18, 510, 400),
																		  (1015, 20, 540, 520),
																		  (1015, 21, 590, 360)
go

Insert into Incoming (NumDoc, CodFuel, CodChange, AmountIn) values ('AAA-001', 11, 1001, 200),
																   ('AAA-002', 13, 1001, 500),
														    	   ('AAA-003', 13, 1002, 500),
																   ('AAA-004', 13, 1003, 500),
																   ('AAA-005', 14, 1001, 700),
																   ('AAA-006', 14, 1002, 700),
																   ('AAA-007', 14, 1003, 700),
																   ('AAA-008', 15, 1001, 1000),
																   ('AAA-009', 15, 1002, 1000),
																   ('AAA-010', 15, 1003, 1000),
																   ('AAA-011', 18, 1001, 1000),
																   ('AAA-012', 18, 1002, 1000),
																   ('AAA-013', 20, 1003, 300),
																   ('AAA-014', 21, 1002, 300)
go

Insert into Outcoming(CodFuel, AmountOut, DateOut) values(11, 20, '2018-09-25'),
									 (13, 25, '2018-09-25'),
									 (13, 20, '2018-09-25'),
									 (13, 20, '2018-09-25'),
									 (14, 30, '2018-09-26'),
									 (14, 30, '2018-09-26'),
									 (14, 25, '2018-09-26'),
									 (15, 15, '2018-09-27'),
									 (15, 10, '2018-09-27'),
								     (18, 10, '2018-09-27'),
									 (18, 20, '2018-09-27'),
									 (20, 25, '2018-09-28'),
									 (21, 5, '2018-09-28'),
									 (21, 10, '2018-09-28')
go


Select * from Reference
go
Select * from WorkChange
go
Select * from Interchange
go
Select * from Incoming
go
Select * from Outcoming
go
Select * from PriceLog
go


--Представление о сменах и пересменах
Create view InfoWorkChangeInterChange As
Select CodFuel, NumChange, DateChange, AmountBegin, AmountEnd
From WorkChange INNER JOIN Interchange on WorkChange.CodChange = Interchange.CodChange
go

--Представление о сменах и приходе топлива
Create view InfoWorkChangeIncoming As
Select CodFuel, NumChange, DateChange, AmountIn
From WorkChange INNER JOIN Incoming on WorkChange.CodChange = Incoming.CodChange
go

--Представление о сменах и продаже топлива
Create view InfoWorkChangeOutcoming As
Select CodFuel, NumChange, DateChange, AmountOut
From WorkChange INNER JOIN Outcoming on WorkChange.DateChange = Outcoming.DateOut
go

--Представление о справке и истории цен
Create view InfoReferencePriceLog As
Select Reference.CodFuel, Mark, Price, Coef, DatePrice
From Reference INNER JOIN PriceLog on Reference.CodFuel = PriceLog.CodFuel
go
Drop View InfoReferencePriceLog

--Представление о справке, истории цен и проданном топливе
Create view InfoReferencePriceLogOutComing As
Select OutComing.CodFuel, Mark, Price, Coef, AmountOut, DateOut
From InfoReferencePriceLog INNER JOIN Outcoming on InfoReferencePriceLog.CodFuel = Outcoming.CodFuel
go

--Представление о справке, истории цен и приходе топлива
Create view InfoReferencePriceLogInComing As
Select Incoming.CodFuel, Incoming.CodChange, Mark, Price, Coef, AmountIn
From InfoReferencePriceLog INNER JOIN Incoming on InfoReferencePriceLog.CodFuel = Incoming.CodFuel
go

--Представление о топливе и пересменке
Create view InfoReferenceInterchange As
Select Reference.CodFuel, Mark, CodChange, AmountBegin, AmountEnd
From Reference INNER JOIN Interchange on Reference.CodFuel = Interchange.CodFuel
go

--Представление о топливе, пересменке и смене
Create view InfoReferenceInterchangeWorkchange As
Select InfoReferenceInterchange.CodFuel, Mark, NumChange, DateChange, AmountBegin, AmountEnd
From InfoReferenceInterchange INNER JOIN WorkChange on InfoReferenceInterchange.CodChange = WorkChange.CodChange
go

--Представление о топливе, пересменке, смене и истории цен
Create view InfoReferenceInterchangeWorkchangePricelog As
Select Mark, NumChange, DateChange, AmountBegin, AmountEnd, Price, Coef, DatePrice
From InfoReferenceInterchangeWorkchange INNER JOIN PriceLog on InfoReferenceInterchangeWorkchange.CodFuel = PriceLog.CodFuel
go

--Представление о справке, истории цен, расходе и приходе
Create view InfoReferencePriceLogOutcomingIncoiming as
Select Mark, Price, Coef, AmountOut, DateOut, AmountIn, CodChange
From InfoReferencePriceLogOutComing INNER JOIN Incoming on InfoReferencePriceLogOutComing.CodFuel = Incoming.CodFuel


--Представление о справке, истории цен, расходе, приходе и сменах
Create view InfoReferencePriceLogOutcomingIncoimingWorkChange as
Select Mark, Price, Coef, AmountOut, DateOut, AmountIn, DateChange as DateIncoming
From InfoReferencePriceLogOutcomingIncoiming INNER JOIN WorkChange on InfoReferencePriceLogOutcomingIncoiming.CodChange = WorkChange.CodChange



Select * From InfoWorkChangeInterChange
Select * From InfoWorkChangeIncoming
Select * From InfoWorkChangeOutcoming

Select * From InfoReferencePriceLog
Select * From InfoReferencePriceLogOutComing
Select * From InfoReferencePriceLogInComing

Select * From InfoReferenceInterchange
Select * From InfoReferenceInterchangeWorkchange
Select * From InfoReferenceInterchangeWorkchangePricelog

Select * From InfoReferencePriceLogOutcomingIncoiming
Select * From InfoReferencePriceLogOutcomingIncoimingWorkChange




--1 Вывести(ежедневно) марки топлива их цены. (меню)
Select Mark, CAST(Round((Price*Coef),2) as DECIMAL(10,2)) as FuelPrice
From InfoReferencePriceLog
Where DatePrice = (Select Max(DatePrice)
				   From PriceLog)

--2 Вывести остаток топлива за текущий день (Зарос на конец дня)
Select Mark, AmountEnd, DateChange as Today
From InfoReferenceInterchangeWorkchange
Where DateChange = (Select Max(DateChange)
					From WorkChange)
go

--3 Подсчитать общее количество проданного топлива каждой марки за текущий день (Запрос на конец дня)
Select Mark, Sum(AmountOut) As TotalAmountSold
From InfoReferencePriceLogOutComing
Where DateOut = (Select Max(DateOut)
					From Outcoming)
Group by Mark


--4 Вывести марку и общую сумму(в денежном эквиваленте) проданного топлива за текущий день (Запрос на конец дня)
Select Mark, CAST(Round(SUM(Price*Coef*AmountOut),2) as DECIMAL(10,2)) As TotalAmountSold
From InfoReferencePriceLogOutComing
Where DateOut = (Select Max(DateOut)
					From Outcoming)
Group by Mark
go

--5 Подсчитать общую сумму всего проданного топлива за определнный день
Select CAST(Round(SUM(Price*Coef*AmountOut),2) as DECIMAL(10,2)) As TotalFuelSold 
From InfoReferencePriceLogOutComing 
Where DateOut = '2018-09-27'
go

--6 Подсчитать общую сумму всего проданного топлива за текущий день
Select CAST(Round(SUM(Price*Coef*AmountOut),2) as DECIMAL(10,2)) As TotalFuelSold 
From InfoReferencePriceLogOutComing 
Where DateOut = (Select Max(DateOut)
					From Outcoming)
go

--7 Вывести общее кол-во проданного топлива каждой марки за определенный месяц
Select Mark As Fuel_Mark, SUM(AmountOut) As TotalAmountSold
From InfoReferencePriceLogOutComing 
Where MONTH(DateOut) = '09' 
Group by Mark


--8 Вывести марку топлива и общую сумму денег за определенный месяц
Select Mark As Fuel_Mark, CAST(Round(SUM(Price*Coef*AmountOut),2) as DECIMAL(10,2)) As TotalFuelSold 
From InfoReferencePriceLogOutComing 
Where MONTH(DateOut) = '09' 
Group by Mark


--9 Вывести дату и общую сумму проданного топлива за все даты работы определенной смены
Select DateChange, CAST(Round(SUM((AmountBegin-AmountEnd)*Coef*Price),2) as DECIMAL(10,2)) As TotalAmountSold
From InfoReferenceInterchangeWorkchangePricelog
Where NumChange = 1
Group by DateChange


--10 Подсчитать кол-во рабочих дней каждой смены в течении определенного месяца
Select NumChange, COUNT(*) As NumberWorkingDays
From WorkChange
Where MONTH(DateChange) = '09'
Group by NumChange 

--9 Вывести марку самого спрашиваемого топлива
Select TOP 1 Mark, Sum(AmountIn-AmountOut) as AmountOfSoldFuel 
From InfoReferencePriceLogOutcomingIncoiming
Group by Mark
Order by AmountOfSoldFuel DESC


-------------------------------------------------------------------------------
--Процедура удаления

Create table ##CopyOutcoming (CodFuel int foreign key references Reference(CodFuel),
					   AmountOut int,
					   DateOut date default '0000-00-00')
go

Create proc DeleteOutcoming @CodFuel int, @DateOut date as
Begin

INSERT INTO ##CopyOutcoming
SELECT CodFuel, AmountOut, DateOut
From Outcoming
Where @CodFuel = CodFuel and @DateOut = DateOut

Delete From Outcoming
Where CodFuel = @CodFuel and @DateOut = DateOut
End
go

Execute DeleteOutcoming 21, '2018-09-28'
GO

Select * From ##CopyOutcoming
go
-------------------------------------------------------------------------------



Create PROC Coef_Add(@fAddCoef decimal(5,2) = 2)
As Update PriceLog set Coef = Coef + @fAddCoef
go
Execute Coef_Add
go

Create PROC Coef_Decrease(@fDecreaseCoef decimal(5,2) = 2)
As Update PriceLog set Coef = Coef - @fDecreaseCoef
go
Execute Coef_Decrease
go

Create PROC Adding_Fuel (@CodFuel int, @Mark varchar(15))
AS Insert Reference values (@CodFuel, @Mark) 

Execute Adding_Fuel 22,'T Euro'

Select *From Reference



--Вывести   информацию  о  продаже  топлива   каждой марки за указанный период.
Select * From InfoReferencePriceLogOutComing
go

Create FUNCTION UserGasStation_Profit (@dDateFirst date, @dDateSecond date)
Returns table
As
RETURN
Select Mark, SUM(Price*Coef*AmountOut) As TotalFuelSold, SUM(AmountOut) as AmountSold
From InfoReferencePriceLogOutComing
Where @dDateFirst<=DateOut and DateOut<=@dDateSecond
Group by (Mark)
go

Select * from UserGasStation_Profit('2018-09-25', '2018-09-29')
go


--------------------------------
--Изменить   цену  продажи  топлива  определенной   марки,  увеличив ее на 20%.
Create PROC Coef_Add(@CodFuel int)
As Update PriceLog set Coef = Coef * 1.2
Where CodFuel = @CodFuel
go

Execute Coef_Add 11
go

Select Mark, Price*Coef As SoldPrice
From InfoReferencePriceLog
Where CodFuel = 10

Select *
From PriceLog
Where CodFuel = 11
go


------------------
--Вывести   выручку   АЗС за определенный месяц
Create FUNCTION Profit(@dDate int)
Returns decimal(7,2)
As
Begin
Return (Select SUM(Price*Coef*AmountOut) As TotalFuelSold
From InfoReferencePriceLogOutComing
Where MONTH(DateOut) = @dDate)
End
go

Select dbo.Profit(09) as TotalFuelSold 

Declare @a varchar(30)
Set @a =(Select top 1 dbo.Profit(09) as TotalFuelSold )
Print 'PROFIT: ' + @a

Declare @a decimal(7,2)
Set @a = dbo.Profit(09)
Select @a
go
----------------------------------------
--1.	Вывести   информацию о количестве дней, которые отработала определенная смена за указанный период

Create Function NumWorkDay(@dDateFirst date, @dDateSecond date, @numChange int)
Returns int as 
Begin

Return (Select COUNT(*) As NumberWorkingDays
From WorkChange
Where @dDateFirst<=DateChange and DateChange<=@dDateSecond and NumChange=@numChange)

END
go

Select dbo.NumWorkDay('2018-09-25', '2018-10-09', 2) as NumberOfWorkChange
go

----------------------------------------
--2.	Удалить марку топлива которая не продавалась  за указанный период

Create FUNCTION FindIfNotSold(@dDateFirst date, @dDateSecond date)
returns int
as
begin

return (Select Outcoming.CodFuel
From Outcoming
Where (@dDateFirst<=DateOut and DateOut<=@dDateSecond) and Outcoming.CodFuel NOT IN (Select O.CodFuel
																					 From Outcoming O))
end
go

create proc DeleteIfNotSold(@codF int) as
begin 

delete from Reference
Where Reference.CodFuel = @codF
end

go

DECLARE @CODF INT
SET @CODF = (Select dbo.FindIfNotSold('2018-09-25', '2018-09-29'))
Execute DeleteIfNotSold @CODF
go
	   

----------------------------------------
--3.	Вывести  марку  самого   ходового топлива.

Create function TopSoldFuel()
returns varchar(15)
as
begin
return (Select TOP 1 Mark
		From InfoReferencePriceLogOutcomingIncoiming
		Group by Mark
		Order by Sum(AmountIn-AmountOut) DESC)
end
go

select dbo.TopSoldFuel() as TopFuel





