using Microsoft.EntityFrameworkCore;
using FavoriteMoviesApp.Models;
using FavoriteMoviesApp.Configuration;
using System.Collections.Generic;
using System.Reflection.Emit;

namespace FavoriteMoviesApp.Data
{
    public class AppDbContext : DbContext
    {
        public DbSet<User> Users { get; set; }
        public DbSet<Movie> Movies { get; set; }
        public DbSet<Favorite> Favorites { get; set; }

        public AppDbContext(DbContextOptions<AppDbContext> options) : base(options) { }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.ApplyConfiguration(new UserConfiguration());
            modelBuilder.ApplyConfiguration(new MovieConfiguration());
            modelBuilder.ApplyConfiguration(new FavoriteConfiguration());
        }
    }
}
