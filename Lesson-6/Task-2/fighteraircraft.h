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
    void setFighter_ModelName(std::string ModelName);

/// GETTERS ///
    float getFighter_Damage()           { return m_fighterDamage; }
    float getFighter_HealthPoint()      { return m_fighterHealthPoint; }
    float getFighter_FlySpeed()         { return m_fighterFlySpeed; }
    std::string getFighter_ModelName()  { return m_fighterModelName; }

/// ACTION FUNCTIONS ///
    void showFighterInfo();

private:

    float m_fighterDamage;
    float m_fighterHealthPoint;
    float m_fighterFlySpeed;
    std::string m_fighterModelName;
};

#endif // FIGHTERAIRCRAFT_H
