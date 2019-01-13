#include "rebelfleet.h"
#include "assert.h"

#define MIN_STARCRUISER_SPEED 99999
#define MAX_STARCRUISER_SPEED 299795
#define MIN_EXPLORER_SPEED 299796
#define MAX_EXPLORER_SPEED 2997960
#define MIN_XWING_SPEED 299796
#define MAX_XWING_SPEED 2997960

Speed RebelStarship::getSpeed() const {
    return speed;
}

Explorer::Explorer(ShieldPoints shld, Speed spd)
    : shield(shld), speed(spd) {
        assert(MIN_EXPLORER_SPEED <= spd && spd <= MAX_EXPLORER_SPEED)
    }

StarCruiser::StarCruiser(ShieldPoints shld, Speed spd, AttackPower atck)
    : shield(shld), speed(spd), attack(atck) {
        assert(MIN_STARCRUISER_SPEED <= spd && spd <= MAX_STARCRUISER_SPEED)
    }

XWing::XWing(ShieldPoints shld, Speed spd, AttackPower atck)
    : shield(shld), speed(spd), attack(atck) {
        assert(MIN_XWING_SPEED <= spd && spd <= MAX_XWING_SPEED)
    }


std::shared_ptr<Explorer> createExplorer(ShieldPoints shield, Speed speed) {
    return std::make_shared<Explorer>(Explorer(shield, speed));
}

std::shared_ptr<StarCruiser> createStarCruiser(ShieldPoints shield,
                                               Speed speed, AttackPower attack) {
    return std::make_shared<StarCruiser>(StarCruiser(shield, speed, attack));
}

std::shared_ptr<XWing> createXWing(ShieldPoints shield, Speed speed,
                                   AttackPower attack) {
    return std::make_shared<XWing>(XWing(shield, speed, attack));
}
