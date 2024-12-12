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
    std::string carModel;
    std::string carLicensePlate;
    bool carAdded;

public:
    Driver(std::string id, std::string name, std::string email, std::string phone, std::string licenseNumber)
        : User(id, name, email, phone), licenseNumber(licenseNumber), carAdded(false) {}

    void showInfo() override {
        std::cout << "Driver ID: " << ID << ", Name: " << name << ", Rating: " << rating << ", License: " << licenseNumber << std::endl;
        if (carAdded) {
            std::cout << "Car Model: " << carModel << ", License Plate: " << carLicensePlate << std::endl;
        } else {
            std::cout << "No car added yet." << std::endl;
        }
    }

    void addCar(std::string model, std::string licensePlate) {
        carModel = model;
        carLicensePlate = licensePlate;
        carAdded = true;
    }

    void updateInfo(std::string newName, std::string newEmail, std::string newPhone) {
        name = newName;
        email = newEmail;
        phone = newPhone;
    }

    void updateCarInfo(std::string model, std::string licensePlate) {
        carModel = model;
        carLicensePlate = licensePlate;
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
    std::vector<std::string> tripHistory;  // История поездок
    std::string password;  // Новый атрибут для пароля

public:
    Client(std::string id, std::string name, std::string email, std::string phone, std::string password)
        : User(id, name, email, phone), password(password) {}

    bool login(const std::string& enteredPassword) {
        return enteredPassword == password;
    }

    void showInfo() override {
        std::cout << "Client ID: " << ID << ", Name: " << name << ", Rating: " << rating << std::endl;
        std::cout << "Trip History: ";
        for (const auto& trip : tripHistory) {
            std::cout << trip << " ";
        }
        std::cout << std::endl;
    }

    void addTripToHistory(const std::string& tripDetails) {
        tripHistory.push_back(tripDetails);
    }

    void updateInfo(std::string newName, std::string newEmail, std::string newPhone) {
        name = newName;
        email = newEmail;
        phone = newPhone;
    }

    std::string toFileFormat() const {
        std::stringstream ss;
        ss << "Client:" << " " << ID << " " << name << " " << email << " " << phone << " " << password;
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

        // Ввод данных автомобиля
        std::string carModel, carLicensePlate;
        std::cout << "Enter Car Model: ";
        std::getline(std::cin, carModel);
        std::cout << "Enter Car License Plate: ";
        std::getline(std::cin, carLicensePlate);

        driver->addCar(carModel, carLicensePlate);
        drivers.push_back(driver);
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
        std::cout << "Enter Client Password: ";  // Добавляем запрос на пароль
        std::getline(std::cin, password);

        Client* client = new Client(id, name, email, phone, password);
        clients.push_back(client);
        std::cout << "Client Registered Successfully!" << std::endl;
    }

    void clientMenu(Client* client) {
        int choice;
        do {
            std::cout << "\n1. View Profile\n2. Edit Personal Info\n3. Book a Trip\n4. View Trips\n5. Logout\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    client->showInfo();
                    break;
                case 2:
                    {
                        std::string name, email, phone;
                        std::cout << "Enter New Name: ";
                        std::cin.ignore();
                        std::getline(std::cin, name);
                        std::cout << "Enter New Email: ";
                        std::getline(std::cin, email);
                        std::cout << "Enter New Phone: ";
                        std::getline(std::cin, phone);
                        client->updateInfo(name, email, phone);
                    }
                    break;
                case 3:
                    bookTrip(client);
                    break;
                case 4:
                    viewTrips(client);
                    break;
                case 5:
                    std::cout << "Logging out..." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice!" << std::endl;
            }
        } while (choice != 5);
    }

    void driverMenu(Driver* driver) {
        int choice;
        do {
            std::cout << "\n1. View Profile\n2. Edit Personal Info\n3. Update Car Info\n4. View Trips\n5. Logout\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    driver->showInfo();
                    break;
                case 2:
                    {
                        std::string name, email, phone;
                        std::cout << "Enter New Name: ";
                        std::cin.ignore();
                        std::getline(std::cin, name);
                        std::cout << "Enter New Email: ";
                        std::getline(std::cin, email);
                        std::cout << "Enter New Phone: ";
                        std::getline(std::cin, phone);
                        driver->updateInfo(name, email, phone);
                    }
                    break;
                case 3:
                    {
                        std::string model, plate;
                        std::cout << "Enter New Car Model: ";
                        std::cin.ignore();
                        std::getline(std::cin, model);
                        std::cout << "Enter New Car License Plate: ";
                        std::getline(std::cin, plate);
                        driver->updateCarInfo(model, plate);
                    }
                    break;
                case 4:
                    viewTrips(driver);
                    break;
                case 5:
                    std::cout << "Logging out..." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice!" << std::endl;
            }
        } while (choice != 5);
    }

    void bookTrip(Client* client) {
        std::string driverID, departure, destination;
        double distance;
        std::cout << "Enter Driver ID: ";
        std::cin >> driverID;
        std::cout << "Enter Departure Location: ";
        std::cin.ignore();
        std::getline(std::cin, departure);
        std::cout << "Enter Destination: ";
        std::getline(std::cin, destination);
        std::cout << "Enter Distance (in km): ";
        std::cin >> distance;

        Driver* driver = nullptr;
        for (auto& d : drivers) {
            if (d->getID() == driverID) {
                driver = d;
                break;
            }
        }

        if (driver) {
            std::string tripID = client->getID() + driverID;  // Trip ID = Client ID + Driver ID
            Trip* trip = new Trip(tripID, client, driver, departure, destination, distance);
            trips.push_back(trip);
            client->addTripToHistory(tripID);  // Добавляем поездку в историю клиента
            std::cout << "Trip Booked Successfully!" << std::endl;
        } else {
            std::cout << "Invalid Driver ID!" << std::endl;
        }
    }

    void viewTrips(Client* client) {
        for (auto& trip : trips) {
            if (trip->toFileFormat().find(client->getID()) != std::string::npos) {
                trip->showInfo();
            }
        }
    }

    void viewTrips(Driver* driver) {
        for (auto& trip : trips) {
            if (trip->toFileFormat().find(driver->getID()) != std::string::npos) {
                trip->showInfo();
            }
        }
    }

    void loginMenu() {
        int choice;
        do {
            std::cout << "\n1. Login as Driver\n2. Login as Client\n3. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    loginAsDriver();
                    break;
                case 2:
                    loginAsClient();
                    break;
                case 3:
                    std::cout << "Exiting..." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice!" << std::endl;
            }
        } while (choice != 3);
    }

    void loginAsDriver() {
        std::string id, password;
        std::cout << "Enter Driver ID: ";
        std::cin >> id;
        std::cout << "Enter Password: ";
        std::cin >> password;

        for (auto& driver : drivers) {
            if (driver->getID() == id) {
                driverMenu(driver);
                return;
            }
        }
        std::cout << "Driver not found!" << std::endl;
    }

    void loginAsClient() {
        std::string id, password;
        std::cout << "Enter Client ID: ";
        std::cin >> id;
        std::cout << "Enter Password: ";
        std::cin >> password;

        for (auto& client : clients) {
            if (client->getID() == id) {
                if (client->login(password)) {
                    clientMenu(client);
                } else {
                    std::cout << "Incorrect password!" << std::endl;
                }
                return;
            }
        }
        std::cout << "Client not found!" << std::endl;
    }

    void saveDataToFile(const std::string& filename) {
        std::ofstream file(filename);
        for (auto& driver : drivers) {
            file << driver->toFileFormat() << std::endl;
        }
        for (auto& client : clients) {
            file << client->toFileFormat() << std::endl;
        }
        for (auto& car : cars) {
            file << car->toFileFormat() << std::endl;
        }
        for (auto& trip : trips) {
            file << trip->toFileFormat() << std::endl;
        }
        file.close();
    }

    void loadDataFromFile(const std::string& filename) {
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream stream(line);
            std::string type;
            stream >> type;

            if (type == "Driver:") {
                std::string id, name, email, phone, licenseNumber, model, plate;
                stream >> id >> name >> email >> phone >> licenseNumber >> model >> plate;
                Driver* driver = new Driver(id, name, email, phone, licenseNumber);
                driver->addCar(model, plate);
                drivers.push_back(driver);
            } else if (type == "Client:") {
                std::string id, name, email, phone, password;
                stream >> id >> name >> email >> phone >> password;
                Client* client = new Client(id, name, email, phone, password);
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
    company.loadDataFromFile("data.txt");

    company.loginMenu();

    company.saveDataToFile("data.txt");
    return 0;
}
