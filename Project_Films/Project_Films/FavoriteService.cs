using FavoriteMoviesApp.Data;
using FavoriteMoviesApp.Models;
using Microsoft.EntityFrameworkCore;

namespace FavoriteMoviesApp.Services
{
   
    public class FavoriteService
    {
        private readonly AppDbContext _context;

        public FavoriteService(AppDbContext context)
        {
            _context = context;
        }

        public async Task AddToFavoritesAsync(int userId, Movie movie)
        {
            var existingMovie = await _context.Movies.FirstOrDefaultAsync(m => m.Title == movie.Title && m.Year == movie.Year);

            if (existingMovie == null)
            {
                _context.Movies.Add(movie);
                await _context.SaveChangesAsync();
                existingMovie = movie;
            }

            var favorite = new Favorite
            {
                UserId = userId,
                MovieId = existingMovie.Id
            };

            _context.Favorites.Add(favorite);
            await _context.SaveChangesAsync();
        }

        public async Task<List<Movie>> GetFavoritesAsync(int userId)
        {
            return await _context.Favorites
                .Include(f => f.Movie)
                .Where(f => f.UserId == userId)
                .Select(f => f.Movie)
                .ToListAsync();
        }
    }
}