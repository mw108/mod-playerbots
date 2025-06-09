#ifndef _PLAYERBOT_RAIDSERPENTSHRINECAVERNTRIGGERS_H
#define _PLAYERBOT_RAIDSERPENTSHRINECAVERNTRIGGERS_H

#include "PlayerbotAI.h"
#include "Playerbots.h"
#include "Trigger.h"

class SerpentShrineCavernEnchantedElementalTrigger : public Trigger
{
public:
    SerpentShrineCavernEnchantedElementalTrigger(PlayerbotAI* botAI) : Trigger(botAI, "enchanted elemental") {}
    bool IsActive() override;
};

class SerpentShrineCavernTaintedElementalTrigger : public Trigger
{
public:
    SerpentShrineCavernTaintedElementalTrigger(PlayerbotAI* botAI) : Trigger(botAI, "tainted elemental") {}
    bool IsActive() override;
};

#endif
