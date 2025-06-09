#ifndef _PLAYERBOT_RAIDSERPENTSHRINECAVERNACTIONS_H
#define _PLAYERBOT_RAIDSERPENTSHRINECAVERNACTIONS_H

#include "Action.h"
#include "AttackAction.h"
#include "GenericActions.h"
#include "MovementActions.h"
#include "PlayerbotAI.h"
#include "Playerbots.h"

class SerpentShrineCavernCheckBuffsAction : public Action
{
public:
    SerpentShrineCavernCheckBuffsAction(PlayerbotAI* botAI) : Action(botAI, "serpentshrinecavern buffs check") {}
    bool Execute(Event event) override;
    bool isUseful() override;
protected:
    void AddBuff(int32 spellId);
};

class SerpentShrineCavernAttackEnchantedElementalAction : public AttackAction
{
public:
    SerpentShrineCavernAttackEnchantedElementalAction(PlayerbotAI* botAI) : AttackAction(botAI, "serpentshrinecavern attack enchanted elemental") {}
    bool Execute(Event event) override;
};

#endif
