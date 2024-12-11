using System;

public enum FuelType
{
    Petrol,
    Diesel,
    Electric,
    Hybrid
}

public enum BodyType
{
    Sedan,
    Hatchback,
    SUV,
    Minivan,
    Bus
}

public class Transport
{
    public string Carnumber { get; set; }
    public string Make { get; set; } 
    public string Model { get; set; }
    public int Year { get; set; } 
    public FuelType Fuel { get; set; } 
    public BodyType Body { get; set; } 

    public Transport(string carnumber, string make, string model, int year, FuelType fuel, BodyType body)
    {
        Carnumber = carnumber;
        Make = make;
        Model = model;
        Year = year;
        Fuel = fuel;
        Body = body;
    }

    public virtual void DisplayInfo()
    {
        Console.WriteLine($"{Make} {Model} {Year} {Fuel} {Body} {Carnumber}");
    }
}

public class Car : Transport
{
    public int Doors { get; set; }

    public Car(string carnumber, string make, string model, int year, FuelType fuel, BodyType body, int doors)
        : base(carnumber, make, model, year, fuel, body)
    {
        Doors = doors;
    }

    public override void DisplayInfo()
    {
        base.DisplayInfo();
        Console.WriteLine($"Doors: {Doors}");
    }
}

public class Bus : Transport
{
    public int Seats { get; set; }

    public Bus(string carnumber, string make, string model, int year, FuelType fuel, BodyType body, int seats)
        : base(carnumber, make, model, year, fuel, body)
    {
        Seats = seats;
    }

    public override void DisplayInfo()
    {
        base.DisplayInfo();
        Console.WriteLine($"Seats: {Seats}");
    }
}

public class FleetManager
{
    private Transport[] vehicles = new Transport[100];
    private int vehicleCount = 0;

    public void AddVehicle(Transport vehicle)
    {
        if (vehicleCount < vehicles.Length)
        {
            vehicles[vehicleCount++] = vehicle;
        }
        else
        {
            Console.WriteLine("Fleet is full. Cannot add more vehicles.");
        }
    }

    public void RemoveVehicle(string carnumber)
    {
        for (int i = 0; i < vehicleCount; i++)
        {
            if (vehicles[i].Carnumber == carnumber)
            {
                
                for (int j = i; j < vehicleCount - 1; j++)
                {
                    vehicles[j] = vehicles[j + 1];
                }
                vehicles[vehicleCount - 1] = null; 
                vehicleCount--; 
                Console.WriteLine("Vehicle removed.");
                return;
            }
        }
        Console.WriteLine("Vehicle not found.");
    }

    public void EditVehicle(string carnumber, string make, string model, int year, FuelType fuel, BodyType body)
    {
        for (int i = 0; i < vehicleCount; i++)
        {
            if (vehicles[i].Carnumber == carnumber)
            {
                vehicles[i].Make = make;
                vehicles[i].Model = model;
                vehicles[i].Year = year;
                vehicles[i].Fuel = fuel;
                vehicles[i].Body = body;
                Console.WriteLine("Vehicle details updated.");
                return;
            }
        }
        Console.WriteLine("Vehicle not found.");
    }

    public void DisplayAllVehicles()
    {
        if (vehicleCount == 0)
        {
            Console.WriteLine("No vehicles in the fleet.");
        }
        else
        {
            for (int i = 0; i < vehicleCount; i++)
            {
                vehicles[i].DisplayInfo();
                Console.WriteLine();
            }
        }
    }
}

class Program
{
    static void Main(string[] args)
    {
        FleetManager fleetManager = new FleetManager();

        while (true)
        {
            Console.WriteLine("Fleet Manager Menu:");
            Console.WriteLine("1. Add Vehicle");
            Console.WriteLine("2. Edit Vehicle");
            Console.WriteLine("3. Remove Vehicle");
            Console.WriteLine("4. Display All Vehicles");
            Console.WriteLine("5. Exit");
            Console.Write("Choose an option: ");
            string choice = Console.ReadLine();

            switch (choice)
            {
                case "1":
                   
                    Console.WriteLine("Enter vehicle details:");
                    Console.Write("Car Number: ");
                    string carnumber = Console.ReadLine();
                    Console.Write("Make: ");
                    string make = Console.ReadLine();
                    Console.Write("Model: ");
                    string model = Console.ReadLine();
                    Console.Write("Year: ");
                    int year = int.Parse(Console.ReadLine());
                    Console.Write("Fuel (0=Petrol, 1=Diesel, 2=Electric, 3=Hybrid): ");
                    FuelType fuel = (FuelType)Enum.Parse(typeof(FuelType), Console.ReadLine(),);
                    Console.Write("Body (0=Sedan, 1=Hatchback, 2=SUV, 3=Minivan, 4=Bus): ");
                    BodyType body = (BodyType)Enum.Parse(typeof(BodyType), Console.ReadLine());

                    Console.Write("Is it a Car (1) or Bus (2): ");
                    string vehicleType = Console.ReadLine();
                    if (vehicleType == "1")
                    {
                        Console.Write("Number of doors: ");
                        int doors = int.Parse(Console.ReadLine());
                        fleetManager.AddVehicle(new Car(carnumber, make, model, year, fuel, body, doors));
                    }
                    else if (vehicleType == "2")
                    {
                        Console.Write("Number of seats: ");
                        int seats = int.Parse(Console.ReadLine());
                        fleetManager.AddVehicle(new Bus(carnumber, make, model, year, fuel, body, seats));
                    }
                    break;

                case "2":
                    
                    Console.Write("Enter car number of the vehicle to edit: ");
                    carnumber = Console.ReadLine();
                    Console.Write("Enter new vehicle details:\nMake: ");
                    make = Console.ReadLine();
                    Console.Write("Model: ");
                    model = Console.ReadLine();
                    Console.Write("Year: ");
                    year = int.Parse(Console.ReadLine());
                    Console.Write("Fuel (0=Petrol, 1=Diesel, 2=Electric, 3=Hybrid): ");
                    fuel = (FuelType)Enum.Parse(typeof(FuelType), Console.ReadLine());
                    Console.Write("Body (0=Sedan, 1=Hatchback, 2=SUV, 3=Minivan, 4=Bus): ");
                    body = (BodyType)Enum.Parse(typeof(BodyType), Console.ReadLine());

                    fleetManager.EditVehicle(carnumber, make, model, year, fuel, body);
                    break;

                case "3":
                    
                    Console.Write("Enter car number of the vehicle to remove: ");
                    carnumber = Console.ReadLine();
                    fleetManager.RemoveVehicle(carnumber);
                    break;

                case "4":
                    
                    fleetManager.DisplayAllVehicles();
                    break;

                case "5":
                    
                    return;

                default:
                    Console.WriteLine("Invalid option. Please try again.");
                    break;
            }
        }
    }
}
