Create database SeaBattle
go

	Use SeaBattle
go

	Create table Battles
		( Cod_Bat int primary key,
		  Name_Bat varchar (35),
		  Data_S date,
		  Data_N date)
go

	INSERT INTO Battles (Cod_Bat, Name_Bat, Data_S, Data_N) 
		VALUES ( 10, 'North Atlantic','1941-05-24', '1941-05-27'),
			   ( 20, 'Guadacanal','1942-11-15', '1942-11-15'),
			   ( 30, 'North Cape','1943-12-26', '1943-12-26'),
		   	   ( 40, 'Surigao Strait','1944-10-25','1944-10-25')
go

	SELECT *FROM Battles
go

	Create table Classes
		( Cod_Cl int primary key,
		  Name_Cl varchar (25),
		  Typ_Cl char (2),
		  Country varchar (25),
		  Num_Guns int,
		  Bore int, 
		  Displacement int)
go

	INSERT INTO Classes (Cod_Cl, Name_Cl, Typ_Cl, Country, Num_Guns, Bore, Displacement)
		VALUES ( 01, 'Bismark', 'bb', 'Germany', 8, 15, 42000),
			   ( 02, 'Iowa', 'bb', 'USA', 9, 16, 46000),
			   ( 03, 'Kongo', 'bc', 'Japan', 8, 14, 32000),
			   ( 04, 'North California', 'bb', 'USA', 9, 16, 37000),
			   ( 05, 'Renown', 'bc', 'Gt. Britain', 6, 15, 32000),
			   ( 06, 'Revenge', 'bb', 'Gt. Britain', 8, 15, 29000),
			   ( 07, 'Tennessee', 'bb', 'USA', 12, 14, 32000),
			   ( 08, 'Yamato', 'bb', 'Japan', 9, 18, 65000) 
go

	SELECT *FROM Classes
go


	Create table Result 
		( Cod_R int primary key,
		  Name_R varchar (7) )
go

	INSERT INTO Result (Cod_R, Name_R)
		VALUES ( 1, 'Sunk'),
			   ( 2, 'Ok'),
			   ( 3, 'Damaget')
go

	SELECT *FROM Result
go


	Create table Ships 
		( Cod_Ship int primary key,
		  Cod_Cl int foreign key references Classes(Cod_Cl),
		  Launched int,
		  Name_Ship varchar (20) )
go

	INSERT INTO Ships (Cod_Ship, Cod_Cl, Launched, Name_Ship)
		VALUES ( 01, 01, 1921, 'California'),
			   ( 02, 02, 1915, 'Haruna'),
			   ( 03, 03, 1914, 'Hiei'),
			   ( 04, 06, 1943, 'Iowa'),
			   ( 05, 08, 1915, 'Kirishima'),
			   ( 06, 08, 1913, 'Komgo'),
			   ( 07, 08, 1944, 'Missouri'),
			   ( 08, 06, 1942, 'Mussashi'),
			   ( 09, 04, 1943, 'New Jersey'), 
			   ( 10, 05, 1941, 'North California'),
			   ( 11, 06, 1917, 'Ramillies'),
			   ( 12, 07, 1916, 'Renown'),
			   ( 13, 07, 1916, 'Repulse'),
			   ( 14, 08, 1916, 'Resolution'),
			   ( 15, 02, 1916, 'Royal Oak'),
			   ( 16, 01, 1916, 'Royal Sovereigh'),
			   ( 17, 01, 1920, 'Tennesse'),
			   ( 18, 03, 1941, 'Washington'),
			   ( 19, 04, 1944, 'Wisconsin'),
			   ( 20, 04, 1941, 'Yamato')
go

	SELECT *FROM Ships
go

Drop table Ships
go
Drop table Classes
go
Drop table Outcomes
go
Drop table Battles
go


	Create table Outcomes 
		( Cod_Ship int foreign key references Ships(Cod_Ship),
		  Cod_Bat int foreign key references Battles(Cod_Bat),
		  Cod_R int foreign key references Result(Cod_R))
go
	  
	INSERT INTO Outcomes(Cod_Ship, Cod_Bat, Cod_R)
		VALUES ( 01, 10, 1),
			   ( 02, 20, 2),
			   ( 03, 10, 3),
			   ( 04, 10, 1),
			   ( 05, 20, 1),
			   ( 06, 20, 2),
			   ( 07, 10, 2),
			   ( 08, 30, 1),
			   ( 09, 40, 3),
			   ( 10, 40, 3),
			   ( 11, 40, 3),
			   ( 12, 30, 1),
			   ( 09, 30, 2),
			   ( 14, 30, 2),
			   ( 15, 10, 3)
go

	SELECT *FROM Outcomes
go

drop table Outcomes

Select s1.Country
From Classes as s1, Classes as s2
Where (s1.Country = s2.Country) and (s1.Typ_Cl='bb') and (s2.Typ_Cl='bc')

Select Distinct Ships.Name_Ship 
From Outcomes as s1, Outcomes as s2, Ships
Where (s1.Cod_Ship=Ships.Cod_Ship) and
      (s1.Cod_Bat!=s2.Cod_Bat) and
	  (s1.Cod_Ship=s2.Cod_Ship) and
	  ((s1.Cod_R=3) or (s2.Cod_R=3)) 

Select Classes.Country
From Classes 
Where (Classes.Num_Guns =All (Select max(Classes.Num_Guns)
							  From Classes))

Select Battles.Name_Bat
From Battles, Outcomes
Where (Battles.Cod_Bat = Outcomes.Cod_Bat) and
      (Outcomes.Cod_Ship in ( Select Ships.Cod_Ship
							From Ships, Classes
							Where (Ships.Cod_Cl=Classes.Cod_Cl) and
							      (Classes.Name_Cl='Kongo')))

(Select Country
From Classes
Where Typ_Cl='bb')
intersect
(Select Country
From Classes
Where Typ_Cl='bc')


Select Name_Cl
From Classes
Where Cod_Cl in (Select Cod_Cl
				From Ships
				Where Cod_Ship in (Select Cod_Ship
								  From Outcomes 
								  Where Cod_R = 3))

	SELECT *FROM Outcomes
go

	SELECT Cod_Ship, Cod_Cl FROM Ships
go



Select Name_Ship
From Ships
Where Cod_Cl in (Select Cod_Cl
				 From Classes as Cl
				 Where (Num_Guns >=All (Select Num_Guns
										From Classes
										Where Displacement in (Select Displacement
																	 From Classes))))



Select Name_CL, min(launched)
From Classes, Ships
Where Classes.Cod_CL = Ships.Cod_Cl
Group by Name_Cl

Select Name_Cl, count(*)
From Classes, Ships
Where (Classes.Cod_Cl=Ships.Cod_Cl) and
	   (Ships.Cod_Ship in (Select Cod_Ship
						From Outcomes
						Where Cod_R=3))
Group by Name_Cl


Select Name_Cl, count(*) as CountClass
From Classes, Ships
Where Classes.Cod_Cl=Ships.Cod_Cl
Group by Name_Cl



Select Name_Bat, count(*) as CountOfKills
From Battles, Outcomes
Where (Battles.Cod_Bat = Outcomes.Cod_Bat) and
	  (Cod_R=3)
Group by Name_Bat




Select Country
From Classes, Outcomes
Where (Outcomes.Cod_Ship in (Select Cod_Ship
							  From Ships)) and (Cod_R<>1) and 
	   (Classes.Cod_Cl in (Select Cod_Cl
						   From Ships))
Group by Country


Select Distinct Country
From Classes
Where Cod_Cl in (Select Cod_Cl
				 From Ships 
				 Where Cod_Ship in (Select Cod_Ship
									From Outcomes
									Where Cod_R<>1))
								