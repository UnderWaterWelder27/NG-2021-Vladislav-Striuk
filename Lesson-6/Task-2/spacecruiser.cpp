#include "spacecruiser.h"
#include <iostream>

using namespace std;

SpaceCruiser::SpaceCruiser()
{
    m_cruiserHealthPoint = 0;
    m_cruiserArmor = 0;
    m_cruiserFlySpeed = 0;
    m_placesAmount = 0;
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
void SpaceCruiser::setCruiserPlacesAmount(float PlacesAmount)
{
    if (PlacesAmount >= 0)
        m_placesAmount = PlacesAmount;
}

void SpaceCruiser::showCruiserInfo()
{
    cout << endl << "==========================================================" << endl
                 << "==========================================================" << endl << endl
                 << "HealthPoint: " << getCruiserHealthPoint() << endl
                 << "Armor: " << getCruiserArmor() << endl
                 << "FlySpeed: " << getCruiserFlySpeed() << endl
                 << "PlacesCount: " << getCruiserPlacesCount() << endl;

    for (FighterAircraft aircraft : fighterPlace)
    {
        aircraft.showFighterInfo();
    }
}

void SpaceCruiser::addFighterAircraft(FighterAircraft aircraft)
{
    fighterPlace.push_back(aircraft);
    m_placesAmount++;
}
