#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

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

    std::string toFileFormat() const {
        std::stringstream ss;
        ss << "Driver:" << " " << ID << " " << name << " " << email << " " << phone << " " << licenseNumber;
        return ss.str();
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

    std::string toFileFormat() const {
        std::stringstream ss;
        ss << "Client:" << " " << ID << " " << name << " " << email << " " << phone;
        return ss.str();
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

    std::string toFileFormat() const {
        std::stringstream ss;
        ss << "Car:" << " " << licensePlate << " " << model << " " << year << " " << mileage << " " << condition;
        return ss.str();
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

    std::string toFileFormat() const {
        std::stringstream ss;
        ss << "Trip:" << " " << tripID << " " << client->getID() << " " << driver->getID() << " "
           << departureLocation << " " << destination << " " << distance;
        return ss.str();
    }
};

class TaxiCompany {
private:
    std::vector<Driver*> drivers;
    std::vector<Client*> clients;
    std::vector<Car*> cars;
    std::vector<Trip*> trips;

public:
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

    void addCar() {
        std::string licensePlate, model, condition;
        int year;
        double mileage;

        std::cout << "Enter Car License Plate: ";
        std::cin >> licensePlate;
        std::cout << "Enter Car Model: ";
        std::cin >> model;
        std::cout << "Enter Car Year: ";
        std::cin >> year;
        std::cout << "Enter Car Mileage: ";
        std::cin >> mileage;
        std::cout << "Enter Car Condition: ";
        std::cin >> condition;

        Car* car = new Car(licensePlate, model, year, mileage, condition);
        cars.push_back(car);
        std::cout << "Car Added Successfully!" << std::endl;
    }

    void bookTrip() {
        std::string clientID, driverID, departure, destination;
        double distance;

        std::cout << "Enter Client ID: ";
        std::cin >> clientID;
        std::cout << "Enter Driver ID: ";
        std::cin >> driverID;
        std::cout << "Enter Departure Location: ";
        std::cin >> departure;
        std::cout << "Enter Destination: ";
        std::cin >> destination;
        std::cout << "Enter Distance (in km): ";
        std::cin >> distance;

        Client* client = nullptr;
        Driver* driver = nullptr;

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
            Trip* trip = new Trip(clientID + driverID, client, driver, departure, destination, distance);
            trips.push_back(trip);
            std::cout << "Trip Booked Successfully!" << std::endl;
        } else {
            std::cout << "Invalid Client or Driver ID!" << std::endl;
        }
    }

    // Функция для анализа и отображения всей информации
    void showAnalytics() {
        std::cout << "\n--- Company Analytics ---\n";

        // Вывод информации о водителях
        std::cout << "\nDrivers:\n";
        for (auto driver : drivers) {
            driver->showInfo();
        }

        // Вывод информации о клиентах
        std::cout << "\nClients:\n";
        for (auto client : clients) {
            client->showInfo();
        }

        // Вывод информации о автомобилях
        std::cout << "\nCars:\n";
        for (auto car : cars) {
            car->showInfo();
        }

        // Вывод информации о поездках
        std::cout << "\nTrips:\n";
        for (auto trip : trips) {
            trip->showInfo();
        }
    }

    // Сохранение данных в файл
    void saveData(const std::string& filename) {
        std::ofstream file(filename);

        // Записываем водителей
        for (auto driver : drivers) {
            file << driver->toFileFormat() << std::endl;
        }

        // Записываем клиентов
        for (auto client : clients) {
            file << client->toFileFormat() << std::endl;
        }

        // Записываем автомобили
        for (auto car : cars) {
            file << car->toFileFormat() << std::endl;
        }

        // Записываем поездки
        for (auto trip : trips) {
            file << trip->toFileFormat() << std::endl;
        }

        file.close();
    }

    // Загрузка данных из файла
    void loadDataFromFile(const std::string& filename) {
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream stream(line);
            std::string type;
            stream >> type;

            if (type == "Driver:") {
                std::string id, name, email, phone, licenseNumber;
                stream >> id >> name >> email >> phone >> licenseNumber;
                Driver* driver = new Driver(id, name, email, phone, licenseNumber);
                drivers.push_back(driver);
            } else if (type == "Client:") {
                std::string id, name, email, phone;
                stream >> id >> name >> email >> phone;
                Client* client = new Client(id, name, email, phone);
                clients.push_back(client);
            } else if (type == "Car:") {
                std::string licensePlate, model, condition;
                int year;
                double mileage;
                stream >> licensePlate >> model >> year >> mileage >> condition;
                Car* car = new Car(licensePlate, model, year, mileage, condition);
                cars.push_back(car);
            } else if (type == "Trip:") {
                std::string tripID, clientID, driverID, departure, destination;
                double distance;
                stream >> tripID >> clientID >> driverID >> departure >> destination >> distance;
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
                    Trip* trip = new Trip(tripID, client, driver, departure, destination, distance);
                    trips.push_back(trip);
                }
            }
        }

        file.close();
    }
};

int main() {
    TaxiCompany company;
    company.loadDataFromFile("data.txt");  // Загрузка данных из файла
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
