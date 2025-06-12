#ifndef _PLAYERBOT_RAIDSERPENTSHRINECAVERNACTIONCONTEXT_H
#define _PLAYERBOT_RAIDSERPENTSHRINECAVERNACTIONCONTEXT_H

#include "Action.h"
#include "NamedObjectContext.h"
#include "RaidSerpentShrineCavernActions.h"

class RaidSerpentShrineCavernActionContext : public NamedObjectContext<Action>
{
public:
    RaidSerpentShrineCavernActionContext()
    {
        LOG_INFO("playerbots", "RaidSerpentShrineCavernActionContext created");

        creators["serpentshrinecavern check buffs"] = &RaidSerpentShrineCavernActionContext::serpentshrinecavern_check_buffs;
        creators["lady vashj choose target"] = &RaidSerpentShrineCavernActionContext::lady_vashj_choose_target;
        creators["throw tainted core"] = &RaidSerpentShrineCavernActionContext::throw_tainted_core;
    }

private:
    static Action* serpentshrinecavern_check_buffs(PlayerbotAI* botAI) { return new SerpentShrineCavernCheckBuffsAction(botAI); }
    static Action* lady_vashj_choose_target(PlayerbotAI* botAI) { return new SerpentShrineCavernLadyVashjCooseTargetAction(botAI); }
    static Action* throw_tainted_core(PlayerbotAI* botAI) { return new ThrowTaintedCoreAction(botAI); }
};

#endif
