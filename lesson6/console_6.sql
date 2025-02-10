CREATE DATABASE Academy4
USE Academy4
CREATE TABLE Curators (
    Id INT IDENTITY PRIMARY KEY,
    Name NVARCHAR(MAX) NOT NULL,
    Surname NVARCHAR(MAX) NOT NULL
);


CREATE TABLE Departments (
    Id INT IDENTITY PRIMARY KEY,
    Building INT NOT NULL CHECK (Building BETWEEN 1 AND 5),
    Financing MONEY NOT NULL DEFAULT 0,
    Name NVARCHAR(100) NOT NULL UNIQUE,
    FacultyId INT NOT NULL,
    FOREIGN KEY (FacultyId) REFERENCES Faculties(Id)
);


CREATE TABLE Faculties (
    Id INT IDENTITY PRIMARY KEY,
    Name NVARCHAR(100) NOT NULL UNIQUE
);


CREATE TABLE Groups (
    Id INT IDENTITY PRIMARY KEY,
    Name NVARCHAR(10) NOT NULL UNIQUE,
    Year INT NOT NULL CHECK (Year BETWEEN 1 AND 5),
    DepartmentId INT NOT NULL,
    FOREIGN KEY (DepartmentId) REFERENCES Departments(Id)
);


CREATE TABLE GroupsCurators (
    Id INT IDENTITY PRIMARY KEY,
    CuratorId INT NOT NULL,
    GroupId INT NOT NULL,
    FOREIGN KEY (CuratorId) REFERENCES Curators(Id),
    FOREIGN KEY (GroupId) REFERENCES Groups(Id)
);


CREATE TABLE GroupsLectures (
    Id INT IDENTITY PRIMARY KEY,
    GroupId INT NOT NULL,
    LectureId INT NOT NULL,
    FOREIGN KEY (GroupId) REFERENCES Groups(Id),
    FOREIGN KEY (LectureId) REFERENCES Lectures(Id)
);


CREATE TABLE GroupsStudents (
    Id INT IDENTITY PRIMARY KEY,
    GroupId INT NOT NULL,
    StudentId INT NOT NULL,
    FOREIGN KEY (GroupId) REFERENCES Groups(Id),
    FOREIGN KEY (StudentId) REFERENCES Students(Id)
);


CREATE TABLE Lectures (
    Id INT IDENTITY PRIMARY KEY,
    Date DATE NOT NULL,
    SubjectId INT NOT NULL,
    TeacherId INT NOT NULL,
    FOREIGN KEY (SubjectId) REFERENCES Subjects(Id),
    FOREIGN KEY (TeacherId) REFERENCES Teachers(Id)
);


CREATE TABLE Students (
    Id INT IDENTITY PRIMARY KEY,
    Name NVARCHAR(MAX) NOT NULL,
    Rating INT NOT NULL CHECK (Rating BETWEEN 0 AND 5),
    Surname NVARCHAR(MAX) NOT NULL
);


CREATE TABLE Subjects (
    Id INT IDENTITY PRIMARY KEY,
    Name NVARCHAR(100) NOT NULL UNIQUE
);


CREATE TABLE Teachers (
    Id INT IDENTITY PRIMARY KEY,
    IsProfessor BIT NOT NULL DEFAULT 0,
    Name NVARCHAR(MAX) NOT NULL,
    Salary MONEY NOT NULL CHECK (Salary > 0),
    Surname NVARCHAR(MAX) NOT NULL
);
-- Заполнение таблицы факультетов
INSERT INTO Faculties (Name) VALUES
(N'Computer Science'),
(N'Mathematics'),
(N'Physics'),
(N'Software Engineering'),
(N'Economics');

-- Заполнение таблицы кафедр
INSERT INTO Departments (Building, Financing, Name, FacultyId) VALUES
(1, 200000, N'Software Development', 1),
(2, 150000, N'Applied Mathematics', 2),
(3, 120000, N'Physics', 3),
(4, 100000, N'Software Engineering', 4),
(5, 130000, N'Economics', 5);

-- Заполнение таблицы групп
INSERT INTO Groups (Name, Year, DepartmentId) VALUES
(N'D221', 2, 1),
(N'D222', 3, 2),
(N'D223', 4, 3),
(N'D224', 5, 4),
(N'D225', 1, 5);

-- Заполнение таблицы кураторов
INSERT INTO Curators (Name, Surname) VALUES
(N'John', N'Doe'),
(N'Alice', N'Smith'),
(N'Bob', N'Johnson'),
(N'Charlie', N'Davis'),
(N'Eve', N'Taylor');

-- Заполнение таблицы групп и кураторов
INSERT INTO GroupsCurators (CuratorId, GroupId) VALUES
(1, 1),
(2, 2),
(3, 3),
(4, 4),
(5, 5);

-- Заполнение таблицы студентов
INSERT INTO Students (Name, Rating, Surname) VALUES
(N'Anna', 5, N'Ivanova'),
(N'Max', 4, N'Petrov'),
(N'Olga', 3, N'Sidorova'),
(N'Igor', 4, N'Kuznetsov'),
(N'Maria', 5, N'Fedorova');

-- Заполнение таблицы дисциплин
INSERT INTO Subjects (Name) VALUES
(N'Mathematics'),
(N'Physics'),
(N'Software Engineering'),
(N'Economics'),
(N'Programming');

-- Заполнение таблицы преподавателей
INSERT INTO Teachers (IsProfessor, Name, Salary, Surname) VALUES
(1, N'Dr. William', 50000, N'Brown'),
(0, N'Prof. George', 40000, N'Smith'),
(1, N'Dr. Linda', 45000, N'Taylor'),
(0, N'Prof. Edward', 35000, N'Clark'),
(1, N'Dr. Jessica', 55000, N'Martinez');

-- Заполнение таблицы лекций
INSERT INTO Lectures (Date, SubjectId, TeacherId) VALUES
('2025-02-01', 1, 1),
('2025-02-02', 2, 2),
('2025-02-03', 3, 3),
('2025-02-04', 4, 4),
('2025-02-05', 5, 5);

-- Заполнение таблицы групп и лекций
INSERT INTO GroupsLectures (GroupId, LectureId) VALUES
(1, 1),
(2, 2),
(3, 3),
(4, 4),
(5, 5);

-- Заполнение таблицы групп и студентов
INSERT INTO GroupsStudents (GroupId, StudentId) VALUES
(1, 1),
(2, 2),
(3, 3),
(4, 4),
(5, 5);

--1
SELECT Building FROM Departments
group by Building having SUM(Financing)>100000;
--2
SELECT g.Name
FROM Groups g
WHERE g.DepartmentId = (
    SELECT d.Id
    FROM Departments d
    WHERE d.Name = 'Software Development'
)
AND g.Year = 5
AND (
    SELECT COUNT(*)
    FROM GroupsLectures gl
    JOIN Lectures l ON gl.LectureId = l.Id
    WHERE gl.GroupId = g.Id
    AND DATEPART(WEEK, l.Date) = 1
) > 10;
--3
SELECT g.Name
FROM Groups g
JOIN GroupsStudents gs ON g.Id = gs.GroupId
JOIN Students s ON gs.StudentId = s.Id
GROUP BY g.Name
HAVING AVG(s.Rating) > (
    SELECT AVG(s2.Rating)
    FROM Groups g2
    JOIN GroupsStudents gs2 ON g2.Id = gs2.GroupId
    JOIN Students s2 ON gs2.StudentId = s2.Id
    WHERE g2.Name = 'D221'
)
--4
select Name,Surname from Teachers
where Salary>(select avg(Salary)from Teachers where IsProfessor=1)
--5
select Name from Groups
join GroupsCurators GC on Groups.Id = GC.GroupId
group by Groups.Name
having  count(GC.CuratorId)>1

--6

SELECT g.Name
FROM Groups g
JOIN GroupsStudents gs ON gs.GroupId = g.Id
JOIN Students s ON s.Id = gs.StudentId
GROUP BY g.Name
HAVING AVG(s.Rating) <
    (SELECT MIN(s2.Rating)
     FROM Groups g2
     JOIN GroupsStudents gs2 ON gs2.GroupId = g2.Id
     JOIN Students s2 ON s2.Id = gs2.StudentId
     WHERE g2.Year = 5);
--7


SELECT f.Name
FROM Faculties f
JOIN Departments d ON d.FacultyId = f.Id
GROUP BY f.Name
HAVING SUM(d.Financing) >
    (SELECT SUM(d2.Financing)
     FROM Departments d2
     JOIN Faculties f2 ON f2.Id = d2.FacultyId
     WHERE f2.Name = 'Computer Science');
--8
SELECT s.Name AS SubjectName,
       t.Name + ' ' + t.Surname AS TeacherFullName
FROM Lectures l
JOIN Subjects s ON s.Id = l.SubjectId
JOIN Teachers t ON t.Id = l.TeacherId
GROUP BY s.Name, t.Name, t.Surname
HAVING COUNT(l.Id) = (
    SELECT MAX(LectureCount)
    FROM (
        SELECT COUNT(l2.Id) AS LectureCount
        FROM Lectures l2
        JOIN Subjects s2 ON s2.Id = l2.SubjectId
        WHERE s2.Name = s.Name
        GROUP BY l2.TeacherId
    ) AS Subquery
);
--9
SELECT TOP 1 s.Name AS SubjectName
FROM Subjects s
JOIN Lectures l ON s.Id = l.SubjectId
GROUP BY s.Name
ORDER BY COUNT(l.Id) ASC;
--10
SELECT
    COUNT(DISTINCT gs.StudentId) AS StudentCount,
    COUNT(DISTINCT l.SubjectId) AS SubjectCount
FROM Departments d
JOIN Groups g ON d.Id = g.DepartmentId
JOIN GroupsStudents gs ON g.Id = gs.GroupId
JOIN GroupsLectures gl ON g.Id = gl.GroupId
JOIN Lectures l ON gl.LectureId = l.Id
WHERE d.Name = 'Software Development';












