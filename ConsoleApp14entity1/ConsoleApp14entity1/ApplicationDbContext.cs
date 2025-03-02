using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Configuration;

namespace ConsoleApp14entity1
{
    public class ApplicationDbContext : DbContext
    {
        public DbSet<Car> Cars { get; set; }
        public DbSet<Dealer> Dealers { get; set; }
        public DbSet<CarOrder> CarOrders { get; set; }
        public DbSet<Customer> Custumer { get; set; }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            var connectionString = new ConfigurationBuilder().AddJsonFile("appsettings.json").Build().GetConnectionString("Default");
            optionsBuilder.UseSqlServer(connectionString).UseLazyLoadingProxies().LogTo(Console.WriteLine,Microsoft.Extensions.Logging.LogLevel.Information);
            
            
        }
        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            base.OnModelCreating(modelBuilder);
            modelBuilder.Entity<Car>()
            .HasIndex(c => new { c.Model, c.Make })
            .IsUnique();
          

        }
        public  void AddCar(Car car)
        {

            try
            {
                if (string.IsNullOrEmpty(car.Make) || string.IsNullOrEmpty(car.Model) || car.Year <= 0)
                {
                    Console.WriteLine("Ошибка: Недопустимые значения для автомобиля.");
                    return;
                }

                Cars.Add(car);
                SaveChanges();
            }
            catch (DbUpdateException ex)
            {
                Console.WriteLine($"Ошибка при сохранении данных: {ex.InnerException?.Message}");
            }


        }
        public void UpdateCar(int carId, string newMake, string newModel, int newYear)
        {
            var car = Cars.FirstOrDefault(c => c.Id == carId);
            if (car == null)
            {
                Console.WriteLine("Автомобиль не найден.");
                return;
            }

            car.Make = newMake;
            car.Model = newModel;
            car.Year = newYear;

           // SaveChanges();
            Console.WriteLine($"Информация о автомобиле {carId} обновлена.");
        }
        public void Removecar(int Carid)
        {
            var cars = Cars.FirstOrDefault(c => c.Id == Carid);
            if (cars == null) { Console.WriteLine("Автомобиль не найден"); }
            else {
                Cars.Remove(cars);
                //SaveChanges();
                Console.WriteLine($"Автомобиль {Carid} удален.");
            }
        }
        public void allCars() 
        {   
            var allcars=Cars.ToList();
            if (allcars.Count == 0)
            {
                Console.WriteLine("Нет автомобилей в базе данных.");
                return;
            }
            foreach (var car in allcars) { Console.WriteLine($"carid :{car.Id} Make: {car.Make}"); }
        
        }
        public void SoftDeleteCar(int carId)
        {
            var car = Cars.FirstOrDefault(c => c.Id == carId);
            if (car == null)
            {
                Console.WriteLine("Автомобиль не найден.");
                return;
            }

            car.IsDeleted = true;
            //SaveChanges();
            Console.WriteLine($"Автомобиль с Id {carId} помечен как удалённый.");
        }
    }
}
