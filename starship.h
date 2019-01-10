#ifndef STARWARS2_STARSHIP_H
#define STARWARS2_STARSHIP_H

#include "helper.h"

class Starship {

protected:

    ShieldPoints shield;

public:

    Starship(ShieldPoints shield, Speed speed);

    ShieldPoints getShield() const {
        return shield;
    }

    void takeDamage(AttackPower damage);
};

class AttackingEntity {

protected:

  AttackPower attack;

public:

  AttackPower getAttackPower() const {
      return attack;
  }
};

#endif //STARWARS2_STARSHIP_H
