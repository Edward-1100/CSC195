#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>

//GCD
template<typename T>
constexpr T gcd(T a, T b) {
    if (b == 0) {
        return (a < 0) ? -a : a;
    }
    return gcd(b, a % b);
}

namespace mathlib {

    template<typename T>
    class Fraction {
    public:
        Fraction(T numerator = 0, T denominator = 1)
            : numerator_(numerator), denominator_(denominator)
        {
            if (denominator_ == 0)
                throw std::invalid_argument("THe Denominator Can Not Equals Zero");
            Simplify();
        }

        //Math
        Fraction operator+(const Fraction& other) const {
            return Fraction(
                numerator_ * other.denominator_ + other.numerator_ * denominator_, denominator_ * other.denominator_);
        }
        Fraction operator-(const Fraction& other) const {
            return Fraction(numerator_ * other.denominator_ - other.numerator_ * denominator_, denominator_ * other.denominator_);
        }
        Fraction operator*(const Fraction& other) const {
            return Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_);
        }
        Fraction operator/(const Fraction& other) const {
            if (other.numerator_ == 0)
                throw std::invalid_argument("Divided By Zero");
            return Fraction(numerator_ * other.denominator_, denominator_ * other.numerator_);
        }

        //Compare
        bool operator==(const Fraction& other) const {
            return numerator_ == other.numerator_ && denominator_ == other.denominator_;
        }
        bool operator!=(const Fraction& other) const {
            return !(*this == other);
        }
        bool operator< (const Fraction& other) const {
            return numerator_ * other.denominator_ < other.numerator_ * denominator_;
        }
        bool operator<=(const Fraction& other) const {
            return *this < other || *this == other;
        }
        bool operator> (const Fraction& other) const {
            return other < *this;
        }
        bool operator>=(const Fraction& other) const {
            return other <= *this;
        }

        //Burger
        template<typename U>
        friend std::ostream& operator<<(std::ostream& os, const Fraction<U>& frac) {
            return os << frac.numerator_ << '/' << frac.denominator_;
        }
        template<typename U>
        friend std::istream& operator>>(std::istream& is, Fraction<U>& frac) {
            U numerator, denominator;
            char seperate;

            if (!(is >> numerator >> seperate >> denominator) || (seperate != '/')) {
                is.setstate(std::ios::failbit);
                return is;
            }

            frac = Fraction<U>(numerator, denominator);
            return is;
        }

        void Simplify() {
            T g = gcd(numerator_, denominator_);
            numerator_ /= g;
            denominator_ /= g;

            if (denominator_ < 0) {
                numerator_ = -numerator_;
                denominator_ = -denominator_;
            }

        }

        double toDouble() const {
            return static_cast<double>(numerator_) / denominator_;
        }

    private:
        T numerator_, denominator_;
    };

}

#endif
