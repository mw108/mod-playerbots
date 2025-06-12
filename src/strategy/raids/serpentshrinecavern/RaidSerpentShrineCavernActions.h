#ifndef _PLAYERBOT_RAIDSERPENTSHRINECAVERNACTIONS_H
#define _PLAYERBOT_RAIDSERPENTSHRINECAVERNACTIONS_H

#include "Action.h"
#include "AttackAction.h"
#include "GenericActions.h"
#include "MovementActions.h"
#include "UseItemAction.h"
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

class SerpentShrineCavernLadyVashjCooseTargetAction : public AttackAction
{
public:
    SerpentShrineCavernLadyVashjCooseTargetAction(PlayerbotAI* botAI) : AttackAction(botAI, "lady vashj choose target") {}
    bool Execute(Event event) override;
};

class ThrowTaintedCoreAction : public UseItemAction
{
public:
    ThrowTaintedCoreAction(PlayerbotAI* botAI) : UseItemAction(botAI, "throw tainted core") {}
    bool Execute(Event event) override;
    bool isPossible() override;
};

#endif
