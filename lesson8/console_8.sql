-- Создаем базу данных
CREATE DATABASE University;
GO

USE University;
GO

-- Таблица студентов
CREATE TABLE Students (
    StudentId INT PRIMARY KEY IDENTITY(1,1),
    FirstName NVARCHAR(50),
    LastName NVARCHAR(50),
    AverageGrade DECIMAL(3,2)
);
GO

-- Таблица групп
CREATE TABLE Groups (
    GroupId INT PRIMARY KEY IDENTITY(1,1),
    GroupName NVARCHAR(50),
    StudentsCount INT
);
GO

-- Таблица курсов
CREATE TABLE Courses (
    CourseId INT PRIMARY KEY IDENTITY(1,1),
    CourseName NVARCHAR(100)
);
GO

-- Таблица курсов для студентов с GroupId
CREATE TABLE StudentGroups (
    StudentId INT,
    GroupId INT,
    PRIMARY KEY (StudentId, GroupId),
    FOREIGN KEY (StudentId) REFERENCES Students(StudentId),
    FOREIGN KEY (GroupId) REFERENCES Groups(GroupId)
);
GO

-- Таблица курсов для студентов
CREATE TABLE StudentCourses (
    StudentId INT,
    CourseId INT,
    PRIMARY KEY (StudentId, CourseId),
    FOREIGN KEY (StudentId) REFERENCES Students(StudentId),
    FOREIGN KEY (CourseId) REFERENCES Courses(CourseId)
);
GO

-- Таблица оценок
CREATE TABLE Grades (
    GradeId INT PRIMARY KEY IDENTITY(1,1),
    StudentId INT,
    CourseId INT,
    Grade DECIMAL(3,2),
    FOREIGN KEY (StudentId) REFERENCES Students(StudentId),
    FOREIGN KEY (CourseId) REFERENCES Courses(CourseId)
);
GO

-- Таблица предупреждений
CREATE TABLE Warnings (
    WarningId INT PRIMARY KEY IDENTITY(1,1),
    StudentId INT,
    Reason NVARCHAR(255),
    Date DATETIME,
    FOREIGN KEY (StudentId) REFERENCES Students(StudentId)
);
GO

-- Таблица учителей
CREATE TABLE Teachers (
    TeacherId INT PRIMARY KEY IDENTITY(1,1),
    FirstName NVARCHAR(50),
    LastName NVARCHAR(50)
);
GO

-- Таблица курсов, привязанных к преподавателям
CREATE TABLE TeacherCourses (
    TeacherId INT,
    CourseId INT,
    PRIMARY KEY (TeacherId, CourseId),
    FOREIGN KEY (TeacherId) REFERENCES Teachers(TeacherId),
    FOREIGN KEY (CourseId) REFERENCES Courses(CourseId)
);
GO

-- Таблица посещаемости
CREATE TABLE Attendance (
    AttendanceId INT PRIMARY KEY IDENTITY(1,1),
    StudentId INT,
    Date DATETIME,
    FOREIGN KEY (StudentId) REFERENCES Students(StudentId)
);
GO

-- Таблица списка пересдач
CREATE TABLE RetakeList (
    StudentId INT,
    CourseId INT,
    FOREIGN KEY (StudentId) REFERENCES Students(StudentId),
    FOREIGN KEY (CourseId) REFERENCES Courses(CourseId)
);
GO

-- Таблица платежей
CREATE TABLE Payments (
    PaymentId INT PRIMARY KEY IDENTITY(1,1),
    StudentId INT,
    Amount DECIMAL(10,2),
    Date DATETIME,
    FOREIGN KEY (StudentId) REFERENCES Students(StudentId)
);
GO
USE University;
GO
CREATE TABLE GradeHistory (
    HistoryId INT IDENTITY(1,1) PRIMARY KEY,  -- уникальный идентификатор записи
    StudentId INT,
    CourseId INT,
    Grade DECIMAL(3,2),
    ChangeDate DATETIME
);


-- Заполнение таблицы студентов
INSERT INTO Students (FirstName, LastName, AverageGrade)
VALUES
('Ivan', 'Ivanov', 4.5),
('Petr', 'Petrov', 3.2),
('Maria', 'Sidorova', 4.0),
('Anna', 'Kuznetsova', 2.5),
('Alexey', 'Smirnov', 4.7),
('Olga', 'Mikhaylova', 5.0),
('Dmitry', 'Popov', 3.8),
('Elena', 'Vasilieva', 3.0);
GO

-- Заполнение таблицы групп
INSERT INTO Groups (GroupName, StudentsCount)
VALUES
('Group A', 7),
('Group B', 6);
GO

-- Заполнение таблицы курсов
INSERT INTO Courses (CourseName)
VALUES
('Введение в программирование'),
('Алгоритмы и структуры данных'),
('Математика для программистов'),
('Базы данных');
GO

-- Заполнение таблицы студентов и групп
INSERT INTO StudentGroups (StudentId, GroupId)
VALUES
(1, 1), (2, 1), (3, 1), (4, 1), (5, 1), (6, 1), (7, 2),
(8, 2);
GO

-- Заполнение таблицы студентов и курсов
INSERT INTO StudentCourses (StudentId, CourseId)
VALUES
(1, 1), (1, 2), (1, 3), (2, 1), (2, 4), (3, 1),
(3, 2), (4, 3), (5, 2), (6, 1), (6, 4), (7, 3),
(8, 1);
GO

-- Заполнение таблицы оценок
INSERT INTO Grades (StudentId, CourseId, Grade)
VALUES
(1, 1, 5.0), (1, 2, 4.5), (1, 3, 4.8), (2, 1, 3.0),
(2, 4, 2.5), (3, 1, 4.0), (3, 2, 4.2), (4, 3, 3.0),
(5, 2, 5.0), (6, 1, 4.9), (6, 4, 4.7), (7, 3, 3.5),
(8, 1, 3.5);
GO

-- Заполнение таблицы предупреждений
INSERT INTO Warnings (StudentId, Reason, Date)
VALUES
(2, 'Низкая оценка', CONVERT(DATETIME, '2025-02-15', 120)),
(4, 'Низкая оценка', CONVERT(DATETIME, '2025-02-15', 120));



-- Заполнение таблицы учителей
INSERT INTO Teachers (FirstName, LastName)
VALUES
('Sergey', 'Ivanov'),
('Olga', 'Petrova');
GO

-- Заполнение таблицы курсов преподавателей
INSERT INTO TeacherCourses (TeacherId, CourseId)
VALUES
(1, 1), (1, 2), (2, 3), (2, 4);
GO

-- Заполнение таблицы посещаемости
INSERT INTO Attendance (StudentId, Date)
VALUES
(1, '2025-02-01'), (1, '2025-02-02'), (2, '2025-02-01'),
(3, '2025-02-03'), (4, '2025-02-04'), (5, '2025-02-02');
GO

-- Заполнение таблицы платежей
INSERT INTO Payments (StudentId, Amount, Date)
VALUES
(1, 5000.00, CONVERT(DATETIME, '2025-01-15', 120)),
(2, 4500.00, CONVERT(DATETIME, '2025-01-15', 120)),
(3, 6000.00, CONVERT(DATETIME, '2025-01-16', 120)),
(4, 7000.00, CONVERT(DATETIME, '2025-01-20', 120));
GO


-- Заполнение таблицы списка пересдач
INSERT INTO RetakeList (StudentId, CourseId)
VALUES
(2, 1), (4, 3);
GO
--1
create trigger trg_LimitGroupSize
on StudentGroups
    after insert
    as
    begin
        DECLARE @GroupId int;
        DECLARE @StudentCount INT;
        SELECT @GroupId=GroupId FROM inserted
        SELECT @StudentCount=COUNT(*)
        FROM StudentGroups WHERE GroupId=@GroupId;
        IF @StudentCount>30
        BEGIN
            PRINT 'Группа уже полна, нельзя добавить нового студента.'
            ROLLBACK ;

        end
    end;
--2
CREATE TRIGGER trg_UpdateGroupSize
ON StudentGroups
AFTER INSERT, DELETE
AS
BEGIN
    DECLARE @GroupId INT;
    DECLARE @StudentCount INT;


    SELECT @GroupId = GroupId FROM INSERTED;
    SELECT @GroupId = GroupId FROM DELETED;


    SELECT @StudentCount = COUNT(*) FROM StudentGroups WHERE GroupId = @GroupId;
    UPDATE Groups SET StudentsCount = @StudentCount WHERE GroupId = @GroupId;
END;
GO
--3
CREATE TRIGGER AVTOREGISTER ON StudentCourses
    AFTER INSERT
    AS
    BEGIN
    DECLARE @StudentId INT;
    DECLARE @CourseId INT;
    DECLARE @ProgrammingCourseId INT;
        SELECT @StudentId=StudentId from inserted
        select @CourseId=CourseId from inserted
        select @ProgrammingCourseId=CourseId FROM Courses WHERE CourseName = 'Введение в программирование';
    if @ProgrammingCourseId is not null
        BEGIN
            INSERT INTO StudentCourses(STUDENTID, COURSEID)
           VALUES (@StudentId, @ProgrammingCourseId);
        end
    end;
--4
    CREATE TRIGGER trg_LowGradeWarning ON Grades
    AFTER INSERT ,UPDATE
    AS
        BEGIN
            declare @studentid int ;

            declare @grade decimal(3,2);
            select @grade=Grade from inserted
            select @studentid=StudentId from inserted
            if @grade<3
            begin
                insert into Warnings(StudentId,Reason,Date)
                values(@studentid,'Низкая оценка',getdate())
            end;

        end;
--5
create trigger trg_PreventTeacherDeletion on Teachers
    instead of delete
    as
    begin
        declare @teacherid int ;
        select @teacherid=TeacherId from deleted
        if exists(select 1 TeacherId from TeacherCourses where TeacherId=@teacherid)
        begin
            print 'Невозможно удалить преподавателя, так как он закреплён за курсами.'
        end
        else
        begin
            delete from Teachers
            where TeacherId=@teacherid
        end;
    end;
--6

create trigger trg_GradeHistory on Grades
    after update
    as
    begin
        declare @studentid int;
        declare @courseid int;
        declare @grade decimal(3,2);
        select @studentid=StudentId from deleted
        select @courseid= CourseId from deleted
        select @grade=Grade from deleted
        insert into GradeHistory(StudentId, CourseId, Grade, ChangeDate)
        VALUES (@studentid, @courseid, @grade, GETDATE());


    end;
--7
create trigger trg_AttendanceControl
    on Attendance
    after insert
    as
    begin
        declare @studentid int ;
        declare @count int;
        select @studentid=StudentId from inserted
         select @count= count(*)from Attendance where StudentId=@studentid
        if @count>5
        begin
            insert into RetakeList(studentid, courseid)
            select @studentid,StudentCourses.CourseId from StudentCourses where StudentId=@studentid
        end;
    end;
--8
create trigger trg_PreventStudentDeletionWithDebt on Students
    instead of delete
    as
    begin
        declare @studentid int
        select @studentid=StudentId from deleted
        if exists(select 1 from Payments where StudentId=@studentid)or
           exists(select 1 from Grades where StudentId=@studentid and Grade<3)
        begin
            print 'Невозможно удалить студента с долгами или неудовлетворительными оценками.'
        end;
        else
        begin
            delete from Students where StudentId=@studentid
        end
    end;
--9
create trigger trg_UpdateAverageGrade on Grades
    after insert ,update
    as
    begin
        declare @studentid int ;
        declare @avggrade decimal(3,2);
        select @studentid=StudentId from inserted
        select @avggrade=avg(Grade)from Grades where StudentId=@studentid
        update Students
        set AverageGrade=@avggrade where StudentId=@studentid
    end



