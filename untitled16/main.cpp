#include <iostream>
#include <cstring>

class TeamMember {
private:
    char name[50];
    char role[50];

public:
    TeamMember(const char* memberName, const char* memberRole) {
        strncpy(name, memberName, 49);
        name[49] = '\0';
        strncpy(role, memberRole, 49);
        role[49] = '\0';
    }

    const char* getName() const {
        return name;
    }

    void setName(const char* memberName) {
        strncpy(name, memberName, 49);
        name[49] = '\0';
    }

    const char* getRole() const {
        return role;
    }

    void setRole(const char* memberRole) {
        strncpy(role, memberRole, 49);
        role[49] = '\0';
    }

    void print() const {
        std::cout << "TeamMember: " << name << ", role: " << role << std::endl;
    }
};

class Task {
private:
    char title[50];
    char status[20];
    int assignedMember;

public:

    Task() : assignedMember(-1) {
        title[0] = '\0';
        status[0] = '\0';
    }

    Task(const char* taskTitle, const char* taskStatus, int memberIndex) {
        strncpy(title, taskTitle, 49);
        title[49] = '\0';
        strncpy(status, taskStatus, 19);
        status[19] = '\0';
        assignedMember = memberIndex;
    }

    const char* getTitle() const {
        return title;
    }

    void setTitle(const char* taskTitle) {
        strncpy(title, taskTitle, 49);
        title[49] = '\0';
    }

    const char* getStatus() const {
        return status;
    }

    void setStatus(const char* taskStatus) {
        strncpy(status, taskStatus, 19);
        status[19] = '\0';
    }

    int getAssignedMember() const {
        return assignedMember;
    }

    void print() const {
        std::cout << "task: " << title << ", status: " << status
                  << ", assignedMember index: " << assignedMember << std::endl;
    }
};

class Project {
private:
    char name[50];
    Task tasks[10];
    int taskCount;

public:
    Project(const char* projectName) : taskCount(0) {
        strncpy(name, projectName, 49);
        name[49] = '\0';
    }

    void addTask(const Task& task) {
        if (taskCount < 10) {
            tasks[taskCount] = task;
            taskCount++;
        } else {
            std::cout << "Maximum task limit reached." << std::endl;
        }
    }

    void printTasks() const {
        std::cout << "Tasks in the project:" << std::endl;
        for (int i = 0; i < taskCount; ++i) {
            tasks[i].print();
        }
    }

    void getTasksByMember(int memberIndex) const {
        std::cout << "Tasks assigned to member with index " << memberIndex << ":" << std::endl;
        for (int i = 0; i < taskCount; ++i) {
            if (tasks[i].getAssignedMember() == memberIndex) {
                std::cout << i << " ";
            }
        }
        std::cout << std::endl;
    }

    void print() const {
        std::cout << "Project: " << name << ", Number of tasks: " << taskCount << std::endl;
    }
};


int main() {

    TeamMember member1("alisa", "Developer");
    TeamMember member2("bob", "Tester");


    Task task1("Development of function A", "in progress", 0);
    Task task2("Testing function A", "new", 1);


    Project project("Project X");


    project.addTask(task1);
    project.addTask(task2);


    project.print();
    project.printTasks();


    project.getTasksByMember(1);

    return 0;
}
