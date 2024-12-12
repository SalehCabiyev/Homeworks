#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

// Класс для автомобиля
class Car {
private:
    std::string model, licensePlate;

public:
    Car(std::string model, std::string licensePlate)
        : model(model), licensePlate(licensePlate) {}

    std::string toFileFormat() {
        return model + " " + licensePlate;
    }
};

// Класс для водителя
class Driver {
private:
    std::string id, name, email, phone, licenseNumber;
    std::vector<Car> cars;

public:
    Driver(std::string id, std::string name, std::string email, std::string phone, std::string licenseNumber)
        : id(id), name(name), email(email), phone(phone), licenseNumber(licenseNumber) {}

    std::string getID() const {
        return id;
    }

    std::string getName() const {
        return name;
    }

    void addCar(const std::string& model, const std::string& plate) {
        cars.push_back(Car(model, plate));
    }

    void showInfo() {
        std::cout << "Driver Info: \n";
        std::cout << "ID: " << id << "\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Email: " << email << "\n";
        std::cout << "Phone: " << phone << "\n";
        std::cout << "License Number: " << licenseNumber << "\n";
        std::cout << "Cars: \n";
        for (auto& car : cars) {
            std::cout << "Model: " << car.toFileFormat() << "\n";
        }
    }

    void editInfo() {
        std::cout << "Edit your info: \n";
        std::cout << "Enter new Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter new Email: ";
        std::getline(std::cin, email);
        std::cout << "Enter new Phone: ";
        std::getline(std::cin, phone);
        std::cout << "Information updated successfully!\n";
    }

    void addCarMenu() {
        std::string model, plate;
        std::cout << "Enter Car Model: ";
        std::getline(std::cin, model);
        std::cout << "Enter Car License Plate: ";
        std::getline(std::cin, plate);
        addCar(model, plate);
        std::cout << "Car added successfully!\n";
    }

    std::string toFileFormat() {
        std::string driverData = "Driver: " + id + " " + name + " " + email + " " + phone + " " + licenseNumber;
        for (auto& car : cars) {
            driverData += " " + car.toFileFormat();
        }
        return driverData;
    }
};

// Класс для поездки
class Trip {
private:
    std::string tripId, clientId, driverId;
    std::string startLocation, endLocation;

public:
    Trip(std::string tripId, std::string clientId, std::string driverId, std::string start, std::string end)
        : tripId(tripId), clientId(clientId), driverId(driverId), startLocation(start), endLocation(end) {}

    std::string toFileFormat() {
        return "Trip: " + tripId + " " + clientId + " " + driverId + " " + startLocation + " " + endLocation;
    }
};

// Класс для клиента
class Client {
private:
    std::string id, name, email, phone, password;

public:
    Client(std::string id, std::string name, std::string email, std::string phone, std::string password)
        : id(id), name(name), email(email), phone(phone), password(password) {}

    std::string getID() const { return id; }

    bool login(const std::string& pass) {
        return pass == password;
    }

    void showInfo() {
        std::cout << "Client Info: \n";
        std::cout << "ID: " << id << "\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Email: " << email << "\n";
        std::cout << "Phone: " << phone << "\n";
    }

    void editInfo() {
        std::cout << "Edit your info: \n";
        std::cout << "Enter new Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter new Email: ";
        std::getline(std::cin, email);
        std::cout << "Enter new Phone: ";
        std::getline(std::cin, phone);
        std::cout << "Information updated successfully!\n";
    }

    void bookTrip(std::vector<Driver*>& drivers, std::vector<Trip*>& trips) {
        std::cout << "Available drivers:\n";
        for (size_t i = 0; i < drivers.size(); ++i) {
            std::cout << i + 1 << ". " << drivers[i]->getID() << " - " << drivers[i]->getName() << "\n";
        }

        int choice;
        std::cout << "Enter driver number: ";
        std::cin >> choice;
        Driver* selectedDriver = drivers[choice - 1];

        std::string tripId = "T" + std::to_string(trips.size() + 1);
        std::string start, end;
        std::cout << "Enter start location: ";
        std::cin.ignore();
        std::getline(std::cin, start);
        std::cout << "Enter end location: ";
        std::getline(std::cin, end);

        Trip* newTrip = new Trip(tripId, this->getID(), selectedDriver->getID(), start, end);
        trips.push_back(newTrip);
        std::cout << "Trip booked successfully!\n";
    }

    std::string toFileFormat() {
        return "Client: " + id + " " + name + " " + email + " " + phone + " " + password;
    }
};

// Класс для компании такси
class TaxiCompany {
private:
    std::vector<Client*> clients;
    std::vector<Driver*> drivers;
    std::vector<Trip*> trips;

public:
    void registerClient() {
        std::string id, name, email, phone, password;
        std::cout << "Enter Client ID: ";
        std::cin >> id;
        std::cout << "Enter Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter Email: ";
        std::getline(std::cin, email);
        std::cout << "Enter Phone: ";
        std::getline(std::cin, phone);
        std::cout << "Enter Password: ";
        std::getline(std::cin, password);

        Client* newClient = new Client(id, name, email, phone, password);
        clients.push_back(newClient);
        std::cout << "Client registered successfully!\n";
    }

    void addDriver() {
        std::string id, name, email, phone, licenseNumber;
        std::cout << "Enter Driver ID: ";
        std::cin >> id;
        std::cout << "Enter Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter Email: ";
        std::getline(std::cin, email);
        std::cout << "Enter Phone: ";
        std::getline(std::cin, phone);
        std::cout << "Enter License Number: ";
        std::getline(std::cin, licenseNumber);

        Driver* newDriver = new Driver(id, name, email, phone, licenseNumber);
        drivers.push_back(newDriver);
        std::cout << "Driver added successfully!\n";
    }

    void showMenu() {
        while (true) {
            int choice;
            std::cout << "1. Register Client\n";
            std::cout << "2. Add Driver\n";
            std::cout << "3. Show Clients\n";
            std::cout << "4. Show Drivers\n";
            std::cout << "5. Book Trip\n";
            std::cout << "6. Exit\n";
            std::cout << "Enter choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    registerClient();
                    break;
                case 2:
                    addDriver();
                    break;
                case 3:
                    for (auto& client : clients) {
                        client->showInfo();
                    }
                    break;
                case 4:
                    for (auto& driver : drivers) {
                        driver->showInfo();
                    }
                    break;
                case 5:
                    for (auto& client : clients) {
                        client->bookTrip(drivers, trips);
                    }
                    break;
                case 6:
                    return;
                default:
                    std::cout << "Invalid choice. Try again.\n";
            }
        }
    }
};

int main() {
    TaxiCompany company;
    company.showMenu();
    return 0;
}
