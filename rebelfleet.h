#ifndef STARWARS2_REBELFLEET_H
#define STARWARS2_REBELFLEET_H

#include <memory>
#include "helper.h"

class RebelStarship : public Starship {

protected:

    Speed speed;

public:

    Speed getSpeed() const {
        return speed;
    }
};

class Explorer : public RebelStarship {

public:

    Explorer(ShieldPoints shield, Speed speed);
};

class StarCruiser : public RebelStarship, public AttackingEntity {

public:

    StarCruiser(ShieldPoints shield, Speed speed, AttackPower attack);

};

class XWing : public RebelStarship, public AttackingEntity {

public:

    XWing(ShieldPoints shield, Speed speed, AttackPower attack);

};

std::shared_ptr<Explorer> createExplorer(ShieldPoints shield, Speed speed);
std::shared_ptr<StarCruiser> createStarCruiser(ShieldPoints shield, Speed speed,
                                   AttackPower attack);
std::shared_ptr<XWing> createXWing(ShieldPoints shield, Speed speed,
                                   AttackPower attack);

#endif //STARWARS2_REBELFLEET_H
