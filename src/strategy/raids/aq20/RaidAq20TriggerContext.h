#ifndef _PLAYERBOT_RAIDAQ20TRIGGERCONTEXT_H
#define _PLAYERBOT_RAIDAQ20TRIGGERCONTEXT_H

#include "AiObjectContext.h"
#include "NamedObjectContext.h"
#include "RaidAq20Triggers.h"

class RaidAq20TriggerContext : public NamedObjectContext<Trigger>
{
public:
    RaidAq20TriggerContext()
    {
        // Kurinnaxx
        creators["kurinnaxx avoid cleave"] = &RaidAq20TriggerContext::kurinnaxx_avoid_cleave;
        creators["kurinnaxx main tank mortal wound"] = &RaidAq20TriggerContext::kurinnaxx_main_tank_mortal_wound;

        // Ossirian
        creators["aq20 move to crystal"] = &RaidAq20TriggerContext::move_to_crystal;
    }

private:
    static Trigger* kurinnaxx_avoid_cleave(PlayerbotAI* ai) { return new KurinnaxxAvoidCleaveTrigger(ai); }
    static Trigger* kurinnaxx_main_tank_mortal_wound(PlayerbotAI* ai) { return new KurinnaxxMainTankMortalWoundTrigger(ai);  }
    static Trigger* move_to_crystal(PlayerbotAI* ai) { return new Aq20MoveToCrystalTrigger(ai); }
};

#endif
