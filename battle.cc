#include "battle.h"

void SpaceBattle::battle() {
    for (auto imperialShip = imperial_fleet->begin(); imperialShip != imperial_fleet->end();) {
      for (auto rebelShip = rebel_fleet->begin(); rebelShip != rebel_fleet->end();) {

        if (imperialShip->getShield() > 0 && rebelShip->getShield() > 0) {
            attack(imperialShip, rebelShip);
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

size_t SpaceBattle::countImperialFleet() const {
    return undestroyed_imperial_starships;
}

size_t SpaceBattle::countRebelFleet() const {
    return undestroyed_rebel_starships;
}

void SpaceBattle::tick(Time timeStep) {
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

SpaceBattle::Builder::Builder() : t0_set(false), t1_set(false),
                                  starships_set(false) {}

SpaceBattle::Builder SpaceBattle::Builder::startTime(const Time &time) {
    // ustawienie czasu startowego (t0) w clocku na time
    this->t0_set = true;
    return *this;
}

SpaceBattle::Builder SpaceBattle::Builder::maxTime(const Time &time) {
    // ustawienie czasu maksymalnego (t1) w clocku na time
    this->t1_set = true;
    return *this;
}

// todo
SpaceBattle::Builder SpaceBattle::Builder::ship(
        const std::shared_ptr <Starship> starship) {

}

SpaceBattle SpaceBattle::Builder::build() {
    assert(t0_set && t1_set && starships_set);
    // todo konstruktor spacebattle
    // return SpaceBattle()
}
