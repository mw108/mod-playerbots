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
    }

private:
    static Trigger* lady_vashj(PlayerbotAI* ai) { return new SerpentShrineCavernLadyVashjTrigger(ai); }
};

#endif
