#ifndef STARWARS2_REBELFLEET_H
#define STARWARS2_REBELFLEET_H

#include <memory>
#include "helper.h"

class RebelStarship {

protected:

    ShieldPoints shield;
    Speed speed;

public:

    RebelStarship(ShieldPoints shield, Speed speed);

    ShieldPoints getShield() const {
        return shield;
    }

    Speed getSpeed() const {
        return speed;
    }

    void takeDamage(AttackPower damage);
};

class Explorer : public RebelStarship {

public:

    Explorer(ShieldPoints shield, Speed speed);
};

class StarCruiser : public RebelStarship {

private:

    AttackPower attack;

public:

    StarCruiser(ShieldPoints shield, Speed speed, AttackPower attack);

    AttackPower getAttackPower() const {
        return attack;
    }
};

class XWing : public RebelStarship {

private:

    AttackPower attack;

public:

    XWing(ShieldPoints shield, Speed speed, AttackPower attack);

    AttackPower getAttackPower() const {
        return attack;
    }
};

std::shared_ptr<Explorer> createExplorer(ShieldPoints shield, Speed speed);
std::shared_ptr<StarCruiser> createStarCruiser(ShieldPoints shield, Speed speed,
                                   AttackPower attack);
std::shared_ptr<XWing> createXWing(ShieldPoints shield, Speed speed,
                                   AttackPower attack);

#endif //STARWARS2_REBELFLEET_H
