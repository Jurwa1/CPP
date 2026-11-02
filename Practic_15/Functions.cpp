#include <iostream>
#include "Structs.h"
#include <cstdlib>
#include <chrono>

void ShowAllStudents(const Student* arr, int size) {
    for (int i{0}; i<size; ++arr, ++i){
        std::cout << "Student: " << arr->name << "\n";
    }
}

void ShowStudent(Student* arr, int size) {
    std::string name;
    std::cout << "Input student name: ";
    std::cin >> name;
    for (int i = 0; i < size; ++arr, ++i) {
        if (arr->name == name) {
            std::cout << "Student name: " << arr->name << "\n" << "Student age: " << arr->age << "\n" << "Student average grade: " << arr->grade << "\n" << "Enrollment status: " << (arr->isEnrolled ? "Enrolled" : "Expelled") << "\n";
            return;
        }
    }

    std::cout << "Error: Incorrect name. try again";
    std::chrono::seconds(3);
    return;
}

void ChangeStudentAge(Student* arr, int size) {
    std::cout << "Input student name: ";
    std::string name;
    int help;

    std::cin >> name;

    for (int i = 0; i < size; ++arr, ++i) {
        if (arr->name == name) {
            std::cout << "Input new age of student " << arr->name << ": ";
            std::cin >> help;

            if (help > 0){
                arr->age = help;
                return;
            }

            else {
                std::cout << "Error: incorrect input. Try again";
                return;
            }
        }
    }

    std::cout << "Student not found. Try again" << "\n";
}

void ChangeStudentGrade(Student* arr, int size) {
    std::cout << "Input student name: ";
    std::string name;
    double help;

    std::cin >> name;

    for (int i = 0; i < size; ++arr, ++i) {
        if (arr->name == name) {
            std::cout << "Input new grade of student " << arr->name << ": ";
            std::cin >> help;
//ЫЫЫЫ СИКС-СЕВЕН
            if (help >= 2.0){
                arr->grade = help;
                return;
            }

            else {
                std::cout << "Error: incorrect input. Try again";
                return;
            }
        }
    }
    std::cout << "Student not found. Try again" << "\n";
}

void ChangeStudentStatus(Student* arr, int size) {
    std::cout << "Input student name: ";
    std::string name;
    std::string help;

    std::cin >> name;

    for (int i = 0; i < size; ++arr, ++i) {
        if (arr->name == name) {
            std::cout << "Input new status of student " << arr->name << " (Enrolled/Expelled): ";
            std::cin >> help;

            if (help == "Enrolled"){
                arr->isEnrolled = true;
                return;
            }

            else if (help == "Expelled") {
                arr->isEnrolled = false;
                return;
            }

            else {
                std::cout << "Error: incorrect input. Try again";
                return;
            }
        }
    }
    std::cout << "Student not found. Try again" << "\n";
}

void FindBestStudent(Student* arr, int size){
    Student* help{nullptr};
    double BestScore;

    for (int i = 0; i < size; ++arr, ++i) {
        if (arr->grade > BestScore){
            help = arr;
        }
    }

    std::cout << "Best student name: " << help->name;
}

void SwapStudents(Student* arr, int size){
    Student* HelpPtr1{nullptr};
    Student* HelpPtr2{arr};

    std::string name1;
    std::string name2;

    std::cout << "Input first student name: ";
    std::cin >> name1;
    std::cout << "Input second strudent name: ";
    std::cin >> name2;

    for (int i = 0; i < size; ++arr, ++i){
        if (name1 == arr->name){
            HelpPtr1 = arr;
        }
    }

    if (HelpPtr1 != nullptr) {
        for (int i = 0; i < size; ++HelpPtr2, ++i){
            if (name2 == HelpPtr2->name){

                *HelpPtr1 = *HelpPtr2;
                *HelpPtr2 = *arr;
                break;
            }
        }
    }

    std::cout << "Error: student not found";
}