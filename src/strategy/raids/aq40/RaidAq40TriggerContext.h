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
        creators["emperor veknilash"] = &RaidAq40TriggerContext::emperor_veknilash;
        creators["emperor veklor"] = &RaidAq40TriggerContext::emperor_veklor;
    }

private:
    static Trigger* emperor_veknilash(PlayerbotAI* ai) { return new Aq40EmperorVeknilashTrigger(ai); }
    static Trigger* emperor_veklor(PlayerbotAI* ai) { return new Aq40EmperorVeklorTrigger(ai); }
};

#endif
