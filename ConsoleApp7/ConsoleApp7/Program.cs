// See https://aka.ms/new-console-template for more information
using System;
using System.Security.Cryptography;

public class Transport
{
    private string _Type;
    private string _Brand;
    private string _Model;
    private int _Year;
    private int _MaxSpeed;
    public Transport(string type, string brand, string model, int year, int maxspeed)
    {
        _Type = type;
        _Brand = brand;
        _Model = model;
        _Year = year;
        _MaxSpeed = maxspeed;

    }
    public string Type
    {
        get => _Type;
        set => _Type = value;

    }
    public string Brand
    {
        get => _Brand;
        set => _Brand = value;

    }
    public string Model
    {
        get => _Model;
        set => _Model = value;

    }
    public int Year
    {
        get => _Year;
        set => _Year = value;

    }
    public int Maxspeed
    {
        get => _MaxSpeed;
        set => _MaxSpeed = value;

    }
    public void ShowInfo()
    {
        Console.WriteLine($"Type:{_Type}");
        Console.WriteLine($"Brand :{_Brand}");
        Console.WriteLine($"Model:{_Model}");
        Console.WriteLine($"Year:{_Year}");
        Console.WriteLine($"Maxspeed:{_MaxSpeed}");
    }
    public virtual void Move()
    {
        Console.WriteLine("start moving ");
    }
    public class Car : Transport
    {
        public string FuelType;
        public Car(string type, string brand, string model, int year, int maxspeed, string fueltype) : base(type, brand, model, year, maxspeed)
        {
            FuelType = fueltype;
        }
        public override void Move()
        {
            Console.WriteLine($"Автомобиль{_Brand} {_Model}едет по дороге со скоростью до {_MaxSpeed} км/ч.”");
        }


    }
    public class Truck : Transport
    {
        public int LoadCapacity;
        public Truck(string type, string brand, string model, int year, int maxspeed, int loadcapacity) : base(type, brand, model, year, maxspeed)
        {
            LoadCapacity = loadcapacity;

        }
        public override void Move()
        {
            Console.WriteLine($"Грузовик {_Brand} {_Model} перевозит груз.");

        }
    }
    public class Bike : Transport
    {
        bool HasSidecar;
        public Bike(string type, string brand, string model, int year, int maxspeed, bool hasSidecar) : base(type, brand, model, year, maxspeed)
        {
            HasSidecar = hasSidecar;

        }
        public override void Move()
        {
            Console.WriteLine($"Мотоцикл {_Brand} {_Model} мчится по дороге");
        }




    }
    public class Bus : Transport
    {
        public int PassengerCapacity;
        public Bus(string type, string brand, string model, int year, int maxspeed, int passengerCapacity) : base(type, brand, model, year, maxspeed)
        {
            PassengerCapacity = passengerCapacity;
        }
        public override void Move()
        {
            Console.WriteLine($"Автобус {_Brand} {_Model} перевозит пассажиров");
        }
    }
    public class Avtopark
    {
        private List<Transport> list = new List<Transport>();
        public void AddTransport(Transport transport)
        {
            list.Add(transport);
        }
        public void ShowTransport()
        {
            foreach (Transport transport in list)
            {

                Console.WriteLine($"index{list.IndexOf(transport)}");
                transport.ShowInfo();
            }
        }
        public void movetransport(int index)
        {
            if (index >= 0 && index < list.Count)
            {
                list[index].Move();
            }
            else { Console.WriteLine("Eror index"); }

        }
        public void removetransport(int index)
        {
            if (index >= 0 && index < list.Count)
            {
                list.RemoveAt(index);
                Console.WriteLine("Transport removed successfuly");
            }
            else { Console.WriteLine("index Error"); }
        }
        public void filterbytype(string type)
        {
            foreach (Transport transport in list) 
            {
                if (type == transport.Type)
                {
                    transport.ShowInfo();
                }
            }
    }
}

 class Proqram
{
        static void Main()
        {
            Avtopark avtopark = new Avtopark();

            

            while (true)
            {
                Console.WriteLine("Меню:");
                Console.WriteLine("1.Добавить транспортное средство:");
                Console.WriteLine("2.Показать все транспортные средства:");
                Console.WriteLine("3.Запустить транспорт:");
                Console.WriteLine("4.Удалить транспортное средство:");
                Console.WriteLine("5.Фильтрация транспорта по типу:");
                Console.WriteLine("6.Выход");
                Console.WriteLine("выберите операцию");

                int choose = 0;
                int.TryParse(Console.ReadLine(), out choose);
                switch (choose)
                {

                    case 1:
                        Console.WriteLine("Выберите тип транспорта (Car, Truck, Bike, Bus):");
                        string cartype = Console.ReadLine();

                        if (cartype == "Car")
                        {
                            Console.WriteLine("Введите марку автомобиля: ");
                            string carbrand = Console.ReadLine();
                            Console.WriteLine("Введите модель автомобиля:");
                            string carModel = Console.ReadLine();
                            Console.WriteLine("Введите год выпуска:");
                            int carYear = int.Parse(Console.ReadLine());
                            Console.WriteLine("Введите максимальную скорость:");
                            int carMaxSpeed = int.Parse(Console.ReadLine());
                            Console.WriteLine("Введите тип топлива:");
                            string fuelType = Console.ReadLine();
                            avtopark.AddTransport(new Car(cartype,carbrand, carModel, carYear, carMaxSpeed, fuelType));
                        }
                        else if (cartype == "Truck")
                        {
                            Console.WriteLine("Введите марку грузовика:");
                            string truckBrand = Console.ReadLine();
                            Console.WriteLine("Введите модель грузовика:");
                            string truckModel = Console.ReadLine();
                            Console.WriteLine("Введите год выпуска:");
                            int truckYear = int.Parse(Console.ReadLine());
                            Console.WriteLine("Введите максимальную скорость:");
                            int truckMaxSpeed = int.Parse(Console.ReadLine());
                            Console.WriteLine("Введите грузоподъемность (в тоннах):");
                            int loadCapacity = int.Parse(Console.ReadLine());
                            avtopark.AddTransport(new Truck(cartype,truckBrand, truckModel, truckYear, truckMaxSpeed, loadCapacity));
                        }
                        else if (cartype == "Bike")
                        {
                            
                            Console.WriteLine("Введите марку мотоцикла:");
                            string bikeBrand = Console.ReadLine();
                            Console.WriteLine("Введите модель мотоцикла:");
                            string bikeModel = Console.ReadLine();
                            Console.WriteLine("Введите год выпуска:");
                            int bikeYear = int.Parse(Console.ReadLine());
                            Console.WriteLine("Введите максимальную скорость:");
                            int bikeMaxSpeed = int.Parse(Console.ReadLine());
                            Console.WriteLine("Есть ли коляска (true/false):");
                            bool hasSidecar = bool.Parse(Console.ReadLine());
                            avtopark.AddTransport(new Bike(cartype,bikeBrand, bikeModel, bikeYear, bikeMaxSpeed, hasSidecar));
                        }
                        else if (cartype == "Bus")
                        {
                            
                            Console.WriteLine("Введите марку автобуса:");
                            string busBrand = Console.ReadLine();
                            Console.WriteLine("Введите модель автобуса:");
                            string busModel = Console.ReadLine();
                            Console.WriteLine("Введите год выпуска:");
                            int busYear = int.Parse(Console.ReadLine());
                            Console.WriteLine("Введите максимальную скорость:");
                            int busMaxSpeed = int.Parse(Console.ReadLine());
                            Console.WriteLine("Введите количество пассажиров:");
                            int passengerCapacity = int.Parse(Console.ReadLine());
                            avtopark.AddTransport(new Bus(cartype,busBrand, busModel, busYear, busMaxSpeed, passengerCapacity));
                        }
                        else
                        {
                            Console.WriteLine("Неверный тип транспорта.");
                        }
                        break;
                    case 2:avtopark.ShowTransport();break;
                        case 3:
                        Console.WriteLine("Введите индекс транспорта:");
                        int transport_index = 0;
                        int.TryParse(Console.ReadLine(),out transport_index);
                        avtopark.movetransport(transport_index);break;
                    case 4:
                        Console.WriteLine("Введите индекс транспорта:");
                        int transport_rindex = 0;
                        int.TryParse(Console.ReadLine(), out transport_rindex);
                        avtopark.removetransport(transport_rindex);break;
                    case 5:
                        Console.WriteLine("Выберите тип транспорта (Car, Truck, Bike, Bus):");
                            string typeofcar=Console.ReadLine();
                       avtopark.filterbytype(typeofcar);
                        break;
                    case 6: Console.WriteLine("Exiting..."); return;
                    default:
                        Console.WriteLine("Неверный выбор. Попробуйте снова.");
                        break;


                }


            }
        }
    }
}
