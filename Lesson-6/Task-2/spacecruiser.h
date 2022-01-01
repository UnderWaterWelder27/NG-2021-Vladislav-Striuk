#ifndef SPACECRUISER_H
#define SPACECRUISER_H

#include "fighteraircraft.h"
#include <vector>

class SpaceCruiser : public FighterAircraft
{

public:

    SpaceCruiser();

/// SETTERS ///
    void setCruiserHealthPoint(float HealthPoint);
    void setCruiserArmor(float Armor);
    void setCruiserFlySpeed(float FlySpeed);
    void setCruiserPlacesAmount(float PlacesAmount);

/// GETTERS ///
    float getCruiserHealthPoint()   { return m_cruiserHealthPoint;}
    float getCruiserArmor()         { return m_cruiserArmor;}
    float getCruiserFlySpeed()      { return m_cruiserFlySpeed;}
    int   getCruiserPlacesCount()   { return m_placesAmount;}

/// ACTION FUNCTIONS ///
    void showCruiserInfo();
    void addFighterAircraft(FighterAircraft aircraft);

private:

    float m_cruiserHealthPoint;
    float m_cruiserArmor;
    float m_cruiserFlySpeed;
    int   m_placesAmount;
    std::vector <FighterAircraft> fighterPlace;
};

#endif // SPACECRUISER_H
