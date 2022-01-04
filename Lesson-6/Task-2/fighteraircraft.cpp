#include "fighteraircraft.h"
#include <iostream>

using namespace std;

/// DEFAULT CONSTRUCTOR ///
FighterAircraft::FighterAircraft()
{
    m_fighterDamage = -1;
    m_fighterHealthPoint = -1;
    m_fighterFlySpeed = -1;
}

/// SETTERS ///
void FighterAircraft::setFighter_Damage(float Damage)
{
    if (Damage >= 0)
        m_fighterDamage = Damage;
}
void FighterAircraft::setFighter_HealthPoint(float HealthPoint)
{
    if (HealthPoint >= 0)
        m_fighterHealthPoint = HealthPoint;
}
void FighterAircraft::setFighter_FlySpeed(float FlySpeed)
{
    if (FlySpeed >= 0)
        m_fighterFlySpeed = FlySpeed;
}

/// SHOW INFORMATION
void FighterAircraft::showFighterInfo()
{
    cout << endl
         << "\t\t F I G H T E R   A I R C R A F T" << endl
         << "\t\t Damage: " << getFighter_Damage() << " H" << endl
         << "\t\t Health points: " << getFighter_HealthPoint() << " HP" << endl
         << "\t\t Fly speed: " << getFighter_FlySpeed() << " km/s" << endl;
}
