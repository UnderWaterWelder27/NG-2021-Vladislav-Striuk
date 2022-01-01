#include "fighteraircraft.h"
#include "spacecruiser.h"
#include <iostream>

using namespace std;

int main()
{
    SpaceCruiser cruiserA, cruiserB;
    FighterAircraft fighterA, fighterB, fighterC;

    cruiserA.addFighterAircraft(fighterA);
    cruiserA.addFighterAircraft(fighterB);
    cruiserA.addFighterAircraft(fighterC);

    cruiserB.addFighterAircraft(fighterA);
    cruiserB.addFighterAircraft(fighterB);
    cruiserB.addFighterAircraft(fighterC);

    cruiserA.showCruiserInfo();
    cruiserB.showCruiserInfo();
    return 0;
}
