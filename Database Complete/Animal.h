#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Animal {
protected:
    std::string m_name;
    int         m_lifespan;
public:
    Animal() = default;
    Animal(const std::string& name, int lifespan)
        : m_name(name), m_lifespan(lifespan) {}
    virtual ~Animal() = default;


    virtual void Read(std::istream& in) {
        std::cout << "Enter Name: ";
        in >> m_name;

        while (true) {
            std::cout << "Enter Lifespan: ";
            in >> m_lifespan;
            if (!in.fail()) {
                break;
            }

            std::cout << "Not A Valid Input, Please Try Again.\n";
            in.clear();
            std::string junk;
            std::getline(in, junk);
        }

    }
    virtual void Write(std::ostream& out) const {
        out << "Name: " << m_name << ", Lifespan: " << m_lifespan;
    }


    virtual void Read(std::ifstream& in) {
        in >> m_name >> m_lifespan;
    }
    virtual void Write(std::ofstream& out) const {
        out << m_name << '\n' << m_lifespan << '\n';
    }

    std::string GetName() const { return m_name; }
    virtual int GetTypeCode() const = 0;


    friend std::istream& operator>>(std::istream& is, Animal& a) {
        a.Read(is);
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const Animal& a) {
        a.Write(os);
        return os;
    }
    friend std::ifstream& operator>>(std::ifstream& is, Animal& a) {
        a.Read(is);
        return is;
    }
    friend std::ofstream& operator<<(std::ofstream& os, const Animal& a) {
        a.Write(os);
        return os;
    }

};
