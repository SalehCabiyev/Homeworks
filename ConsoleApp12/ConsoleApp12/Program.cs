using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text.Json;
using  ConsoleApp12;








class Program
{
    private static List<Showroom> Showrooms = new List<Showroom>();
    private static List<User> Users = new List<User>();
    private static List<Sale> Sales = new List<Sale>();
    private static string ShowroomsFile = "showrooms.json";
    private static string UsersFile = "users.json";
    private static string SalesFile = "sales.json";

    static void Main(string[] args)
    {
        LoadData();
        Run();
    }

    static void LoadData()
    {
        // Загружаем данные о салонах
        if (File.Exists(ShowroomsFile))
        {
            Showrooms = JsonSerializer.Deserialize<List<Showroom>>(File.ReadAllText(ShowroomsFile)) ?? new List<Showroom>();
        }

        // Загружаем данные о пользователях
        if (File.Exists(UsersFile))
        {
            Users = JsonSerializer.Deserialize<List<User>>(File.ReadAllText(UsersFile)) ?? new List<User>();
        }

        // Загружаем данные о продажах
        if (File.Exists(SalesFile))
        {
            Sales = JsonSerializer.Deserialize<List<Sale>>(File.ReadAllText(SalesFile)) ?? new List<Sale>();
        }

        // Для каждого автосалона загружаем машины из отдельного файла
        foreach (var showroom in Showrooms)
        {
            string carFile = $"cars_{showroom.Id}.json";
            if (File.Exists(carFile))
            {
                showroom.Cars = JsonSerializer.Deserialize<List<Car>>(File.ReadAllText(carFile)) ?? new List<Car>();
            }
        }
    }

    static void SaveData()
    {
        // Сохраняем данные о салонах
        File.WriteAllText(ShowroomsFile, JsonSerializer.Serialize(Showrooms, new JsonSerializerOptions { WriteIndented = true }));

        // Сохраняем данные о пользователях
        File.WriteAllText(UsersFile, JsonSerializer.Serialize(Users, new JsonSerializerOptions { WriteIndented = true }));

        // Сохраняем данные о продажах
        File.WriteAllText(SalesFile, JsonSerializer.Serialize(Sales, new JsonSerializerOptions { WriteIndented = true }));

        // Для каждого автосалона сохраняем машины в отдельный файл
        foreach (var showroom in Showrooms)
        {
            string carFile = $"cars_{showroom.Id}.json";
            File.WriteAllText(carFile, JsonSerializer.Serialize(showroom.Cars, new JsonSerializerOptions { WriteIndented = true }));
        }
    }

    static void Run()
    {
        while (true)
        {
            Console.Clear();
            Console.WriteLine("1. Вход");
            Console.WriteLine("2. Регистрация");
            Console.WriteLine("3. Выход");
            Console.Write("Выберите действие: ");
            var choice = Console.ReadLine();
            switch (choice)
            {
                case "1":
                    Login();
                    break;
                case "2":
                    Register();
                    break;
                case "3":
                    SaveData();
                    return;
                default:
                    Console.WriteLine("Неверный выбор. Попробуйте снова.");
                    break;
            }
        }
    }

    static void Login()
    {
        Console.Write("Введите имя пользователя: ");
        string username = Console.ReadLine();
        Console.Write("Введите пароль: ");
        string password = Console.ReadLine();

        var user = Users.Find(u => u.Username == username && u.Password == password);
        if (user != null)
        {
            Console.WriteLine("Вы вошли в систему.");
            if (user.ShowroomId.HasValue)
            {
                user.Showroom = Showrooms.Find(s => s.Id == user.ShowroomId.Value);
            }
            ShowUserMenu(user);
        }
        else
        {
            Console.WriteLine("Неверные данные.");
        }
        Console.ReadLine();
    }

    static void Register()
    {
        Console.Write("Введите имя пользователя: ");
        string username = Console.ReadLine();
        Console.Write("Введите пароль: ");
        string password = Console.ReadLine();

        var user = new User
        {
            Username = username,
            Password = password,
            Role = "user" // по умолчанию роль "user"
        };

        Users.Add(user);
        Console.WriteLine("Пользователь зарегистрирован.");
        Console.ReadLine();
    }

    static void ShowUserMenu(User user)
    {
        while (true)
        {
            Console.Clear();
            Console.WriteLine($"Привет, {user.Username}!");
            Console.WriteLine("1. Просмотр профиля");
            Console.WriteLine("2. Просмотр салона");
            Console.WriteLine("3. Редактирование профиля");
            Console.WriteLine("4. Создание нового салона");
            Console.WriteLine("5. Добавление машины в салон");
            Console.WriteLine("6. Продажа машины");
            Console.WriteLine("7. Просмотр машин в салоне");
            Console.WriteLine("8. Редактирование машины");
            Console.WriteLine("9. Удаление машины");
            Console.WriteLine("10. Просмотр всех машин");
            Console.WriteLine("11. Выход");
            Console.Write("Выберите действие: ");
            var choice = Console.ReadLine();

            switch (choice)
            {
                case "1":
                    ViewProfile(user);
                    break;
                case "2":
                    ViewShowroom(user);
                    break;
                case "3":
                    EditProfile(user);
                    break;
                case "4":
                    CreateShowroom(user);
                    break;
                case "5":
                    AddCar(user);
                    break;
                case "6":
                    SellCar(user);
                    break;
                case "7":
                    ViewCarsInShowroom(user);
                    break;
                case "8":
                    EditCar(user);
                    break;
                case "9":
                    DeleteCar(user);
                    break;
                case "10":
                    ViewAllCars(user);
                    break;
                case "11":
                    SaveData();
                    return;
                default:
                    Console.WriteLine("Неверный выбор. Попробуйте снова.");
                    break;
            }
        }
    }

    static void ViewProfile(User user)
    {
        Console.WriteLine($"Имя пользователя: {user.Username}");
        Console.WriteLine($"Роль: {user.Role}");
        if (user.Showroom != null)
        {
            Console.WriteLine($"Салон: {user.Showroom.Name}");
        }
        else
        {
            Console.WriteLine("Салон не назначен.");
        }
        Console.ReadLine();
    }

    static void ViewShowroom(User user)
    {
        if (user.Showroom == null)
        {
            Console.WriteLine("У вас нет салона.");
        }
        else
        {
            Console.WriteLine($"Салон: {user.Showroom.Name}");
            Console.WriteLine($"Вместимость: {user.Showroom.CarCapacity}");
            Console.WriteLine($"Количество машин: {user.Showroom.CarCount}");
        }
        Console.ReadLine();
    }

    static void EditProfile(User user)
    {
        Console.WriteLine("Редактирование профиля");
        Console.Write("Введите новое имя пользователя: ");
        string newUsername = Console.ReadLine();
        user.Username = newUsername;
        Console.WriteLine("Профиль обновлен.");
        Console.ReadLine();
    }

    static void CreateShowroom(User user)
    {
        if (user.Showroom != null)
        {
            Console.WriteLine("У вас уже есть салон.");
            Console.ReadLine();
            return;
        }

        Console.Write("Введите имя салона: ");
        string showroomName = Console.ReadLine();
        Console.Write("Введите вместимость салона: ");
        int capacity = int.Parse(Console.ReadLine());

        Showroom showroom = new Showroom { Name = showroomName, CarCapacity = capacity };
        Showrooms.Add(showroom);

        user.ShowroomId = showroom.Id;
        user.Showroom = showroom;

        Console.WriteLine("Салон создан.");
        Console.ReadLine();
    }

    static void AddCar(User user)
    {
        if (user.Showroom == null || user.Showroom.CarCount >= user.Showroom.CarCapacity)
        {
            Console.WriteLine("Салон не существует или достигнут лимит машин.");
            Console.ReadLine();
            return;
        }

        Console.Write("Введите марку машины: ");
        string make = Console.ReadLine();
        Console.Write("Введите модель машины: ");
        string model = Console.ReadLine();
        Console.Write("Введите год выпуска: ");
        int year = int.Parse(Console.ReadLine());

        var car = new Car { Make = make, Model = model, Year = new DateTime(year, 1, 1) };
        user.Showroom.Cars.Add(car);

        Console.WriteLine("Машина добавлена в салон.");
        Console.ReadLine();
    }

    // Просмотр всех машин из всех салонов
    static void ViewAllCars(User user)
    {
        Console.WriteLine("Машины из всех салонов:");
        bool anyCars = false;

        foreach (var showroom in Showrooms)
        {
            foreach (var car in showroom.Cars)
            {
                Console.WriteLine($"Салон: {showroom.Name} | ID: {car.Id} | {car.Make} {car.Model} ({car.Year.Year})");
                anyCars = true;
            }
        }

        if (!anyCars)
        {
            Console.WriteLine("Нет машин в салонах.");
        }

        Console.ReadLine();
    }

    // Просмотр машин в салоне пользователя
    static void ViewCarsInShowroom(User user)
    {
        if (user.Showroom == null || user.Showroom.CarCount == 0)
        {
            Console.WriteLine("Нет машин в вашем салоне.");
        }
        else
        {
            foreach (var car in user.Showroom.Cars)
            {
                Console.WriteLine($"ID: {car.Id} | {car.Make} {car.Model} ({car.Year.Year})");
            }
        }
        Console.ReadLine();
    }

    static void SellCar(User user)
    {
        if (user.Showroom == null || user.Showroom.CarCount == 0)
        {
            Console.WriteLine("Нет машин для продажи в вашем салоне.");
            Console.ReadLine();
            return;
        }

        Console.WriteLine("Выберите машину для продажи из вашего салона:");
        for (int i = 0; i < user.Showroom.CarCount; i++)
        {
            var car = user.Showroom.Cars[i];
            Console.WriteLine($"{i + 1}. {car.Make} {car.Model} ({car.Year.Year})");
        }

        int choice = int.Parse(Console.ReadLine()) - 1;
        if (choice < 0 || choice >= user.Showroom.CarCount)
        {
            Console.WriteLine("Неверный выбор.");
            Console.ReadLine();
            return;
        }

        var carToSell = user.Showroom.Cars[choice];

        Console.Write("Введите цену продажи: ");
        decimal price = decimal.Parse(Console.ReadLine());

        var sale = new Sale
        {
            Car = carToSell,
            User = user,
            Showroom = user.Showroom,
            SaleDate = DateTime.Now,
            Price = price
        };

        Sales.Add(sale);
        user.Showroom.Cars.RemoveAt(choice);
        user.Showroom.SalesCount++;

        Console.WriteLine($"Машина {carToSell.Make} {carToSell.Model} продана.");
        Console.ReadLine();
    }

    static void EditCar(User user)
    {
        if (user.Showroom == null || user.Showroom.CarCount == 0)
        {
            Console.WriteLine("Нет машин в салоне.");
            Console.ReadLine();
            return;
        }

        Console.WriteLine("Выберите машину для редактирования:");
        for (int i = 0; i < user.Showroom.CarCount; i++)
        {
            var car = user.Showroom.Cars[i];
            Console.WriteLine($"{i + 1}. {car.Make} {car.Model} ({car.Year.Year})");
        }

        int choice = int.Parse(Console.ReadLine()) - 1;
        if (choice < 0 || choice >= user.Showroom.CarCount)
        {
            Console.WriteLine("Неверный выбор.");
            Console.ReadLine();
            return;
        }

        var carToEdit = user.Showroom.Cars[choice];

        Console.WriteLine("Редактирование машины:");
        Console.Write($"Марка ({carToEdit.Make}): ");
        string make = Console.ReadLine();
        Console.Write($"Модель ({carToEdit.Model}): ");
        string model = Console.ReadLine();
        Console.Write($"Год выпуска ({carToEdit.Year.Year}): ");
        int year = int.Parse(Console.ReadLine());

        carToEdit.Make = string.IsNullOrEmpty(make) ? carToEdit.Make : make;
        carToEdit.Model = string.IsNullOrEmpty(model) ? carToEdit.Model : model;
        carToEdit.Year = year == 0 ? carToEdit.Year : new DateTime(year, 1, 1);

        Console.WriteLine("Машина обновлена.");
        Console.ReadLine();
    }

    static void DeleteCar(User user)
    {
        if (user.Showroom == null || user.Showroom.CarCount == 0)
        {
            Console.WriteLine("Нет машин в салоне.");
            Console.ReadLine();
            return;
        }

        Console.WriteLine("Выберите машину для удаления:");
        for (int i = 0; i < user.Showroom.CarCount; i++)
        {
            var car = user.Showroom.Cars[i];
            Console.WriteLine($"{i + 1}. {car.Make} {car.Model} ({car.Year.Year})");
        }

        int choice = int.Parse(Console.ReadLine()) - 1;
        if (choice < 0 || choice >= user.Showroom.CarCount)
        {
            Console.WriteLine("Неверный выбор.");
            Console.ReadLine();
            return;
        }

        var carToDelete = user.Showroom.Cars[choice];
        user.Showroom.Cars.RemoveAt(choice);

        Console.WriteLine($"Машина {carToDelete.Make} {carToDelete.Model} удалена.");
        Console.ReadLine();
    }
}
