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

        creators["aq40 check shadow protection potion buff"] = &RaidAq40ActionContext::aq40_check_shadow_protection_potion_buff;
        creators["aq40 check nature protection potion buff"] = &RaidAq40ActionContext::aq40_check_nature_protection_potion_buff;
        creators["aq40 check fear ward buff"] = &RaidAq40ActionContext::aq40_check_fear_ward_buff;
        creators["aq40 attack veknilash"] = &RaidAq40ActionContext::aq40_attack_veknilash;
        creators["aq40 attack veklor"] = &RaidAq40ActionContext::aq40_attack_veklor;
    }

private:
    static Action* aq40_check_shadow_protection_potion_buff(PlayerbotAI* botAI) { return new Aq40CheckShadowProtectionPotionBuffAction(botAI); }
    static Action* aq40_check_nature_protection_potion_buff(PlayerbotAI* botAI) { return new Aq40CheckNatureProtectionPotionBuffAction(botAI); }
    static Action* aq40_check_fear_ward_buff(PlayerbotAI* botAI) { return new Aq40CheckFearWardBuffAction(botAI); }
    static Action* aq40_attack_veknilash(PlayerbotAI* botAI) { return new Aq40AttackVeknilashAction(botAI); }
    static Action* aq40_attack_veklor(PlayerbotAI* botAI) { return new Aq40AttackVeklorAction(botAI); }
};

#endif
