#ifndef STARWARS2_IMPERIALFLEET_H
#define STARWARS2_IMPERIALFLEET_H

#include <memory>
#include <vector>
#include "helper.h"

class ImperialStarship : public Starship, public AttackingEntity {};

class DeathStar : public ImperialStarship {

public:

    DeathStar(ShieldPoints shield, AttackPower attack);
};

class ImperialDestroyer : public ImperialStarship {

public:

    ImperialDestroyer(ShieldPoints shield, AttackPower attack);
};

class TIEFighter : public ImperialStarship {

public:

    TIEFighter(ShieldPoints shield, AttackPower attack);
};

std::shared_ptr<DeathStar> createDeathStar(ShieldPoints shield,
                                           AttackPower attack);
std::shared_ptr<ImperialDestroyer> createImperialDestroyer(ShieldPoints shield,
                                                           AttackPower attack);
std::shared_ptr<TIEFighter> createTIEFighter(ShieldPoints shield,
                                             AttackPower attack);

class Squadron : public ImperialStarship {

private:

    std::vector<std::shared_ptr<ImperialStarship>> squadron;

public:

    Squadron(std::vector<std::shared_ptr<ImperialStarship>> squadron);
    Squadron(std::initializer_list<std::shared_ptr<ImperialStarship>> squadron);
    ~Squadron() {};

    ShieldPoints getShield() const;

    AttackPower getAttackPower() const;

    void takeDamage(AttackPower damage);
};

std::shared_ptr<Squadron> createSquadron(
        std::vector<std::shared_ptr<ImperialStarship>> squadron);
std::shared_ptr<Squadron> createSquadron(
        std::initializer_list<std::shared_ptr<ImperialStarship>> squadron);

#endif //STARWARS2_IMPERIALFLEET_H
