#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <numeric>

class Rational {
private:
    int num_;
    int denum_;
public:
    Rational() : num_(0), denum_(1) {}
    Rational(int num, int denum) : num_(num), denum_(denum) {}
    Rational(Rational& rhs) noexcept : num_(rhs.num_), denum_(rhs.denum_) {}
    void reduce() {
        int gcd = std::gcd(num_, denum_);
        num_ /= gcd;
        denum_ /= gcd;
    }
    Rational& operator=(const Rational& rhs) {
        this->num_ = rhs.num_;
        this->denum_ = rhs.denum_;
        return *this;
    }
    Rational& operator*=(Rational& rhs) {
        this->num_ *= rhs.num_;
        this->denum_ *= rhs.denum_;
        this->reduce();
        return *this;
    }
    Rational& operator/=(Rational& rhs) {
        this->num_ *= rhs.denum_;
        this->denum_ *= rhs.num_;
        this->reduce();
        return *this;
    }
    Rational operator*(Rational& rhs) {
        Rational result(*this);
        result *= rhs;
        return result;
    }
    Rational operator/(Rational& rhs) {
        Rational result(*this);
        result /= rhs;
        return result;
    }
    friend std::ostream& operator<<(std::ostream& out, Rational& number) {
        out << number.num_ << " / " << number.denum_;
        return out;
    }
};

#endif // RATIONAL_H
