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
        creators["move behind the boss"] = &RaidAq20TriggerContext::move_behind_the_boss;

        // Kurinnaxx
        creators["kurinnaxx find sand trap"] = &RaidAq20TriggerContext::kurinnaxx_find_sand_trap;
        creators["kurinnaxx tank mortal wound"] = &RaidAq20TriggerContext::kurinnaxx_tank_mortal_wound;

        // Ossirian
        creators["aq20 move to crystal"] = &RaidAq20TriggerContext::move_to_crystal;
    }

private:
    static Trigger* move_behind_the_boss(PlayerbotAI* ai) { return new MoveBehindTheBossTrigger(ai); }
    static Trigger* kurinnaxx_find_sand_trap(PlayerbotAI* ai) { return new KurinnaxxFindSandTrapTrigger(ai); }
    static Trigger* kurinnaxx_tank_mortal_wound(PlayerbotAI* ai) { return new KurinnaxxTankMortalWoundTrigger(ai);  }
    static Trigger* move_to_crystal(PlayerbotAI* ai) { return new Aq20MoveToCrystalTrigger(ai); }
};

#endif
