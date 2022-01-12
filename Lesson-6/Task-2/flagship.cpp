#include "flagship.h"
#include <iostream>

using namespace std;

FlagShip::FlagShip()
{
    m_flagshipArmor = -1;
}

void FlagShip::setFlagshipArmor(float Armor)
{
    if (Armor >= 0)
        m_flagshipArmor = Armor;
}


void FlagShip::showFlagshipInfo()
{
    cout << endl
         << "F L A G S H I P" << endl
         << "Health point: " << calculateFleetHealthPoint() << " HP" << endl
         << "Armor: " << getFlagshipArmor() << " A" << endl
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
    return fleetFlySpeed;
}

float FlagShip::calculateFleetHealthPoint()
{
    float fleetHealthPoint = m_flagshipSpacecruiser[0].calculateMaximumHealthPoint();
    for (unsigned long long i = 0; i < m_flagshipSpacecruiser.size(); i++)
    {
        if (fleetHealthPoint < m_flagshipSpacecruiser[i].calculateMaximumHealthPoint())
            fleetHealthPoint = m_flagshipSpacecruiser[i].calculateMaximumHealthPoint();
    }
    return fleetHealthPoint;
}
