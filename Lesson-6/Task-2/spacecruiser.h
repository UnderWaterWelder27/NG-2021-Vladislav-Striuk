#ifndef SPACECRUISER_H
#define SPACECRUISER_H

#include <vector>
#include "fighteraircraft.h"

class SpaceCruiser : protected FighterAircraft
{

public:

    SpaceCruiser();

/// SETTERS ///
    void setCruiserArmor(float Armor);
    void setCruiserPlacesAmount(int PlacesAmount);

/// GETTERS ///
    float getCruiserArmor()         { return m_cruiserArmor;}
    int   getCruiserPlacesCount()   { return m_placesAmount;}

/// ACTION FUNCTIONS ///
    void showCruiserInfo();
    void addFighterAircraft(FighterAircraft aircraft);                      // add initialized FighterAircraft-element to vector
    float calculateGeneralDamage();                                         // sum of all damage of every fightercraft
    float calculateMinimalSpeed();                                          // search for minimal fightercraft speed in cruiser
    float calculateMaximumHealthPoint();                                    // search for maximal fightercraft HP in cruiser

private:

    float m_cruiserArmor;
    int   m_indexAmount;                                                    // used in (addFighterAircraft) - variable
    int   m_placesAmount;                                                   // setted value to places amount
    std::vector <FighterAircraft> m_cruiserFighter;                         // FighterAircraft vector-array type
};

#endif // SPACECRUISER_H
