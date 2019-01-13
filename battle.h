#ifndef STARWARS2_BATTLE_H
#define STARWARS2_BATTLE_H

#include "helper.h"
#include "imperialfleet.h"
#include "rebelfleet.h"

class SpaceBattle {

private:

    Clock clock;
    size_t undestroyed_imperial_starships;
    size_t undestroyed_rebel_starships;
    std::vector<std::shared_ptr<ImperialStarship>> imperial_fleet;
    std::vector<std::shared_ptr<RebelStarship>> rebel_fleet;

    void battle();

public:

    // konstruktor SpaceBattle

    size_t countImperialFleet() const;

    size_t countRebelFleet() const;

    void tick(Time timeStep);

    class Builder {

    private:

        Clock clock;
        std::vector<std::shared_ptr<ImperialStarship>> imperial_fleet;
        std::vector<std::shared_ptr<RebelStarship>> rebel_fleet;
        bool t0_set, t1_set, starships_set;

    public:

        Builder();

        SpaceBattle build();

        Builder startTime(const Time &time);

        Builder maxTime(const Time &time);

        Builder ship(const std::shared_ptr<Starship> starship);
    };
};

// Zostanie wywołane, jeśli statek rebeliancki może atakować.
void attack(ImperialStarship *imp, AttackingEntity *reb) {
    AttackPower impPower = imp->getAttackPower();
    AttackPower rebPower = reb->getAttackPower();
    reb->takeDamage(impPower);
    imp->takeDamage(rebPower);
}

// Wywołane, gdy statek rebelii nie może atakować.
void attack(ImperialStarship *imp, RebelStarship *reb) {
    AttackPower impPower = imp->getAttackPower();
    reb->takeDamage(impPower);
}

#endif //STARWARS2_BATTLE_H
