create database Vidioteca
go
use Vidioteca 
go
create type allNames from varchar(20)
go
create table MovieStar 
(
codStar int primary key,
NameStar allNames,
Adres allNames,
Gender char(1),
Birthday date default '0000-00-00'
)
go

create table MovieExec
(
prodC int primary key,
nameProd allNames,
Adres allNames,
Networth int,
)
go

create table Studio
(
codStudio int primary key,
NameSudio allNames,
Adres allNames,
ProdC int foreign key references MovieExec(prodC)
)
go

create table Movie
(
codM int primary key,
Title allNames,
YearM int,
Lenght int,
Incolor char(1),
CodStudio int foreign key references Studio(codStudio),
prodC int foreign key references MovieExec(prodC)
)
go
create table StarSln
(
codM int foreign key references Movie(codM),
codStar int foreign key references MovieStar(codStar)
)
go


Insert into MovieStar(codStar, NameStar, Adres, Gender, Birthday)values(1, 'Alec Baldwin', 'New York', 'M', '1967-12-12')
go
Insert into MovieStar(codStar, NameStar, Adres, Gender, Birthday)values(10, 'Gillian Kearney', 'New York', 'F', '1974-09-25')
go
Insert into MovieStar(codStar, NameStar, Adres, Gender, Birthday)values(11, 'Hugh Grant', 'Los-Angeles', 'M', '1980-11-17')
go
Insert into MovieStar(codStar, NameStar, Adres, Gender, Birthday)values(12, 'Jesse Bradford', 'Hollywood', 'F', '1967-07-04')
go
Insert into MovieStar(codStar, NameStar, Adres, Gender, Birthday)values(13, 'JoaNA Cassidy', 'New York', 'F', '1967-12-29')
go
Insert into MovieStar(codStar, NameStar, Adres, Gender, Birthday)values(14, 'John Lone', 'Los-Angeles', 'M', '1980-12-18')
go
Insert into MovieStar(codStar, NameStar, Adres, Gender, Birthday)values(15, 'Jonathan Broke', 'Hollywood', 'M', '1967-01-30')
go
Insert into MovieStar(codStar, NameStar, Adres, Gender, Birthday)values(16, 'Jude Law', 'Los-Angeles', 'M', '1977-09-25')
go
Insert into MovieStar(codStar, NameStar, Adres, Gender, Birthday)values(17, 'Julia Roberts', 'New York', 'F', '1982-12-18')
go
Insert into MovieStar(codStar, NameStar, Adres, Gender, Birthday)values(18, 'Kate Winslet', 'Hollywood', 'F', '1979-10-15')
go
Insert into MovieStar(codStar, NameStar, Adres, Gender, Birthday)values(19, 'Molly Parker', 'Hollywood', 'M', '1974-01-20')
go
Insert into MovieStar(codStar, NameStar, Adres, Gender, Birthday)values(2, 'Angus MacFadyen', 'New York', 'M', '1969-07-04')
go
Insert into MovieStar(codStar, NameStar, Adres, Gender, Birthday)values(20, 'Nicolas Cage', 'New York', 'M', '1969-03-04')
go
Insert into MovieStar(codStar, NameStar, Adres, Gender, Birthday)values(21, 'Penelope Ann Miller', 'Los-Angeles', 'F', '1970-09-25')
go
Insert into MovieStar(codStar, NameStar, Adres, Gender, Birthday)values(22, 'Robin Williams', 'Los-Angeles', 'M', '1980-12-18')
go
Insert into MovieStar(codStar, NameStar, Adres, Gender, Birthday)values(23, 'Shiri Appleby', 'New York', 'F', '1969-07-04')
go
Insert into MovieStar(codStar, NameStar, Adres, Gender, Birthday)values(24, 'Tobin Bell', 'Hollywood', 'M', '1983-12-14')
go
Insert into MovieStar(codStar, NameStar, Adres, Gender, Birthday)values(25, 'Maxim Rusnak', 'Chisinau', 'M', '1983-12-14')
go
Insert into MovieStar(codStar, NameStar, Adres, Gender, Birthday)values(26, 'Valeria Petrova', 'Chisinau', 'F', '1983-12-14')
go



Insert into MovieExec(prodC, nameProd, Adres, Networth)values(10000,'Neil LaBute','Hollywood', 900000)
go
Insert into MovieExec(prodC, nameProd, Adres, Networth)values(10100,'David Mamet','New York', 1300000)
go
Insert into MovieExec(prodC, nameProd, Adres, Networth)values(10941,'Marlowe Fawcett','Hollywood', 756000)
go
Insert into MovieExec(prodC, nameProd, Adres, Networth)values(10975,'Woody Allen','Hollywood', 800000)
go
Insert into MovieExec(prodC, nameProd, Adres, Networth)values(10987,'Darren Lynn Bousman','New York', 1000000)
go
Insert into MovieExec(prodC, nameProd, Adres, Networth)values(11000,'Nancy Meyers','Hollywood', 1240000)
go
Insert into MovieExec(prodC, nameProd, Adres, Networth)values(11345,'Robert Zemeckis','Dallas', 25000000)
go
Insert into MovieExec(prodC, nameProd, Adres, Networth)values(11789,'Russell Mulcahy','Hollywood', 700000)
go
Insert into MovieExec(prodC, nameProd, Adres, Networth)values(12000,'John Polson','Hollywood', 600000)
go
Insert into MovieExec(prodC, nameProd, Adres, Networth)values(12536,'Roger Michell','Detroid', 600000)
go
Insert into MovieExec(prodC, nameProd, Adres, Networth)values(14675,'Shawn Levy','Hollywood', 1800000)
go



Insert into Studio(codStudio, NameSudio, Adres,ProdC)values(1,'20th Century Fox','Columbia', 10975)
go
Insert into Studio(codStudio, NameSudio, Adres,ProdC)values(3,'Columbia Pictures','Hollywood', 10941)
go
Insert into Studio(codStudio, NameSudio, Adres,ProdC)values(5,'Paramount Pictures','Hollywood', 12536)
go
Insert into Studio(codStudio, NameSudio, Adres,ProdC)values(9,'Warner Bros.','Hollywood', 14675)
go



Insert into Movie(codM, Title, YearM, Lenght, Incolor, CodStudio, prodC)values(1, 'Mighty Afrodite', 1995, 95, 'c', 1, 10975)
go
Insert into Movie(codM, Title, YearM, Lenght, Incolor, CodStudio, prodC)values(2, 'Night at the museum', 2006, 104, 'c', 3, 14675)
go
Insert into Movie(codM, Title, YearM, Lenght, Incolor, CodStudio, prodC)values(3, 'Notting hill', 1999, 115, 'c', 1, 12536)
go
Insert into Movie(codM, Title, YearM, Lenght, Incolor, CodStudio, prodC)values(4, 'Saw III', 2006, 112, 'c', 9, 10987)
go
Insert into Movie(codM, Title, YearM, Lenght, Incolor, CodStudio, prodC)values(5, 'State the Main', 2000, 101, 'c', 5, 10100)
go
Insert into Movie(codM, Title, YearM, Lenght, Incolor, CodStudio, prodC)values(6, 'Swimfan', 2002, 84, 'c', 9, 12000)
go
Insert into Movie(codM, Title, YearM, Lenght, Incolor, CodStudio, prodC)values(7, 'The Holliday', 2006, 132, 'c', 3, 11000)
go
Insert into Movie(codM, Title, YearM, Lenght, Incolor, CodStudio, prodC)values(8, 'The other Half', 2006, 96, 'c', 9, 10941)
go
Insert into Movie(codM, Title, YearM, Lenght, Incolor, CodStudio, prodC)values(9, 'The Shadow', 1994, 102, 'c', 1, 11789)
go
Insert into Movie(codM, Title, YearM, Lenght, Incolor, CodStudio, prodC)values(10, 'The Wicker Man', 2006, 97, 'c', 3, 10000)
go
Insert into Movie(codM, Title, YearM, Lenght, Incolor, CodStudio, prodC)values(11, 'Who Framed Roger Rabbit', 1988, 99, 'c', 9, 11345)
go
Insert into Movie(codM, Title, YearM, Lenght, Incolor, CodStudio, prodC)values(12, 'TOR', 2001, 115, 'c', 1, 12536)
go

Drop Table Movie
Drop Table Studio
Drop Table MovieExec
Drop Table StarSln



Insert into StarSln(codM, codStar)values(3, 11)
go
Insert into StarSln(codM, codStar)values(4, 12)
go



select * from MovieStar
go
select * from MovieExec
go
select * from Studio
go
select * from Movie
go
select * from StarSln
go

--Укажите пары актёров состоящих проживающих по одному адресу
Select M1.NameStar, M2.NameStar
From MovieStar as M1, MovieStar as M2
Where M1.CodStar in (Select CodStar
				   From MovieStar
				   Where Gender = 'M') and
	  M2.CodStar in (Select CodStar
					From MovieStar
					Where Gender = 'F') and
	 M1.Adres=M2.Adres


--Фильмы длинее The Shadow
Select Title, Lenght
From Movie
Where Lenght >All(Select Lenght
				  From Movie
				  Where Title = 'The Shadow')

--Указать продолжительность фильмов только для продюсеров выпустивших хотя бы один свой фильм до 2000 года
Create view ProdStudioInfo AS
Select nameProd, MovieExec.Adres as ProdAdres, Networth, codStudio, NameSudio, Studio.Adres as StudioAdres
From MovieExec inner join Studio on MovieExec.ProdC = Studio.ProdC

Create view ProdStudioMovieInfo as
Select nameProd, ProdAdres, Networth, NameSudio, StudioAdres, Title, YearM, Lenght, Incolor
From ProdStudioInfo inner join Movie on ProdStudioInfo.codStudio = Movie.CodStudio

Create view ProdMmovieEarlier2000 as
Select MovieExec.prodC, Title, YearM, Lenght
From MovieExec inner join Movie on MovieExec.prodC = Movie.prodC
Where YearM<2000


Select * From ProdStudioInfo
Select * From ProdStudioMovieInfo
Select * From ProdMmovieEarlier2000


Select Title, Lenght, YearM
From Movie
Where prodC in (Select prodC
				From ProdMmovieEarlier2000) AND YearM>2000

Select Title, Lenght, YearM
From ProdStudioMovieInfo
Group by Title, Lenght, YearM
Having min(YearM)<2000

Select nameProd, count(*) as CountMovie
From MovieExec, Movie
Where MovieExec.prodC=Movie.prodC
Group by nameProd
Having min(Yearm)<2000


create view SudioMovieInfo as
Select Title, YearM, NameSudio
From Movie inner join Studio on Movie.CodStudio = Studio.CodStudio

Select NameSudio, min(YearM)
From SudioMovieInfo
Group by NameSudio






