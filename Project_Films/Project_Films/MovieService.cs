using FavoriteMoviesApp.Models;

namespace FavoriteMoviesApp.Services
{
    public class MovieService
    {
        private readonly List<Movie> _movies;

        public MovieService()
        {
           
            _movies = new List<Movie>
            {
                new Movie { Id = 1, Title = "The Shawshank Redemption", Genre = "Drama", Year = 1994 },
                new Movie { Id = 2, Title = "The Godfather", Genre = "Crime", Year = 1972 },
                new Movie { Id = 3, Title = "Inception", Genre = "Sci-Fi", Year = 2010 },
                new Movie { Id = 4, Title = "Interstellar", Genre = "Sci-Fi", Year = 2014 },
                new Movie { Id = 5, Title = "The Matrix", Genre = "Action", Year = 1999 },
                new Movie { Id = 6, Title = "Gladiator", Genre = "Action", Year = 2000 }
            };
        }

        public List<Movie> Search(string query)
        {
            return _movies
                .Where(m => m.Title.Contains(query, StringComparison.OrdinalIgnoreCase) ||
                            m.Genre.Contains(query, StringComparison.OrdinalIgnoreCase))
                .ToList();
        }

        public Movie? GetMovieById(int id)
        {
            return _movies.FirstOrDefault(m => m.Id == id);
        }

        public List<Movie> GetAllMovies()
        {
            return _movies;
        }
    }
}
