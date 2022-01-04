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
    void addFighterAircraft(FighterAircraft aircraft);                      // add initialized FighterAircraft-element to vector
    float calculateGeneralDamage();                                         // sum of all damage of every fightercraft
    float calculateMinimalSpeed();                                          // search for minimal fightercraft speed in cruiser

private:

    float m_cruiserHealthPoint;
    float m_cruiserArmor;
    float m_cruiserFlySpeed;
    int   m_indexAmount;                                                    // used in (addFighterAircraft) - variable
    int   m_placesAmount;                                                   // setted value to places amount
    std::vector <FighterAircraft> m_cruiserFighter;                         // FighterAircraft vector-array type
};

#endif // SPACECRUISER_H
