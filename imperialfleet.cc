#include "imperialfleet.h"

///////////// IMPERIAL SHIPS /////////////////////

DeathStar::DeathStar(ShieldPoints shld, AttackPower atck)
    : shield(shld), attack(atck) {}

ImperialDestroyer::ImperialDestroyer(ShieldPoints shld, AttackPower atck)
    : shield(shld), attack(atck) {}

TIEFighter::TIEFighter(ShieldPoints shld, AttackPower atck)
    : shield(shld), attack(atck) {}


std::shared_ptr<DeathStar> createDeathStar(ShieldPoints shield,
                                           AttackPower attack) {
    return std::make_shared<DeathStar>(DeathStar(shield, attack));
}

std::shared_ptr<ImperialDestroyer> createImperialDestroyer(ShieldPoints shield,
                                                           AttackPower attack) {
    return std::make_shared<ImperialDestroyer>(ImperialDestroyer(
            shield, attack));
}

std::shared_ptr<TIEFighter> createTIEFighter(ShieldPoints shield,
                                             AttackPower attack) {
    return std::make_shared<TIEFighter>(TIEFighter(shield, attack));

}

/////////////////// SQUADRON ////////////////////

Squadron::Squadron(std::vector<std::shared_ptr<ImperialStarship>> sqdr) {
    for (auto element : sqdr) {
        squadron.push_back(element);
    }
}

Squadron::Squadron(std::initializer_list<std::shared_ptr<ImperialStarship>> sqdr) {
    for (auto element : sqdr) {
        squadron.push_back(element);
    }
}


ShieldPoints Squadron::getShield() const {
    ShieldPoints totalShield = 0;
    for (auto ship : squadron) {
        totalShield += ship->getShield();
    }
    return totalShield;
}

// do zweryfikowania
AttackPower Squadron::getAttackPower() const {
    AttackPower totalAttack = 0;
    for (auto &ship : squadron) {
        if (ship->getShield() > 0)
            totalAttack += ship->getAttackPower();
    }
    return totalAttack;
}

// do zweryfikowania
void Squadron::takeDamage(AttackPower damage) {
    for (auto &ship = squadron.begin(); ship != squadron.end();) {
    (*ship)->takeDamage(damage);
    if ((*ship)->getShield() > 0) {
      ship++;
    }
    else {
      ship = ships.erase(ship);
    }
  }
}


std::shared_ptr<Squadron> createSquadron(
        std::vector<std::shared_ptr<ImperialStarship>> squadron) {
    return std::make_shared<Squadron>(Squadron(squadron));
}

std::shared_ptr<Squadron> createSquadron(
        std::initializer_list<std::shared_ptr<ImperialStarship>> squadron) {
    return std::make_shared<Squadron>(Squadron(squadron));
}
