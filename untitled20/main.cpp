#include <iostream>
#include <cstring>

class Course {
protected:
    char* _title;
    int _credits;

public:
    Course(const char* title, int credits) {
        _title = new char[strlen(title) + 1];
        strcpy(_title, title);
        _credits = credits;
    }

    virtual ~Course() {
        delete[] _title;
    }

    virtual void display() const {
        std::cout << "Course Title: " << _title << std::endl
                  << "Credits: " << _credits << std::endl;
    }
};

class OnlineCourse : public Course {
private:
    char* _platform;

public:
    OnlineCourse(const char* title, int credits, const char* platform)
        : Course(title, credits) {
        _platform = new char[strlen(platform) + 1];
        strcpy(_platform, platform);
    }

    ~OnlineCourse() {
        delete[] _platform;
    }

    void display() const override {
        Course::display();
        std::cout << "Platform: " << _platform << std::endl;
    }
};

class OfflineCourse : public Course {
private:
    char* _location;

public:
    OfflineCourse(const char* title, int credits, const char* location)
        : Course(title, credits) {
        _location = new char[strlen(location) + 1];
        strcpy(_location, location);
    }

    ~OfflineCourse() {
        delete[] _location;
    }

    void display() const override {
        Course::display();
        std::cout << "Location: " << _location << std::endl;
    }
};

class Student {
private:
    char* _name;
    int _age;
    Course** _courses;
    int _courseCount;

public:
    Student(const char* name, int age)
        : _age(age), _courses(nullptr), _courseCount(0) {
        _name = new char[strlen(name) + 1];
        strcpy(_name, name);
    }

    ~Student() {
        delete[] _name;
        for (int i = 0; i < _courseCount; i++) {
            delete _courses[i];
        }
        delete[] _courses;
    }

    void enrollCourse(Course* course) {
        Course** temp = new Course*[_courseCount + 1];
        for (int i = 0; i < _courseCount; i++) {
            temp[i] = _courses[i];
        }
        temp[_courseCount] = course;
        delete[] _courses;
        _courses = temp;
        _courseCount++;
    }

    void display() const {
        std::cout << "Student Name: " << _name << std::endl
                  << "Age: " << _age << std::endl
                  << "Enrolled Courses: " << std::endl;
        for (int i = 0; i < _courseCount; i++) {
            _courses[i]->display();
        }
    }
};

class University {
private:
    Course** _courses;
    Student** _students;
    int _courseCount;
    int _studentCount;

public:
    University() : _courseCount(0), _studentCount(0), _courses(nullptr), _students(nullptr) {}

    ~University() {
        for (int i = 0; i < _courseCount; i++) {
            delete _courses[i];
        }
        delete[] _courses;
        for (int i = 0; i < _studentCount; i++) {
            delete _students[i];
        }
        delete[] _students;
    }

    void addCourse(Course* course) {
        Course** temp = new Course*[_courseCount + 1];
        for (int i = 0; i < _courseCount; i++) {
            temp[i] = _courses[i];
        }
        temp[_courseCount] = course;
        delete[] _courses;
        _courses = temp;
        _courseCount++;
    }

    void addStudent(Student* student) {
        Student** temp = new Student*[_studentCount + 1];
        for (int i = 0; i < _studentCount; i++) {
            temp[i] = _students[i];
        }
        temp[_studentCount] = student;
        delete[] _students;
        _students = temp;
        _studentCount++;
    }

    void enrollStudentInCourse(Student* student, Course* course) {
        student->enrollCourse(course);
    }

    void display() const {
        std::cout << "University Courses: " << _courseCount << std::endl;
        for (int i = 0; i < _courseCount; ++i) {
            _courses[i]->display();
        }
        std::cout << "University Students: " << _studentCount << std::endl;
        for (int i = 0; i < _studentCount; ++i) {
            _students[i]->display();
        }
    }
};

int main() {
    University university;

    Course* course1 = new Course("Course 1", 10);
    university.addCourse(course1);

    OnlineCourse* online = new OnlineCourse("Online Course", 20, "Zoom");
    university.addCourse(online);

    OfflineCourse* offline = new OfflineCourse("Offline Course", 15, "Room 101");
    university.addCourse(offline);

    Student* student1 = new Student("Student 1", 30);
    university.addStudent(student1);
    university.enrollStudentInCourse(student1, course1);
    university.enrollStudentInCourse(student1, online);
    university.enrollStudentInCourse(student1, offline);

    university.display();

    return 0;
}
