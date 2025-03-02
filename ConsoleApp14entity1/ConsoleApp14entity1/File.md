create database  CarDealershipDb
use CarDealershipDb


-- Добавление ещё нескольких записей в таблицу Dealers
INSERT INTO Dealers (Name, Location)
VALUES
('Dealer4', 'Miami'),
('Dealer5', 'Dallas');

-- Добавление новых машин
INSERT INTO Cars (Make, Model, Year, DealerId)
VALUES
('Chevrolet', 'Camaro', 2022, 1),
('BMW', 'M3', 2023, 2);

-- Добавление клиентов
INSERT INTO Customer (Name)
VALUES
('Alice Green'),
('Bob White');

-- Создание заказов
INSERT INTO CarOrders (CarId, CustomerId)
VALUES
(1, 1),  -- Alice Green заказала Chevrolet Camaro
(2, 2); 