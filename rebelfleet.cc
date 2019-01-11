#include "rebelfleet.h"

RebelStarship::getSpeed() const {
    return speed;
}

Explorer::Explorer(ShieldPoints shld, Speed spd)
    : shield(shld), speed(spd) {}

StarCruiser::StarCruiser(ShieldPoints shld, Speed spd, AttackPower atck)
    : shield(shld), speed(spd), attack(atck) {}

XWing::XWing(ShieldPoints shld, Speed spd, AttackPower atck)
    : shield(shld), speed(spd), attack(atck) {}

// TODO
createExplorer(ShieldPoints shield, Speed speed) {

}

// TODO
createStarCruiser(ShieldPoints shield, Speed speed, AttackPower attack) {

}

// TODO
createXWing(ShieldPoints shield, Speed speed, AttackPower attack) {

}
