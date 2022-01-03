#include "spacecruiser.h"
#include <iostream>

using namespace std;

SpaceCruiser::SpaceCruiser()
{
    m_cruiserHealthPoint = -1;
    m_cruiserArmor = -1;
    m_cruiserFlySpeed = -1;
    m_placesAmount = 0;
    m_indexAmount = 0;
}

/// SETTERS ///
void SpaceCruiser::setCruiserHealthPoint(float HealthPoint)
{
    if (HealthPoint >= 0)
        m_cruiserHealthPoint = HealthPoint;
}
void SpaceCruiser::setCruiserArmor(float Armor)
{
    if (Armor >= 0)
        m_cruiserArmor = Armor;
}
void SpaceCruiser::setCruiserFlySpeed(float FlySpeed)
{
    if (FlySpeed >= 0)
        m_cruiserFlySpeed = FlySpeed;
}
void SpaceCruiser::setCruiserPlacesAmount(int PlacesAmount)
{
    if (PlacesAmount >= 0)
        m_placesAmount = PlacesAmount;
}

/// SHOW INFORMATION ///
void SpaceCruiser::showCruiserInfo()
{
    cout << endl << "==========================================================" << endl
                 << "==========================================================" << endl << endl
                 << "HealthPoint: " << getCruiserHealthPoint() << " HP" << endl
                 << "Armor: " << getCruiserArmor() << " A"<< endl
                 << "FlySpeed: " << getCruiserFlySpeed() << " km/s"<< endl
                 << "PlacesCount: " << getCruiserPlacesCount() << endl;

    for (FighterAircraft aircraft : m_cruiserFighter)
    {
         aircraft.showFighterInfo();
    }
}

void SpaceCruiser::addFighterAircraft(FighterAircraft aircraft)
{
    if (m_indexAmount < getCruiserPlacesCount())
    {
        m_cruiserFighter.push_back(aircraft);
        m_indexAmount++;
    }
}

void SpaceCruiser::calculateGeneralDamage()
{

}
