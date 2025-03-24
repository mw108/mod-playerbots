#ifndef _PLAYERBOT_RAIDAQ20ACTIONCONTEXT_H
#define _PLAYERBOT_RAIDAQ20ACTIONCONTEXT_H

#include "Action.h"
#include "NamedObjectContext.h"
#include "RaidAq20Actions.h"

class RaidAq20ActionContext : public NamedObjectContext<Action>
{
public:
    RaidAq20ActionContext()
    {
        // Kurinnaxx
        creators["kurinnaxx move away from sand trap"] = &RaidAq20ActionContext::move_away_from_sand_trap;

        // Ossirian
        creators["aq20 use crystal"] = &RaidAq20ActionContext::use_crystal;
    }

private:
    static Action* move_away_from_sand_trap(PlayerbotAI* ai) { return new KurinnaxxMoveAwayFromSandTrapAction(ai); }
    static Action* use_crystal(PlayerbotAI* ai) { return new Aq20UseCrystalAction(ai); }
};

#endif
