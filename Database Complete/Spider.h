#pragma once
#include "Animal.h"

class Spider : public Animal {
    int m_websSpun;
public:
    Spider() = default;
    Spider(const std::string& n, int l, int webs)
        : Animal(n, l), m_websSpun(webs) {}

    void Read(std::istream& in) override {
        Animal::Read(in);

        while (true) {
            std::cout << "Enter Webs Spun: ";
            in >> m_websSpun;
            if (!in.fail()) {
                break;
            }

            std::cout << "Not A Valid Number, Please Try Again.\n";
            in.clear();
            std::string junk;
            std::getline(in, junk);
        }
    }
    void Write(std::ostream& out) const override {
        Animal::Write(out);
        out << ", Webs Spun: " << m_websSpun;
    }


    void Read(std::ifstream& in) override {
        Animal::Read(in);
        in >> m_websSpun;
    }
    void Write(std::ofstream& out) const override {
        Animal::Write(out);
        out << m_websSpun << '\n';
    }


    int GetTypeCode() const override { return 4; }

};
    