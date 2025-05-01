#ifndef _PLAYERBOT_RAIDAQ40TRIGGERS_H
#define _PLAYERBOT_RAIDAQ40TRIGGERS_H

#include "PlayerbotAI.h"
#include "Playerbots.h"
#include "Trigger.h"

class Aq40MovePhysicalsToVeknilashTrigger : public Trigger
{
public:
    Aq40MovePhysicalsToVeknilashTrigger(PlayerbotAI* botAI) : Trigger(botAI, "aq40 move to veknilash") {}
    bool IsActive() override;
};

class Aq40MoveCastersToVeklorTrigger : public Trigger
{
public:
    Aq40MoveCastersToVeklorTrigger(PlayerbotAI* botAI) : Trigger(botAI, "aq40 move to veklor") {}
    bool IsActive() override;
};

#endif
