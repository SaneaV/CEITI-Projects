create database Warehouse
go
use Warehouse
go 
create table Providers
(
codeProvider int primary key,
nameProvider varchar(25),
adresProvider varchar(20),
accountProvider varchar(8),
phoneProvider varchar(9)
)
go
create table TypesProducts
(
codeType int primary key,
nameType varchar(30),
)
go
create table Customers
(
codeCustomer int primary key,
nameCustomer varchar(25),
adresCustomer varchar(20),
phoneCustomer varchar(9),
accountCustomer varchar(8)
)
go
create table Products
(
codeProduct int primary key,
nameProduct varchar(25),
codeProvider int foreign key references Providers(codeProvider),
codeType int foreign key references TypesProducts(codeType),
priceProduct int,
unit varchar(5),
dateIssie date default '0000-00-00',
shelfLife int,
koefIncreace decimal(4,2)
)
go
create table Journal
(
codeProduct int unique references Products(codeProduct),
dateJournal date default '0000-00-00',
rest int
)
go
create table Invoice
(
codeInvoice int,
dateInvoice date default '0000-00-00',
codeProduct int foreign key references Products(codeProduct),
quantityInvoice int
)
go
create table Discount 
(
codeProduct int unique references Products(codeProduct),
quantityDiscount int,
koefDiscount decimal(4,2)
)
go
create table Orders 
(
codeOrder int,
dateOrder date default '0000-00-00',
codeProduct int foreign key references Products(codeProduct),
codeCustomer int foreign key references Customers(codeCustomer),
quantityOrder int,
typeOrder char(1)
)
go
Insert into Providers(codeProvider,nameProvider,adresProvider,accountProvider,phoneProvider)
values (1,'Franzeluta','Sarmezegetusa 23','05s4d756','078578903') 
go
Insert into Providers(codeProvider,nameProvider,adresProvider,accountProvider,phoneProvider)
values (2,'Chishinau','Cuza-Voda 123','158d7s3f','069487013') 
go
Insert into Providers(codeProvider,nameProvider,adresProvider,accountProvider,phoneProvider)
values (3,'JLC','Pushkin 27','016sd79g','068475213') 
go
Insert into Providers(codeProvider,nameProvider,adresProvider,accountProvider,phoneProvider)
values (4,'Bucuria','Stefan 74','79d4f679','078578610') 
go
Insert into Providers(codeProvider,nameProvider,adresProvider,accountProvider,phoneProvider)
values (5,'Pegas','Hristo Botev 71','76ad4fs3','069412507') 
go
Insert into Providers(codeProvider,nameProvider,adresProvider,accountProvider,phoneProvider)
values (6,'Milina','Cernishevkogo 31','3saf43sf','069964120') 
go
Insert into Providers(codeProvider,nameProvider,adresProvider,accountProvider,phoneProvider)
values (7,'Cricova','Cuza-Voda 146','7afs98vc','078412357')
go
Insert into Providers(codeProvider,nameProvider,adresProvider,accountProvider,phoneProvider)
values (8,'Milenisti mici','Sarmizegetusa 93','s78139sa','069417922') 
go
Insert into Providers(codeProvider,nameProvider,adresProvider,accountProvider,phoneProvider)
values (9,'Carmez','Ceapaev 432','d47f78b','068741200') 
go
Insert into Providers(codeProvider,nameProvider,adresProvider,accountProvider,phoneProvider)
values (10,'HP','Lenin 74','4w255r7w','069413507') 
go

Insert into TypesProducts(codeType,nameType)
values (1,'Вино')
go 
Insert into TypesProducts(codeType,nameType)
values (2,'Хлебобулочные изделия')
go
Insert into TypesProducts(codeType,nameType)
values (3,'Молочные изделия')
go
Insert into TypesProducts(codeType,nameType)
values (4,'Сладости')
go 
Insert into TypesProducts(codeType,nameType)
values (5,'Алкогольные напитки')
go  
Insert into TypesProducts(codeType,nameType)
values (6,'Компьютеры')
go 
Insert into TypesProducts(codeType,nameType)
values (7,'Колбасные изделия')
go 
Insert into TypesProducts(codeType,nameType)
values (8,'Крупы')
go 
Insert into TypesProducts(codeType,nameType)
values (9,'Фрукты')
go 
Insert into TypesProducts(codeType,nameType)
values (10,'Овощи')
go 

Insert into Customers(codeCustomer,nameCustomer,adresCustomer,phoneCustomer,accountCustomer)
values(1,'Petorv Oleg','Pushkin 42','069713459','f47d9120')
go
Insert into Customers(codeCustomer,nameCustomer,adresCustomer,phoneCustomer,accountCustomer)
values(2,'Moraru Alexander','Ceapaev 7','078364972','7f9h456q')
go
Insert into Customers(codeCustomer,nameCustomer,adresCustomer,phoneCustomer,accountCustomer)
values(3,'Perepelita Alexander','Lomanosov 9','079314267','ae79201g')
go
Insert into Customers(codeCustomer,nameCustomer,adresCustomer,phoneCustomer,accountCustomer)
values(4,'Perevalov Ivan','Gorkii 90','069457891','78aqwe79')
go
Insert into Customers(codeCustomer,nameCustomer,adresCustomer,phoneCustomer,accountCustomer)
values(5,'Hadji Andrei','Lenin 78','079458312','qefds472')
go
Insert into Customers(codeCustomer,nameCustomer,adresCustomer,phoneCustomer,accountCustomer)
values(6,'Maxim Kazanli','Stalin 7','069123475','qpfd978b')
go
Insert into Customers(codeCustomer,nameCustomer,adresCustomer,phoneCustomer,accountCustomer)
values(7,'Bejenar Nicolai','Gagauzkaia 91','068123751','84asr130')
go
Insert into Customers(codeCustomer,nameCustomer,adresCustomer,phoneCustomer,accountCustomer)
values(8,'Rusnak Maxim','Lermantov 791','068435971','792spqb1')
go
Insert into Customers(codeCustomer,nameCustomer,adresCustomer,phoneCustomer,accountCustomer)
values(9,'Osadciuk Vladimir','Stoickov 77','069004210','dsfa789l')
go
Insert into Customers(codeCustomer,nameCustomer,adresCustomer,phoneCustomer,accountCustomer)
values(10,'Pimanova Iana','Bob Marley 69','078945612','fekr789g')
go

Insert into Products(codeProduct,nameProduct,codeProvider,codeType,priceProduct,unit,dateIssie,shelfLife,koefIncreace)
values (1,'Bere "Chishinau"',2,5,11,'l','2018-11-23',94,1.30)
go
Insert into Products(codeProduct,nameProduct,codeProvider,codeType,priceProduct,unit,dateIssie,shelfLife,koefIncreace)
values (2,'Piine "Botanica"',1,2,5,'gr','2019-02-13',4,1.37)
go
Insert into Products(codeProduct,nameProduct,codeProvider,codeType,priceProduct,unit,dateIssie,shelfLife,koefIncreace)
values (8,'Bucurel',4,4,60,'gr','2019-01-13',49,1.33)
go
Insert into Products(codeProduct,nameProduct,codeProvider,codeType,priceProduct,unit,dateIssie,shelfLife,koefIncreace)
values (3,'Servelat',5,7,155,'gr','2019-01-10',77,1.37)
go
Insert into Products(codeProduct,nameProduct,codeProvider,codeType,priceProduct,unit,dateIssie,shelfLife,koefIncreace)
values (4,'Chifla',7,3,4,'gr','2019-01-23',4,1.27)
go
Insert into Products(codeProduct,nameProduct,codeProvider,codeType,priceProduct,unit,dateIssie,shelfLife,koefIncreace)
values (5,'Sampanskoe',6,7,51,'l','2014-11-13',1700,1.32)
go
Insert into Products(codeProduct,nameProduct,codeProvider,codeType,priceProduct,unit,dateIssie,shelfLife,koefIncreace)
values (6,'Nuga',9,10,57,'gr','2018-07-13',132,1.17)
go
Insert into Products(codeProduct,nameProduct,codeProvider,codeType,priceProduct,unit,dateIssie,shelfLife,koefIncreace)
values (7,'Laptop',7,1,14000,'st','2018-02-10',-1,1.5)
go
Insert into Products(codeProduct,nameProduct,codeProvider,codeType,priceProduct,unit,dateIssie,shelfLife,koefIncreace)
values (12,'Meat',9,10,57,'gr','2018-07-13',132,1.17)
go
Insert into Products(codeProduct,nameProduct,codeProvider,codeType,priceProduct,unit,dateIssie,shelfLife,koefIncreace)
values (10,'Hleb',9,10,5,'gr','2018-07-13',132,1.17)
go
Insert into Products(codeProduct,nameProduct,codeProvider,codeType,priceProduct,unit,dateIssie,shelfLife,koefIncreace)
values (11,'Suhari',9,10,11,'gr','2018-07-13',132,1.17)
go


Insert into Journal(codeProduct,dateJournal,rest)
values(1,'2019-02-11',5)
go
Insert into Journal(codeProduct,dateJournal,rest)
values(2,'2019-02-11',7)
go
Insert into Journal(codeProduct,dateJournal,rest)
values(3,'2019-02-11',18)
go
Insert into Journal(codeProduct,dateJournal,rest)
values(4,'2019-02-11',51)
go
Insert into Journal(codeProduct,dateJournal,rest)
values(5,'2019-02-11',70)
go
Insert into Journal(codeProduct,dateJournal,rest)
values(6,'2019-02-11',7)
go
Insert into Journal(codeProduct,dateJournal,rest)
values(7,'2019-02-11',4)
go

Insert into Invoice(codeInvoice,dateInvoice,codeProduct,quantityInvoice)
values(1,'2019-03-16',4,40)
go
Insert into Invoice(codeInvoice,dateInvoice,codeProduct,quantityInvoice)
values(2,'2019-03-16',7,30)
go
Insert into Invoice(codeInvoice,dateInvoice,codeProduct,quantityInvoice)
values(3,'2019-03-16',1,740)
go
Insert into Invoice(codeInvoice,dateInvoice,codeProduct,quantityInvoice)
values(4,'2019-03-16',4,7)
go
Insert into Invoice(codeInvoice,dateInvoice,codeProduct,quantityInvoice)
values(5,'2019-03-16',2,9)
go
Insert into Invoice(codeInvoice,dateInvoice,codeProduct,quantityInvoice)
values(6,'2019-03-16',8,31)
go
Insert into Invoice(codeInvoice,dateInvoice,codeProduct,quantityInvoice)
values(7,'2019-03-16',4,40)
go
Insert into Invoice(codeInvoice,dateInvoice,codeProduct,quantityInvoice)
values(7,'2019-03-16',4,40)
go

Insert into Discount(codeProduct,quantityDiscount,koefDiscount)
values(1,70,1.10)
go
Insert into Discount(codeProduct,quantityDiscount,koefDiscount)
values(2,10,1.14)
go
Insert into Discount(codeProduct,quantityDiscount,koefDiscount)
values(3,17,1.15)
go
Insert into Discount(codeProduct,quantityDiscount,koefDiscount)
values(4,51,1.19)
go
Insert into Discount(codeProduct,quantityDiscount,koefDiscount)
values(5,75,1.27)
go
Insert into Discount(codeProduct,quantityDiscount,koefDiscount)
values(6,17,1.31)
go

Insert into Orders(codeOrder,dateOrder,codeProduct,codeCustomer,quantityOrder,typeOrder)
values(1,'2019-03-17',1,1,114,'o')
go
Insert into Orders(codeOrder,dateOrder,codeProduct,codeCustomer,quantityOrder,typeOrder)
values(2,'2019-03-17',7,2,14,'n')
go
Insert into Orders(codeOrder,dateOrder,codeProduct,codeCustomer,quantityOrder,typeOrder)
values(3,'2019-03-17',4,3,9,'n')
go
Insert into Orders(codeOrder,dateOrder,codeProduct,codeCustomer,quantityOrder,typeOrder)
values(4,'2019-03-17',1,4,7,'n')
go
Insert into Orders(codeOrder,dateOrder,codeProduct,codeCustomer,quantityOrder,typeOrder)
values(5,'2019-03-17',1,5,4,'n')
go
Insert into Orders(codeOrder,dateOrder,codeProduct,codeCustomer,quantityOrder,typeOrder)
values(6,'2019-03-17',7,6,30,'n')
go

create index ProviderIndex on Providers(nameProvider)
go

create index PriceIndex on Products(priceProduct)
go

create index TypeIndex on TypesProducts(nameType)
go

create index DateIndex on Journal(dateJournal)


Drop table Orders
Drop table Invoice

select *from Providers 
go
select *from TypesProducts 
go
select *from Customers
go
select *from Journal
go
select *from Products
go
select *from Invoice
go
select *from Discount
go
select *from Orders
go


------------------------------------------------------------------------------
Create view InfoZaiavki as
Select Sum(quantityInvoice) as Quant, codeInvoice
From Invoice
Where codeInvoice in (Select codeInvoice
					  From Invoice)
Group by codeInvoice


Select Invoice.codeInvoice, dateInvoice
From Invoice join InfoZaiavki on Invoice.codeInvoice = InfoZaiavki.codeInvoice
Where Quant = (Select max(Quant)
			   From InfoZaiavki)


------------------------------------------------------------------------------
Select nameProvider, SUM(Invoice.quantityInvoice) as SumQuant
From (Products Join Invoice on Products.codeProduct = Invoice.codeProduct) Join Providers on Products.codeProvider = Providers.codeProvider
Group by nameProvider


------------------------------------------------------------------------------
Create view PrihodTovara as 
Select nameProduct, Sum(quantityInvoice) as 'Заказали' , Sum(quantityOrder) as 'Продали', (Sum(quantityInvoice)-Sum(quantityOrder)) as 'Остаток'
From (Invoice join Orders on Invoice.codeProduct = Orders.codeProduct) join Products on Invoice.codeProduct = Products.codeProduct
Where (DATEPART(month, dateOrder) = DATEPART(month, GetDate())-1) and (DATEPART(year, dateOrder) = DATEPART(year, GetDate())) and
	  (DATEPART(month, dateInvoice) = DATEPART(month, GetDate())-1) and (DATEPART(year, dateInvoice) = DATEPART(year, GetDate()))
Group by nameProduct

Select *From PrihodTovara

------------------------------------------------------------------------------
--Найти товары, цены которых совпадают у двух и более наименований
Select P1.nameProduct, P2.nameProduct 
From Products as P1, Products as P2 
Where (P1.priceProduct = P2.priceProduct) and
	  (P1.codeProduct <> P2.codeProduct)



------------------------------------------------------------------------------
--Укажите поставщиков, продающих только молочные продукты
---------------------------------1 Вариант------------------------------------
Select nameProvider
From Providers
Where codeProvider in (Select codeProvider
					   From Products
					   Where codeType = (Select codeType
										 From TypesProducts
										 Where nameType like '%молоч%'))
---------------------------------2 Вариант------------------------------------

Create view ProviderProduct as 
Select nameProvider,adresProvider,accountProvider,phoneProvider, codeProduct,nameProduct,codeType,priceProduct,unit,dateIssie,shelfLife,koefIncreace
From Providers join Products on Providers.codeProvider = Products.codeProvider

Create view TypeProduct as 
Select TypesProducts.codeType, nameType, codeProduct,nameProduct,priceProduct,unit,dateIssie,shelfLife,koefIncreace
From TypesProducts join Products on TypesProducts.codeType = Products.codeType

Create view TypeProviderProduct as 
Select nameType, TypeProduct.codeProduct, TypeProduct.nameProduct, TypeProduct. priceProduct, TypeProduct.unit, 
TypeProduct.dateIssie,TypeProduct.shelfLife, TypeProduct.koefIncreace, nameProvider,adresProvider,accountProvider,phoneProvider
From TypeProduct join ProviderProduct on TypeProduct.codeType = ProviderProduct.codeType

Select nameProvider
From TypeProviderProduct
Where nameType like '%молоч%'


------------------------------------------------------------------------------
--Подсчитать количество товара проданного каждым поставщиком
------------------------------------------------------------------------------

Create view ProviderProduct as 
Select nameProvider,adresProvider,accountProvider,phoneProvider, codeProduct,nameProduct,codeType,priceProduct,unit,dateIssie,shelfLife,koefIncreace
From Providers join Products on Providers.codeProvider = Products.codeProvider

Create view OrderProduct as 
Select nameProduct,codeType,priceProduct,unit,dateIssie,shelfLife,koefIncreace, dateOrder, codeCustomer, quantityOrder, typeOrder, Orders.codeProduct
From Orders join Products on Orders.codeProduct = Products.codeProduct

Create view ProviederOrderProduct as
Select ProviderProduct.nameProduct, ProviderProduct.codeType, ProviderProduct.priceProduct, ProviderProduct.unit, ProviderProduct.dateIssie, 
ProviderProduct.shelfLife, ProviderProduct.koefIncreace, dateOrder, codeCustomer, 
quantityOrder, typeOrder, nameProvider, adresProvider, accountProvider, phoneProvider
From ProviderProduct join OrderProduct on ProviderProduct.codeProduct = OrderProduct.codeProduct

Select nameProvider,Sum(quantityOrder) as SumProvider
From ProviederOrderProduct
Group by nameProvider
