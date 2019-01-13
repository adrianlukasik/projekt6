#include "rebelfleet.h"

Speed RebelStarship::getSpeed() const {
    return speed;
}

Explorer::Explorer(ShieldPoints shld, Speed spd)
    : shield(shld), speed(spd) {}

StarCruiser::StarCruiser(ShieldPoints shld, Speed spd, AttackPower atck)
    : shield(shld), speed(spd), attack(atck) {}

XWing::XWing(ShieldPoints shld, Speed spd, AttackPower atck)
    : shield(shld), speed(spd), attack(atck) {}


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
