#include "fighteraircraft.h"
#include <iostream>

using namespace std;

FighterAircraft::FighterAircraft()
{
    m_fighterDamage = 0;
    m_fighterHealthPoint = 0;
    m_fighterFlySpeed = 0;
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

void FighterAircraft::showFighterInfo()
{
    cout << endl
         << "\t Damage: " << getFighter_Damage() << endl
         << "\t HealthPoint: " << getFighter_HealthPoint() << endl
         << "\t FlySpeed: " << getFighter_FlySpeed() << endl;
}
