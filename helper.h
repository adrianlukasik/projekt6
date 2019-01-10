#ifndef STARWARS2_HELPER_H
#define STARWARS2_HELPER_H

using ShieldPoints = int;
using Speed = int;
using AttackPower = int;
using Time = int;

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

class Clock {

private:
  /* czas startowy. */
  Time t0;
  /* czas maksymalny. */
  Time t1;
  /* aktualny czas */
  Time t;

public:

  Clock();

  void setStartTime(Time t0);

  void setMaximumTime(Time t1);

  /* Zwraca true, jeśli statki mają się atakować. */
  bool clockTick(Time timeStep);
};

#endif //STARWARS2_HELPER_H
