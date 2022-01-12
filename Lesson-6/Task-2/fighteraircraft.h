#ifndef FIGHTERAIRCRAFT_H
#define FIGHTERAIRCRAFT_H

#include <string>

class FighterAircraft
{
public:

    FighterAircraft();

/// SETTERS ///
    void setFighter_Damage(float Damage);
    void setFighter_HealthPoint(float HealthPoint);
    void setFighter_FlySpeed(float FlySpeed);

/// GETTERS ///
    float getFighter_Damage()           { return m_fighterDamage; }
    float getFighter_HealthPoint()      { return m_fighterHealthPoint; }
    float getFighter_FlySpeed()         { return m_fighterFlySpeed; }

/// ACTION FUNCTIONS ///
    void showFighterInfo();

protected:

    float m_fighterFlySpeed;
    float m_fighterHealthPoint;

private:

    float m_fighterDamage;

};

#endif // FIGHTERAIRCRAFT_H
