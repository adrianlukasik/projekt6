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

    Starship(ShieldPoints shield);
    ShieldPoints getShield() const;
    void takeDamage(AttackPower damage);
};

class AttackingEntity {

protected:

  AttackPower attack;

public:

  AttackPower getAttackPower() const;
};

class Clock {

private:
  /* czas startowy. */
  Time startTime;
  /* czas maksymalny. */
  Time maxTime;
  /* aktualny czas */
  Time now;

public:

  Clock(Time t0, Time t1);

  Time getStartTime() {
    return startTime;
  }

  Time getMaxTime() {
    return maxTime;
  }

  void setStartTime(Time t) {
    startTime = t;
  }

  void setMaxTime(Time t) {
    maxTime = t;
  }

  /* Zwraca true, jeśli statki mają się atakować. */
  bool clockTick(Time timeStep);
};

#endif //STARWARS2_HELPER_H
