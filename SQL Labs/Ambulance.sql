Create database Ambulance
Use Ambulance

create table Pacient (Cod_Patient int primary key, 
					  Name_Patient varchar(30),
					  Adres_Patient varchar(40),
					  Phone_Patient int,
					  Section_Patient int)

Create table Priem (Cod_Priem int,
					Data_Priem date default '0000-00-00',
					Time_Priem time default '00:00',
					Cod_Patient int foreign key references Pacient(Cod_Patient),
					Name_Doctor varchar(30),
					Diagnoz varchar(50),
					Recept varchar(50))

Insert into Pacient (Cod_Patient, Name_Patient, Adres_Patient, Phone_Patient, Section_Patient) values
				(001,'Запорожан Александр', 'Молдова, Льова', 069725648, 100),
				(002, 'Морару Александр', 'Молдова, Комрат', 069754216, 200),
				(003, 'Перевалов Иван', 'Молдова, Чимишлия', 065478123, 100),
				(004, 'Манаф Анастасия', 'Молдова, Чимишлия', 068452162, 100),
				(005, 'Перепелица Александр', 'Молдова, Кишинёв', 069874236, 200)

Insert into Priem (Cod_Priem, Data_Priem, Time_Priem, Cod_Patient, Name_Doctor, Diagnoz, Recept) values
				  (1, '2019-04-17', '10:10:00', 001, 'Сырбу Александр', 'Сахарный диабет', 'Антибиотики'),
				  (2, '2019-04-17', '11:00:00', 002, 'Пиманова Яна', 'Запор', 'Здоровое питание'),
				  (3, '2019-04-18', '12:00:00', 001, 'Сырбу Александр', 'Сахарный диабет', 'Полное обследование'),
				  (4, '2019-04-18', '13:00:00', 004, 'Сырбу Александр', 'Боль сердца', 'Полное обследование'),
				  (5, '2019-04-18', '15:00:00', 005, 'Пиманова Яна', 'Операция на череп', 'Полное обследование')


Select * From Pacient
Select * From Priem