#include "helper.h"

////////////// STARSHIP ////////////////////

Starship::Starship(ShieldPoints shld) : shield(shld) {}

ShieldPoints Starship::getShield() const {
    return shield;
}

void Starship::takeDamage(AttackPower damage) {
  if (shield > damage) {
    shield -= damage;
  }
  else {
    shield = 0;
  }
}

//////////// ATTACKING ENTITY //////////////

AttackPower AttackingEntity::getAttackPower() const {
    return attack;
}

////////////////// CLOCK //////////////////

Clock::Clock(Time t0, Time t1) : startTime(t0), maxTime(t1) {}

bool Clock::clockTick(Time timeStep) {
  // Sprawdz czy jest czas ataku.
  bool isAttackTime = ((now % 2 == 0 || now % 3 == 0) && !(now % 5 == 0));
  // Zaktualizuj czas.
  now = (now + timeStep) % maxTime;
  return isAttackTime;
}
