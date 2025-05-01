#pragma once
#include "Animal.h"

class Cat : public Animal {
    std::string m_color;
public:
    Cat() = default;
    Cat(const std::string& n, int l, const std::string& c)
        : Animal(n, l), m_color(c) {}

    void Read(std::istream& in) override {
        Animal::Read(in);
        std::cout << "Enter Fur Color: ";
        in >> m_color;
    }
    void Write(std::ostream& out) const override {
        Animal::Write(out);
        out << ", Fur Color: " << m_color;
    }


    void Read(std::ifstream& in) override {
        Animal::Read(in);
        in >> m_color;
    }
    void Write(std::ofstream& out) const override {
        Animal::Write(out);
        out << m_color << '\n';
    }


    int GetTypeCode() const override { return 2; }

};
