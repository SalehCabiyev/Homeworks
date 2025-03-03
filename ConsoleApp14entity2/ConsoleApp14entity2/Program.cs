using System;
using ConsoleApp14entity2;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Metadata.Internal;

public class Program
{
    public static void Main(string[] args)
    {
       using var context = new ApplicationContext();
        //dobavleniye 
        var car1 = new Car {  Model = "toyota Camry", Make = "toyota", Year = 2020, Price = 25000 };
        context.Add<Car>(car1);
        context.SaveChanges();
        //obnovleniye
        var car =context.Cars.FirstOrDefault(c => c.Id == 1);
        if (car != null)
        {
            car.Price = 7000;
        }
        context.SaveChanges();
        //udaleniye
        var cardelete=context.Cars.FirstOrDefault(car => car.Id == 1);
        if(cardelete != null)
        {
            context.Remove<Car>(cardelete);
            context.SaveChanges();
        }
        else
        {
            Console.WriteLine("not found ");
        }
        //poluceniye dannix 
        var allcars = context.Cars.ToList();
        foreach (var item in allcars)
        {
            Console.WriteLine($"id:{item.Id} Model: {item.Model} Make: {item.Make}");
        }
        //ling
        var customerId = 2;
        var carsBoughtByCustomer = context.Sales
            .Where(sale => sale.CustomerId == customerId)
            .Join(context.Cars, sale => sale.CarId, car => car.Id, (sale, car) => car);
        foreach (var item in carsBoughtByCustomer)
        {
            
            Console.WriteLine($"Model: {item.Model}, Make: {item.Make}, Year: {item.Year}, Price: {item.Price}");
        }

        
        DateTime startDate = new DateTime(2023, 01, 01);
        DateTime endDate = new DateTime(2023, 03, 31);

        
        var salesInPeriod = context.Sales
                                    .Where(sale => sale.Date >= startDate && sale.Date <= endDate)
                                    .Join(context.Cars, sale => sale.CarId, car => car.Id, (sale, car) => new { sale, car })
                                    .Join(context.Customers, result => result.sale.CustomerId, customer => customer.CustomerId, (result, customer) => new { result, customer })
                                    .Select(x => new
                                    {
                                        SaleId = x.result.sale.SaleId,
                                        CarModel = x.result.car.Model,
                                        CarMake = x.result.car.Make,
                                        SaleDate = x.result.sale.Date,
                                        CustomerName = x.customer.Name,
                                        CustomerEmail = x.customer.Email
                                    })
                                    .ToList();

        
        foreach (var sale in salesInPeriod)
        {
            Console.WriteLine($"SaleId: {sale.SaleId}, Model: {sale.CarModel}, Make: {sale.CarMake}, Sale Date: {sale.SaleDate.ToShortDateString()}, Customer: {sale.CustomerName}, Email: {sale.CustomerEmail}");
        }


        var salesCountByEmployee = context.Sales
                                   .GroupBy(sale => sale.EmployeeId) 
                                   .Select(group => new
                                   {
                                       EmployeeId = group.Key,  
                                       SalesCount = group.Count()  
                                   })
                                   .Join(context.Employees, saleCount => saleCount.EmployeeId, employee => employee.EmployeeId, (saleCount, employee) => new
                                   {
                                       EmployeeName = employee.Name,
                                       SalesCount = saleCount.SalesCount
                                   })
                                   .ToList();

        
        foreach (var item in salesCountByEmployee)
        {
            Console.WriteLine($"Employee: {item.EmployeeName}, Sales Count: {item.SalesCount}");
        }




    }
}