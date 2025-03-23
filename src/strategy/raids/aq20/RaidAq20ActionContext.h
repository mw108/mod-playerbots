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
        creators["kurinnaxx go behind the boss"] = &RaidAq20ActionContext::go_behind_the_boss;

        // Ossirian
        creators["aq20 use crystal"] = &RaidAq20ActionContext::use_crystal;
    }

private:
    static Action* go_behind_the_boss(PlayerbotAI* ai) { return new KurinnaxxGoBehindAction(ai); }
    static Action* use_crystal(PlayerbotAI* ai) { return new Aq20UseCrystalAction(ai); }
};

#endif
