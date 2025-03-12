using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Configuration;
using Microsoft.EntityFrameworkCore.Metadata.Builders;

namespace project_ef
{
    public class AutoServiceContext:DbContext
    {
        public DbSet<Client> Clients { get; set; }
        public DbSet<Car> Cars { get; set; }
        public DbSet<Service> Services { get; set; }
        public DbSet<Order> Orders { get; set; }
        public DbSet<OrderedService> OrderedServices { get; set; }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            var connectionstring = new ConfigurationBuilder().AddJsonFile("addsetting.json").Build().GetConnectionString("Default");
            optionsBuilder.UseSqlServer(connectionstring);
        }
        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            //base.OnModelCreating(modelBuilder);
            modelBuilder.Entity<Client>()
                .HasIndex(c=>c.Password)
                .IsUnique();
            modelBuilder.Entity<Car>()
                .HasKey(c => c.CarId);
            modelBuilder.Entity<Car>()
                .Property(c => c.Brand)
                .HasMaxLength(50)
                .IsRequired();
            modelBuilder.Entity<Car>()
                .Property(c => c.Model)
                .IsRequired()
                .HasMaxLength(50);
            modelBuilder.Entity<Car>()
                .Property(c => c.Year)
                .IsRequired();
            modelBuilder.Entity<Car>()
                .HasOne(c => c.Client);

            modelBuilder.Entity<Client>()
                .HasKey(cl => cl.ClientId) ;
            modelBuilder.Entity<Client>()
                .Property(cl => cl.Email)
                .IsRequired()
                .HasMaxLength(50);
            modelBuilder.Entity<Client>()
                .Property(cl=>cl.FirstName)
                .IsRequired()
                .HasMaxLength (50);
            modelBuilder.Entity<Client>()
                .Property(cl=>cl.LastName)
                .IsRequired ()
                .HasMaxLength(50);
            modelBuilder.Entity<Client>()
                .HasMany(c => c.Cars);
            
            

                
             
        }
    }
     
}
