create database Academy2
use Academy2
create table Curators(
    Id int identity (1,1) not null primary key ,
    Name nvarchar(max) not null check (Name<>''),
    Surname nvarchar(max) not null check (Surname<>'')
)
create table Departments(
    Id int identity (1,1) not null  primary key ,
    Financing money not null check (Financing>=0) default 0,
    Name nvarchar(100) not null check (Name<>'')unique ,
    FacultyId int not null ,
    FOREIGN KEY (FacultyId)references Faculties(Id)


)
create table Faculties(
    Id int identity (1,1) not null PRIMARY KEY ,
    Financing money not null check (Financing>=0)default 0,
    Name nvarchar(100) not null check (Name<>'')unique
)
create table Groups(
    Id int  identity (1,1)not null PRIMARY KEY ,
    Name nvarchar(10)not null check (Name<>'')unique ,
    [Year] int not null check (Year>=1 and Year<=5),
    DepartmentId int not null ,
    foreign key (DepartmentId)references Departments(Id)
)
create  table GroupsCurators(
    Id int not null identity (1,1) primary key ,
    CuratorId int not null ,
    foreign key (CuratorId)references Curators(Id),
    GroupId int not null foreign key references Groups(Id)

)
create table GroupsLectures(
    Id int identity (1,1)not null primary key ,
    GroupId int not null FOREIGN key references Groups(Id),
    LectureId int not null foreign key references Lectures(Id)
)
create table Lectures(
    Id int not null identity (1,1)primary key ,
    LectureRoom nvarchar(max) not null check (Lectures.LectureRoom<>''),
    SubjectId int not null foreign key references Subjects(Id),
    TeacherId int not null foreign key references Teachers(Id)
)
create table Subjects(
    Id int identity (1,1)not null primary key ,
    Name nvarchar(100) not null  unique check (Name<>''),

)
create table Teachers(
    Id int not null identity (1,1)primary key ,
    Name nvarchar(max)not null check (Name<>''),
    Salary money not null check (Salary>0),
    Surname nvarchar(max)not null check (Surname<>''),
)




INSERT INTO Faculties (Financing, Name)
VALUES
(1000000, N'Инженерный факультет'),
(500000, N'Факультет информатики'),
(750000, N'Филологический факультет');


INSERT INTO Subjects (Name)
VALUES
(N'Математика'),
(N'Программирование'),
(N'Литература'),
(N'Физика');


INSERT INTO Teachers (Name, Salary, Surname)
VALUES
(N'Иван', 45000, N'Иванов'),
(N'Алексей', 50000, N'Алексеев'),
(N'Марина', 60000, N'Маринина'),
(N'Никита', 55000, N'Никитин');

INSERT INTO Curators (Name, Surname)
VALUES
(N'Сергей', N'Сергеев'),
(N'Елена', N'Еленова');


INSERT INTO Departments (Financing, Name, FacultyId)
VALUES
(200000, N'Кафедра прикладной математики', 1),
(150000, N'Кафедра программирования', 2),
(100000, N'Кафедра филологии', 3);


INSERT INTO Groups (Name, [Year], DepartmentId)
VALUES
(N'Группа 101', 1, 1),
(N'Группа 102', 2, 2),
(N'Группа 103', 3, 3);



INSERT INTO GroupsCurators (CuratorId, GroupId)
VALUES
(1, 1),  -- CuratorId = 1 ссылается на 'Сергей Сергеев', GroupId = 1 ссылается на 'Группа 101'
(2, 2);  -- CuratorId = 2 ссылается на 'Елена Еленова', GroupId = 2 ссылается на 'Группа 102'




INSERT INTO Lectures (LectureRoom, SubjectId, TeacherId)
VALUES
(N'Аудитория 101', 1, 1),
(N'Аудитория 102', 2, 2),
(N'Аудитория 103', 3, 3);




INSERT INTO GroupsLectures (GroupId, LectureId)
VALUES
(1, 1),  -- GroupId = 1 ссылается на 'Группа 101', LectureId = 1 ссылается на 'Аудитория 101'
(2, 2),  -- GroupId = 2 ссылается на 'Группа 102', LectureId = 2 ссылается на 'Аудитория 102'
(3, 3);  -- GroupId = 3 ссылается на 'Группа 103', LectureId = 3 ссылается на 'Аудитория 103'


SELECT
    Teachers.Name AS TeacherName,
    Teachers.Surname AS TeacherSurname,
    Groups.Name AS GroupName
FROM Teachers
JOIN Lectures ON Teachers.Id = Lectures.TeacherId
JOIN GroupsLectures ON Lectures.Id = GroupsLectures.LectureId
JOIN Groups ON GroupsLectures.GroupId = Groups.Id;


select
    Faculties.Name as FacultiesName,
    Departments.Financing as DepartmentsFinansing
from Faculties
JOIN Departments ON Faculties.Id = Departments.FacultyId
where Departments.Financing > Faculties.Financing;

select
    Curators.Surname as CuratorsSurname,
    Groups.Name as GroupsName
from Curators
join GroupsCurators on Curators.Id = GroupsCurators.CuratorId
join Groups on Groups.Id=GroupsCurators.GroupId

select
    Teachers.Name as Teachersname,
    Teachers.Surname as Teacherssurname
from Teachers
join Lectures on Teachers.Id = Lectures.TeacherId
join GroupsLectures on Lectures.Id = GroupsLectures.LectureId
join Groups on GroupsLectures.GroupId = Groups.Id
where Groups.Name=N'Группа 101';

SELECT distinct
    Teachers.Surname AS TeacherSurname,
    Faculties.Name AS FacultyName
FROM Teachers
JOIN Lectures ON Teachers.Id = Lectures.TeacherId
JOIN Subjects ON Lectures.SubjectId = Subjects.Id
JOIN Departments ON Subjects.Id = Departments.Id
JOIN Faculties ON Departments.FacultyId = Faculties.Id;

--6
select
    Departments.Name as departmentsname,
    Groups.Name as groupsname
from Departments
join Groups  on Departments.Id = Groups.DepartmentId


--7
SELECT
    S.Name as Subjectname
from Teachers
join Lectures L  on Teachers.Id = L.TeacherId
join Subjects S on S.Id = L.SubjectId
WHERE Teachers.Name=N'Иван' and Teachers.Surname=N'Иванов';
--8
SELECT
    D.Name as Deparmentname
from Subjects
JOIN Lectures L on Subjects.Id = L.SubjectId
JOIN GroupsLectures GL on L.Id = GL.LectureId
JOIN Groups G on GL.GroupId = G.Id
JOIN Departments D on G.DepartmentId = D.Id
where Subjects.Name=N'Программирование'
--9
SELECT
    G.Name as Groupname
FROM Faculties
JOIN Departments D on Faculties.Id = D.FacultyId
JOIN Groups G on D.Id = G.DepartmentId
WHERE Faculties.Name=N'Инженерный факультет'
--10
SELECT
    Groups.Name as Groupname,
    F.Name as Facultiesname
from Groups
JOIN Departments D on Groups.DepartmentId = D.Id
JOIN Faculties F on D.FacultyId = F.Id
WHERE Groups.Year=2
--11
SELECT
    Teachers.Name AS Teachersname,
    L.Id as LecturesiD,
    S.Name as Subjectname,
    G.Name as Groupname
from Teachers
join Lectures L on Teachers.Id = L.TeacherId
join GroupsLectures GL on L.Id = GL.LectureId
join Groups G on GL.GroupId = G.Id
join Subjects S on L.SubjectId = S.Id
WHERE LectureRoom=N'Аудитория 101'











