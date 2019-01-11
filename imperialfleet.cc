#include "imperialfleet.h"

///////////// IMPERIAL SHIPS /////////////////////

DeathStar::DeathStar(ShieldPoints shld, AttackPower atck)
    : shield(shld), attack(atck) {}

ImperialDestroyer::ImperialDestroyer(ShieldPoints shld, AttackPower atck)
    : shield(shld), attack(atck) {}

TIEFighter::TIEFighter(ShieldPoints shld, AttackPower atck)
    : shield(shld), attack(atck) {}

// TODO
createDeathStar(ShieldPoints shield, AttackPower attack) {

}
// TODO
createImperialDestroyer(ShieldPoints shield, AttackPower attack) {

}
// TODO
createTIEFighter(ShieldPoints shield, AttackPower attack) {

}

/////////////////// SQUADRON ////////////////////

Squadron::Squadron(std::vector<std::shared_ptr<ImperialStarship>> sqdr)
    : squadron(sqdr) {}

Squadron::Squadron(std::initializer_list<std::shared_ptr<ImperialStarship>> sqdr)
    : squadron(sqdr) {}

// TODO
Squadron::~Squadron() {

}

Squadron::getShield() const {
    ShieldPoints totalShield = 0;
    for (auto ship : squadron) {
        totalShield += ship->getShield();
    }
    return totalShield;
}

Squadron::getAttackPower() const {
    AttackPower totalAttack = 0;
    for (auto ship : squadron) {
        totalAttack += ship->getAttackPower();
    }
    return totalAttack;
}

Squadron::takeDamage(AttackPower damage) {
    for (auto ship = squadron.begin(); ship != squadron.end();) {
    (*ship)->takeDamage(damage);
    if ((*ship)->getShield() > 0) {
      ship++;
    }
    else {
      ship = ships.erase(ship);
    }
  }
}

// TODO
createSquadron(std::vector<std::shared_ptr<ImperialStarship>> squadron) {

}
// TODO
createSquadron(std::initializer_list<std::shared_ptr<ImperialStarship>> squadron) {

}
