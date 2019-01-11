#include "battle.h"

SpaceBattle::battle() {
    for (auto imperialShip = imperial_fleet->begin(); imperialShip != imperial_fleet->end();) {
      for (auto rebelShip = rebel_fleet->begin(); rebelShip != rebel_fleet->end();) {

        if (imperialShip->getShield() > 0 && rebelShip->getShield() > 0) {
            // TODO atak
        }

        if (rebelShip->getShield() > 0) {
          rebelShip++;
        } else {
          rebelShip = rebel_fleet->erase(rebelShip);
        }
      }

      if (imperialShip->getShield() > 0) {
        imperialShip++;
      } else {
        imperialShip = imperial_fleet->erase(imperialShip);
      }
    }
}

SpaceBattle::countImperialFleet() const {
    return undestroyed_imperial_starships;
}

SpaceBattle::countRebelFleet() const {
    return undestroyed_rebel_starships;
}

SpaceBattle::tick(Time timeStep) {
    if (countImperialFleet() == 0 && countRebelFleet() == 0) {
        std::cout << "DRAW\n";
    }
    else if (countImperialFleet() == 0) {
        std::cout << "REBELLION WON\n";
    }
    else if (countRebelFleet() == 0) {
        std::cout << "IMPERIUM WON\n";
    }
    else if (clock.tickClock(timeStep)) {
        battle();
    }
}

// TODO Builder dla SpaceBattle
