#ifndef _PLAYERBOT_RAIDAQ40TRIGGERS_H
#define _PLAYERBOT_RAIDAQ40TRIGGERS_H

#include "PlayerbotAI.h"
#include "Playerbots.h"
#include "Trigger.h"

class Aq40MoveToVeknilashTrigger : public Trigger
{
public:
    Aq40MoveToVeknilashTrigger(PlayerbotAI* botAI) : Trigger(botAI, "aq40 move to veknilash") {}
    bool IsActive() override;
};

class Aq40MoveToVeklorTrigger : public Trigger
{
public:
    Aq40MoveToVeklorTrigger(PlayerbotAI* botAI) : Trigger(botAI, "aq40 move to veklor") {}
    bool IsActive() override;
};

#endif
