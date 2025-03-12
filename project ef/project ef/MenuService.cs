using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;

namespace project_ef
{
    public class MenuService
    {
        public void DisplayMainMenu()
        {
            Console.Clear();
            Console.WriteLine("=== Меню ===");
            Console.WriteLine("1. Регистрация ");
            Console.WriteLine("2. Вход");
            Console.WriteLine("3. Выйти из программы");
            Console.Write("Выберите опцию (1-3): ");

        }
        public void DisplayClientMenu(Client client, AutoServiceContext context)
        {
            Console.Clear();
            Console.WriteLine($"Добро пожаловать, {client.FirstName}!");
            Console.WriteLine("1. Добавить автомобиль");
            Console.WriteLine("2. Сделать заказ");
            Console.WriteLine("3. Подсчет общей стоимости заказа");
            Console.WriteLine("4. Вывод истории заказов");
            Console.WriteLine("5. Выйти в главное меню");
            Console.WriteLine("6. Просмотр профиля");
            Console.Write("Выберите опцию (1-6): ");

            HandleClientMenuChoice(client, context);
        }

        public void HandleMainMenuChoice(AutoServiceContext context)
        {

            int choice;


            while (true)
            {
                DisplayMainMenu();



                if (int.TryParse(Console.ReadLine(), out choice))
                {
                    switch (choice)
                    {
                        case 1:
                            RegisterClient(context);
                            break;
                        case 2:
                            LoginClient(context);
                            break;
                        case 3:
                            Console.WriteLine("Выход из программы...");
                            return;
                        default:
                            Console.WriteLine("Неверный выбор. Попробуйте снова.");
                            break;
                    }
                }
                else
                {
                    Console.WriteLine("Пожалуйста, введите число от 1 до 3.");
                }
            }
        }
        public void RegisterClient(AutoServiceContext context)
        {
            
            
                Console.Clear();
                Console.WriteLine("=== Регистрация клиента ===");

                Console.Write("Введите ваше имя: ");
                string firstName = Console.ReadLine();

                Console.Write("Введите вашу фамилию: ");
                string lastName = Console.ReadLine();

                Console.Write("Введите номер телефона: ");
                string phone = Console.ReadLine();

                Console.Write("Введите email: ");
                string email = Console.ReadLine();

                Console.Write("Введите пароль: ");
                string password = Console.ReadLine();
               

                var client = new Client
                {
                    FirstName = firstName,
                    LastName = lastName,
                    Phone = phone,
                    Email = email,
                    Password = password
                };



                context.Clients.Add(client);
                var passwordbase=context.Clients.FirstOrDefault(p=>p.Password==password);
                if (passwordbase!= null)
                {
                    Console.WriteLine("Этот пароль уже используется. Пожалуйста, выберите другой.");
                    Console.WriteLine("Нажмите любую клавишу для продолжения...");
                    Console.ReadKey();
                    return;

                }


            
            
                context.SaveChanges();

                Console.WriteLine("Клиент успешно зарегистрирован!");
                Console.WriteLine("Нажмите любую клавишу для продолжения...");
                Console.ReadKey();
            
        }
        public void LoginClient(AutoServiceContext context)
        {
            Console.Clear();
            Console.WriteLine("=== Вход в систему ===");

            Console.Write("Введите email: ");
            string email = Console.ReadLine();

            Console.Write("Введите пароль: ");
            string password = Console.ReadLine();


            var client = context.Clients.FirstOrDefault(c => c.Email == email && c.Password == password);

            if (client != null)
            {

                DisplayClientMenu(client, context);
            }
            else
            {
                Console.WriteLine("Неверный номер телефона или пароль.");
                Console.WriteLine("Нажмите любую клавишу для продолжения...");
                Console.ReadKey();
            }
        }
        public void HandleClientMenuChoice(Client client, AutoServiceContext context)
        {
            int choice;

            if (int.TryParse(Console.ReadLine(), out choice))
            {
                switch (choice)
                {
                    case 1:
                        AddCarToClient(client, context);
                        break;
                    case 2:
                        CreateServiceOrder(context, client);
                        break;
                    case 3:
                        CalculateOrderTotal(context, client);
                        break;
                    case 4:
                        ShowOrderHistory(context, client);
                        break;
                    case 5:
                        HandleMainMenuChoice(context);


                        return;
                    case 6:
                        Showprofil(context, client);

                        
                        break;
                    default:
                        Console.WriteLine("Неверный выбор. Попробуйте снова.");
                        break;
                }
            }
            else
            {
                Console.WriteLine("Неверный ввод. Попробуйте снова.");
            }

            Console.WriteLine("\nНажмите любую клавишу для продолжения...");
            Console.ReadKey();
        }
        public void AddCarToClient(Client client, AutoServiceContext context)
        {
            Console.Clear();
            Console.WriteLine("=== Добавление автомобиля ===");

            Console.Write("Введите марку автомобиля: ");
            string brand = Console.ReadLine();

            Console.Write("Введите модель автомобиля: ");
            string model = Console.ReadLine();

            Console.Write("Введите год выпуска: ");
            int year = int.Parse(Console.ReadLine());


            var car = new Car
            {

                Brand = brand,
                Model = model,
                Year = year,
                ClientId = client.ClientId
            };

            context.Cars.Add(car);
            context.SaveChanges();

            Console.WriteLine("Автомобиль успешно добавлен!");
            Console.ReadKey();
            DisplayClientMenu(client, context);

        }
        public void CreateServiceOrder(AutoServiceContext context, Client client)
        {
            while (true) {

                var order = new Order { ClientId = client.ClientId, Date = DateTime.Now, Status = "Ожидает" };
                context.Orders.Add(order);
                context.SaveChanges();
                Console.Clear();
                Console.WriteLine(" выберите заказ :");
                var services = context.Services.ToList();
                foreach (var service in services)
                {
                    Console.WriteLine($" {service.ServiceId}. {service.Name} {service.Price} манат");
                }
                int choice;
                int count=context.Services.Count();
                if (count > 0)
                {

                    if (int.TryParse(Console.ReadLine(), out choice))
                    {
                        if (choice <= count && choice >= 1)
                        {
                            var orderedService = new OrderedService { ServiceId = choice, OrderId = order.OrderId, Quantity = 1 };
                            context.OrderedServices.Add(orderedService);
                            context.SaveChanges();

                            Console.WriteLine($"Услуга {services.First(s => s.ServiceId == choice).Name} добавлена в заказ.");
                            break;
                        }
                    }
                }
                else { Console.WriteLine("нет сервисов");break; }

                




            }
            Console.WriteLine("Заказ оформлен");
            Console.ReadKey();
            DisplayClientMenu(client, context);


        }
        public void CalculateOrderTotal(AutoServiceContext context, Client client)
        {
        
            var activeOrders = context.Orders
                .Where(o => o.ClientId == client.ClientId && o.Status == "Ожидает") 
                .Include(o => o.OrderedServices) 
                .ThenInclude(os => os.Service)   
                .ToList();

            decimal total = 0;

           
            foreach (var order in activeOrders)
            {

            
                foreach (var orderedService in order.OrderedServices)
                {
                    
                   
                    total += orderedService.TotalPrice;
                }
            }
            Console.WriteLine();


            
            Console.WriteLine($"Общая сумма активных заказов клиента {client.FirstName} {client.LastName}: {total} манат");

            Console.WriteLine("Нажмите любую клавишу для продолжения...");
            Console.ReadKey();
            DisplayClientMenu(client, context);
        }
        public void ShowOrderHistory(AutoServiceContext context, Client client)
        {
            var activeOrders = context.Orders
                .Where(o => o.ClientId == client.ClientId)
                .Include(o => o.OrderedServices)
                .ThenInclude(os => os.Service)
                .ToList();

            decimal total = 0;


            foreach (var order in activeOrders)
            {


                foreach (var orderedService in order.OrderedServices)
                {
                    Console.WriteLine($"Id:{orderedService.OrderId}  время заказа : {order.Date} Услуга: {orderedService.Service.Name}, " +
                $"Цена: {orderedService.Service.Price} манат");


                    total += orderedService.TotalPrice;
                }
            }
            Console.WriteLine();



            

            Console.WriteLine("Нажмите любую клавишу для продолжения...");
            Console.ReadKey();
            DisplayClientMenu(client, context);



        }
        public void Showprofil(AutoServiceContext context, Client client)
        {
            var profil = context.Clients
                .Include(c => c.Cars)
                .FirstOrDefault(c => c.ClientId == client.ClientId);
                
            Console.WriteLine($"1.Id: {profil.ClientId}");
            Console.WriteLine($"2.Имя: {profil.FirstName}");
            Console.WriteLine($"3.Фамилия: {profil.LastName}");
            Console.WriteLine($"4.email: {profil.Email}");
            Console.WriteLine($"5.Номер: {profil.Phone}");
            if (profil.Cars != null) 
            {
                Console.WriteLine(" Машины: ");
                foreach (var car in profil.Cars)
                {
                    
                    Console.WriteLine($"- {car.Brand} {car.Model} ({car.Year})");
                }

            }
            else
            {
                Console.WriteLine("У клиента нет машин.");
            }

            Console.ReadKey();
            DisplayClientMenu(client,context);
        }






    }
}
