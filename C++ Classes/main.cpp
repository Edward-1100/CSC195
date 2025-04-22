#include <iostream>
#include <vector>
#include <string>

class BaseClassName {
public:
    enum class eType { CAT, CRAB };

    BaseClassName() = default;
    virtual ~BaseClassName() = default;

    virtual void Read(std::ostream& os, std::istream& is) {
        os << "Enter Animal's Name: ";
        is >> name;
        os << "Enter Animal's Age: ";
        is >> age;
    }

    virtual void Write(std::ostream& os) const {
        os << "Name: " << name << "\n";
        os << "Age: " << age << "\n";
    }

    std::string GetName() const { return name; }
    virtual eType GetType() const = 0;

protected:
    std::string name;
    int age;
};

class Cat : public BaseClassName {
public:
    Cat() : favoriteColor("Olive") {}

    void Read(std::ostream& os, std::istream& is) override {
        BaseClassName::Read(os, is);
    }

    void Write(std::ostream& os) const override {
        BaseClassName::Write(os);
        os << "Favorite Color: " << favoriteColor << "\n";
    }

    eType GetType() const override { return eType::CAT; }

private:
    std::string favoriteColor;
};

class Crab : public BaseClassName {
public:
    Crab() : favoriteShow("The Fresh Prince of Bel-Air") {}

    void Read(std::ostream& os, std::istream& is) override {
        BaseClassName::Read(os, is);
    }

    void Write(std::ostream& os) const override {
        BaseClassName::Write(os);
        os << "Favorite Show: " << favoriteShow << "\n";
    }

    eType GetType() const override { return eType::CRAB; }

private:
    std::string favoriteShow;
};

class Database {
public:
    ~Database() {
        for (auto ptr : objects)
            delete ptr;
    }

    void Create(BaseClassName::eType type) {
        BaseClassName* obj = nullptr;
        switch (type) {
            case BaseClassName::eType::CAT:
                obj = new Cat();
                break;
            case BaseClassName::eType::CRAB:
                obj = new Crab();
                break;
        }
        if (obj) {
            obj->Read(std::cout, std::cin);
            objects.push_back(obj);
        }
    }

    void DisplayAll() const {
        for (auto ptr : objects) {
            ptr->Write(std::cout);
            std::cout << "\n";
        }
    }

    void Display(const std::string& name) const {
        for (auto ptr : objects) {
            if (ptr->GetName() == name) {
                ptr->Write(std::cout);
                std::cout << "\n";
            }
        }
    }

    void Display(BaseClassName::eType type) const {
        for (auto ptr : objects) {
            if (ptr->GetType() == type) {
                ptr->Write(std::cout);
                std::cout << "\n";
            }
        }
    }

private:
    std::vector<BaseClassName*> objects;
};

int main() {
    Database database;
    bool quit = false;
    while (!quit) {
        std::cout << "1. Create\n2. Display All\n3. Display by Name\n4. Display by Type\n5. Quit\n";
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1: {
                std::cout << "Choose Animal.\n1 for Cat\n2 for Crab: ";
                int t;
                std::cin >> t;
                t--;
                database.Create(static_cast<BaseClassName::eType>(t));
                break;
            }
            case 2:
                database.DisplayAll();
                break;
            case 3: {
                std::cout << "Enter name: ";
                std::string name;
                std::cin >> name;
                database.Display(name);
                break;
            }
            case 4: {
                std::cout << "Choose Animal.\n1 for Cat\n2 for Crab: ";
                int t;
                std::cin >> t;
                t--;
                database.Display(static_cast<BaseClassName::eType>(t));
                break;
            }
            case 5:
                quit = true;
                break;
            default:
                std::cout << "Not A Valid Choice\n";
        }
    }
    return 0;
}
