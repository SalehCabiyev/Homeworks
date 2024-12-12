
#include <algorithm>
#include <iostream>
#include <cstring>
struct book {
    char name[100];
    char author[100];
    char year_of_publication[100];
    char genre[100];
    bool yesorno;
};
void add_book(book book1,book books[100], int& count) {
    books[count]=book1;
    count++;
}
void show_all_books(int count,book books[100]) {
    for (int i = 0; i < count; i++) {
        std::cout << "book " << (i + 1) << ":" << std::endl;
        std::cout << "Name: " << books[i].name << std::endl;
        std::cout << "author: " << books[i].author << std::endl;
        std::cout << "year_of_publicatin: " << books[i].year_of_publication << std::endl;
        std::cout << "genre: " << books[i].genre << std::endl;
        std::cout << "---------------------------" << std::endl;
    }
}
void modify_book(book& book1) {
    std::cout << "Enter name: ";
    std::cin >> book1.name;

    std::cout << "Enter authot: ";
    std::cin >> book1.author;

    std::cout << "Enter year of publication: ";
    std::cin >> book1.year_of_publication;

    std::cout << "Enter genre: ";
    std::cin >> book1.genre;
}
void delete_book(book books[], int& count) {
    char search_param[100];
    std::cout << "Enter book name ";
    std::cin >> search_param;

    for (int i = 0; i < count; i++) {

        int j = 0;
        while (search_param[j] != '\0' || books[i].name[j] != '\0') {
            if (search_param[j] != books[i].name[j]) {
                break;
            }
            j++;
        }


        if (search_param[j] == '\0' && books[i].name[j] == '\0') {

            for (int k = i; k < count - 1; k++) {
                books[k] = books[k + 1];
            }
            count--;
            std::cout << "The book was successfully deleted.\n";
            return;
        }
    }
    std::cout << "Book not found.\n";
}

void search_book(int count, book books[100]) {
    char search_param[100];
    std::cout << "Enter parametr: ";
    std::cin >> search_param;

    for (int i = 0; i < count; i++) {
        int j = 0;
        while (search_param[j] != '\0' && books[i].name[j] != '\0') {
            if (search_param[j] != books[i].name[j]) {
                break;
            }
            j++;
        }
        if (search_param[j] == '\0' && books[i].name[j] == '\0') {
            std::cout << "Book found!" << std::endl;
            std::cout << "Name: " << books[i].name << std::endl;
            std::cout << "author: " << books[i].author << std::endl;
            std::cout << "year_of_publication: " << books[i].year_of_publication << std::endl;
            std::cout << "genre: " << books[i].genre << std::endl;
            return;
        }

        j = 0;
        while (search_param[j] != '\0' && books[i].author[j] != '\0') {
            if (search_param[j] != books[i].author[j]) {
                break;
            }
            j++;
        }
        if (search_param[j] == '\0' && books[i].author[j] == '\0') {
            std::cout << "Book found!" << std::endl;
            std::cout << "name: " << books[i].name << std::endl;
            std::cout << "author: " << books[i].author << std::endl;
            std::cout << "year_of_publication: " << books[i].year_of_publication << std::endl;
            std::cout << "genre: " << books[i].genre << std::endl;
            return;
        }

        j = 0;
        while (search_param[j] != '\0' && books[i].year_of_publication[j] != '\0') {
            if (search_param[j] != books[i].year_of_publication[j]) {
                break;
            }
            j++;
        }
        if (search_param[j] == '\0' && books[i].year_of_publication[j] == '\0') {
            std::cout << "Book found!" << std::endl;
            std::cout << "name: " << books[i].name << std::endl;
            std::cout << "author: " << books[i].author << std::endl;
            std::cout << "year_of_publication: " << books[i].year_of_publication << std::endl;
            std::cout << "genre: " << books[i].genre << std::endl;
            return;
        }

        j = 0;
        while (search_param[j] != '\0' && books[i].genre[j] != '\0') {
            if (search_param[j] != books[i].genre[j]) {
                break;
            }
            j++;
        }
        if (search_param[j] == '\0' && books[i].genre[j] == '\0') {
            std::cout << "Book found!" << std::endl;
            std::cout << "name: " << books[i].name << std::endl;
            std::cout << "author: " << books[i].author << std::endl;
            std::cout << "year_of_publication: " << books[i].year_of_publication << std::endl;
            std::cout << "genre: " << books[i].genre << std::endl;
            return;
        }
    }

    std::cout << "Book not found." << std::endl;
}
void changing_information(book books[100], int count ){
    char search_param[100];
    std::cout << "Enter name: ";
    std::cin >> search_param;

    for (int i = 0; i < count; i++) {
        int j = 0;
        while (search_param[j] != '\0' && books[i].name[j] != '\0') {
            if (search_param[j] != books[i].name[j]) {
                break;
            }
            j++;
        }
        if (search_param[j] == '\0' && books[i].name[j] == '\0') {
            std::cout<<"Book found"<< std::endl;
           modify_book(books[i]);

            return;
        }

    }
    std::cout << "Book not found" << std::endl;
    }

int main() {
    book books[100];


    book book1;
    int count=0;
    char choose=0;

    while (true) {
        std::cout<<"Menu:"<<std::endl;
        std::cout<<"0.Add book"<<std::endl;
        std::cout<<"1.Delete book"<<std::endl;
        std::cout<<"2.Changing information about a book"<<std::endl;
        std::cout<<"3.Search for a book"<<std::endl;
        std::cout<<"4.Show all books"<<std::endl;

        std::cout<<"enter the command(0-4):"<<std::endl;
        std::cin>>choose;
        if (choose == 0) {
            modify_book( book1);
            add_book(book1,books,count);
        }
        else if (choose==4) {show_all_books(count,books);

        }
        else if (choose==3){search_book(count,books);}
        else if (choose==2){changing_information(books,count);}
        else if (choose==1){delete_book(books,count);}
        else std::cout<<"wrong input"<<std::endl;
    }


    return 0;
}
