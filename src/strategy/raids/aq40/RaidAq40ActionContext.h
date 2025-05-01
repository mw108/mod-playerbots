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
        creators["aq40 check shadow protection potion buff"] = &RaidAq40ActionContext::aq40_check_shadow_protection_potion_buff;
        creators["aq40 check nature protection potion buff"] = &RaidAq40ActionContext::aq40_check_nature_protection_potion_buff;
    }

private:
    static Action* aq40_check_shadow_protection_potion_buff(PlayerbotAI* botAI) { return new Aq40CheckShadowProtectionPotionBuffAction(botAI); }
    static Action* aq40_check_nature_protection_potion_buff(PlayerbotAI* botAI) { return new Aq40CheckNatureProtectionPotionBuffAction(botAI); }
};

#endif
