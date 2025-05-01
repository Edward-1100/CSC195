#include "Database.h"
#include <crtdbg.h>
#include <iostream>

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    Database* db = new Database;
    bool running = true;

    while (running) {
        std::cout << "1) Create\n";
        std::cout << "2) Display All\n";
        std::cout << "3) Display Name\n";
        std::cout << "4) Display Type\n";
        std::cout << "5) Load\n";
        std::cout << "6) Save\n";
        std::cout << "7) Quit\n";
        std::cout << "Choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "Type: 1) Dog, 2) Cat, 3) Crab, 4) Spider ";
            int t; std::cin >> t;
            auto animal = db->Create(t);
            if (!animal) {
                std::cout << "Invalid Yype\n";
                break;
            }
            std::cin >> *animal;
            db->Add(std::move(animal));
            break;
        }
        case 2:
            db->DisplayAll();
            break;
        case 3:
            db->DisplayNames();
            break;
        case 4:
            db->DisplayTypes();
            break;
        case 5: {
            std::cout << "Enter File Name To Load: ";
            std::string fname; std::cin >> fname;
            db->Load(fname);
            break;
        }
        case 6: {
            std::cout << "Enter File Name: ";
            std::string fname; std::cin >> fname;
            db->Save(fname);
            break;
        }
        case 7:
            running = false;
            break;
        default:
            std::cout << "Not A Valid Choice\n";
        }
    }

    delete db;
    return 0;
}
