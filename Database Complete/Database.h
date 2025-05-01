#pragma once
#include <vector>
#include <memory>
#include <fstream>
#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Crab.h"
#include "Spider.h"

class Database {
public:
    std::unique_ptr<Animal> Create(int type) {
        switch (type) {
        case 1: return std::make_unique<Dog>();
        case 2: return std::make_unique<Cat>();
        case 3: return std::make_unique<Crab>();
        case 4: return std::make_unique<Spider>();
        default: return nullptr;
        }
    }

    void Add(std::unique_ptr<Animal> a) {
        if (a) m_container.push_back(std::move(a));
    }


    void Save(const std::string& filename) {
        std::ofstream out(filename);

        if (!out) return;

        for (const auto& a : m_container) {
            out << a->GetTypeCode() << '\n';
            out << *a;
        }
    }


    void Load(const std::string& filename) {
        std::ifstream in(filename);

        if (!in) return;

        m_container.clear();
        int type;

        while (in >> type) {
            auto a = Create(type);
            if (!a) break;
            in >> *a;
            m_container.push_back(std::move(a));
        }

    }


    void DisplayAll() const {
        for (const auto& a : m_container) {
            std::cout << *a << '\n';
        }
    }


    void DisplayNames() const {
        for (const auto& a : m_container) {
            std::cout << a->GetName() << '\n';
        }
    }


    static std::string TypeName(int typeCode) {
        switch (typeCode) {
        case 1: return "Dog";
        case 2: return "Cat";
        case 3: return "Crab";
        case 4: return "Spider";
        default: return "Unknown";
        }
    }

    void DisplayTypes() const {
        for (const auto& a : m_container) {
            int code = a->GetTypeCode();
            std::cout << TypeName(code) << " (" << code << ")\n";
        }
    }


private:
    std::vector<std::unique_ptr<Animal>> m_container;
};
