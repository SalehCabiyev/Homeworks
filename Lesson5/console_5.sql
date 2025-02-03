CREATE DATABASE Academy3
use Academy3
create table Departments(
    Id int identity (1,1)not null primary key ,
    Financing money not null check (Financing>=0)default 0,
    Name nvarchar(100)not null check (Name<>'')unique

)
create table Faculties(
    Id int identity (1,1)not null primary key ,
    Dean nvarchar(max)not null check (Dean<>''),
    Name nvarchar(100)not null check (Name<>'')unique ,

)
create table Groups(
    Id int identity (1,1) not null primary key ,
    Name nvarchar(10)not null check (Name<>'')unique ,
    Rating int not null check (Rating>=0 and Rating<=5),
    Year int not null check (Year>=1 and Year<=5),

)
create table Teachers(
    Id int identity (1,1)not null primary key ,
    EmploymentDate date not null check (EmploymentDate>='01.01.1990'),
    IsAssistant bit not null default 0,
    IsProfessor bit not null default 0,
    Name nvarchar(max)not null check (Name<>''),
    Position nvarchar(max)not null check (Position<>''),
    Premium money not null check (Premium>=0)default 0,
    Salary money not null check (Salary>0),
    Surname nvarchar(max) not null check (Surname<>'')
)
INSERT INTO Departments(Financing, Name)
VALUES (100000,N'Computer Science'),
       (50000, N'Mathematics'),
        (70000, N'Physics'),
        (30000, N'Chemistry');
INSERT INTO Faculties (Dean, Name)
VALUES
(N'Dr. John Smith', N'Faculty of Science'),
(N'Dr. Emily Johnson', N'Faculty of Engineering'),
(N'Dr. Michael Brown', N'Faculty of Arts');

INSERT INTO Groups (Name, Rating, Year)
VALUES
(N'CS101', 4, 1),
(N'CS102', 5, 2),
(N'CS103', 3, 3),
(N'MAT101', 4, 1),
(N'PHY101', 5, 1);

INSERT INTO Teachers (EmploymentDate, IsAssistant, IsProfessor, Name, Position, Premium, Salary, Surname)
VALUES
('2005-09-01', 0, 1, N'John', N'Professor', 5000, 75000, N'Smith'),
('2010-03-15', 1, 0, N'Emily', N'Assistant', 2000, 40000, N'Johnson'),
('2015-06-30', 1, 0, N'Michael', N'Assistant', 1500, 35000, N'Brown'),
('2000-01-20', 0, 1, N'Sarah', N'Professor', 6000, 80000, N'Davis');

--1
SELECT Name,Financing,Id from Departments;
--2
SELECT
    Groups.Name AS [Group Name],
    Groups.Rating AS [Group Rating]
FROM Groups
--3
    SELECT
    Surname AS [Teacher Surname],
    (Premium / Salary) * 100 AS [Premium Percentage],
    ((Salary + Premium) / Salary) * 100 AS [Total Salary Percentage]
FROM Teachers;
--4
SELECT
    'The dean of faculty ' + Name + ' is '+ Dean+ ' . ' AS [Faculty info]
FROM Faculties;
--5
SELECT
    Surname
    FROM Teachers
WHERE IsProfessor=1 AND Salary>1050;
--6
SELECT Name FROM Departments WHERE Financing<11000 OR Financing>25000;
--7
SELECT Name FROM Faculties WHERE Name<>'Faculty of Science';
--8
SELECT Surname,Position FROM Teachers WHERE Position<>'Professor';
--9
SELECT Surname,Position,Salary,Premium
FROM Teachers WHERE IsAssistant=1 AND Premium BETWEEN 160 AND 550;
--10
SELECT Surname,Salary
FROM Teachers WHERE IsAssistant=1;
--11
SELECT Surname,Position
FROM Teachers WHERE EmploymentDate<'01.01.2000';
--12
SELECT
    Name AS [Name of Department]
FROM Departments
WHERE Name<'Mathematics'
ORDER BY Name;
--13
SELECT Surname
FROM Teachers WHERE IsAssistant=1 AND (Salary+Premium)<=1200;
--14
SELECT Name
FROM Groups WHERE Year=5 AND Rating BETWEEN 2 AND 4;
--15
SELECT Surname
FROM  Teachers  WHERE IsAssistant = 1 AND Salary<550 OR Premium<200;





