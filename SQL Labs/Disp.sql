create database Disp 
go 
alter authorization on database :: Disp to sa 
use Disp 
go 
create table Pacient( P_ID int primary key, P_IDPN char(13), P_Name varchar(30), p_Adress varchar(20), P_Uchastok varchar(20), P_Number varchar(20)) 
go 
create table Doktor(D_ID int primary key, D_Name varchar(30), D_Adress varchar(20), D_Number varchar(20), D_Uchastok varchar(20)) 
go 
create table Remedies(R_ID int primary key, R_Name varchar(30), R_Forma varchar(30), R_Massa int, R_Price decimal(5, 2)) 
go 
create table Diagnoz(DI_ID int primary key, DI_Description varchar(300)) 
go 
create table Recepy(RE_ID int primary key, R_ID int foreign key references Remedies(R_ID), RE_Doza int) 
go 
create table Priem(D_ID int foreign key references Doktor(D_ID),
 P_ID int foreign key references Pacient(P_ID), 
 PR_Date date, 
 DI_ID int foreign key references Diagnoz(DI_ID), 
 RE_ID int unique references Recepy(RE_ID)) 
go

Drop table Pacient
Drop table Doktor
Drop table Remedies
Drop table Diagnoz
Drop table Recepy
Drop table Priem

Select D_Id, count(*)
From Priem, Pacient
Where (Priem.P_Id=Pacient.P_Id) and 
	  (PR_Date='2018.10.29')
Group by D_Id