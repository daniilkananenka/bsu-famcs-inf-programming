#include "header.h"
#include "airline.h"

int main() {
    std::ifstream fin("input.txt");
    if (!fin.is_open()) {
        std::cout << "Can`t open input file" << std::endl;
        return 0;
    }

    Airline airline{};
    airline.ReadAll(fin);
    
    std::cout << "-----------Airplanes-----------" << std::endl;
    airline.PrintAll(std::cout);
    std::cout << "-----------Airplanes (SORTED BY FUEL)-----------" << std::endl;
    airline.Sort(comparators::kByFuel);
    airline.PrintAll(std::cout);
    std::cout << "-----------Airplanes (SORTED BY MAX SPEED)-----------" << std::endl;
    airline.Sort(comparators::kByMaxSpeed);
    airline.PrintAll(std::cout);
    std::cout << "-----------Airplane (100 t. < FUEL < 260 t.)-----------" << std::endl;
    std::optional<AirplanePtr> airplane_by_criteria = airline.First(
        [](const AirplanePtr& airplane) {
            return airplane->GetFuel() > 100 && airplane->GetFuel() < 260;
        }
    );
    if (!airplane_by_criteria.has_value()) {
        std::cout << "THERE ISN`T ANY AIRPLANES WITH SUCH PARAMETERS" << std::endl;
    } else {
        airplane_by_criteria.value()->Print(std::cout);
    }
    std::cout << "-----------Airplanes count (10 t. <= FUEL <= 250 t.)-----------" <<std::endl;
    size_t airplanes_by_criteria_count = airline.Count(
        [](const AirplanePtr& airplane) {
            return airplane->GetFuel() >= 10 && airplane->GetFuel() <= 250;
        }
    );
    std::cout << "COUNT: " << airplanes_by_criteria_count << std::endl;

    return 0;
}