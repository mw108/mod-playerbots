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
        creators["serpentshrinecavern attack enchanted elemental"] = &RaidSerpentShrineCavernActionContext::serpentshrinecavern_attack_veknilash;
        creators["serpentshrinecavern attack tainted elemental"] = &RaidSerpentShrineCavernActionContext::serpentshrinecavern_attack_veklor;
    }

private:
    static Action* serpentshrinecavern_check_buffs(PlayerbotAI* botAI) { return new SerpentShrineCavernCheckBuffsAction(botAI); }
    static Action* serpentshrinecavern_attack_veknilash(PlayerbotAI* botAI) { return new SerpentShrineCavernAttackEnchantedElementalAction(botAI); }
    static Action* serpentshrinecavern_attack_veklor(PlayerbotAI* botAI) { return new SerpentShrineCavernAttackTaintedElementalAction(botAI); }
};

#endif
