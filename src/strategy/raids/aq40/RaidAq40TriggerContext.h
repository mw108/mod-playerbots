#ifndef _PLAYERBOT_RAIDAQ20TRIGGERCONTEXT_H
#define _PLAYERBOT_RAIDAQ20TRIGGERCONTEXT_H

#include "AiObjectContext.h"
#include "NamedObjectContext.h"
#include "RaidAq40Triggers.h"

class RaidAq40TriggerContext : public NamedObjectContext<Trigger>
{
public:
    RaidAq40TriggerContext()
    {
        creators["aq40 move physicals to veknilash"] = &RaidAq40TriggerContext::move_physicals_to_veknilash;
        creators["aq40 move casters to veklor"] = &RaidAq40TriggerContext::move_casters_to_veklor;
    }

private:
    static Trigger* move_physicals_to_veknilash(PlayerbotAI* ai) { return new Aq40MovePhysicalsToVeknilashTrigger(ai); }
    static Trigger* move_casters_to_veklor(PlayerbotAI* ai) { return new Aq40MoveCastersToVeklorTrigger(ai); }
};

#endif
