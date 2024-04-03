#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {
private:
    double x_;
    double y_;
public:
    Vector() : x_(0), y_(0) {}
    Vector(double x, double y) : x_(x), y_(y) {}
    Vector(Vector& rhs) noexcept : x_(rhs.x_), y_(rhs.y_) {}
    Vector& operator=(const Vector& rhs) {
        this->x_ += rhs.x_;
        this->y_ += rhs.y_;
        return *this;
    }
    Vector& operator+=(Vector& rhs) {
        this->x_ += rhs.x_;
        this->y_ += rhs.y_;
        return *this;
    }
    Vector& operator-=(Vector& rhs) {
        this->x_ -= rhs.x_;
        this->y_ -= rhs.y_;
        return *this;
    }
    Vector operator+(Vector& rhs) {
        Vector result(*this);
        result += rhs;
        return result;
    }
    Vector operator-(Vector& rhs) {
        Vector result(*this);
        result -= rhs;
        return result;
    }
    friend std::ostream& operator<<(std::ostream& out, Vector& number) {
        out << "(" << number.x_ << ", " << number.y_ << ")";
        return out;
    }
};

#endif // VECTOR_H
