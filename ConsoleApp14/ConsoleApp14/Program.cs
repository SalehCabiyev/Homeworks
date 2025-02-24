using System.Data;
using Dapper;
using Microsoft.Data.SqlClient;
using System;
using System.Data.SqlClient;





public class Car
{
    public int Id { get; set; }
    public string Brand { get; set; }
    public string Model { get; set; }
    public int Year { get; set; }
    public decimal Price { get; set; }
}

public class Program
{
    public static void Main(string[] args)
    {
        var connectionString =
    "Data Source=localhost ;Initial Catalog=newcarsbase;Integrated Security=True;Trust Server Certificate=true;";

        var newCar = new Car
        {
            Brand = "Toyota",
            Model = "Corolla",
            Year = 2020,
            Price = 20000.00m
        };

        AddCar(newCar, connectionString);
        updateprice(connectionString,1,30000);
        deletecar(connectionString, 1);
        selectallcars(connectionString);
        selectcarsbrend(connectionString, "Toyota");
    }

    public static void AddCar(Car car, string connectionString)
    {
        using (var connection = new SqlConnection(connectionString))
        {
            connection.Open();

           
            var query = @"
                INSERT INTO Cars (Brand, Model, Year, Price)
                VALUES (@Brand, @Model, @Year, @Price)";

            
            var result = connection.Execute(query, car);

            if (result > 0)
            {
                Console.WriteLine("Новая запись успешно добавлена!");
            }
            else
            {
                Console.WriteLine("Ошибка при добавлении записи.");
            }
        }
    }
    // test 2
    public static void updateprice(string connectionString,int carid,decimal newprice)
    {
        using (var conection = new SqlConnection(connectionString))
        {

            conection.Open();
            var query = @"UPDATE Cars SET Price = @NewPrice WHERE Id = @CarId";
            var parametrs = new 
            {
                Newprice = newprice,
                Carid = carid
            };
            var result=conection.Execute(query, parametrs);
            if (result > 0)
            {
                Console.WriteLine($"Цена автомобиля с ID {carid} успешно обновлена на {newprice}");

            }
            else { Console.WriteLine($"Не удалось обновить цену для автомобиля с ID {carid}");
            }


        }
    }
    //test 3
    public static void deletecar(string connectionString, int Carid)
    {
        using (var conection = new SqlConnection(connectionString))
        {
            conection.Open();
            var query = @"DELETE FROM Cars WHERE Id = @CarId";
            var parametrs = new
            {
                CarId = Carid
            };
            var result = conection.Execute(query, parametrs);
            if (result > 0)
            {
                Console.WriteLine($"Автомобиль с ID {Carid} успешно удален.");
            }
            else
            {
                Console.WriteLine($"Не удалось найти автомобиль с ID {Carid} для удаления.");
            }

        }
    }
    //test 4
    public static void selectallcars(string connectionString)
    {
        using var conection = new SqlConnection(connectionString);
        conection.Open();
        var query = "SELECT * FROM Cars";
        var cars=conection.Query<Car>(query).AsList();
        foreach (var car in cars) 
        {
            Console.WriteLine($"ID: {car.Id}, Brand: {car.Brand}, Model: {car.Model}, Year: {car.Year}, Price: {car.Price}");
        }
    }
    //test 5
    public static void selectcarsbrend(string connectionString,string brandname) 
    {
    using var conection=new SqlConnection(connectionString);
        conection.Open();
        var query = "SELECT * FROM Cars WHERE Brand = @BrandName";
        var parametr = new
        {
            Brandname = brandname
        };
        var cars=conection.Query<Car>(query,parametr).AsList();
        foreach (var car in cars)
        {
            Console.WriteLine($"id {car.Id} Price {car.Price} Year{car.Year} Model {car.Model} Brand {car.Brand}");
        }


    }

}
