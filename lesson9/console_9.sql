CREATE DATABASE CarDealership;
GO
USE CarDealership;
GO

-- Таблица клиентов
CREATE TABLE Customers (
    Id INT PRIMARY KEY IDENTITY(1,1),
    Name NVARCHAR(100) NOT NULL,
    Email NVARCHAR(100) UNIQUE NOT NULL,
    Phone NVARCHAR(20) NOT NULL
);

-- Таблица автомобилей
CREATE TABLE Cars (
    Id INT PRIMARY KEY IDENTITY(1,1),
    Brand NVARCHAR(50) NOT NULL,
    Model NVARCHAR(50) NOT NULL,
    Year INT CHECK (Year >= 2000),
    Price DECIMAL(10,2) CHECK (Price > 0)
);

-- Таблица заказов
CREATE TABLE Orders (
    Id INT PRIMARY KEY IDENTITY(1,1),
    CustomerId INT FOREIGN KEY REFERENCES Customers(Id) ON DELETE CASCADE,
    CarId INT FOREIGN KEY REFERENCES Cars(Id) ON DELETE CASCADE,
    OrderDate DATETIME DEFAULT GETDATE()
);

-- Таблица истории цен автомобилей
CREATE TABLE CarPriceHistory (
    Id INT PRIMARY KEY IDENTITY(1,1),
    CarId INT FOREIGN KEY REFERENCES Cars(Id) ON DELETE CASCADE,
    OldPrice DECIMAL(10,2),
    NewPrice DECIMAL(10,2),
    ChangeDate DATETIME DEFAULT GETDATE()
);

-- Таблица логов удалённых заказов
CREATE TABLE DeletedOrdersLog (
    Id INT PRIMARY KEY IDENTITY(1,1),
    OrderId INT,
    CustomerId INT,
    CarId INT,
    OrderDate DATETIME,
    DeletedAt DATETIME DEFAULT GETDATE()
);
INSERT INTO Customers (Name, Email, Phone) VALUES
('Иван Петров', 'ivan.petrov@email.com', '123-456-789'),
('Мария Сидорова', 'maria.sidorova@email.com', '987-654-321'),
('Алексей Смирнов', 'alex.smirnov@email.com', '555-666-777');

INSERT INTO Cars (Brand, Model, Year, Price) VALUES
('Toyota', 'Camry', 2022, 30000),
('BMW', 'X5', 2023, 60000),
('Mercedes', 'C-Class', 2021, 50000);

INSERT INTO Orders (CustomerId, CarId) VALUES
(1, 1),
(2, 2),
(3, 3);


--1
create trigger trg_CarPriceUpdate on Cars
    after update
    as begin
        if update(Price)
        begin
           DECLARE @CarId INT, @OldPrice DECIMAL(10, 2), @NewPrice DECIMAL(10, 2);
           select @CarId=inserted.Id,@NewPrice=inserted.Price from inserted
            select @OldPrice=deleted.Price from deleted
            insert into CarPriceHistory(carid, oldprice, newprice)
            values (@CarId,@OldPrice,@NewPrice)
        end;

end;
--2
create trigger trg_PreventDeleteCustomerWithActiveOrders on Customers
    instead of delete
    as
    begin
        declare @customerid int
        select @customerid=Id from deleted
        if exists(select 1 from Orders where CustomerId=@customerid)
        begin
            print 'Невозможно удалить клиента с активными заказами.'
        end
        else
            begin
               delete from Customers where Id=@customerid
            end;

    end;

--3
create trigger trg_LogDeletedOrder on Orders
    after delete
    as
    begin
        insert into DeletedOrdersLog(orderid, customerid, carid, orderdate)
        select Id, customerid, carid, orderdate
        from deleted
    end;
--4
CREATE TRIGGER trg_UpdatePriceOnYearChange
ON Cars
AFTER UPDATE
AS
BEGIN
    IF UPDATE(Year)
    BEGIN
        DECLARE @CarId INT, @OldYear INT, @NewYear INT, @NewPrice DECIMAL(10, 2);


        SELECT @CarId = inserted.Id, @NewYear = inserted.Year
        FROM inserted;

        SELECT @OldYear = deleted.Year
        FROM deleted;


        IF @OldYear <> @NewYear
        BEGIN

            SELECT @NewPrice = inserted.Price
            FROM inserted;


            SET @NewPrice = @NewPrice * 0.95;

            UPDATE Cars
            SET Price = @NewPrice
            WHERE Id = @CarId;
        END
    END
END;
--5
create trigger trg_PreventDuplicateOrders on Orders
    instead of  insert
    as
    begin
        declare @carid int
        select @carid=CarId from inserted
        if exists(select 1 from Orders where CarId=@carid)
        begin
            print 'Клиент уже оформил заказ на этот автомобиль.'
        end
        else
        begin
            insert into Orders(customerid, carid)
            select customerid, carid from inserted
        end
end;

