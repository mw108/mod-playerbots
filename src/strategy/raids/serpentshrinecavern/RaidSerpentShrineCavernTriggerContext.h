#ifndef _PLAYERBOT_RAIDSERPENTSHRINECAVERNTRIGGERCONTEXT_H
#define _PLAYERBOT_RAIDSERPENTSHRINECAVERNTRIGGERCONTEXT_H

#include "AiObjectContext.h"
#include "NamedObjectContext.h"
#include "RaidSerpentShrineCavernTriggers.h"

class RaidSerpentShrineCavernTriggerContext : public NamedObjectContext<Trigger>
{
public:
    RaidSerpentShrineCavernTriggerContext()
    {
        creators["lady vashj"] = &RaidSerpentShrineCavernTriggerContext::lady_vashj;
        creators["has tainted core"] = &RaidSerpentShrineCavernTriggerContext::has_tainted_core;
    }

private:
    static Trigger* lady_vashj(PlayerbotAI* ai) { return new SerpentShrineCavernLadyVashjTrigger(ai); }
    static Trigger* has_tainted_core(PlayerbotAI* ai) { return new SerpentShrineCavernHasTaintedCoreTrigger(ai); }
};

#endif
