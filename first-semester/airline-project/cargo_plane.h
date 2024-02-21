#pragma once
#include "header.h"
#include "airplane.h"

class CargoPlane : public Airplane {
   private:
    double cargo_{};

   public:
    CargoPlane() = default;
    CargoPlane(std::string model, int crew, int max_speed, int fuel, double cargo);

    [[nodiscard]] double GetCargo() const;
    void SetCargo(double value);

    std::ostream& Print(std::ostream& out) const override;
    std::istream& Read(std::istream& in) override;
};

inline CargoPlane::CargoPlane(std::string model, int crew, int max_speed, int fuel, double cargo)
        : Airplane(std::move(model), crew, max_speed, fuel), cargo_(cargo) {
}

inline double CargoPlane::GetCargo() const {
    return cargo_;
}

inline void CargoPlane::SetCargo(double value) {
    cargo_ = value;
}

inline std::ostream& CargoPlane::Print(std::ostream& out) const {
    Airplane::Print(out);
    out << "Cargo: " << cargo_ << " t." << std::endl;
    return out;
}

inline std::istream& CargoPlane::Read(std::istream& in) {
    Airplane::Read(in);
    in >> cargo_;
    return in;
}
