#ifndef STARWARS2_CLOCK_H
#define STARWARS2_CLOCK_H

#include "helper.h"

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

#endif //STARWARS2_CLOCK_H
