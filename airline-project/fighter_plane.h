#pragma once
#include "header.h"
#include "airplane.h"

class FighterPlane : public Airplane {
   private:
    int missiles_{};
    bool is_stealth_{};

   public:
    FighterPlane() = default;

    FighterPlane(std::string model, int crew, int max_speed, int fuel, int missiles, bool is_stealth);

    [[nodiscard]] int GetMissiles() const;
    void SetMissiles(int value);

    [[nodiscard]] bool GetIsStealth() const;
    void SetIsStealth(bool value);

    std::ostream& Print(std::ostream& out) const override;
    std::istream& Read(std::istream& in) override;
};

inline FighterPlane::FighterPlane(std::string model, int crew, int max_speed, int fuel, int missiles, bool is_stealth)
        : Airplane(std::move(model), crew, max_speed, fuel), missiles_(missiles), is_stealth_(is_stealth) {
}

inline int FighterPlane::GetMissiles() const {
    return missiles_;
}

inline void FighterPlane::SetMissiles(int value) {
    missiles_ = value;
}

inline bool FighterPlane::GetIsStealth() const {
    return is_stealth_;
}

inline void FighterPlane::SetIsStealth(bool value) {
    is_stealth_ = value;
}

inline std::ostream& FighterPlane::Print(std::ostream& out) const {
    Airplane::Print(out);
    out << "Missiles number: " << missiles_ << std::endl
        << "Is stealth: " << (is_stealth_ ? "YES" : "NO") << std::endl;
    return out;
}

inline std::istream& FighterPlane::Read(std::istream& in) {
    Airplane::Read(in);
    in >> missiles_ >> is_stealth_;
    return in;
}
