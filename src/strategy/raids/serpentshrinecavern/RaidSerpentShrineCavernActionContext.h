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
        creators["serpentshrinecavern attack enchanted elemental"] = &RaidSerpentShrineCavernActionContext::serpentshrinecavern_attack_enchanted_elemental;
    }

private:
    static Action* serpentshrinecavern_check_buffs(PlayerbotAI* botAI) { return new SerpentShrineCavernCheckBuffsAction(botAI); }
    static Action* serpentshrinecavern_attack_enchanted_elemental(PlayerbotAI* botAI) { return new SerpentShrineCavernAttackEnchantedElementalAction(botAI); }
};

#endif
