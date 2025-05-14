using FavoriteMoviesApp.Data;
using FavoriteMoviesApp.Models;
using FavoriteMoviesApp.Utilities;
using Microsoft.EntityFrameworkCore;

namespace FavoriteMoviesApp.Services
{
    public class AuthService
    {
        private readonly AppDbContext _context;
        private readonly PasswordHasher _hasher;

        public AuthService(AppDbContext context, PasswordHasher hasher)
        {
            _context = context;
            _hasher = hasher;
        }

        public async Task<bool> RegisterUserAsync(string email, string password)
        {
            if (await _context.Users.AnyAsync(u => u.Email == email))
                return false;

            var user = new User
            {
                Email = email,
                PasswordHash = _hasher.HashPassword(password)
            };

            _context.Users.Add(user);
            await _context.SaveChangesAsync();
            return true;
        }

        public async Task<User?> LoginAsync(string email, string password)
        {
            var user = await _context.Users.FirstOrDefaultAsync(u => u.Email == email);
            if (user == null) return null;

            return _hasher.VerifyPassword(password, user.PasswordHash) ? user : null;
        }
    }
}
