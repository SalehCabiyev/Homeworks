using System;
using Dapper;
using Microsoft.Data.SqlClient;
using System.Collections.Generic;


// sql skripti

//create database newcarsbase1
//    use newcarsbase1

//    create table Cars(
//        Id int primary key identity (1,1),
//       Brand nvarchar(50),
//       Model nvarchar(50),

//       [Year] int,
//       Price decimal(18,2)
//    )
//    create table Owners(
//        Id int primary key identity (1,1),
//       Name nvarchar(100),
//       CarId int foreign key references Cars(Id)
//    )
//    INSERT INTO Cars (Brand, Model, Year, Price)
//    VALUES
//    ('Toyota', 'Camry', 2020, 25000.00),
//    ('Honda', 'Civic', 2021, 22000.00),
//    ('Ford', 'Focus', 2019, 19000.00);

//--Добавление данных в таблицу Owners
//    INSERT INTO Owners (Name, CarId)
//    VALUES
//    ('Alice', 1),
//    ('Bob', 2),
//    ('Charlie', 3);
/// <summary>
/// ///////////////////////////////////////////////////////////////////////////////////
/// </summary>

public class Car
{
    public int Id { get; set; }
    public string Brand { get; set; }
    public string Model { get; set; }
    public int Year { get; set; }
    public decimal Price { get; set; }
}
public class Owner
{
    public int Id { get; set; }
    public string Name { get; set; }
    public int CarId { get; set; }
    public Car Car { get; set; } 
}

public class CarWithOwner
{
    public int Id { get; set; }
    public string Brand { get; set; }
    public string Model { get; set; }
    public int Year { get; set; }
    public decimal Price { get; set; }
    public string OwnerName { get; set; }
}



public class Program 
{
    
    public static void Main(string[] args) 
    {
        
        // test1 
        var conectionstring= "Data Source=localhost ;Initial Catalog=newcarsbase1;Integrated Security=True;Trust Server Certificate=true;";
        using var connection = new SqlConnection(conectionstring);

        connection.Open();
        try
        {
            string sqlquery= @"SELECT o.Id AS OwnerId, o.Name AS OwnerName, 
                           c.Id AS CarId, c.Brand, c.Model, c.Year, c.Price
                    FROM Owners o
                    INNER JOIN Cars c ON o.CarId = c.Id";
            var owners = connection.Query<Owner, Car, Owner>(sqlquery, (Owner owner, Car car) => { owner.Car = car; return owner; }, splitOn: "CarId").ToList();
            foreach (var owner in owners)
            {
                Console.WriteLine($"Owner: {owner.Name}, Car: {owner.Car.Brand} {owner.Car.Model}, Year: {owner.Car.Year}, Price: {owner.Car.Price}");
            }

        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error: {ex.Message}");
        }



        var newCar = new Car
        {
            Brand = "Toyota",
            Model = "Corolla",
            Year = 2020,
            Price = 20000.00m
        };

        var newOwner = new Owner
        {
            Name = "John Doe",
            CarId = 1 
        };

        InsertCarAndOwner(newCar, newOwner,conectionstring);

        Updatebycarid(conectionstring, "saleh", 3);
        removecarandowner(conectionstring, 2);
        GetAllCarsWithOwners(conectionstring);
        filterownerscars(conectionstring, "John Doe");


    }







    //test 2
    public static void InsertCarAndOwner(Car car, Owner owner,string connectionString)
    {
        using (var connection = new SqlConnection(connectionString))
        {
            connection.Open();

            using (var transaction = connection.BeginTransaction())
            {
                try
                {
                    
                    var carInsertQuery = "INSERT INTO Cars (Brand, Model, Year, Price) OUTPUT INSERTED.Id VALUES (@Brand, @Model, @Year, @Price)";
                    car.Id = connection.Query<int>(carInsertQuery, car, transaction).Single();

                    
                    var ownerInsertQuery = "INSERT INTO Owners (Name, CarId) VALUES (@Name, @CarId)";
                    owner.CarId = car.Id;
                    connection.Execute(ownerInsertQuery, owner, transaction);

                    
                    transaction.Commit();
                    Console.WriteLine("Данные успешно добавлены.");
                }
                catch (Exception ex)
                {
                    
                    transaction.Rollback();
                    Console.WriteLine("Ошибка: " + ex.Message);
                }
            }
        }
    }
    //test 3
     public static void Updatebycarid(string connectionString,string name,int carid)
    {
        using var connection = new SqlConnection(connectionString);
        connection.Open();
        var updateQuery = "UPDATE Owners SET Name = @Name WHERE CarId = @CarId";
        var parametr = new
        {
            Name = name,
            CarId = carid
        };
        var rowsAffected = connection.Execute(updateQuery,parametr );
        if (rowsAffected > 0)
        {
            Console.WriteLine("Имя владельца успешно обновлено.");
        }
        else
        {
            Console.WriteLine("Не удалось обновить данные владельца. Возможно, нет записи с таким CarId.");
        }


    } 
    //test 4
    public static void removecarandowner(string connectionString,int carid)
    {
        using var connection = new SqlConnection(connectionString);
        connection.Open();
        var deleteOwnerQuery = @"DELETE FROM Owners WHERE CarId = @CarId";
        var deleteCarQuery = @"DELETE FROM Cars WHERE Id = @CarId";
        var parametr = new
        {
            Carid = carid
        };
        var rowsAffected= connection.Execute(deleteOwnerQuery, parametr );
        var rowsAffected2= connection.Execute(deleteCarQuery, parametr );
        if (rowsAffected > 0 || rowsAffected2 > 0)
        {
            Console.WriteLine("Автомобиль и владелец успешно удалены.");
        }

    }
    //test 5
    public static List<CarWithOwner> GetAllCarsWithOwners (string connectionString) 
    {
        try
        {
            using var conn = new SqlConnection(connectionString);
            conn.Open();
            var sqlquery = @"SELECT c.Id, c.Brand, c.Model, c.Year, c.Price, o.Name AS OwnerName 
FROM Cars c
INNER JOIN Owners o ON c.Id = o.CarId";
            var carsWithOwners = conn.Query<CarWithOwner>(sqlquery).AsList();
            return carsWithOwners;
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Ошибка: {ex.Message}");
            return null;
        }


     }
    //test 6
    static void filterownerscars(string connectionString,string ownername) 
    {
    using  var connection= new SqlConnection(connectionString);
        try
        {
            connection.Open();
            var sqlquery = @"SELECT c.Id, c.Brand, c.Model, c.Year, c.Price 
FROM Cars c
INNER JOIN Owners o ON c.Id = o.CarId
WHERE o.Name = @OwnerName";
            var parametr = new { Ownername = ownername };
            var cars = connection.Query<Car>(sqlquery, parametr).AsList();
            if (cars.Count > 0)
            {
                Console.WriteLine("владелеү најден");
            }
            else Console.WriteLine("нет такого влаелүа ");
            foreach (var car in cars)
            {
                Console.WriteLine($"carid {car.Id} brand {car.Brand} year {car.Year}price {car.Price}model {car.Model}");

            }
        }
        catch(Exception ex) 
        {
            Console.WriteLine($"Ошибка: {ex.Message}");
            

        }
        


    }

 }


