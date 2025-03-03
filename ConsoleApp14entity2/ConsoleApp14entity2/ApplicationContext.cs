using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Configuration;

namespace ConsoleApp14entity2
{
    public class ApplicationContext : DbContext

    {
        
        public DbSet<Car> Cars { get; set; }
        public DbSet<Customer> Customers { get; set; }
        public DbSet<Sale> Sales { get; set; }
        public DbSet<Employee> Employees { get; set; }
        public DbSet<ServiceHistory> ServiceHistories { get; set; }


        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            var connectionstring = new ConfigurationBuilder().AddJsonFile("addsetting.json").Build().GetConnectionString("Default");
            optionsBuilder.UseSqlServer(connectionstring);
        }
        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
           
           modelBuilder.Entity<Customer>().HasData(
              new Customer { CustomerId = 1, Name = "John Doe", Email = "johndoe@example.com" },
            new Customer { CustomerId = 2, Name = "Jane Smith", Email = "janesmith@example.com" },
            new Customer { CustomerId = 3, Name = "Bob Brown", Email = "bobbrown@example.com" },
            new Customer { CustomerId = 4, Name = "Alice Johnson", Email = "alicej@example.com" },
            new Customer { CustomerId = 5, Name = "Charlie White", Email = "charliew@example.com" },
            new Customer { CustomerId = 6, Name = "David Green", Email = "davidg@example.com" },
            new Customer { CustomerId = 7, Name = "Emma Blue", Email = "emmab@example.com" },
            new Customer { CustomerId = 8, Name = "Frank Black", Email = "frankb@example.com" },
            new Customer { CustomerId = 9, Name = "Grace Yellow", Email = "gracey@example.com" },
            new Customer { CustomerId = 10, Name = "Henry Red", Email = "henryr@example.com" });

                
            modelBuilder.Entity<Car>().HasData(
               new Car { Id = 1, Model = "Toyota Camry", Make = "Toyota", Year = 2020, Price = 25000 },
    new Car { Id = 2, Model = "Honda Civic", Make = "Honda", Year = 2021, Price = 22000 },
    new Car { Id = 3, Model = "BMW 3 Series", Make = "BMW", Year = 2022, Price = 35000 },
    new Car { Id = 4, Model = "Audi A4", Make = "Audi", Year = 2021, Price = 38000 },
    new Car { Id = 5, Model = "Mercedes-Benz C-Class", Make = "Mercedes-Benz", Year = 2023, Price = 45000 }
            );

            modelBuilder.Entity<Employee>().HasData(
    new Employee { EmployeeId = 1, Name = "John Smith" },
    new Employee { EmployeeId = 2, Name = "Jane Doe" },
    new Employee { EmployeeId = 3, Name = "Mark Johnson" },
    new Employee { EmployeeId = 4, Name = "Emily White" },
    new Employee { EmployeeId = 5, Name = "Michael Brown" }
);

            modelBuilder.Entity<Sale>().HasData(
               new Sale { SaleId = 1, CarId = 1, CustomerId = 1, Date = new DateTime(2023, 01, 15), EmployeeId = 1 },
    new Sale { SaleId = 2, CarId = 2, CustomerId = 2, Date = new DateTime(2023, 02, 10), EmployeeId = 2 },
    new Sale { SaleId = 3, CarId = 3, CustomerId = 3, Date = new DateTime(2023, 03, 05), EmployeeId = 3 },
    new Sale { SaleId = 4, CarId = 4, CustomerId = 4, Date = new DateTime(2023, 04, 20), EmployeeId = 4 },
    new Sale { SaleId = 5, CarId = 5, CustomerId = 5, Date = new DateTime(2023, 05, 30), EmployeeId = 5 });
        }

    }
    
}
