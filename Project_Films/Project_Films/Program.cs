using System;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.DependencyInjection;
using FavoriteMoviesApp.Data;
using FavoriteMoviesApp.Services;
using FavoriteMoviesApp.Utilities;
using FavoriteMoviesApp.Models;

var services = new ServiceCollection();

services.AddDbContext<AppDbContext>(options =>
    options.UseSqlServer("Server=localhost;Database=FavoriteMoviesDb;Trusted_Connection=True;TrustServerCertificate=True;"));

services.AddScoped<AuthService>();
services.AddScoped<MovieService>();
services.AddScoped<FavoriteService>();
services.AddScoped<EmailService>();
services.AddScoped<PdfService>();
services.AddScoped<PasswordHasher>();

var provider = services.BuildServiceProvider();

using var scope = provider.CreateScope();
var context = scope.ServiceProvider.GetRequiredService<AppDbContext>();
context.Database.Migrate();

if (!context.Movies.Any())
{
    context.Movies.AddRange(
        new Movie { Title = "The Shawshank Redemption", Year = 1994, Genre = "Drama" },
        new Movie { Title = "The Godfather", Year = 1972, Genre = "Crime" },
        new Movie { Title = "The Dark Knight", Year = 2008, Genre = "Action" },
        new Movie { Title = "Pulp Fiction", Year = 1994, Genre = "Crime" },
        new Movie { Title = "The Matrix", Year = 1999, Genre = "Action" }
    );
    context.SaveChanges();
}

var authService = scope.ServiceProvider.GetRequiredService<AuthService>();
var movieService = scope.ServiceProvider.GetRequiredService<MovieService>();
var favoriteService = scope.ServiceProvider.GetRequiredService<FavoriteService>();
var emailService = scope.ServiceProvider.GetRequiredService<EmailService>();
var pdfService = scope.ServiceProvider.GetRequiredService<PdfService>();

Console.WriteLine("Добро пожаловать в Favorite Movies App!");
Console.WriteLine("1. Зарегистрироваться\n2. Войти");
Console.Write("Выберите опцию: ");
var option = Console.ReadLine();

User? currentUser = null;

if (option == "1")
{
    Console.Write("Введите email: ");
    var email = Console.ReadLine();
    Console.Write("Введите пароль: ");
    var password = Console.ReadLine();

    var registered = await authService.RegisterUserAsync(email!, password!);
    Console.WriteLine(registered ? "Регистрация прошла успешно!" : "Пользователь с таким email уже существует.");
}
else if (option == "2")
{
    Console.Write("Введите email: ");
    var email = Console.ReadLine();
    Console.Write("Введите пароль: ");
    var password = Console.ReadLine();

    currentUser = await authService.LoginAsync(email!, password!);
    if (currentUser == null)
    {
        Console.WriteLine("Неверные учетные данные.");
        return;
    }

    Console.WriteLine($"Добро пожаловать, {currentUser.Email}!");

    string input;
    do
    {
        Console.WriteLine("\nМеню:");
        Console.WriteLine("1. Поиск фильма");
        Console.WriteLine("2. Показать избранное");
        Console.WriteLine("3. Экспорт в PDF и отправить на email");
        Console.WriteLine("0. Выход");
        Console.Write("Выберите опцию: ");
        input = Console.ReadLine();

        switch (input)
        {
            case "1":
                Console.Write("Введите название или жанр: ");
                var query = Console.ReadLine();
                var results = movieService.Search(query!);
                if (results.Count == 0)
                {
                    Console.WriteLine("Фильмы не найдены.");
                }
                else
                {
                    Console.WriteLine("Найденные фильмы:");
                    foreach (var movie in results)
                        Console.WriteLine($"{movie.Id}. {movie.Title} ({movie.Year}) - {movie.Genre}");

                    Console.Write("Введите ID фильма для добавления в избранное (или пусто для отмены): ");
                    var idStr = Console.ReadLine();
                    if (int.TryParse(idStr, out int movieId))
                    {
                        var movie = movieService.GetMovieById(movieId);
                        if (movie != null)
                        {
                            await favoriteService.AddToFavoritesAsync(currentUser.Id, movie);
                            Console.WriteLine("Фильм добавлен в избранное.");
                        }
                        else
                        {
                            Console.WriteLine("Фильм не найден.");
                        }
                    }
                }
                break;

            case "2":
                var favorites = await favoriteService.GetFavoritesAsync(currentUser.Id);
                Console.WriteLine("\nИзбранные фильмы:");
                foreach (var fav in favorites)
                    Console.WriteLine($"{fav.Title} ({fav.Year}) - {fav.Genre}");
                break;

            case "3":
                var favsToExport = await favoriteService.GetFavoritesAsync(currentUser.Id);
                if (favsToExport.Count == 0)
                {
                    Console.WriteLine("Нет избранных фильмов для экспорта.");
                    break;
                }

                var pdfFiles = pdfService.GenerateFavoriteMoviesPdf(favsToExport);
                await emailService.SendEmailWithPdfsAsync(currentUser.Email,new List<byte[]> { pdfFiles });
                Console.WriteLine("PDF-файлы отправлены на вашу почту.");
                break;
        }

    } while (input != "0");
}
