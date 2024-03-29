#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <iostream>

class ComplexNumber {
private:
    double real_;
    double image_;
public:
    ComplexNumber() : real_(0), image_(0) {}
    ComplexNumber(double real, double image) : real_(real), image_(image) {}
    ComplexNumber(ComplexNumber& rhs) : real_(rhs.real_), image_(rhs.image_) {}
    ComplexNumber& operator+=(ComplexNumber& rhs) {
        this->real_ += rhs.real_;
        this->image_ += rhs.image_;
        return *this;
    }
    ComplexNumber& operator-=(ComplexNumber& rhs) {
        this->real_ -= rhs.real_;
        this->image_ -= rhs.image_;
        return *this;
    }
    ComplexNumber operator+(ComplexNumber& rhs) {
        ComplexNumber result(*this);
        result += rhs;
        return result;
    }
    ComplexNumber operator-(ComplexNumber& rhs) {
        ComplexNumber result(*this);
        result -= rhs;
        return result;
    }

    friend std::ostream& operator<<(std::ostream& out, ComplexNumber& number) {
        out << "(" << number.real_ << ")" << "+i(" << number.image_ << ")";
        return out;
    }
};

#endif // COMPLEXNUMBER_H
