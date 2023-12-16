#pragma once
#include "header.h"
#include "airplane.h"

class PassengerPlane : public Airplane {
   private:
    int capacity_{};

   public:
    PassengerPlane() = default;

    PassengerPlane(std::string model, int crew, int max_speed, int fuel, int capacity);

    [[nodiscard]] int GetCapacity() const;
    void SetCapacity(int value);

    std::ostream& Print(std::ostream& out) const override;
    std::istream& Read(std::istream& in) override;
};

inline PassengerPlane::PassengerPlane(
    std::string model, int crew, int max_speed, int fuel, int capacity)
    : Airplane(std::move(model), crew, max_speed, fuel), capacity_(capacity) {
}

inline int PassengerPlane::GetCapacity() const {
    return capacity_;
}

inline void PassengerPlane::SetCapacity(int value) {
    capacity_ = value;
}

inline std::ostream& PassengerPlane::Print(std::ostream& out) const {
    Airplane::Print(out);
    out << "Capacity: " << capacity_ << " p." << std::endl;
    return out;
}

inline std::istream& PassengerPlane::Read(std::istream& in) {
    Airplane::Read(in);
    in >> capacity_;
    return in;
}
