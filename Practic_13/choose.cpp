#include <iostream>
#include "Types.h"

void Authorization (ApiRequest& e){
    int Help{1};
    int i{0};
    std::string HelpStr;
    std::cout << R"(Identify yourself as:
    1 -> Guest
    2 -> User
    3 -> Admin)" << "\n";
    
    do {
        if (Help < 1 || Help > 3){
            std::cout << "ERROR: Incorrect input. Try again: ";
        }

        std::cin >> Help;
    } while (Help < 1 || Help > 3);

    if (Help == 3) {
        std::cout << "Input password for log in admin account: ";

        do{
            if (i > 0)
                std::cout << "Incporrect password. Try again: ";
            std::cin >> HelpStr;
            ++i;
        } while(i!=3 && HelpStr != e.session.password);

        if (HelpStr != e.session.password) {
            e.session.isBanned = true;
            std::cout << "Incorrect password. Access denied";
        }
    }

    if (e.session.isBanned == false){
        e.session.role = static_cast<UserNames>(Help-1);
    }
}

void InputEndPoint (ApiRequest& e){
    int Help{1};
    const std::string endpoints[] = {
    "/api/users",
    "/api/data",
    "/api/messages",    
    "/api/messages"
    };

    std::cout << R"(Input Choose a request name:
    1 -> /api/users
    2 -> /api/data
    3 -> /api/messages
    4 -> /api/messages)" << "\n";

    do {
        if (Help < 1 || Help > 4){
            std::cout << "ERROR: Incorrect input. Try again: ";
        }

        std::cin >> Help;
    } while (Help < 1 || Help > 4);

    e.endpoint = endpoints[Help-1];
}
//ЫЫЫ СИКС-СЕВЕН
void ChooseHTTPAction (ApiRequest& e) {
    int Help{1};
    std::cout << R"(Select HTTP method
    1 -> Retrieve data (Get)
    2 -> Create data/Submit form (Post)
    3 -> Remove data (Delete))" << "\n";

    do {
        if (Help < 1 || Help > 3){
            std::cout << "ERROR: Incorrect input. Try again: ";
        }

        std::cin >> Help;
    } while (Help < 1 || Help > 3);

    e.method = static_cast<HTTP>(Help-1);
}