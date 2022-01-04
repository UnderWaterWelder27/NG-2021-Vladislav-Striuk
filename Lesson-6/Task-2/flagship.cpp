#include "flagship.h"
#include <iostream>

using namespace std;

FlagShip::FlagShip()
{
    m_flagshipHealthPoint = -1;
    m_flagshipArmor = -1;
    m_flagshipFlySpeed = -1;
    m_flagshipFleetFlySpeed = -1;
}

void FlagShip::setFlagshipHealthPoint(float HealthPoint)
{
    if (HealthPoint >= 0)
        m_flagshipHealthPoint = HealthPoint;
}
void FlagShip::setFlagshipArmor(float Armor)
{
    if (Armor >= 0)
        m_flagshipArmor = Armor;
}
void FlagShip::setFlagshipFlySpeed(float FlySpeed)
{
    if (FlySpeed >= 0)
        m_flagshipFlySpeed = FlySpeed;
}
void FlagShip::setFlagshipFleetFlySpeed(float FleetFlySpeed)
{
    if (FleetFlySpeed >= 0)
        m_flagshipFleetFlySpeed = FleetFlySpeed;
}

void FlagShip::showFlagshipInfo()
{
    cout << endl
         << "F L A G S H I P" << endl
         << "Health point: " << getFlagshipHealthPoint() << " HP" << endl
         << "Armor: " << getFlagshipArmor() << " A" << endl
         << "Fly speed: " << getFlagshipFlySpeed() << " km/s" << endl
         << "Fleet fly speed: " << calculateFleetFlySpeed() << " km/s" << endl;

    for (SpaceCruiser cruiser : m_flagshipSpacecruiser)
    {
         cruiser.showCruiserInfo();
    }
}

void FlagShip::addSpaceCruiser(SpaceCruiser cruiser)
{
    m_flagshipSpacecruiser.push_back(cruiser);
}

float FlagShip::calculateFleetFlySpeed()
{
    float fleetFlySpeed = m_flagshipSpacecruiser[0].calculateMinimalSpeed();
    for (unsigned long long i = 0; i < m_flagshipSpacecruiser.size(); i++)
    {
        if (fleetFlySpeed > m_flagshipSpacecruiser[i].calculateMinimalSpeed())
            fleetFlySpeed = m_flagshipSpacecruiser[i].calculateMinimalSpeed();
    }
    setFlagshipFleetFlySpeed(fleetFlySpeed);
    return getFlagshipFleetFlySpeed();
}
