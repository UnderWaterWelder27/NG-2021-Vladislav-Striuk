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

void FlagShip::setFlagshipFleetFlySpeed()
{
    float fleetSpeed = m_flagshipSpacecruiser[0].calculateMinimalSpeed();
    for (int i = 0; i < 2; i++)
    {
        if (fleetSpeed > m_flagshipSpacecruiser[i].calculateMinimalSpeed())
            fleetSpeed = m_flagshipSpacecruiser[i].calculateMinimalSpeed();
    }
    m_flagshipFleetFlySpeed = fleetSpeed;
}

void FlagShip::showFlagshipInfo()
{
    cout << endl << "==========================================================" << endl
                 << "==========================================================" << endl << endl
                 << "Health point: " << getFlagshipHealthPoint() << " HP" << endl
                 << "Armor: " << getFlagshipArmor() << " A" << endl
                 << "Fly speed: " << getFlagshipFlySpeed() << " km/s" << endl
                 << "Fleet fly speed: " << getFlagshipFleetFlySpeed() << " km/s" << endl;

    for (SpaceCruiser cruiser : m_flagshipSpacecruiser)
    {
         cruiser.showCruiserInfo();
    }
}

void FlagShip::addSpaceCruiser(SpaceCruiser cruiser)
{
    m_flagshipSpacecruiser.push_back(cruiser);
}
