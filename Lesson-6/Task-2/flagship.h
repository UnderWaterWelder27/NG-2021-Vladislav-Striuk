#ifndef FLAGSHIP_H
#define FLAGSHIP_H

#include "spacecruiser.h"
#include <vector>

class FlagShip : protected SpaceCruiser
{

public:

    FlagShip();

/// SETTERS ///
    void setFlagshipArmor(float Armor);

/// GETTERS ///
    float getFlagshipArmor()            { return m_flagshipArmor; }

/// ACTION FUNCTIONS ///
    void showFlagshipInfo();
    void addSpaceCruiser(SpaceCruiser cruiser);                             // add initialized SpaceCruiser-element to vector
    float calculateFleetFlySpeed();                                         // search for minimal spacecruiser speed in flagship
    float calculateFleetHealthPoint();                                      // search for maximal spacecruiser HP in flagship

private:

    float m_flagshipArmor;
    float m_flagshipFleetFlySpeed;
    std::vector <SpaceCruiser> m_flagshipSpacecruiser;                      // SpaceCruiser vector-array type
};

#endif // FLAGSHIP_H
