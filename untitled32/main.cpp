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
    std::string password; // Store password for login

public:
    User(std::string id, std::string name, std::string email, std::string phone, std::string password, double rating = 0)
        : ID(id), name(name), email(email), phone(phone), password(password), rating(rating) {}

    virtual void showInfo() = 0;

    std::string getID() const { return ID; }
    std::string getName() const { return name; }
    double getRating() const { return rating; }
    void updateRating(double newRating) { rating = newRating; }

    bool authenticate(std::string inputPassword) {
        return password == inputPassword;
    }

    virtual ~User() {}
};

class Driver : public User {
private:
    std::string licenseNumber;
    int tripsCompleted;

public:
    Driver(std::string id, std::string name, std::string email, std::string phone, std::string password, std::string licenseNumber)
        : User(id, name, email, phone, password), licenseNumber(licenseNumber), tripsCompleted(0) {}

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

    std::string getLicensePlate() const { return licenseNumber; }
};

class Client : public User {
private:
    std::vector<std::string> tripHistory;

public:
    Client(std::string id, std::string name, std::string email, std::string phone, std::string password)
        : User(id, name, email, phone, password) {}

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

    void setName(const std::string& name) { this->name = name; }
    void setEmail(const std::string& email) { this->email = email; }
    void setPhone(const std::string& phone) { this->phone = phone; }
};

class TaxiCompany {
private:
    std::vector<Driver*> drivers;
    std::vector<Client*> clients;

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
        std::cout << "Enter Password: ";
        std::getline(std::cin, password);

        Driver* driver = new Driver(id, name, email, phone, password, licenseNumber);
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
        std::cout << "Enter Password: ";
        std::getline(std::cin, password);

        Client* client = new Client(id, name, email, phone, password);
        clients.push_back(client);
        std::cout << "Client Registered Successfully!" << std::endl;
    }

    User* authenticateUser(std::string id, std::string password) {
        for (auto& driver : drivers) {
            if (driver->getID() == id && driver->authenticate(password)) {
                return driver;
            }
        }
        for (auto& client : clients) {
            if (client->getID() == id && client->authenticate(password)) {
                return client;
            }
        }
        return nullptr;  // Invalid credentials
    }

    void showDriverMenu(Driver* driver) {
        int choice;
        do {
            std::cout << "\nDriver Menu:\n";
            std::cout << "1. Complete Trip\n";
            std::cout << "2. View Trip Details\n";
            std::cout << "3. Logout\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    driver->completeTrip();
                    std::cout << "Trip Completed!" << std::endl;
                    break;
                case 2:
                    driver->showInfo();
                    break;
                case 3:
                    std::cout << "Logging out..." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Try again." << std::endl;
            }
        } while (choice != 3);
    }

    void showClientMenu(Client* client) {
        int choice;
        do {
            std::cout << "\nClient Menu:\n";
            std::cout << "1. View Trip History\n";
            std::cout << "2. Logout\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    for (const auto& trip : client->getTripHistory()) {
                        std::cout << trip << std::endl;
                    }
                    break;
                case 2:
                    std::cout << "Logging out..." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Try again." << std::endl;
            }
        } while (choice != 2);
    }
};

int main() {
    TaxiCompany company;
    int choice;

    // Register users
    company.registerDriver();
    company.registerClient();

    // Authentication process
    std::string id, password;
    std::cout << "Enter your ID: ";
    std::cin >> id;
    std::cout << "Enter your Password: ";
    std::cin >> password;

    User* loggedInUser = company.authenticateUser(id, password);

    if (loggedInUser) {
        std::cout << "Login Successful!" << std::endl;

        // Check if the logged-in user is a driver or client
        if (Driver* driver = dynamic_cast<Driver*>(loggedInUser)) {
            company.showDriverMenu(driver);
        } else if (Client* client = dynamic_cast<Client*>(loggedInUser)) {
            company.showClientMenu(client);
        }
    } else {
        std::cout << "Invalid credentials!" << std::endl;
    }

    return 0;
}
