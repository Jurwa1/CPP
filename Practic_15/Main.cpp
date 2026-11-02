#include <iostream>
#include "Structs.h"
#include "Functions.h"

int main () {
    int Help;
    Student Students[]{
    {"Alex", 19, 4.5, true},
    {"Bob", 21, 3.8, true},
    {"Max", 18, 2.9, false},
    {"Daniel", 20, 4.9, true},
    {"Oliver", 22, 3.4, true},
    {"Sophia", 19, 4.7, true},
    {"Emma", 18, 3.2, false},
    {"Lucas", 23, 4.1, true},
    {"Mia", 20, 4.8, true},
    {"James", 21, 5.0, false}
    };

    while (true) {
        std::cout << R"(===== STUDENT DATABASE =====

        1. Show all students
        2. Select student
        3. Change age
        4. Change grade
        5. Change enrollment status
        6. Find best student
        7. Swap students
        8. Exit
        
        Choose an action: )";

        std::cin >> Help;
        switch(Help){
            case 1:
            ShowAllStudents(Students, std::size(Students));
            break;
            case 2:
            ShowStudent(Students, std::size(Students));
            break;
            case 3:
            ChangeStudentAge(Students, std::size(Students));
            break;
            case 4:
            ChangeStudentGrade(Students, std::size(Students));
            break;
            case 5:
            ChangeStudentStatus(Students, std::size(Students));
            break;
            case 6:
            FindBestStudent(Students, std::size(Students));
            break;
            case 7:
            SwapStudents(Students, std::size(Students));
            break;
            case 8:
            std::cout << "Exiting the program...\n";
            return 0;
            default:
            std::cout << "Incorrect input. Try again\n";
        }
    }
}