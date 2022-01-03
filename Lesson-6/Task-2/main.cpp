#include "fighteraircraft.h"
#include "spacecruiser.h"
#include <iostream>

using namespace std;

int main()
{
    SpaceCruiser cruiserA, cruiserB;
    FighterAircraft fighterA1, fighterA2, fighterA3, fighterA4, fighterA5, fighterA6,
                    fighterB1, fighterB2, fighterB3, fighterB4, fighterB5, fighterB6;

    /// FIRST CRUISER ///                                   /// SECOND CRUISER ///
    cruiserA.setCruiserHealthPoint(3500);                   cruiserB.setCruiserHealthPoint(5500);
    cruiserA.setCruiserArmor(1000);                         cruiserB.setCruiserArmor(2000);
    cruiserA.setCruiserFlySpeed(20);                        cruiserB.setCruiserFlySpeed(25);
    cruiserA.setCruiserPlacesAmount(5);                     cruiserB.setCruiserPlacesAmount(5);

    /// 1st A-AIRCRAFT ///                                  /// 1st B-AIRCRAFT ///
    fighterA1.setFighter_ModelName("A1");                   fighterB1.setFighter_ModelName("B1");
    fighterA1.setFighter_HealthPoint(100);                  fighterB1.setFighter_HealthPoint(150);
    fighterA1.setFighter_Damage(10);                        fighterB1.setFighter_Damage(15);
    fighterA1.setFighter_FlySpeed(100);                     fighterB1.setFighter_FlySpeed(150);

    /// 2st A-AIRCRAFT ///                                  /// 2st B-AIRCRAFT ///
    fighterA2.setFighter_ModelName("A2");                   fighterB2.setFighter_ModelName("B2");
    fighterA2.setFighter_HealthPoint(200);                  fighterB2.setFighter_HealthPoint(250);
    fighterA2.setFighter_Damage(20);                        fighterB2.setFighter_Damage(25);
    fighterA2.setFighter_FlySpeed(90);                      fighterB2.setFighter_FlySpeed(140);

    /// 3st A-AIRCRAFT ///                                  /// 3st B-AIRCRAFT ///
    fighterA3.setFighter_ModelName("A3");                   fighterB3.setFighter_ModelName("B3");
    fighterA3.setFighter_HealthPoint(300);                  fighterB3.setFighter_HealthPoint(350);
    fighterA3.setFighter_Damage(30);                        fighterB3.setFighter_Damage(35);
    fighterA3.setFighter_FlySpeed(80);                      fighterB3.setFighter_FlySpeed(130);

    /// 4st A-AIRCRAFT ///                                  /// 4st B-AIRCRAFT ///
    fighterA4.setFighter_ModelName("A4");                   fighterB4.setFighter_ModelName("B4");
    fighterA4.setFighter_HealthPoint(400);                  fighterB4.setFighter_HealthPoint(450);
    fighterA4.setFighter_Damage(40);                        fighterB4.setFighter_Damage(45);
    fighterA4.setFighter_FlySpeed(70);                      fighterB4.setFighter_FlySpeed(120);

    /// 5st A-AIRCRAFT ///                                  /// 5st B-AIRCRAFT ///
    fighterA5.setFighter_ModelName("A5");                   fighterB5.setFighter_ModelName("B5");
    fighterA5.setFighter_HealthPoint(500);                  fighterB5.setFighter_HealthPoint(550);
    fighterA5.setFighter_Damage(50);                        fighterB5.setFighter_Damage(55);
    fighterA5.setFighter_FlySpeed(60);                      fighterB5.setFighter_FlySpeed(110);

    /// ADD ALL A-AIRCRAFTS ///                             /// ADD ALL B-AIRCRAFTS ///
    cruiserA.addFighterAircraft(fighterA1);                 cruiserB.addFighterAircraft(fighterB1);
    cruiserA.addFighterAircraft(fighterA2);                 cruiserB.addFighterAircraft(fighterB2);
    cruiserA.addFighterAircraft(fighterA3);                 cruiserB.addFighterAircraft(fighterB3);
    cruiserA.addFighterAircraft(fighterA4);                 cruiserB.addFighterAircraft(fighterB4);
    cruiserA.addFighterAircraft(fighterA5);                 cruiserB.addFighterAircraft(fighterB5);

    cruiserA.showCruiserInfo();
    cruiserB.showCruiserInfo();
    return 0;
}
