Create database CreditCard
go

Use CreditCard
go

Create table Person (CodPers char(3) primary key,
					 NamePers varchar(30),
					 IDNP char(9),
					 AdresPers varchar(40),
					 MobilPers char(9),
					 MailPers varchar(25),
					 DatePers Date default '00-00-0000')
go

Create table CreditCardT(CodCard char(3) primary key,
						 EndDate Date default '00-00-0000',
						 CVV char(16),
						 PinCod char(4))
go

Create table PersCredit(CodPers char(3) foreign key references Person(CodPers),
						CodCard char(3) unique references CreditCardT(CodCard),
						SumCard int, 
						DatePersCard Date default '00-00-0000')
go




Insert into Person(CodPers, NamePers, IDNP, AdresPers, MobilPers, MailPers, DatePers) values
				  (100, 'Жуков Иван Станиславович', 987654321, 'Молдова, Кишинёв', 069654882, 'Jukov@mail.ru', '20-12-1995'),
				  (101, 'Федотов Родион Глебович', 213456789, 'Молдова, Кишинёв', 069654112, 'Fedot@mail.ru', '12-04-1998'),
				  (102, 'Зуев Орест Максимович', 120345689, 'Молдова, Кишинёв', 069654887, 'Zuev@mail.com', '05-09-1994'),
				  (103, 'Сидоров Корнелий Юрьевич', 215674895, 'Молдова, Кишинёв', 069654112, 'Sidr@gmail.com', '04.03.2000')
 go

 Insert into CreditCardT (CodCard, EndDate, CVV, PinCod) values
						(900, '10-10-2021', 1234567899876542, 5544),
						(901, '11-11-2022', 5478413602145876, 4455),
						(902, '12-12-2023', 4150212021487564, 4545),
						(903, '09-09-2024', 5748425423645975, 5454)
go

Insert into PersCredit(CodPers, CodCard, SumCard, DatePersCard) values
					  (100, 900, 1000, '11-04-2019'),
					  (101, 901, 2000, '11-04-2019'),
					  (102, 902, 3000, '11-04-2019'),
					  (103, 903, 4000, '11-04-2019')
go

ROLLBACK
GO
