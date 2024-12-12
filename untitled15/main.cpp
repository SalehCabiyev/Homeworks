#include <fstream>
#include <stdio.h>
#include <iostream>
#include <cstring>
struct book {
    char name[100];
    char author[100];
    char year_of_publication[100];
    char genre[100];
    bool yesorno;
};
void print_book_struct(int count ,book newbooks[100]) {
    for (size_t i = 0; i < count; i++) {
        std::cout <<"book "<< i+1 <<std::endl;
        std::cout<<"Name: " << newbooks[i].name<<std::endl;
        std::cout<<"author: " << newbooks[i].author<<std::endl;
        std::cout<<"year_of_publication: " << newbooks[i].year_of_publication<<std::endl;
        std::cout<<"genre: " << newbooks[i].genre<<std::endl;
        std::cout<<"yesorno: " << newbooks[i].yesorno<<std::endl;

    }
}
void to_lowercase(char str[100]) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}
int read_from_file(book newbooks[100], int count) {
    FILE*bookf=nullptr;
    fopen_s(&bookf,"file.bin","rb");
    if (bookf==nullptr){printf("File error!\n");return 1;}
    fread(newbooks,sizeof(book),count,bookf);
    fclose(bookf);


    return 0;
}
int upload_to_file(book books[100], int count) {
    FILE*bookf=nullptr;
    fopen_s( &bookf,"file.bin","wb");
    if (bookf==nullptr) {
        printf("File error!\n");
        return 1;
    }
    fwrite(books,sizeof(book),count,bookf);
    fclose(bookf);
    return 0;


}
void add_book(book book1,book books[100], int& count) {
    books[count]=book1;
    count++;
}

void modify_book(book& book1) {
    std::cout << "Enter name: ";
    std::cin.ignore();
    std::cin.getline(book1.name, 100);

    std::cout << "Enter author: ";
    std::cin.getline(book1.author, 100);

    std::cout << "Enter year of publication: ";
    std::cin.getline(book1.year_of_publication, 100);

    std::cout << "Enter genre: ";
    std::cin.getline(book1.genre, 100);

    to_lowercase(book1.name);
    to_lowercase(book1.author);
    to_lowercase(book1.year_of_publication);
    to_lowercase(book1.genre);
}
void delete_book(book books[], int& count) {
    char search_param[100];
    std::cout << "Enter book name ";
    std::cin.ignore();
    std::cin.getline(search_param, 100);
    to_lowercase(search_param);

    for (int i = 0; i < count; i++) {
        char lower_name[100];
        strcpy(lower_name, books[i].name);
        to_lowercase(lower_name);

        int j = 0;
        while (lower_name[j] != '\0' && search_param[j] != '\0') {
            if (lower_name[j] != search_param[j]) {
                break;
            }
            j++;
        }


        if (lower_name[j] == '\0' && search_param[j] == '\0') {
            std::cout << "Book found" << std::endl;
            modify_book(books[i]); //
            return;
        }
    }
    std::cout << "Book not found" << std::endl;
}


void search_book(int count, book books[100]) {
    char search_param[200];
    std::cout << "Enter parametr: ";
    std::cin.ignore();
    std::cin.getline(search_param, 200);
    to_lowercase(search_param);
    for (int i = 0; i < count; i++) {
        char lower_name[100], lower_author[100], lower_year[100], lower_genre[100];
        strcpy(lower_name, books[i].name);
        strcpy(lower_author, books[i].author);
        strcpy(lower_year, books[i].year_of_publication);
        strcpy(lower_genre, books[i].genre);

        to_lowercase(lower_name);
        to_lowercase(lower_author);
        to_lowercase(lower_year);
        to_lowercase(lower_genre);


        for (int j = 0; j < 4; j++) {
            const char* current_field = nullptr;
            switch (j) {
                case 0: current_field = lower_name; break;
                case 1: current_field = lower_author; break;
                case 2: current_field = lower_year; break;
                case 3: current_field = lower_genre; break;
            }

            int k = 0;
            while (current_field[k] != '\0' || search_param[k] != '\0') {
                if (current_field[k] != search_param[k]) {
                    break;
                }
                k++;
            }

            if (current_field[k] == '\0' && search_param[k] == '\0') {
                std::cout << "Book found!" << std::endl;
                std::cout << "Name: " << books[i].name << std::endl;
                std::cout << "Author: " << books[i].author << std::endl;
                std::cout << "Year of Publication: " << books[i].year_of_publication << std::endl;
                std::cout << "Genre: " << books[i].genre << std::endl;
                return;
            }
        }
    }

    std::cout << "Book not found." << std::endl;
}

void changing_information(book books[100], int count ){
    char search_param[100];
    std::cout << "Enter name: ";
    std::cin.ignore();
    std::cin.getline(search_param, 100);
    to_lowercase(search_param);
    for (int i = 0; i < count; i++) {
        char lower_name[100];
        strcpy(lower_name, books[i].name);
        to_lowercase(lower_name);
        int j = 0;
        while (lower_name[j] != '\0' && search_param[j] != '\0') {
            if (lower_name[j] != search_param[j]) {
                break;
            }
            j++;
        }
        if (lower_name[j] == '\0' && search_param[j] == '\0') {
            std::cout << "Book found" << std::endl;
            modify_book(books[i]);
            return;
        }

    }
    std::cout << "Book not found" << std::endl;


    }

int main() {
    book books[100];
    book newbooks[100];

    book book1;
    int count=0;
    int choose=0;

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
            upload_to_file(books,count);
        }
        else if (choose==4) {read_from_file(newbooks,count);print_book_struct(count,newbooks);}
        else if (choose==3){search_book(count,books);}
        else if (choose==2){changing_information(books,count);upload_to_file(books,count);}
        else if (choose==1){delete_book(books,count);upload_to_file(books,count);}
        else std::cout<<"wrong input"<<std::endl;
    }


    return 0;
}
