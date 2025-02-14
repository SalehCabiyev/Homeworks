create database new
use new
CREATE TABLE Customers (
    CustomerID INT PRIMARY KEY,
    FirstName VARCHAR(50),
    LastName VARCHAR(50),
    Email VARCHAR(100)
);
--1
INSERT INTO Customers (CustomerID, FirstName, LastName, Email)
VALUES
    (1, 'John', 'Doe', 'john.doe@example.com'),
    (2, 'Jane', 'Smith', 'jane.smith@example.com'),
    (3, 'Emily', 'Johnson', 'emily.johnson@example.com'),
    (4, 'Michael', 'Williams', 'michael.williams@example.com');
--2
update Customers
set Email ='new.email@example.com'
where CustomerID=1;
--3
delete from Customers where CustomerID=5
--4
select * from Customers
order by LastName;
--5
INSERT INTO Customers (CustomerID, FirstName, LastName, Email)
VALUES
(5, 'Alice', 'Brown', 'alice.brown@example.com'),
(6, 'Bob', 'Davis', 'bob.davis@example.com'),
(7, 'Charlie', 'Miller', 'charlie.miller@example.com'),
(8, 'David', 'Wilson', 'david.wilson@example.com');


CREATE TABLE Orders (
    OrderID INT PRIMARY KEY,
    CustomerID INT,
    OrderDate DATE,
    TotalAmount DECIMAL(10, 2),
    FOREIGN KEY (CustomerID) REFERENCES Customers(CustomerID)
);
INSERT INTO Orders (OrderID,CustomerID, OrderDate, TotalAmount)
VALUES (2,1, '2025-02-01', 100.50);

INSERT INTO Orders (OrderID,CustomerID, OrderDate, TotalAmount)
VALUES (3,2, '2025-02-02', 250.75);

INSERT INTO Orders (OrderID,CustomerID, OrderDate, TotalAmount)
VALUES (4,3, '2025-02-03', 150.00);

INSERT INTO Orders (OrderID,CustomerID, OrderDate, TotalAmount)
VALUES (5,4, '2025-02-04', 200.10);

--6
INSERT INTO Orders (OrderID,CustomerID, OrderDate, TotalAmount)
VALUES (1,1, '2025-02-09', 250.75);
--7
update Orders SET TotalAmount=5000 WHERE OrderID=2
--8
DELETE FROM Orders WHERE OrderID=3;
--9
SELECT * FROM Orders WHERE CustomerID=1;
--10
SELECT * FROM Orders WHERE YEAR(OrderDate)=2023;

CREATE TABLE Products (
    ProductID INT PRIMARY KEY,
    ProductName VARCHAR(100),
    Price DECIMAL(10, 2)
);
INSERT INTO Products (ProductID, ProductName, Price)
VALUES
    (1, 'Laptop', 1200.00),
    (2, 'Smartphone', 800.00),
    (3, 'Tablet', 450.00),
    (4, 'Monitor', 300.00),
    (5, 'Mouse', 25.99);

--11
INSERT INTO Products(ProductId,ProductName,Price)
values
    (6,'car',60000.00)
--12
update Products set Price=2000 where ProductID=2;
--13
delete from Products where ProductID=4;
--14
select * from Products where Price>100;
--15
SELECT * FROM Products WHERE Price<=50;


CREATE TABLE OrderDetails (
    OrderDetailID INT PRIMARY KEY,
    OrderID INT,
    ProductID INT,
    Quantity INT,
    Price DECIMAL(10, 2),
    FOREIGN KEY (OrderID) REFERENCES Orders(OrderID),
    FOREIGN KEY (ProductID) REFERENCES Products(ProductID)
);


-- Добавляем отсутствующий продукт с ProductID = 4
INSERT INTO Products (ProductID, ProductName, Price)
VALUES (4, 'Monitor', 300.00);

-- 16
INSERT INTO OrderDetails (OrderDetailID, OrderID, ProductID, Quantity, Price)
VALUES
    (1, 5, 1, 2, 19.99),  -- Заказ 5, продукт 1, количество 2, цена 19.99
    (2, 4, 2, 1, 49.99),  -- Заказ 4, продукт 2, количество 1, цена 49.99
    (3, 2, 3, 5, 9.99),   -- Заказ 2, продукт 3, количество 5, цена 9.99
    (4, 3, 1, 3, 19.99),  -- Заказ 3, продукт 1, количество 3, цена 19.99
    (5, 3, 4, 1, 29.99);  -- Заказ 3, продукт 4, количество 1, цена 29.99


--17
update OrderDetails
set Quantity=8 where OrderDetailID=1;
--18
delete from OrderDetails where OrderDetailID=2;
--19
SELECT * FROM OrderDetails WHERE OrderID=1;
--20
SELECT *FROM OrderDetails WHERE ProductID=2;
--21
SELECT Orders.OrderID as orderid,
       C.FirstName+' '+C.LastName as customersfullname
from Orders
join Customers C on C.CustomerID = Orders.CustomerID


--22
    SELECT ProductName,FirstName,Quantity
FROM Products
JOIN OrderDetails OD on Products.ProductID = OD.ProductID
JOIN Orders O on OD.OrderID = O.OrderID
JOIN Customers C on O.CustomerID = C.CustomerID
--23
SELECT OrderID ,FirstName,LastName
FROM Orders
LEFT JOIN Customers C on Orders.CustomerID = C.CustomerID
--24
SELECT O.OrderID,ProductName
FROM Orders O
JOIN Customers C on O.CustomerID = C.CustomerID
JOIN OrderDetails OD on O.OrderID = OD.OrderID
JOIN Products P on OD.ProductID = P.ProductID
--25
SELECT C.CustomerID,O.OrderID
FROM Customers C
LEFT JOIN Orders O on C.CustomerID = O.CustomerID
--26
SELECT ProductName,O.OrderID,TotalAmount,OrderDate
FROM Products
RIGHT JOIN OrderDetails OD on Products.ProductID = OD.ProductID
RIGHT JOIN Orders O on OD.OrderID = O.OrderID
--27
SELECT O.OrderID,ProductName
FROM Orders O
JOIN OrderDetails OD on O.OrderID = OD.OrderID
JOIN Products P on OD.ProductID = P.ProductID

--28
SELECT FirstName,O.OrderID,Price
FROM Customers
JOIN Orders O on Customers.CustomerID = O.CustomerID
JOIN OrderDetails OD on O.OrderID = OD.OrderID
--29
SELECT FirstName FROM Customers
where CustomerID in (select CustomerID from Orders where TotalAmount>500 )
--30
SELECT ProductName FROM Products
WHERE ProductID IN (
SELECT ProductID
FROM OrderDetails
GROUP BY ProductID HAVING COUNT(OrderDetailID)>10)

--31
SELECT C.CustomerID,C.FirstName,C.LastName,
(SELECT SUM(O.TotalAmount) from Orders O WHERE O.CustomerID=C.CustomerId)as TotalOrdersAmount
from Customers C;
--32
SELECT ProductName FROM Products
WHERE Price> (SELECT AVG(Price) FROM Products)
--33
SELECT O.OrderID,C.CustomerID,FirstName,LastName,ProductName,P.Price
from Orders O
JOIN OrderDetails OD on O.OrderID = OD.OrderID
JOIN Products P on OD.ProductID = P.ProductID
JOIN Customers C on O.CustomerID = C.CustomerID
--34
SELECT FirstName,O.OrderID,ProductName,OD.Price,Quantity
FROM Customers
JOIN Orders O on Customers.CustomerID = O.CustomerID
JOIN OrderDetails OD on O.OrderID = OD.OrderID
JOIN Products P on OD.ProductID = P.ProductID
--35
SELECT FirstName,ProductName,TotalAmount FROM Orders
JOIN OrderDetails OD on Orders.OrderID = OD.OrderID
JOIN Products P on OD.ProductID = P.ProductID
JOIN Customers C on Orders.CustomerID = C.CustomerID
--36
SELECT O.OrderID, COUNT(OD.ProductID) AS TotalProducts, SUM(OD.Quantity * OD.Price) AS TotalAmount
FROM Orders O
JOIN OrderDetails OD ON O.OrderID = OD.OrderID
GROUP BY O.OrderID
HAVING SUM(OD.Quantity * OD.Price) > 1000;
--37
SELECT C.CustomerID, C.FirstName, C.LastName,
       SUM(O.TotalAmount) AS TotalOrdersAmount
FROM Customers C
JOIN Orders O ON C.CustomerID = O.CustomerID
GROUP BY C.CustomerID, C.FirstName, C.LastName
HAVING SUM(O.TotalAmount) > (SELECT AVG(TotalAmount) FROM Orders);
--38
SELECT C.CustomerID, C.FirstName, C.LastName, COUNT(O.OrderID) AS NumberOfOrders
FROM Customers C
JOIN Orders O ON C.CustomerID = O.CustomerID
GROUP BY C.CustomerID, C.FirstName, C.LastName;
--39
SELECT P.ProductName, SUM(OD.Quantity) AS TotalQuantity
FROM Products P
JOIN OrderDetails OD ON P.ProductID = OD.ProductID
GROUP BY P.ProductName
HAVING SUM(OD.Quantity) > 3;
--40
SELECT FirstName,sum(Quantity)AS TotalProducts, O.OrderID
FROM Customers
JOIN Orders O on Customers.CustomerID = O.CustomerID
JOIN OrderDetails OD on O.OrderID = OD.OrderID
GROUP BY FirstName, O.OrderID


