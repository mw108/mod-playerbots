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
        creators["enchanted elemental"] = &RaidSerpentShrineCavernTriggerContext::enchanted_elemental;
    }

private:
    static Trigger* enchanted_elemental(PlayerbotAI* ai) { return new SerpentShrineCavernEnchantedElementalTrigger(ai); }
};

#endif
