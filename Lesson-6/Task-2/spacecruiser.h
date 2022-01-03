#ifndef SPACECRUISER_H
#define SPACECRUISER_H

#include <vector>
#include "fighteraircraft.h"

class SpaceCruiser
{

public:

    SpaceCruiser();

/// SETTERS ///
    void setCruiserHealthPoint(float HealthPoint);
    void setCruiserArmor(float Armor);
    void setCruiserFlySpeed(float FlySpeed);
    void setCruiserPlacesAmount(int PlacesAmount);

/// GETTERS ///
    float getCruiserHealthPoint()   { return m_cruiserHealthPoint;}
    float getCruiserArmor()         { return m_cruiserArmor;}
    float getCruiserFlySpeed()      { return m_cruiserFlySpeed;}
    int   getCruiserPlacesCount()   { return m_placesAmount;}

/// ACTION FUNCTIONS ///
    void showCruiserInfo();
    void addFighterAircraft(FighterAircraft aircraft);
    float calculateGeneralDamage();
    float calculateMinimalSpeed();

protected:
    int   m_placesAmount;

private:

    float m_cruiserHealthPoint;
    float m_cruiserArmor;
    float m_cruiserFlySpeed;
    int   m_indexAmount;
    std::vector <FighterAircraft> m_cruiserFighter;
};

#endif // SPACECRUISER_H
