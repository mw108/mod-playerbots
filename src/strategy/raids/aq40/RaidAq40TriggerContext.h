#ifndef _PLAYERBOT_RAIDAQ40TRIGGERCONTEXT_H
#define _PLAYERBOT_RAIDAQ40TRIGGERCONTEXT_H

#include "AiObjectContext.h"
#include "NamedObjectContext.h"
#include "RaidAq40Triggers.h"

class RaidAq40TriggerContext : public NamedObjectContext<Trigger>
{
public:
    RaidAq40TriggerContext()
    {
        creators["aq40 move to veknilash"] = &RaidAq40TriggerContext::move_to_veknilash;
        creators["aq40 move to veklor"] = &RaidAq40TriggerContext::move_to_veklor;
    }

private:
    static Trigger* move_to_veknilash(PlayerbotAI* ai) { return new Aq40MoveToVeknilashTrigger(ai); }
    static Trigger* move_to_veklor(PlayerbotAI* ai) { return new Aq40MoveToVeklorTrigger(ai); }
};

#endif
