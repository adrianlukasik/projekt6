#include "battle.h"
#include <cassert>
#include <iostream>

void SpaceBattle::battle() {
    /*for (auto imperialShip = imperial_fleet->begin(); imperialShip != imperial_fleet->end();) {
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
    }*/
}

SpaceBattle::SpaceBattle(
        const Clock &clock_,
        const std::vector<std::shared_ptr<ImperialStarship>> &imp_fleet,
        const std::vector<std::shared_ptr<RebelStarship>> &reb_fleet) :
        clock(clock_), undestroyed_imperial_starships(0),
        undestroyed_rebel_starships(0), imperial_fleet(imp_fleet),
        rebel_fleet(reb_fleet) {
    for (auto &ship : imp_fleet) {
        if (ship->getShield() > 0) {
            undestroyed_imperial_starships++;
        }
    }
    for (auto &ship : reb_fleet) {
        if (ship->getShield() > 0) {
            undestroyed_rebel_starships++;
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
    else if (clock.clockTick(timeStep)) {
        battle();
    }
}

SpaceBattle::Builder::Builder() : t0_set(false), t1_set(false),
                                  imp_starships_set(false),
                                  reb_starships_set(false),  {}

SpaceBattle::Builder SpaceBattle::Builder::startTime(const Time &time) {
    this->clock.setStartTime(time);
    this->t0_set = true;
    return *this;
}

SpaceBattle::Builder SpaceBattle::Builder::maxTime(const Time &time) {
    this->clock.setMaxTime(time);
    this->t1_set = true;
    return *this;
}

SpaceBattle::Builder SpaceBattle::Builder::ship(
        const std::shared_ptr <ImperialStarship> &imp_starship) {
    if (set_imp_fleet.find(imp_starship) == set_imp_fleet.end()) {
        set_imp_fleet.insert(imp_starship);
        imperial_fleet.push_back(imp_starship);
        this->imp_starships_set = true;
    }
    return *this;
}

SpaceBattle::Builder SpaceBattle::Builder::ship(
        const std::shared_ptr <RebelStarship> &reb_starship) {
    if (set_reb_fleet.find(reb_starship) == set_reb_fleet.end()) {
        set_reb_fleet.insert(reb_starship);
        rebel_fleet.push_back(reb_starship);
        this->reb_starships_set = true;
    }
    return *this;
}

SpaceBattle SpaceBattle::Builder::build() {
    assert(t0_set && t1_set && starships_set);
    return SpaceBattle(Clock(clock.getStartTime(), clock.getMaxTime()),
                       imperial_fleet, rebel_fleet);
}

void attack(ImperialStarship *imp, RebelStarship *reb) {
    AttackPower impPower = imp->getAttackPower();
    reb->takeDamage(impPower);
    if (reb->isAttacking()) {
        AttackPower rebPower = reb->getAttackPower();
        imp->takeDamage(rebPower);
    }
}
