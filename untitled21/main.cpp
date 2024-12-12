#include <iostream>
#include <cstring>

class BookNotFoundException {
public:
    const char* what() const {
        return "Book not found in the library.";
    }
};

class LibraryCapacityExceededException {
public:
    const char* what() const {
        return "Library capacity exceeded.";
    }
};


class Item {
protected:
    char* title;

public:
    Item(const char* title) {
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
    }

    virtual ~Item() {
        delete[] title;
    }

    virtual const char* getInfo() const = 0;
};
class Book : public Item {
private:
    char* author;
    int publicationYear;

public:
    Book(const char* title, const char* author, int publicationYear)
        : Item(title), publicationYear(publicationYear) {
        this->author = new char[strlen(author) + 1];
        strcpy(this->author, author);
    }

    ~Book() {
        delete[] author;
    }

    const char* getInfo() const override {

        char* info = new char[256];
        strcpy(info, "Book: ");
        strcat(info, title);
        strcat(info, ", Author: ");
        strcat(info, author);
        strcat(info, ", Year: ");
        return info;
    }
};
class Library {
private:
    Item** items;
    int size;
    int capacity;

public:
    Library(int capacity) : size(0), capacity(capacity) {
        items = new Item*[capacity];
    }

    ~Library() {
        for (int i = 0; i < size; i++) {
            delete items[i];
        }
        delete[] items;
    }

    void addItem(Item* item) {
        if (size >= capacity) {
            throw LibraryCapacityExceededException();
        }
        items[size++] = item;
    }

    void removeItem(const char* title) {
        for (int i = 0; i < size; i++) {
            if (strcmp(items[i]->getInfo(), title) == 0) {
                delete items[i];
                items[i] = items[size - 1];
                size--;
                return;
            }
        }
        throw BookNotFoundException();
    }

    void listItems() const {
        for (int i = 0; i < size; i++) {
            std::cout << items[i]->getInfo() << std::endl;
        }
    }
};
//dalse ne uspel

