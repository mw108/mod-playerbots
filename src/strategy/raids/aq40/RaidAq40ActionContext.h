#ifndef _PLAYERBOT_RAIDAQ40ACTIONCONTEXT_H
#define _PLAYERBOT_RAIDAQ40ACTIONCONTEXT_H

#include "Action.h"
#include "NamedObjectContext.h"
#include "RaidAq40Actions.h"

class RaidAq40ActionContext : public NamedObjectContext<Action>
{
public:
    RaidAq40ActionContext()
    {
        LOG_INFO("playerbots", "RaidAq40ActionContext created");

        creators["aq40 check buffs"] = &RaidAq40ActionContext::aq40_check_buffs;
        creators["aq40 attack veknilash"] = &RaidAq40ActionContext::aq40_attack_veknilash;
        creators["aq40 attack veklor"] = &RaidAq40ActionContext::aq40_attack_veklor;
    }

private:
    static Action* aq40_check_buffs(PlayerbotAI* botAI) { return new Aq40CheckBuffsAction(botAI); }
    static Action* aq40_attack_veknilash(PlayerbotAI* botAI) { return new Aq40AttackVeknilashAction(botAI); }
    static Action* aq40_attack_veklor(PlayerbotAI* botAI) { return new Aq40AttackVeklorAction(botAI); }
};

#endif
