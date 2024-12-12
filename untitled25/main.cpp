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
};

class Trip {
private:
    std::string tripID;
    Client* client;
    Driver* driver;
    std::string departureLocation;
    std::string destination;
    double distance;
    double price;
    std::string status;

public:
    Trip(std::string tripID, Client* client, Driver* driver, std::string departure, std::string destination, double distance)
        : tripID(tripID), client(client), driver(driver), departureLocation(departure), destination(destination),
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
             << ", From: " << departureLocation << " to " << destination << ", Distance: " << distance
             << ", Price: $" << price << ", Status: " << status << std::endl;
    }

    std::string getTripID() const { return tripID; }
    double getPrice() const { return price; }
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
        std::cin.ignore(); // Чтобы избавиться от символа новой строки после ввода ID

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
        std::cin.ignore(); // Чтобы избавиться от символа новой строки после ввода ID

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
        std::cin.ignore(); // Чтобы избавиться от символа новой строки после ввода License Plate

        std::cout << "Enter Car Model: ";
        std::getline(std::cin, model);
        std::cout << "Enter Car Year: ";
        std::cin >> year;
        std::cout << "Enter Car Mileage: ";
        std::cin >> mileage;
        std::cin.ignore(); // Чтобы избавиться от символа новой строки после ввода Mileage
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
        std::cin.ignore(); // Чтобы избавиться от символа новой строки после ввода Driver ID

        std::cout << "Enter Departure Location: ";
        std::getline(std::cin, departure);
        std::cout << "Enter Destination Location: ";
        std::getline(std::cin, destination);
        std::cout << "Enter Distance: ";
        std::cin >> distance;

        Client* client = nullptr;
        Driver* driver = nullptr;

        // Поиск клиента и водителя по ID
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

        if (client && driver) {
            std::string tripID = "TRIP" + std::to_string(trips.size() + 1);
            Trip* newTrip = new Trip(tripID, client, driver, departure, destination, distance);
            trips.push_back(newTrip);
            driver->completeTrip();
            std::cout << "Trip Booked Successfully!" << std::endl;
        } else {
            std::cout << "Invalid Client or Driver ID!" << std::endl;
        }
    }

    // Печать аналитики
    void showAnalytics() {
        double totalRevenue = 0;
        for (auto trip : trips) {
            totalRevenue += trip->getPrice();
        }
        std::cout << "Total Revenue: $" << totalRevenue << std::endl;
    }

    // Сохранение данных в файл
    void saveData(const std::string& filename) {
        std::ofstream file(filename);
        for (auto trip : trips) {
            file << "Trip ID: " << trip->getTripID() << ", Price: " << trip->getPrice() << std::endl;
        }
        file.close();
    }
};

int main() {
    TaxiCompany company;
    int choice;

    do {
        std::cout << "\nMenu: \n";
        std::cout << "1. Register Driver\n";
        std::cout << "2. Register Client\n";
        std::cout << "3. Add Car\n";
        std::cout << "4. Book Trip\n";
        std::cout << "5. Show Analytics\n";
        std::cout << "6. Save Data\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

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
            company.showAnalytics();
            break;
        case 6:
            company.saveData("data.txt");
            break;
        case 7:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
