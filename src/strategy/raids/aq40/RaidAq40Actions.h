#ifndef _PLAYERBOT_RAIDAQ40ACTIONS_H
#define _PLAYERBOT_RAIDAQ40ACTIONS_H

#include "Action.h"
#include "AttackAction.h"
#include "GenericActions.h"
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

class Aq40CheckFrostProtectionPotionBuffAction : public Action
{
public:
    Aq40CheckFrostProtectionPotionBuffAction(PlayerbotAI* botAI) : Action(botAI, "aq40 frost protection potion buff check") {}
    bool Execute(Event event) override;
    bool isUseful() override;
};

class Aq40CheckFearWardBuffAction : public Action
{
public:
    Aq40CheckFearWardBuffAction(PlayerbotAI* botAI) : Action(botAI, "aq40 fear ward buff check") {}
    bool Execute(Event event) override;
    bool isUseful() override;
};

class Aq40AttackVeknilashAction : public AttackAction
{
public:
    Aq40AttackVeknilashAction(PlayerbotAI* botAI) : AttackAction(botAI, "aq40 attack veknilash") {}
    bool Execute(Event event) override;
};

class Aq40AttackVeklorAction : public AttackAction
{
public:
    Aq40AttackVeklorAction(PlayerbotAI* botAI) : AttackAction(botAI, "aq40 attack veklor") {}
    bool Execute(Event event) override;
};

#endif
