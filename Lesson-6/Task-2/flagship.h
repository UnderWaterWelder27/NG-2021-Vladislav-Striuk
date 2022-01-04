#ifndef FLAGSHIP_H
#define FLAGSHIP_H

#include "spacecruiser.h"
#include <vector>

class FlagShip
{

public:

    FlagShip();

/// SETTERS ///
    void setFlagshipHealthPoint(float HealthPoint);
    void setFlagshipArmor(float Armor);
    void setFlagshipFlySpeed(float FlySpeed);
    void setFlagshipFleetFlySpeed(float FleetFlySpeed);

/// GETTERS ///
    float getFlagshipHealthPoint()      { return m_flagshipHealthPoint; }
    float getFlagshipArmor()            { return m_flagshipArmor; }
    float getFlagshipFlySpeed()         { return m_flagshipFlySpeed; }
    float getFlagshipFleetFlySpeed()    { return m_flagshipFleetFlySpeed; }

/// ACTION FUNCTIONS ///
    void showFlagshipInfo();
    void addSpaceCruiser(SpaceCruiser cruiser);
    float calculateFleetFlySpeed();

private:

    float m_flagshipHealthPoint;
    float m_flagshipArmor;
    float m_flagshipFlySpeed;
    float m_flagshipFleetFlySpeed;
    std::vector <SpaceCruiser> m_flagshipSpacecruiser;
};

#endif // FLAGSHIP_H
