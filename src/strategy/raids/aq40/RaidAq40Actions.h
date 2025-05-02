#ifndef _PLAYERBOT_RAIDAQ40ACTIONS_H
#define _PLAYERBOT_RAIDAQ40ACTIONS_H

#include "MovementActions.h"
#include "PlayerbotAI.h"
#include "Playerbots.h"

class Aq40CheckShadowProtectionPotionBuffAction : public Action
{
public:
    Aq40CheckShadowProtectionPotionBuffAction(PlayerbotAI* botAI) : Action(botAI, "aq40 shadow protection potion buff check") {}
    bool Execute(Event event) override;
    bool isUseful() override;
};

class Aq40CheckNatureProtectionPotionBuffAction : public Action
{
public:
    Aq40CheckNatureProtectionPotionBuffAction(PlayerbotAI* botAI) : Action(botAI, "aq40 nature protection potion buff check") {}
    bool Execute(Event event) override;
    bool isUseful() override;
};

class Aq40AttackVeknilashAction : public MovementAction
{
public:
    Aq40AttackVeknilashAction(PlayerbotAI* botAI) : Action(botAI, "aq40 attack veknilash") {}
    bool Execute(Event event) override;
};

class Aq40AttackVeklorAction : public MovementAction
{
public:
    Aq40AttackVeklorAction(PlayerbotAI* botAI) : Action(botAI, "aq40 attack veklor") {}
    bool Execute(Event event) override;
};

#endif
