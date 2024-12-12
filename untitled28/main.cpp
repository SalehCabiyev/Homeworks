#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class User {
protected:
    std::string ID;
    std::string name;
    std::string email;
    std::string phone;
    double rating;

public:
    User(std::string id, std::string name, std::string email, std::string phone, double rating = 0)
        : ID(id), name(name), email(email), phone(phone), rating(rating) {}

    virtual void showInfo() = 0;

    std::string getID() const { return ID; }
    std::string getName() const { return name; }
    double getRating() const { return rating; }
    void updateRating(double newRating) { rating = newRating; }

    virtual ~User() {}
};

class Driver : public User {
private:
    std::string licenseNumber;
    int tripsCompleted;

public:
    Driver(std::string id, std::string name, std::string email, std::string phone, std::string licenseNumber)
        : User(id, name, email, phone), licenseNumber(licenseNumber), tripsCompleted(0) {}

    void showInfo() override {
        std::cout << "Driver ID: " << ID << ", Name: " << name << ", Rating: " << rating << ", License: " << licenseNumber << std::endl;
    }

    void completeTrip() {
        tripsCompleted++;
    }

    int getTripsCompleted() const { return tripsCompleted; }

    // Метод для сохранения данных водителя в файл
    void saveToFile(std::ofstream& outFile) {
        outFile << ID << " " << name << " " << email << " " << phone << " " << rating << " " << licenseNumber << " " << tripsCompleted << "\n";
    }

    // Метод для загрузки данных водителя из файла
    static Driver* loadFromFile(std::ifstream& inFile) {
        std::string id, name, email, phone, licenseNumber;
        double rating;
        int tripsCompleted;
        inFile >> id >> name >> email >> phone >> rating >> licenseNumber >> tripsCompleted;
        return new Driver(id, name, email, phone, licenseNumber);
    }
};

class Client : public User {
private:
    std::vector<std::string> tripHistory;

public:
    Client(std::string id, std::string name, std::string email, std::string phone)
        : User(id, name, email, phone) {}

    void showInfo() override {
        std::cout << "Client ID: " << ID << ", Name: " << name << ", Rating: " << rating << std::endl;
    }

    void addTripToHistory(const std::string& tripDetails) {
        tripHistory.push_back(tripDetails);
    }

    std::vector<std::string> getTripHistory() const { return tripHistory; }

    // Метод для сохранения данных клиента в файл
    void saveToFile(std::ofstream& outFile) {
        outFile << ID << " " << name << " " << email << " " << phone << " " << rating << "\n";
    }

    // Метод для загрузки данных клиента из файла
    static Client* loadFromFile(std::ifstream& inFile) {
        std::string id, name, email, phone;
        double rating;
        inFile >> id >> name >> email >> phone >> rating;
        return new Client(id, name, email, phone);
    }
};

class Car {
private:
    std::string licensePlate;
    std::string model;
    int year;
    double mileage;
    std::string condition;

public:
    Car(std::string licensePlate, std::string model, int year, double mileage, std::string condition)
        : licensePlate(licensePlate), model(model), year(year), mileage(mileage), condition(condition) {}

    void showInfo() {
        std::cout << "Car Model: " << model << ", License Plate: " << licensePlate << ", Year: " << year
             << ", Mileage: " << mileage << ", Condition: " << condition << std::endl;
    }

    void scheduleMaintenance() {
        std::cout << "Maintenance scheduled for " << model << std::endl;
    }

    std::string getLicensePlate() const { return licensePlate; }
    std::string getModel() const { return model; }

    // Метод для сохранения машины в файл
    void saveToFile(std::ofstream& outFile) {
        outFile << licensePlate << " " << model << " " << year << " " << mileage << " " << condition << "\n";
    }

    // Метод для загрузки машины из файла
    static Car* loadFromFile(std::ifstream& inFile) {
        std::string licensePlate, model, condition;
        int year;
        double mileage;
        inFile >> licensePlate >> model >> year >> mileage >> condition;
        return new Car(licensePlate, model, year, mileage, condition);
    }
};

class Trip {
private:
    std::string tripID;
    Client* client;
    Driver* driver;
    Car* car;
    std::string departureLocation;
    std::string destination;
    double distance;
    double price;
    std::string status;

public:
    Trip(std::string tripID, Client* client, Driver* driver, Car* car, std::string departure, std::string destination, double distance)
        : tripID(tripID), client(client), driver(driver), car(car), departureLocation(departure), destination(destination),
          distance(distance), status("Booked") {
        calculatePrice();
    }

    void calculatePrice() {
        price = distance * 1.0;  // Простой расчет: $1 за км
    }

    void updateStatus(const std::string& newStatus) {
        status = newStatus;
    }

    void showInfo() {
        std::cout << "Trip ID: " << tripID << ", Client: " << client->getName() << ", Driver: " << driver->getName()
             << ", Car: " << car->getModel() << ", From: " << departureLocation << " to " << destination
             << ", Distance: " << distance << ", Price: $" << price << ", Status: " << status << std::endl;
    }

    std::string getTripID() const { return tripID; }
    double getPrice() const { return price; }

    Client* getClient() const { return client; }
    Driver* getDriver() const { return driver; }
    Car* getCar() const { return car; }
    std::string getDepartureLocation() const { return departureLocation; }
    std::string getDestination() const { return destination; }
    double getDistance() const { return distance; }
    std::string getStatus() const { return status; }

    // Метод для сохранения поездки в файл
    void saveToFile(std::ofstream& outFile) {
        outFile << tripID << " " << client->getID() << " " << driver->getID() << " " << car->getLicensePlate()
                << " " << departureLocation << " " << destination << " " << distance << " " << price << " " << status << "\n";
    }

    // Метод для загрузки поездки из файла
    static Trip* loadFromFile(std::ifstream& inFile, std::vector<Client*>& clients, std::vector<Driver*>& drivers, std::vector<Car*>& cars) {
        std::string tripID, clientID, driverID, licensePlate, departureLocation, destination, status;
        double distance, price;
        inFile >> tripID >> clientID >> driverID >> licensePlate >> departureLocation >> destination >> distance >> price >> status;

        Client* client = nullptr;
        Driver* driver = nullptr;
        Car* car = nullptr;

        // Поиск клиента, водителя и машины по ID
        for (auto& c : clients) {
            if (c->getID() == clientID) {
                client = c;
                break;
            }
        }
        for (auto& d : drivers) {
            if (d->getID() == driverID) {
                driver = d;
                break;
            }
        }
        for (auto& c : cars) {
            if (c->getLicensePlate() == licensePlate) {
                car = c;
                break;
            }
        }

        return new Trip(tripID, client, driver, car, departureLocation, destination, distance);
    }
};

class TaxiCompany {
private:
    std::vector<Driver*> drivers;
    std::vector<Client*> clients;
    std::vector<Car*> cars;
    std::vector<Trip*> trips;

public:
    // Регистрация водителя
    void registerDriver() {
        std::string id, name, email, phone, licenseNumber;
        std::cout << "Enter Driver ID: ";
        std::cin >> id;
        std::cin.ignore();

        std::cout << "Enter Driver Name: ";
        std::getline(std::cin, name);
        std::cout << "Enter Driver Email: ";
        std::getline(std::cin, email);
        std::cout << "Enter Driver Phone: ";
        std::getline(std::cin, phone);
        std::cout << "Enter Driver License Number: ";
        std::getline(std::cin, licenseNumber);

        Driver* driver = new Driver(id, name, email, phone, licenseNumber);
        drivers.push_back(driver);
        std::cout << "Driver Registered Successfully!" << std::endl;
    }

    // Регистрация клиента
    void registerClient() {
        std::string id, name, email, phone;
        std::cout << "Enter Client ID: ";
        std::cin >> id;
        std::cin.ignore();

        std::cout << "Enter Client Name: ";
        std::getline(std::cin, name);
        std::cout << "Enter Client Email: ";
        std::getline(std::cin, email);
        std::cout << "Enter Client Phone: ";
        std::getline(std::cin, phone);

        Client* client = new Client(id, name, email, phone);
        clients.push_back(client);
        std::cout << "Client Registered Successfully!" << std::endl;
    }

    // Добавление машины
    void addCar() {
        std::string licensePlate, model, condition;
        int year;
        double mileage;

        std::cout << "Enter Car License Plate: ";
        std::cin >> licensePlate;
        std::cin.ignore();

        std::cout << "Enter Car Model: ";
        std::getline(std::cin, model);
        std::cout << "Enter Car Year: ";
        std::cin >> year;
        std::cout << "Enter Car Mileage: ";
        std::cin >> mileage;
        std::cin.ignore();
        std::cout << "Enter Car Condition: ";
        std::getline(std::cin, condition);

        Car* car = new Car(licensePlate, model, year, mileage, condition);
        cars.push_back(car);
        std::cout << "Car Added Successfully!" << std::endl;
    }

    // Создание поездки
    void bookTrip() {
        std::string clientID, driverID, departure, destination;
        double distance;

        std::cout << "Enter Client ID: ";
        std::cin >> clientID;
        std::cout << "Enter Driver ID: ";
        std::cin >> driverID;
        std::cin.ignore();

        std::cout << "Enter Departure Location: ";
        std::getline(std::cin, departure);
        std::cout << "Enter Destination Location: ";
        std::getline(std::cin, destination);
        std::cout << "Enter Distance: ";
        std::cin >> distance;

        Client* client = nullptr;
        Driver* driver = nullptr;
        Car* car = nullptr;

        // Поиск клиента, водителя и машины по ID
        for (auto& c : clients) {
            if (c->getID() == clientID) {
                client = c;
                break;
            }
        }
        for (auto& d : drivers) {
            if (d->getID() == driverID) {
                driver = d;
                break;
            }
        }

        if (client && driver && !cars.empty()) {
            car = cars.back(); // Используем последнюю добавленную машину для поездки

            std::string tripID = "TRIP" + std::to_string(trips.size() + 1);
            Trip* newTrip = new Trip(tripID, client, driver, car, departure, destination, distance);
            trips.push_back(newTrip);
            driver->completeTrip();
            client->addTripToHistory(tripID);
            std::cout << "Trip Booked Successfully!" << std::endl;
        } else {
            std::cout << "Invalid Client, Driver or No Cars Available!" << std::endl;
        }
    }

    // Печать всех поездок
    void showAllTrips() {
        if (trips.empty()) {
            std::cout << "No trips available!" << std::endl;
        }
        for (auto& trip : trips) {
            trip->showInfo();
        }
    }

    // Сохранение всех данных в файл
    void saveData() {
        std::ofstream outFile("taxi_company_data.txt");

        if (outFile.is_open()) {
            // Сохраняем водителей
            for (auto& driver : drivers) {
                driver->saveToFile(outFile);
            }

            // Сохраняем клиентов
            for (auto& client : clients) {
                client->saveToFile(outFile);
            }

            // Сохраняем машины
            for (auto& car : cars) {
                car->saveToFile(outFile);
            }

            // Сохраняем поездки
            for (auto& trip : trips) {
                trip->saveToFile(outFile);
            }

            outFile.close();
            std::cout << "Data Saved Successfully!" << std::endl;
        } else {
            std::cout << "Error opening file for saving!" << std::endl;
        }
    }

    // Загрузка всех данных из файла
    void loadData() {
        std::ifstream inFile("taxi_company_data.txt");

        if (!inFile.is_open()) {
            std::cout << "Error opening file for reading!" << std::endl;
            return;
        }

        std::string line;
        while (std::getline(inFile, line)) {
            // Загрузка водителей
            if (line.find("Driver") != std::string::npos) {
                Driver* driver = Driver::loadFromFile(inFile);
                drivers.push_back(driver);
            }

            // Загрузка клиентов
            if (line.find("Client") != std::string::npos) {
                Client* client = Client::loadFromFile(inFile);
                clients.push_back(client);
            }

            // Загрузка машин
            if (line.find("Car") != std::string::npos) {
                Car* car = Car::loadFromFile(inFile);
                cars.push_back(car);
            }

            // Загрузка поездок
            if (line.find("Trip") != std::string::npos) {
                Trip* trip = Trip::loadFromFile(inFile, clients, drivers, cars);
                trips.push_back(trip);
            }
        }

        inFile.close();
    }
};

int main() {
    TaxiCompany company;
    int choice;

    // Загружаем данные из файла при запуске программы
    company.loadData();

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Register Driver\n";
        std::cout << "2. Register Client\n";
        std::cout << "3. Add Car\n";
        std::cout << "4. Book Trip\n";
        std::cout << "5. Show All Trips\n";
        std::cout << "6. Save Data\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1:
            company.registerDriver();
            break;
        case 2:
            company.registerClient();
            break;
        case 3:
            company.addCar();
            break;
        case 4:
            company.bookTrip();
            break;
        case 5:
            company.showAllTrips();
            break;
        case 6:
            company.saveData();
            break;
        case 7:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice.\n";
        }
    } while (choice != 7);

    return 0;
}
