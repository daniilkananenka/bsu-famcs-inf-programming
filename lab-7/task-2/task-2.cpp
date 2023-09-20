#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Train.h"

const std::string FILENAME = "trains.txt";

void PrintTrains(std::vector<Train>&);
void FindTrainsByDestination(std::vector<Train>&, std::vector<Train>&, std::string);
void FindExpressTrains(std::vector<Train>&, std::vector<Train>&);

int main()
{
    std::ifstream fin(FILENAME);
    std::vector<Train> trains;

    Train train;
    while (fin >> train) {
        trains.push_back(train);
    }
    
    std::string destination {};
    std::cout << "Input destination:" << std::endl;
    std::cin >> destination;

    std::vector<Train> trainsByDestination;
    FindTrainsByDestination(trains, trainsByDestination, destination);
    std::vector<Train> expressTrains;
    FindExpressTrains(trainsByDestination, expressTrains);

    std::cout << "Trains with " << destination << " destination:" << std::endl;
    PrintTrains(trainsByDestination);
    std::cout << "Express trains with " << destination << " destination:" << std::endl;
    PrintTrains(expressTrains);

    return 0;
}

void PrintTrains(std::vector<Train>& trains)
{
    for (int i = 0; i < trains.size(); i++) {
        std::cout << trains[i] << std::endl;
    }

    std::cout << std::endl;
}

void FindTrainsByDestination(std::vector<Train>& trains, 
    std::vector<Train>& result, 
    std::string destination)
{
    for (int i = 0; i < trains.size(); i++) {
        if (trains[i].getDestination() == destination) {
            result.push_back(trains[i]);
        }
    }
}

void FindExpressTrains(std::vector<Train>& trains,
    std::vector<Train>& result)
{
    for (int i = 0; i < trains.size(); i++) {
        if (trains[i].getIsExpress()) {
            result.push_back(trains[i]);
        }
    }
}
