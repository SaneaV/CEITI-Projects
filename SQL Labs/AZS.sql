Create database AZSD
go

use AZSD

Create table Spravka 
(codt int primary key,
marka varchar(10),
prisez decimal(4,2),
Koef decimal(4,2))
go


drop table Spravka
go
Select* from Spravka


insert into Spravka(codt,marka,prisez,Koef) values (10,'AI-72',6.10,1.30)
insert into Spravka(codt,marka,prisez,Koef) values (11,'AI-76',6.20,1.30)
insert into Spravka(codt,marka,prisez,Koef) values (12,'AI-80',6.30,1.30)
insert into Spravka(codt,marka,prisez,Koef) values (13,'AI-92',7.20,1.40)
insert into Spravka(codt,marka,prisez,Koef) values (14,'AI-95',8.00,1.40)
insert into Spravka(codt,marka,prisez,Koef) values (15,'AI-98',8.20,1.50)
insert into Spravka(codt,marka,prisez,Koef) values (16,'AI-99',8.50,1.60)
insert into Spravka(codt,marka,prisez,Koef) values (17,'AI-100',9.00,1.70)
insert into Spravka(codt,marka,prisez,Koef) values (18,'DT',7.30,1.50)
insert into Spravka(codt,marka,prisez,Koef) values (19,'DT EURO',7.50,1.50)
insert into Spravka(codt,marka,prisez,Koef) values (20,'Metan',5.00,1.40)
insert into Spravka(codt,marka,prisez,Koef) values (21,'Propan',5.10,1.40)


delete from Spravka where(Koef<1.20)
Select* from Spravka


Create table Smena
(cods int primary key,
nums int,
datas date default '0000-00-00')
go


drop table Smena
go
Select* from Smena


insert into Smena(cods,nums,datas) values (1001,1,'2019-09-25')
insert into Smena(cods,nums,datas) values (1002,2,'2007-09-26')
insert into Smena(cods,nums,datas) values (1003,1,'2007-09-27')
insert into Smena(cods,nums,datas) values (1004,1,'2007-09-28')
insert into Smena(cods,nums,datas) values (1005,2,'2007-09-29')
insert into Smena(cods,nums,datas) values (1006,1,'2007-09-30')
insert into Smena(cods,nums,datas) values (1007,1,'2007-10-01')
insert into Smena(cods,nums,datas) values (1008,2,'2007-10-02')
insert into Smena(cods,nums,datas) values (1009,1,'2007-10-03')
insert into Smena(cods,nums,datas) values (1010,1,'2007-10-04')
insert into Smena(cods,nums,datas) values (1011,2,'2007-10-05')
insert into Smena(cods,nums,datas) values (1012,1,'2007-10-06')


Create table Peresmenka
(cods int foreign key references Smena (cods),
codt int foreign key references Spravka (codt),
ktns int,
ktks int)
go


Select* from Peresmenka


insert into Peresmenka(cods,codt,ktks,ktns) values (1001,13,500,300)
insert into Peresmenka(cods,codt,ktks,ktns) values (1001,14,650,200)
insert into Peresmenka(cods,codt,ktks,ktns) values (1001,15,650,250)
insert into Peresmenka(cods,codt,ktks,ktns) values (1002,13,500,250)
insert into Peresmenka(cods,codt,ktks,ktns) values (1002,14,450,250)
insert into Peresmenka(cods,codt,ktks,ktns) values (1002,15,400,250)
insert into Peresmenka(cods,codt,ktks,ktns) values (1002,18,250,200)
insert into Peresmenka(cods,codt,ktks,ktns) values (1003,14,200,200)
insert into Peresmenka(cods,codt,ktks,ktns) values (1003,15,250,100)
insert into Peresmenka(cods,codt,ktks,ktns) values (1003,16,250,200)
insert into Peresmenka(cods,codt,ktks,ktns) values (1004,14,220,100)
insert into Peresmenka(cods,codt,ktks,ktns) values (1005,15,220,100)
insert into Peresmenka(cods,codt,ktks,ktns) values (1005,16,500,110)
insert into Peresmenka(cods,codt,ktks,ktns) values (1006,18,500,250)
insert into Peresmenka(cods,codt,ktks,ktns) values (1006,19,350,100)


drop table Peresmenka
go


Create table Rashod
(codt int foreign key references Spravka(codt),
kolr int,
datar date default '0000-00-00')
go


drop table Rashod
go
Select* from Rashod


insert into Rashod(codt,kolr,datar) values (11,20,'2007-09-25')
insert into Rashod(codt,kolr,datar) values (13,25,'2007-09-25')
insert into Rashod(codt,kolr,datar) values (13,20,'2007-09-25')
insert into Rashod(codt,kolr,datar) values (13,20,'2007-09-25')
insert into Rashod(codt,kolr,datar) values (14,30,'2007-09-26')
insert into Rashod(codt,kolr,datar) values (14,30,'2007-09-26')
insert into Rashod(codt,kolr,datar) values (14,25,'2007-09-26')
insert into Rashod(codt,kolr,datar) values (15,15,'2007-09-27')
insert into Rashod(codt,kolr,datar) values (15,10,'2007-09-27')
insert into Rashod(codt,kolr,datar) values (18,10,'2007-09-27')
insert into Rashod(codt,kolr,datar) values (13,20,'2007-09-25')
insert into Rashod(codt,kolr,datar) values (21,5,'2007-09-28')
insert into Rashod(codt,kolr,datar) values (21,10,'2007-09-28')

Create table Prihod
(cods int foreign key references Smena(cods),
codt int foreign key references Spravka(codt),
kolp int)
go


drop table Prihod
go
Select* from Prihod


insert into Prihod(cods,codt,kolp) values (1001,11,200)
insert into Prihod(cods,codt,kolp) values (1001,13,500)
insert into Prihod(cods,codt,kolp) values (1002,13,500)
insert into Prihod(cods,codt,kolp) values (1003,13,500)
insert into Prihod(cods,codt,kolp) values (1001,14,700)
insert into Prihod(cods,codt,kolp) values (1002,14,700)
insert into Prihod(cods,codt,kolp) values (1003,14,700)
insert into Prihod(cods,codt,kolp) values (1001,15,1000)
insert into Prihod(cods,codt,kolp) values (1002,15,1000)
insert into Prihod(cods,codt,kolp) values (1003,15,1000)
insert into Prihod(cods,codt,kolp) values (1001,18,1000)
insert into Prihod(cods,codt,kolp) values (1002,18,1000)
insert into Prihod(cods,codt,kolp) values (1003,20,300)
insert into Prihod(cods,codt,kolp) values (1002,21,300)


Select* from Spravka
Select* from Prihod
Select* from Rashod
Select* from Peresmenka
Select* from Smena


Select marka  
from Spravka
where (prisez*koef)>=10
go


Select nums as 'Smena',datas as 'Data Smeni'
from Smena
where nums=1
go


Select kolr as 'Kollicestvo ',datar as 'Data Rashoda'
from Rashod
where datar Like '____-09-__'
go

--Изменение года на 11 лет вперёд

Update Rashod Set datar = DATEADD (YEAR, 11, Datar)
where year(datar) = 2007
go

Update Smena Set datas = DATEADD (YEAR, 11, Datas)
where year(datas) = 2007
go

Update Rashod Set datar = DATEADD (DAY, 11, Datar)
where day(datar)=25
go

Select year(datar)
from Rashod
go


--Изменение года
UPDATE dbo.TableToUpdate
  SET [Date Column] = DATEADD(YEAR, -2, [Date Column]);

--Вывести марки топлива, которые были проданы за дату ....

Select Marka 
From Spravka
Where Codt in (Select Codt
			   From Rashod
			   Where datar='2018-09-28')

Select Marka 
From Spravka
Where Codt =any (Select Codt
			   From Rashod
			   Where datar='2018-09-28')

Select Distinct Marka
From Spravka, Rashod
Where (Rashod.Datar = '2018-09-26') and (Spravka.codt=Rashod.Codt)


--Вывести даты, за которые работала первая смена
Select Datas
From Smena
Where Nums=1



--Where Spravka.Codt=Rashod.Codt


--Подсчитать количество каждого проданного топлива за определённый день
Select Marka, sum(Kolr*price) as CountRashod
From RashodSpravkaDatar
Where Datar='2018-09-27'
Group by Marka


--Вывести марку и общую сумму проданного за определённый день топлива
Select Marka, Sum(Kolr) as Kol
From InfoRashodView
Where Datar='2018-09-27'
Group by Marka



--Общая сумма за определённую дату

Select Sum(Prisez*Koef*Kolr) as Sum
From InfoRashodView
Where Datar='2018-09-27'



--Вывести дату и сумму проданного топлива за всё врем работы первой смены

Select Datas, Sum((ktks-ktns)*prisez*koef) as SumOfNums
From SmenaPeresmenkaSpravkaView
Where Nums = 1 and datas Like '____-09-__'
Group by Datas


--Вывести общее количество проданного топлива каждой марки за определенный месяц
--Подсчитать количество рабочих дней каждой смены в течении определённого месяца
--Вывести марку самого спрашиваемого топлива (по общему количество объёма)


Select Marka, sum(kolr) as SumOfSoldFuel
From InfoRashodView
where datar Like '____-09-__' and Nums=2
Group by Marka

Select Nums, count(*) as KolOfSmens
From Smena
where datas Like '____-09-__'
Group by Nums


		


------------------------------------------------------------------------------------
Create view SmenaPeresmenaView as
Select Nums, Datas, Codt, ktns, ktks
From Smena inner join Peresmenka on Smena.Cods=Peresmenka.Cods

Create view SmenaPeresmenkaSpravkaView as
Select Marka, Prisez, Koef, ktns, ktks, Nums, Datas
From Spravka inner join SmenaPeresmenaView on Spravka.Codt=SmenaPeresmenaView.Codt

Create view InfoRashodView as
Select Spravka.Codt, Marka, Prisez, Koef, Kolr, Datar
From Spravka inner join Rashod on Spravka.Codt=Rashod.Codt

Create view InfoRashodPrihodView as 
Select Marka, Prisez, Koef, Kolr, Datar, Kolp
From InfoRashodView inner join Prihod on InfoRashodView.Codt = Prihod.Codt




Select Sum(ktks-ktns) as SumOfNums, 'September' as Mesiac
From SmenaPeresmenkaSpravkaView
Where Nums = 1 and datas Like '____-09-__'


Select Marka, Sum(Kolr) as MaxElem
From InfoRashodView
Group by Marka
Having Sum(Kolr)>=All (Select Sum(Kolr)
						From InfoRashodView
						Group by Marka)

Select Marka, Sum(Kolp-Kolr) as KolProdaj , '2018' as YearOfSale
From InfoRashodPrihodView
Group by Marka


----------------------------------------------------------------
Drop View ToplInfo

Create View ToplInfo as
Select Cods, Marka, ktns
From  Spravka Inner Join Peresmenka on Spravka.Codt = Peresmenka.Codt

Select Marka , Nums, Datas, ktns
From Smena Inner Join ToplInfo on Smena.Cods = ToplInfo.Cods
Where Datas = '2018-09-27'



----------------------------------------------------------------

Create View SpravkaRashod as
Select Spravka.Codt, Marka, Kolr, Datar
From Spravka inner join Rashod
on Spravka.Codt = Rashod.Codt

Select Marka, Nums, Sum(Kolr) as KolTopl, Datar
From SpravkaRashod, Smena
Where Datar = Datas and Datar = '2018-09-27' 
Group by Marka, Nums, Datar



----------------------------------------------------------------
Подсчитать сколько раз работало смена в течения одного месяца

Select Nums, count(Nums) as KolSmen
From Smena
Where Nums = 1 and month(datas) = 9
Group by Nums


----------------------------------------------------------------
Вывести номер смены и доход смены за месяц

Drop view RashodPrice

Create View RashodPrice as
Select Marka, Datar, Sum (Prisez*Koef*Kolr) as Suma
From Spravka Inner Join Rashod on Spravka.Codt = Rashod.Codt
Group by Marka, Datar


Select Nums, Sum(Suma) as Suma
From RashodPrice, Smena
Where month(Datar) = 9 and Datar = Datas
Group by Nums

----------------------------------------------------------------

Select TOP 1 Marka, Sum(Kolp-Kolr) as KolProdaj 
From InfoRashodPrihodView
Group by Marka
Order by KolProdaj DESC
