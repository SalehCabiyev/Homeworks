using System;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Metadata.Internal;
using Microsoft.Extensions.Configuration;
using Microsoft.SqlServer;
using System.Linq;  

namespace ConsoleApp14entity1 {
    









    public class Program
    {
        public static void Main(string[] args)
        {
            using var context = new ApplicationDbContext();
            var dealer = new Dealer
            {
                Location = "New York",
                Name= "Dealer A"
            };
            var dealer2 = new Dealer
            {
                Name = "Saleh",
                Location = "Narimanov"

            };
            context.Dealers.Add(dealer);
            context.Dealers.Add(dealer2);
            context.SaveChanges();
           

            //test 5 проверка на ограничениә
            try
            {
                var newcar4 = new Car { Year = 3000 };
                context.Cars.Add(newcar4);
                context.SaveChanges();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"нелғзә вводитғ нулл значение длә Модел и Дата автомобилә имеет ограничениеҸ");
            }
            //test 6 проверка
            try
            {
                var newcar5 = new Car { Make = "GM", Year = 2000, Model = "BMW" };
                context.Cars.Add(newcar5);
                context.SaveChanges();
                var newcar6 = new Car { Make = "GM", Year = 2000, Model = "BMW" };
                context.Cars.Add(newcar6);
                context.SaveChanges();
            }
            catch (Exception ex) { Console.WriteLine(" Не удается вставить повторяющуюся строку ключа в объект"); }
            //test 7

            var alldealerswithcars = context.Dealers.Include(d => d.Cars).ToList();
            foreach (var dealer1 in alldealerswithcars)
            {
                Console.WriteLine(dealer1.Name);
                foreach (var car in dealer1.Cars)
                {
                    Console.WriteLine($" model :{car.Model}  year: {car.Year}  Make: {car.Make} ");
                }
            }
            //test 8
            var car6 = context.Cars.FirstOrDefault(c => c.Id == 1);
            if (car6 != null)
            {
                context.Entry(car6).Reference(c => c.Dealer).Load();
                Console.WriteLine($"Car: {car6.Model}, Dealer: {car6.Dealer.Name}");
            }
            else
            {
                Console.WriteLine("Car not found");


                    }
              //test 9
                var cars9=context.Cars.ToList();
           foreach (var car in cars9)
            {
                //Ленивая загрузка: дилер загружается только здесь
                Console.WriteLine(car.Dealer.Name);
            }
            //test 10

            string brand = "BMW";
            var car10 = context.Cars.FromSqlRaw("SELECT * FROM Cars WHERE Make = {0}", brand).ToList();
            foreach (var car in car10)
            {
                Console.WriteLine($"Make: {car.Make}, Model: {car.Model}, Year: {car.Year}");
            }
            //test 11
            var car11 = new Car {
                Make = "Toyota",
                Model = "Corolla",
                Year = 2020,
                DealerId=1
              
                
            };
           context.AddCar(car11);
            context.UpdateCar(4, "dsaj", "dfhsjfsj", 555);
            context.Removecar(4);
            context.allCars();
            // test12 ++++
            //смотретғ в ApplicationDbContext
            //test 13
            context.SoftDeleteCar(4);
            //test14
            using var transaction=context.Database.BeginTransaction();
            try
            {
                var car14 = new Car
                {
                    Make = "Honda",
                    Model = "Civic",
                    Year = 2022,
                    DealerId = 1
                };
                context.Cars.Add(car14);
                var custumer = new Customer { Name = "Saleh" };
                context.Custumer.Add(custumer);
                context.SaveChanges();
                transaction.Commit();
                Console.WriteLine("Машина и её владелец успешно добавлены в рамках одной транзакции.");

            }
            catch (Exception ex) 
            {
                transaction.Rollback();
                Console.WriteLine($"Произошла ошибка: {ex.Message}. Транзакция откатана.");

            }
            


        }
    }
}