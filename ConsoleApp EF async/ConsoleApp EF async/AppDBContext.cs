using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Configuration;

namespace ConsoleApp_EF_async
{
    public class AppDBContext:DbContext
    {
        public DbSet<Student> Students { get; set; }
        protected  override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {

            var connectinsting = new ConfigurationBuilder().AddJsonFile("addsetting.json").Build().GetConnectionString("Default");
            optionsBuilder.UseSqlServer(connectinsting);

        }
        
        public void AddStudentManually(string name)
        {
            Task.Run(() =>
            {
                Console.WriteLine($"AddStudetManually thread {Thread.CurrentThread.ManagedThreadId}  start");
                Students.Add(new Student { Name = name });
                SaveChanges();
                Console.WriteLine($"AddStudetManually thread {Thread.CurrentThread.ManagedThreadId} end ");


            }).GetAwaiter().GetResult();

        }
        public void ShowAllStudentsManually()
        {
            int counter = 1;
            Task.Run(() =>
            {
                Console.WriteLine($"ShowAllStudentsManually thread {Thread.CurrentThread.ManagedThreadId} start");
                var allstudets = Students.ToList();
                foreach (var student in allstudets)
                {
                    Console.WriteLine($"{counter}.{student.Name}");
                    counter++;
                }
                Console.WriteLine($"ShowAllStudentsManually thread {Thread.CurrentThread.ManagedThreadId} end");

            }).GetAwaiter().GetResult();
        }
        public async Task AddStudentAsync(string name)
        {
             Console.WriteLine($"AddStudentAsync thread {Thread.CurrentThread.ManagedThreadId}start");
            await Students.AddAsync(new Student { Name = name });
            await SaveChangesAsync();
            Console.WriteLine($"AddStudentAsync thread {Thread.CurrentThread.ManagedThreadId} end");

        }
        public async Task ShowAllStudensAsync()
        {
            Console.WriteLine($"ShowAllStudensAsync thread {Thread.CurrentThread.ManagedThreadId} start");
            int counter = 1;
             var students=await Students.ToListAsync();
            foreach (var student in students)
            {
                Console.WriteLine($"{counter}.{student.Name}");
                counter++;
            }
            Console.WriteLine($"ShowAllStudensAsync thread {Thread.CurrentThread.ManagedThreadId} end");

        }

    }

}
