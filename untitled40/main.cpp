#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>

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

public:
    std::string password;

    Driver(std::string id, std::string name, std::string email, std::string phone, std::string licenseNumber, std::string password)
        : User(id, name, email, phone), licenseNumber(licenseNumber), carAdded(false), password(password) {}

    bool login(const std::string& enteredPassword) {
        return enteredPassword == password;
    }

    void showInfo() override {
        std::cout << "Driver ID: " << ID << ", Name: " << name << ", Rating: " << rating << ", License: " << licenseNumber <<", email: "<<email<<", phone: "<<phone<<std::endl;
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
    }

    void addCar(std::string model, std::string licensePlate) {
        carModel = model;
        carLicensePlate = licensePlate;
        carAdded = true;
    }

    void updateCarInfo(std::string model, std::string licensePlate) {
        carModel = model;
        carLicensePlate = licensePlate;
    }

    void addTrip(const std::string& tripID) {
        trips.push_back(tripID);
    }

    void updateInfo(std::string newName, std::string newEmail, std::string newPhone) {
        name = newName;
        email = newEmail;
        phone = newPhone;
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
        std::cout << "Client ID: " << ID << ", Name: " << name << ", Rating: " << rating <<", email: "<<email<<", phone: "<<phone<< std::endl;
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

    void updateInfo(std::string newName, std::string newEmail, std::string newPhone) {
        name = newName;
        email = newEmail;
        phone = newPhone;
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

//евклидово расстояние
double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Функция для вычисления стоимости поездки
double calculateFare(double distance) {
    const double pricePerKm = 5.0; // стоимость за километр
    return distance * pricePerKm;
}

class TaxiCompany {
private:
    std::vector<Driver*> drivers;
    std::vector<Client*> clients;
    std::vector<std::string> trips;  // Список всех поездок

public:
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
        std::cout << "Enter Client Password: ";
        std::getline(std::cin, password);

        Client* client = new Client(id, name, email, phone, password);
        clients.push_back(client);
        std::cout << "Client Registered Successfully!" << std::endl;
    }

    Driver* driverLogin() {
        std::string id, password;
        std::cout << "Enter Driver ID: ";
        std::cin >> id;
        std::cout << "Enter Driver Password: ";
        std::cin >> password;

        for (auto driver : drivers) {
            if (driver->getID() == id && driver->login(password)) {
                std::cout << "Login Successful!" << std::endl;
                return driver;
            }
        }

        std::cout << "Invalid ID or Password." << std::endl;
        return nullptr;
    }

    Client* clientLogin() {
        std::string id, password;
        std::cout << "Enter Client ID: ";
        std::cin >> id;
        std::cout << "Enter Password: ";
        std::cin >> password;

        for (auto client : clients) {
            if (client->getID() == id && client->login(password)) {
                std::cout << "Login Successful!" << std::endl;
                return client;
            }
        }

        std::cout << "Invalid ID or Password." << std::endl;
        return nullptr;
    }

    void driverMenu(Driver* driver) {
        int choice;

        do {
            std::cout << "\n1. View Profile\n2. Edit Personal Info\n3. Add/Update Car Info\n4. View Trips\n5. Logout\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    driver->showInfo();
                    break;
                case 2: {
                    std::string name, email, phone;
                    std::cout << "Enter New Name: ";
                    std::cin.ignore();
                    std::getline(std::cin, name);
                    std::cout << "Enter New Email: ";
                    std::getline(std::cin, email);
                    std::cout << "Enter New Phone: ";
                    std::getline(std::cin, phone);
                    driver->updateInfo(name, email, phone);
                    std::cout << "Information Updated!" << std::endl;
                    break;
                }
                case 3: {
                    std::string model, licensePlate;
                    std::cout << "Enter Car Model: ";
                    std::cin.ignore();
                    std::getline(std::cin, model);
                    std::cout << "Enter Car License Plate: ";
                    std::getline(std::cin, licensePlate);
                    driver->addCar(model, licensePlate);
                    std::cout << "Car Added!" << std::endl;
                    break;
                }
                case 4:
                    driver->showInfo();
                    break;
                case 5:
                    std::cout << "Logging out..." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice!" << std::endl;
            }
        } while (choice != 5);
    }

    void clientMenu(Client* client) {
        int choice;

        do {
            std::cout << "\n1. View Profile\n2. Edit Personal Info\n3. Book Trip\n4. View Info\n5. Logout\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    client->showInfo();
                    break;
                case 2: {
                    std::string name, email, phone;
                    std::cout << "Enter New Name: ";
                    std::cin.ignore();
                    std::getline(std::cin, name);
                    std::cout << "Enter New Email: ";
                    std::getline(std::cin, email);
                    std::cout << "Enter New Phone: ";
                    std::getline(std::cin, phone);
                    client->updateInfo(name, email, phone);
                    std::cout << "Information Updated!" << std::endl;
                    break;
                }
                case 3: {
                    std::string from, to;
                    double x1, y1, x2, y2, distance;
                    std::cout << "Enter your location coordinates(x, y) and from: ";
                    std::cin >> x1 >> y1>>from;
                    std::cout << "Enter destination coordinates (x, y)and to: ";
                    std::cin >> x2 >> y2>>to;
                    distance = calculateDistance(x1, y1, x2, y2);
                    double fare = calculateFare(distance);

                    std::cout << "From: " << from << " To: " << to << " Distance: " << distance << " km. Fare: " << fare << " units." << std::endl;

                    client->bookTrip(from, to, distance);
                    client->addTripToHistory(from + " to " + to);
                    std::cout << "Trip Booked!" << std::endl;
                    break;
                }
                case 4:
                    client->showInfo();
                    break;
                case 5:
                    std::cout << "Logging out..." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice!" << std::endl;
            }
        } while (choice != 5);
    }

    void saveData() {
        std::ofstream outFile("data.txt");
        for (auto driver : drivers) {
            outFile << driver->toFileFormat() << std::endl;
        }
        for (auto client : clients) {
            outFile << client->toFileFormat() << std::endl;
        }
        for (auto trip : trips) {
            outFile << trip << std::endl;
        }
    }

    void loadData() {
        std::ifstream inFile("data.txt");
        std::string line;
        while (std::getline(inFile, line)) {
            std::stringstream ss(line);
            std::string type;
            ss >> type;
            if (type == "Driver:") {
                std::string id, name, email, phone, licenseNumber, password, carModel, carLicensePlate;
                ss >> id >> name >> email >> phone >> licenseNumber >> password;
                Driver* driver = new Driver(id, name, email, phone, licenseNumber, password);
                if (ss >> carModel >> carLicensePlate) {
                    driver->addCar(carModel, carLicensePlate);
                }
                drivers.push_back(driver);
            } else if (type == "Client:") {
                std::string id, name, email, phone, password;
                ss >> id >> name >> email >> phone >> password;
                Client* client = new Client(id, name, email, phone, password);
                clients.push_back(client);
            } else {
                trips.push_back(line);
            }
        }
    }
};

int main() {
    TaxiCompany company;
    company.loadData();

    int choice;
    do {
        std::cout << "\n1. Register Driver\n2. Register Client\n3. Login as Driver\n4. Login as Client\n5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                company.registerDriver();
                break;
            case 2:
                company.registerClient();
                break;
            case 3: {
                Driver* driver = company.driverLogin();
                if (driver) {
                    company.driverMenu(driver);
                }
                break;
            }
            case 4: {
                Client* client = company.clientLogin();
                if (client) {
                    company.clientMenu(client);
                }
                break;
            }
            case 5:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    } while (choice != 5);

    company.saveData();  // Сохраняем данные перед выходом
    return 0;
}
