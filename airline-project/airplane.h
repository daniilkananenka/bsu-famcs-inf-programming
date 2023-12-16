#pragma once
#include "header.h"

class Airplane {
   private:
    std::string model_{"Airplane"};
    int crew_{};
    int max_speed_{};
    double fuel_{};

   public:
    virtual ~Airplane() = default;
    Airplane() = default;

    Airplane(std::string model, int crew, int max_speed, double fuel);

    Airplane(const Airplane&) = default;
    Airplane(Airplane&&) = default;
    Airplane& operator=(const Airplane&) = default;
    Airplane& operator=(Airplane&&) = default;

    virtual std::ostream& Print(std::ostream& out) const;
    virtual std::istream& Read(std::istream& in);

    friend std::ostream& operator<<(std::ostream& out, const std::shared_ptr<Airplane>& airplane);
    friend std::istream& operator>>(std::istream& in, const std::shared_ptr<Airplane>& airplane);

    [[nodiscard]] std::string GetModel() const;
    [[nodiscard]] int GetCapacity() const;
    [[nodiscard]] int GetMaxSpeed() const;
    [[nodiscard]] double GetFuel() const;

    void SetModel(std::string value);
    void SetCapacity(int value);
    void SetFuel(double value);
    void SetMaxSpeed(int value);
};

inline Airplane::Airplane(std::string model, int crew, int max_speed, double fuel)
    : model_(std::move(model)), crew_(crew), max_speed_(max_speed), fuel_(fuel) {
}

inline std::string Airplane::GetModel() const {
    return model_;
}

inline int Airplane::GetCapacity() const {
    return crew_;
}

inline int Airplane::GetMaxSpeed() const {
    return max_speed_;
}

inline double Airplane::GetFuel() const {
    return fuel_;
}

inline void Airplane::SetModel(std::string value) {
    model_ = std::move(value);
}

inline void Airplane::SetCapacity(int value) {
    crew_ = value;
}

inline void Airplane::SetFuel(double value) {
    fuel_ = value;
}

inline void Airplane::SetMaxSpeed(int value) {
    max_speed_ = value;
}

inline std::ostream& Airplane::Print(std::ostream& out) const {
    out << "----" << model_ << "----" << std::endl
        << "Capacity - " << crew_ << " p." << std::endl
        << "Max speed - " << max_speed_ << " km/h" << std::endl
        << "Fuel - " << fuel_ << " t." << std::endl;

    return out;
}

inline std::istream& Airplane::Read(std::istream& in) {
    in >> model_ >> crew_ >> max_speed_ >> fuel_;

    return in;
}

inline std::ostream& operator<<(std::ostream& out, const std::shared_ptr<Airplane>& airplane) {
    return airplane->Print(out);
}

inline std::istream& operator>>(std::istream& in, const std::shared_ptr<Airplane>& airplane) {
    return airplane->Read(in);
}
