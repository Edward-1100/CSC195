#pragma once
#include "Animal.h"

class Dog : public Animal {
    std::string m_breed;
public:
    Dog() = default;
    Dog(const std::string& n, int l, const std::string& b)
        : Animal(n, l), m_breed(b) {}

    void Read(std::istream& in) override {
        Animal::Read(in);
        std::cout << "Enter Breed: ";
        in >> m_breed;
    }
    void Write(std::ostream& out) const override {
        Animal::Write(out);
        out << ", Breed: " << m_breed;
    }


    void Read(std::ifstream& in) override {
        Animal::Read(in);
        in >> m_breed;
    }
    void Write(std::ofstream& out) const override {
        Animal::Write(out);
        out << m_breed << '\n';
    }


    int GetTypeCode() const override { return 1; }

};
