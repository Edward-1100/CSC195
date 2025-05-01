#pragma once
#include "Animal.h"

class Crab : public Animal {
    double m_clawSize;
public:
    Crab() = default;
    Crab(const std::string& n, int l, double c)
        : Animal(n, l), m_clawSize(c) {}

    void Read(std::istream& in) override {
        Animal::Read(in);

        while (true) {
            std::cout << "Enter Claw Size (mm): ";
            in >> m_clawSize;
            if (!in.fail()) {
                break;
            }

            std::cout << "Not A Valid Input, Please Try Again.\n";
            in.clear();
            std::string junk;
            std::getline(in, junk);
        }
    }
    void Write(std::ostream& out) const override {
        Animal::Write(out);
        out << ", Claw Size: " << m_clawSize;
    }


    void Read(std::ifstream& in) override {
        Animal::Read(in);
        in >> m_clawSize;
    }
    void Write(std::ofstream& out) const override {
        Animal::Write(out);
        out << m_clawSize << '\n';
    }


    int GetTypeCode() const override { return 3; }

};
