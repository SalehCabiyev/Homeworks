#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <map>

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
    std::string carModel;
    std::string carLicensePlate;
    bool carAdded;
    std::vector<std::string> trips;
    bool available;

public:
    std::string password;

    Driver(std::string id, std::string name, std::string email, std::string phone, std::string licenseNumber, std::string password)
        : User(id, name, email, phone), licenseNumber(licenseNumber), carAdded(false), password(password), available(true) {}

    bool login(const std::string& enteredPassword) {
        return enteredPassword == password;
    }

    void showInfo() override {
        std::cout << "Driver ID: " << ID << ", Name: " << name << ", Rating: " << rating << ", License: " << licenseNumber << std::endl;
        if (carAdded) {
            std::cout << "Car Model: " << carModel << ", License Plate: " << carLicensePlate << std::endl;
        } else {
            std::cout << "No car added yet." << std::endl;
        }
        std::cout << "Trips: ";
        for (const auto& trip : trips) {
            std::cout << trip << " ";
        }
        std::cout << std::endl;
        std::cout << "Available: " << (available ? "Yes" : "No") << std::endl;
    }

    void addCar(std::string model, std::string licensePlate) {
        carModel = model;
        carLicensePlate = licensePlate;
        carAdded = true;
    }

    void addTrip(const std::string& tripID) {
        trips.push_back(tripID);
    }

    void setAvailability(bool status) {
        available = status;
    }

    bool isAvailable() const {
        return available;
    }

    std::string toFileFormat() const {
        std::stringstream ss;
        ss << "Driver:" << " " << ID << " " << name << " " << email << " " << phone << " " << licenseNumber;
        if (carAdded) {
            ss << " " << carModel << " " << carLicensePlate;
        }
        return ss.str();
    }
};

class Client : public User {
private:
    std::vector<std::string> tripHistory;
    std::string password;
    std::string currentTrip;

public:
    Client(std::string id, std::string name, std::string email, std::string phone, std::string password)
        : User(id, name, email, phone), password(password) {}

    bool login(const std::string& enteredPassword) {
        return enteredPassword == password;
    }

    void showInfo() override {
        std::cout << "Client ID: " << ID << ", Name: " << name << ", Rating: " << rating << std::endl;
        std::cout << "Current Trip: " << currentTrip << std::endl;
        std::cout << "Trip History: ";
        for (const auto& trip : tripHistory) {
            std::cout << trip << " ";
        }
        std::cout << std::endl;
    }

    void addTripToHistory(const std::string& tripDetails) {
        tripHistory.push_back(tripDetails);
    }

    void bookTrip(const std::string& from, const std::string& to, double distance) {
        currentTrip = "From: " + from + " To: " + to + " Distance: " + std::to_string(distance) + " km";
    }

    std::string toFileFormat() const {
        std::stringstream ss;
        ss << "Client:" << " " << ID << " " << name << " " << email << " " << phone << " " << password;
        return ss.str();
    }
};

// Функция для вычисления расстояния между двумя точками (Евклидова дистанция)
double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Функция для вычисления стоимости поездки
double calculateFare(double distance) {
    const double pricePerKm = 5.0; // Цена за километр
    return distance * pricePerKm;
}

class TaxiCompany {
private:
    std::map<std::string, Driver*> drivers;  // Хранение водителей по ID
    std::map<std::string, Client*> clients;  // Хранение клиентов по ID
    std::vector<std::string> pendingTrips;  // Список ожидающих поездок

public:
    void loadDriversFromFile() {
        std::ifstream file("drivers.txt");
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream ss(line);
            std::string type, id, name, email, phone, licenseNumber, carModel, carLicensePlate;
            ss >> type >> id >> name >> email >> phone >> licenseNumber;
            Driver* driver = new Driver(id, name, email, phone, licenseNumber, "");
            if (ss >> carModel >> carLicensePlate) {
                driver->addCar(carModel, carLicensePlate);
            }
            drivers[id] = driver;
        }
    }

    void loadClientsFromFile() {
        std::ifstream file("clients.txt");
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream ss(line);
            std::string type, id, name, email, phone, password;
            ss >> type >> id >> name >> email >> phone >> password;
            Client* client = new Client(id, name, email, phone, password);
            clients[id] = client;
        }
    }

    void saveDriversToFile() {
        std::ofstream file("drivers.txt");
        for (const auto& driverPair : drivers) {
            file << driverPair.second->toFileFormat() << std::endl;
        }
    }

    void saveClientsToFile() {
        std::ofstream file("clients.txt");
        for (const auto& clientPair : clients) {
            file << clientPair.second->toFileFormat() << std::endl;
        }
    }

    void registerDriver() {
        std::string id, name, email, phone, licenseNumber, password;
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
        std::cout << "Enter Driver Password: ";
        std::getline(std::cin, password);

        Driver* driver = new Driver(id, name, email, phone, licenseNumber, password);
        drivers[id] = driver;
        std::cout << "Driver Registered Successfully!" << std::endl;
    }

    void registerClient() {
        std::string id, name, email, phone, password;
        std::cout << "Enter Client ID: ";
        std::cin >> id;
        std::cin.ignore();

        std::cout << "Enter Client Name: ";
        std::getline(std::cin, name);
        std::cout << "Enter Client Email: ";
        std::getline(std::cin, email);
        std::cout << "Enter Client Phone: ";
        std::getline(std::cin, phone);
        std::cout << "Enter Client Password: ";
        std::getline(std::cin, password);

        Client* client = new Client(id, name, email, phone, password);
        clients[id] = client;
        std::cout << "Client Registered Successfully!" << std::endl;
    }

    Driver* driverLogin() {
        std::string id, password;
        std::cout << "Enter Driver ID: ";
        std::cin >> id;
        std::cout << "Enter Password: ";
        std::cin >> password;

        if (drivers.find(id) != drivers.end() && drivers[id]->login(password)) {
            std::cout << "Driver Logged In!" << std::endl;
            return drivers[id];
        } else {
            std::cout << "Invalid ID or Password!" << std::endl;
            return nullptr;
        }
    }

    Client* clientLogin() {
        std::string id, password;
        std::cout << "Enter Client ID: ";
        std::cin >> id;
        std::cout << "Enter Password: ";
        std::cin >> password;

        if (clients.find(id) != clients.end() && clients[id]->login(password)) {
            std::cout << "Client Logged In!" << std::endl;
            return clients[id];
        } else {
            std::cout << "Invalid ID or Password!" << std::endl;
            return nullptr;
        }
    }

    void showStartMenu() {
        int choice;
        std::cout << "1. Register Driver\n2. Register Client\n3. Login as Driver\n4. Login as Client\n5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                registerDriver();
                break;
            case 2:
                registerClient();
                break;
            case 3:
                driverLogin();
                break;
            case 4:
                clientLogin();
                break;
            case 5:
                saveDriversToFile();
                saveClientsToFile();
                std::cout << "Exiting...\n";
                exit(0);
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    }

    void run() {
        loadDriversFromFile();
        loadClientsFromFile();
        while (true) {
            showStartMenu();
        }
    }
};

int main() {
    TaxiCompany company;
    company.run();
    return 0;
}
