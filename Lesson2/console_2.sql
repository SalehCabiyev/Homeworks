create database Academy
use Academy
create table Groups(
    [id] int identity(1,1) primary key,
    [name] nvarchar(10) not null check (name<>'')unique,
    [Rating] int not null check (Rating>=0 and Rating<=5),
    [year] int not null check (year>=1 and year<=5),
)
create table Department(
    [id] int identity (1,1) primary key ,
    [Financing] money not null check (Financing>=0) default 0,
    [name] nvarchar(100) not null check (name<>'')unique
)
create table Teachers(
    [id] int identity (1,1) primary key,
    [EmploymentDate] date not null check (EmploymentDate>='01.01.1990'),
    [Name] nvarchar(max)not null check (Teachers.Name<>''),
    [Premium] money not null check (Premium>=0) default 0,
    [Salary] money not null check (Salary>0),
    [Surname] nvarchar(max) not null check (Surname<>''),

)
