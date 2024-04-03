#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

class Complex {
private:
    double real_;
    double image_;
public:
    Complex() : real_(0), image_(0) {}
    Complex(double real, double image) : real_(real), image_(image) {}
    Complex(Complex& rhs) noexcept : real_(rhs.real_), image_(rhs.image_) {}
    Complex& operator=(const Complex& rhs) {
        this->real_ += rhs.real_;
        this->image_ += rhs.image_;
        return *this;
    }
    Complex& operator+=(Complex& rhs) {
        this->real_ += rhs.real_;
        this->image_ += rhs.image_;
        return *this;
    }
    Complex& operator-=(Complex& rhs) {
        this->real_ -= rhs.real_;
        this->image_ -= rhs.image_;
        return *this;
    }
    Complex operator+(Complex& rhs) {
        Complex result(*this);
        result += rhs;
        return result;
    }
    Complex operator-(Complex& rhs) {
        Complex result(*this);
        result -= rhs;
        return result;
    }
    friend std::ostream& operator<<(std::ostream& out, Complex& number) {
        out << "(" << number.real_ << ")" << "+i(" << number.image_ << ")";
        return out;
    }
};

#endif // COMPLEX_H
