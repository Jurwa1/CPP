#include <iostream>
#include <random>
#include "functions.h"

int Random (int min, int max){
    static std::mt19937 x {std::random_device{}()};
	std::uniform_int_distribution y{ min, max };
	int result = y(x);
	return result;
}

std::ostream& operator<<(std::ostream& out, const HTTP& method) {
    switch (method) {
        case HTTP::Get:    out << "GET";    break;
        case HTTP::Post:   out << "POST";   break;
        case HTTP::Delete: out << "DELETE"; break;
        default:           out << "UNKNOWN"; break;
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, const UserNames& role) {
    switch (role) {
        case UserNames::Admin: out << "Admin"; break;
        case UserNames::User:  out << "User";  break;
        case UserNames::Guest: out << "Guest"; break;
        default:               out << "Unknown"; break;
    }
    return out;
}

int main() {
    ApiRequest Request;
    Request.session.id = Random(0, 100);
    Request.id = Random(0,100);

    Authorization (Request);

    if (Request.session.isBanned == true){
        std::cout << "LOG IN ERROR: Your session has been blocked by the system. Please try again later.";
        return 0;
    }

    InputEndPoint (Request);

    ChooseHTTPAction (Request);

    std::cout << "[SUCCESS] Request to " << Request.endpoint << " by user " << Request.session.role << "[ID: " << Request.id <<"]" << "\nWith action " << Request.method << " was successfully processed.\n" << "[Session ID: " << Request.session.id << "]";
}