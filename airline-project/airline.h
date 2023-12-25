#pragma once

#include "airplane.h"
#include "cargo_plane.h"
#include "fighter_plane.h"
#include "header.h"
#include "passenger_plane.h"

#include <functional>
#include <optional>
#include <utility>

using AirplanePtr = std::shared_ptr<Airplane>;

namespace comparators {
inline const auto kByMaxSpeed = [](const AirplanePtr& a, const AirplanePtr& b) -> bool {
    return a->GetMaxSpeed() < b->GetMaxSpeed();
};

inline const auto kByFuel = [](const AirplanePtr& a, const AirplanePtr& b) -> bool {
    return a->GetFuel() < b->GetFuel();
};
}  // namespace comparators

class Airline {
   private:
    std::vector<AirplanePtr> airplanes_;

   public:
    ~Airline() = default;
    Airline() = default;

    Airline(const Airline&) = default;
    Airline(Airline&&) = default;
    Airline& operator=(const Airline&) = default;
    Airline& operator=(Airline&&) = default;

    void PrintAll(std::ostream& out) const;
    void ReadAll(std::istream& in);

    std::vector<std::shared_ptr<Airplane>>& Airplanes();
    void RemoveAllAirplanes();

    template <class Comparator>
    void Sort(Comparator comp);

    template <class Predicate>
    std::optional<AirplanePtr> First(Predicate predicate);

    template <class Predicate>
    size_t Count(Predicate predicate);
};

template <class Comparator>
inline void Airline::Sort(Comparator comp) {
    std::sort(airplanes_.begin(), airplanes_.end(), std::move(comp));
}

template <class Predicate>
std::optional<AirplanePtr> Airline::First(Predicate predicate) {
    auto it = std::find_if(airplanes_.begin(), airplanes_.end(), predicate);
    if (it == airplanes_.end()) {
        return std::nullopt;
    }
    return std::make_optional(*it);
}

template <class Predicate>
size_t Airline::Count(Predicate predicate) {
    size_t result = std::count_if(airplanes_.begin(), airplanes_.end(), predicate);
    return result;
}

inline std::shared_ptr<Airplane> GetAirplanePtr(char type) {
    switch (type) {
        case 'P':
            return std::make_shared<PassengerPlane>();
        case 'C':
            return std::make_shared<CargoPlane>();
        case 'F':
            return std::make_shared<FighterPlane>();
        default:
            throw std::runtime_error("Can`t recognize plane");
    }
}

inline void Airline::PrintAll(std::ostream& out) const {
    std::copy(airplanes_.begin(), airplanes_.end(), std::ostream_iterator<AirplanePtr>(out));
}

inline void Airline::ReadAll(std::istream& in) {
    char type{};
    while (in >> type) {
        std::shared_ptr<Airplane> airplane = GetAirplanePtr(type);
        in >> airplane;

        airplanes_.push_back(airplane);
    }
}

inline std::vector<std::shared_ptr<Airplane>>& Airline::Airplanes() {
    return airplanes_;
}

inline void Airline::RemoveAllAirplanes() {
    airplanes_.clear();
}
