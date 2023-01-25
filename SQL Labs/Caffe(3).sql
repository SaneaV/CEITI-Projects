Create database ex_Caffe 
go
use ex_Caffe
go

Create table TipBL(
					CodTipa int primary key,
					NameTipa varchar(20))
go

Create table Bliuda(CodBl int primary key,
					NameBl varchar(30),
					CodTipa int foreign key references TipBL(CodTipa),
					Gramaj int CHECK (Gramaj > 0),
					Price int CHECK (Price > 0))
go
Create table Menu(Datam date default GETDATE(),
					CodBl int foreign key references Bliuda(CodBl),
					UNIQUE (Datam, CodBL))
go
Create table Zakaz(IdSciota int, 
					Dataz date default GETDATE(), 
					CodBl int foreign key references Bliuda(CodBl), 
					ColPr int DEFAULT 1 CHECK (ColPr > 0), 
					UNIQUE(IdSciota, CodBl) )
go

Insert into TipBL(CodTipa,NameTipa) values(10,'Холодные закуски') 
go 
Insert into TipBL(CodTipa,NameTipa) values(11,'Салаты') 
go 
Insert into TipBL(CodTipa,NameTipa) values(12,'Горячие закуски') 
go 
Insert into TipBL(CodTipa,NameTipa) values(13,'Супы') 
go 
Insert into TipBL(CodTipa,NameTipa) values(14,'Гратарные блюда') 
go 
Insert into TipBL(CodTipa,NameTipa) values(15,'Блюда из рыбы') 
go 
Insert into TipBL(CodTipa,NameTipa) values(16,'Блюда из говявидены') 
go 
Insert into TipBL(CodTipa,NameTipa) values(17,'Блюда из свинины') 
go 
Insert into TipBL(CodTipa,NameTipa) values(18,'Блюда из птицы') 
go 
Insert into TipBL(CodTipa,NameTipa) values(19,'Блюда из яиц') 
go 
Insert into TipBL(CodTipa,NameTipa) values(20,'Мучные Блюда') 
go 
Insert into TipBL(CodTipa,NameTipa) values(21,'Блюда из овощей') 
go 
Insert into TipBL(CodTipa,NameTipa) values(22,'Гарниры') 
go 
Insert into TipBL(CodTipa,NameTipa) values(23,'Сладкие блюда') 
go 
Insert into TipBL(CodTipa,NameTipa) values(24,'Горяие напитки') 
go 
Insert into TipBL(CodTipa,NameTipa) values(25,'Коктейли') 
go 
Insert into TipBL(CodTipa,NameTipa) values(26,'Спиртное') 
go 
Insert into TipBL(CodTipa,NameTipa) values(27,'Шоколад') 
go

Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1001,'Канапе с черной икрой',10,250,42)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1004,'Осетрина с лимоном',10,400,60)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1006,'Сельд с маслинами',10,400,60)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1008,'Асорти из свежих овощей',11,400,51)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1101,'От шеф-повара',11,400,25)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1102,'Канапе с красной икрой',10,400,27)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1104,'Крабовый',11,250,25)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1105,'Греческий',11,300,29)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1107,'Из свежих овощей',11,300,24)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1201,'Жульен из птицы',12,200,35)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1202,'Жульен из куринной печени',12,200,38)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1204,'Жульен из грибов',12,200,38)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1301,'Зама из птицы',13,200,35)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1303,'Суп вегетарианский',13,200,36)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1304,'Окрошка',13,200,20)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1401,'Осетрина на гратаре',14,200,45)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1404,'Шашлык из свинины',14,200,48)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1405,'Филе куринное на гратаре',14,200,45)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1406,'Шашлык из птицы',14,200,50)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1501,'Филе судака в фольге',15,200,35)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1502,'Филе судака жаренное',15,200,35)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1601,'Говядина с грибами',16,200,38)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1602,'Стэйк с вишней',16,200,38)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1603,'Стэйк с закопченным сыром',16,200,20)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1701,'Отбивная "Нежность"',17,200,20)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1702,'Отбивная с грибами',17,200,20)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1801,'Чулама из циплят',18,200,20)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1802,'Крылышки циплёнка',18,150,25)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1901,'Омлет с пастрамой',19,250,25)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(1902,'Яичница с помидорами',19,250,25)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(2001,'Чебуреки',20,150,20)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(2002,'Пельмени',20,150,20)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(2101,'Картофель по-домашнему',21,150,20)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(2102,'Грибы в сметанном соусе',21,150,20)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(2201,'Рис отварной',22,150,20)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(2202,'Картофель отварной',22,150,20)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(2301,'Салат фруктовый',23,250,25)
go
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(2302,'Мороженное с шоколадом',23,250,25) 
go 
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(2303,'Мороженное с орехами',23,250,22) 
go 
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(2401,'Чай',24,250,10) 
go 
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(2402,'Кофе',24,250,15) 
go 
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(2501,'Кровавая Мэри',25,250,30) 
go 
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(2502,'Мороженное с коффе',25,250,30) 
go 
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(2602,'Пиво',26,500,20) 
go 
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(2603,'Водка',26,50,15) 
go 
Insert into Bliuda(CodBl,NameBl,CodTipa,Gramaj,Price) values(2701,'Корона',27,100,15) 
go

Insert into Menu(Datam,CodBl) values('2007.11.16',1001) 
go 
Insert into Menu(Datam,CodBl) values('2007.11.16',1101) 
go 
Insert into Menu(Datam,CodBl) values('2007.11.16',1201) 
go 
Insert into Menu(Datam,CodBl) values('2007.11.16',1301) 
go 
Insert into Menu(Datam,CodBl) values('2007.11.16',1401) 
go 
Insert into Menu(Datam,CodBl) values('2007.11.17',1501) 
go 
Insert into Menu(Datam,CodBl) values('2007.11.17',1601) 
go 
Insert into Menu(Datam,CodBl) values('2007.11.17',1701) 
go 
Insert into Menu(Datam,CodBl) values('2007.11.17',1801) 
go 
Insert into Menu(Datam,CodBl) values('2007.11.17',1901) 
go 
Insert into Menu(Datam,CodBl) values('2007.11.17',2001) 
go 
Insert into Menu(Datam,CodBl) values('2007.11.18',2101) 
go 
Insert into Menu(Datam,CodBl) values('2007.11.18',2201) 
go 
Insert into Menu(Datam,CodBl) values('2007.11.18',2301) 
go 
Insert into Menu(Datam,CodBl) values('2007.11.18',2401) 
go 
Insert into Menu(Datam,CodBl) values('2007.11.19',2501) 
go 
Insert into Menu(Datam,CodBl) values('2007.11.19',2701) 
go 

Insert into Zakaz(IdSciota,Dataz,CodBl,ColPr) values(10010001,'2007.11.16',1001,2) 
go 
Insert into Zakaz(IdSciota,Dataz,CodBl,ColPr) values(10040002,'2007.11.16',1201,2) 
go 
Insert into Zakaz(IdSciota,Dataz,CodBl,ColPr) values(11010003,'2007.11.16',1301,2) 
go 
Insert into Zakaz(IdSciota,Dataz,CodBl,ColPr) values(11030004,'2007.11.16',1401,2) 
go 
Insert into Zakaz(IdSciota,Dataz,CodBl,ColPr) values(13010005,'2007.11.16',1501,2) 
go 
Insert into Zakaz(IdSciota,Dataz,CodBl,ColPr) values(13020006,'2007.11.17',1601,2) 
go 
Insert into Zakaz(IdSciota,Dataz,CodBl,ColPr) values(14020007,'2007.11.17',1701,4) 
go 
Insert into Zakaz(IdSciota,Dataz,CodBl,ColPr) values(15020008,'2007.11.17',1801,4) 
go 
Insert into Zakaz(IdSciota,Dataz,CodBl,ColPr) values(16010009,'2007.11.17',1901,4) 
go 
Insert into Zakaz(IdSciota,Dataz,CodBl,ColPr) values(20020010,'2007.11.18',2001,1) 
go 
Insert into Zakaz(IdSciota,Dataz,CodBl,ColPr) values(21020011,'2007.11.18',2101,1) 
go 
Insert into Zakaz(IdSciota,Dataz,CodBl,ColPr) values(22020012,'2007.11.18',2201,2) 
go

Create View Bliuda_Tip as (
Select CodBl, NameBl, Gramaj, Price, NameTipa
From Bliuda
Join TipBL On Bliuda.CodTipa = TipBL.CodTipa
)
go
Create View Bliuda_Tip_Menu as (
Select NameBl, Gramaj, Price, NameTipa, Datam
From Menu
Join Bliuda_Tip on Bliuda_Tip.CodBl = Menu.CodBl )
go

Create View Bliuda_Tip_Zakaz as (
Select  NameBl, Gramaj, Price, NameTipa, IdSciota, Dataz, ColPr
From Zakaz
Join Bliuda_Tip on Bliuda_Tip.CodBl = Zakaz.CodBl)
go