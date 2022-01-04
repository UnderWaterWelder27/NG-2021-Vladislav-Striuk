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
    cout << endl
         << "\t S P A C E   C R U I S E R" << endl
         << "\t Health point: " << getCruiserHealthPoint() << " HP" << endl
         << "\t Armor: " << getCruiserArmor() << " A" << endl
         << "\t Fly speed: " << getCruiserFlySpeed() << " km/s" << endl
         << "\t Places count: " << getCruiserPlacesCount() << endl
         << "\t Total damage: " << calculateGeneralDamage() << " H" << endl
         << "\t Rate of speed: " << calculateMinimalSpeed() << " km/s" << endl;

    for (FighterAircraft aircraft : m_cruiserFighter)
    {
         aircraft.showFighterInfo();
    }
}

void SpaceCruiser::addFighterAircraft(FighterAircraft aircraft)
{
    if (m_indexAmount < getCruiserPlacesCount())                                    // true while m_indexAmount != m_placesAmount
    {
        m_cruiserFighter.push_back(aircraft);
        m_indexAmount++;
    }
}

float SpaceCruiser::calculateGeneralDamage()
{
    float totalDamage = 0;
    for (int i = 0; i < m_placesAmount; i++)
        totalDamage += m_cruiserFighter[i].getFighter_Damage();
    return totalDamage;
}

float SpaceCruiser::calculateMinimalSpeed()
{
    float minimalSpeed = m_cruiserFighter[0].getFighter_FlySpeed();
    for (int i = 0; i < m_placesAmount; i++)
    {
        if (minimalSpeed > m_cruiserFighter[i].getFighter_FlySpeed())
            minimalSpeed = m_cruiserFighter[i].getFighter_FlySpeed();
    }
    return minimalSpeed;
}
