#include <iostream>
#include <cstring>


struct Student
{
    struct Grades {
        char math[20];
        char eng [30];
        char physics[20];
        char chemistry [45];
        char computer_science[50];
    };

    char name[25];
    char  age[30];
    char gpa[40];
    char email[50];
    char phone[20];
    Grades grades;
};
void addstudent(Student *&people,int&count,const Student&newpeople) {
    Student*emptypeople=new Student[count+1];
   for (int i=0;i<count;i++) {
       emptypeople[i]=people[i];
   }
    emptypeople[count]=newpeople;
    count++;
    delete[] people;
    people = emptypeople;
}
void showstudens(const Student* students,int count) {
    for (size_t i = 0; i < count; i++)
    {
        std::cout << "index  "<<i << std::endl<<"name "<< students[i].name << std::endl;
        std::cout <<"age  " <<students[i].age << std::endl;
        std::cout << "gpa  "<<students[i].gpa << std::endl;
        std::cout << "email  "<<students[i].email << std::endl;
        std::cout <<"phone"<< students[i].phone << std::endl;

        std::cout<<"chemistry  "<< students[i].grades.chemistry << std::endl;
        std::cout<<"computer_science  " << students[i].grades.computer_science << std::endl;
        std::cout<<"eng  "<< students[i].grades.eng << std::endl;
        std::cout<<"math  "<< students[i].grades.math << std::endl;
        std::cout<<"physics  "<< students[i].grades.physics << std::endl;

        std::cout << "\n\n";
    }
}
    void deleteStudent(Student *&people, int &count, int index) {
            if (index < 0 || index >= count) {
                std::cout << "error index" << std::endl;
                return;
            }

            Student *temp = new Student[count - 1];
            for (int i = 0, j = 0; i < count; i++) {
                if (i != index) {
                    temp[j++] = people[i];
                }
            }
            count--;
            delete[] people;
            people = temp;

            std::cout << "student udalen." << std::endl;
        }
int choose_parametr(Student*people, const char *choose_symbol,int count) {
    for (int i = 0; i < count; i++) {
        if (strstr(people[i].name, choose_symbol  ) || strstr(people[i].age, choose_symbol  )|| strstr(people[i].gpa, choose_symbol  )|| strstr(people[i].email, choose_symbol  )|| strstr(people[i].phone, choose_symbol  )|| strstr(people[i].grades.chemistry, choose_symbol  )|| strstr(people[i].grades.computer_science, choose_symbol  )|| strstr(people[i].grades.eng, choose_symbol  )|| strstr(people[i].grades.math, choose_symbol  )|| strstr(people[i].grades.physics, choose_symbol  )!= nullptr) {
            return i;
        }
    }
    return -1;
}


int main() {
    Student* students = nullptr;
    int count = 0;
    int choice =0;
    char delete_parametr[60];
    char choose_symbol[100];
while (true) {
    std::cout<<"Menu:"<<std::endl;
    std::cout<<"0.Add:"<<std::endl;
    std::cout<<"1.Delete:"<<std::endl;
    std::cout<<"2.Show:"<<std::endl;
    std::cout<<"3.Exit:"<<std::endl;
    std::cout<<"4.choose:"<<std::endl;
    std::cout<<"viberite funkciyu:"<<std::endl;
    std::cin>>choice ;
    Student student;

    if (choice ==0) {

        std::cout<<"enter name:";
        std::cin>> student.name;
        std::cout<<"enter age:";
        std::cin>> student.age;
        std::cout<<"enter gpa:";
        std::cin>> student.gpa;
        std::cout<<"enter email:";
        std::cin>> student.email;
        std::cout<<"enter phone:";
        std::cin>> student.phone;
        std::cout<<"enter math:";
        std::cin>> student.grades.math;
        std::cout<<"enter eng:";
        std::cin>> student.grades.eng;
        std::cout<<"enter physics:";
        std::cin>> student.grades.physics;
        std::cout<<"enter chemistry:";
        std::cin>> student.grades.chemistry;
        std::cout<<"enter computer_science:";
        std::cin>> student.grades.computer_science;

        addstudent(students, count, student);
    }
    else if (choice==1) {
        std::cout <<"enter index: ";
        int index;
        std::cin >> index;
        deleteStudent(students, count, index);


    }
    else if (choice ==2) {
        showstudens(students,count);

    }
    else if (choice ==3){break;}
    else if (choice==4) {
        std::cout<<"vvedite danniye:";
        std::cin>>choose_symbol;
        int found_index= choose_parametr(students,choose_symbol,count);
        if (found_index != -1) {
            std::cout << " student  nayden: "<< std::endl<<"name  " <<students[found_index].name <<std::endl<<"age  "<<students[found_index].age<< std::endl<<"gpa  "<<students[found_index].gpa<< std::endl<<"email  "<<students[found_index].email<< std::endl<<"phone  "<<students[found_index].phone<< std::endl;
        } else {
            std::cout << "student ne nayden." << std::endl;
        }
    }
}
    delete[] students;


}