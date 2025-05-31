#ifndef _PLAYERBOT_RAIDAQ40TRIGGERS_H
#define _PLAYERBOT_RAIDAQ40TRIGGERS_H

#include "PlayerbotAI.h"
#include "Playerbots.h"
#include "Trigger.h"

class Aq40EmperorVeknilashTrigger : public Trigger
{
public:
    Aq40EmperorVeknilashTrigger(PlayerbotAI* botAI) : Trigger(botAI, "emperor vek'nilash") {}
    bool IsActive() override;
};

class Aq40EmperorVeklorTrigger : public Trigger
{
public:
    Aq40EmperorVeklorTrigger(PlayerbotAI* botAI) : Trigger(botAI, "emperor vek'lor") {}
    bool IsActive() override;
};

#endif
