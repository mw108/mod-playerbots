#ifndef _PLAYERBOT_RAIDAQ40ACTIONS_H
#define _PLAYERBOT_RAIDAQ40ACTIONS_H

#include "Action.h"
#include "AttackAction.h"
#include "GenericActions.h"
#include "MovementActions.h"
#include "PlayerbotAI.h"
#include "Playerbots.h"

class Aq40CheckBuffsAction : public Action
{
public:
    Aq40CheckBuffsAction(PlayerbotAI* botAI) : Action(botAI, "aq40 buffs check") {}
    bool Execute(Event event) override;
    bool isUseful() override;
protected:
    void AddBuff(int32 spellId);
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
