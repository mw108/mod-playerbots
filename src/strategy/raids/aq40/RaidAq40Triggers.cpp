#include "RaidAq40Triggers.h"

#include "RaidAq40Utils.h"
#include "SharedDefines.h"

bool Aq40EmperorVeknilashTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "emperor vek'nilash"))
    {
        bool isPhysical = bot->IsClass(CLASS_WARRIOR) || bot->IsClass(CLASS_ROGUE) ||
                          bot->IsClass(CLASS_DEATH_KNIGHT) || bot->IsClass(CLASS_PALADIN) ||
                          bot->IsClass(CLASS_HUNTER) || bot->IsClass(CLASS_SHAMAN) || bot->IsClass(CLASS_DRUID);
        bool isTank = botAI->IsTank(bot) && !botAI->IsAssistTank(bot);
        bool isHealer = botAI->IsHeal(bot);
        bool isRanged = botAI->IsRangedDps(bot);
        isPhysical = isPhysical && !isHealer && !isRanged;

        bool isEligible = isPhysical || isTank;
        if (boss->IsInCombat() && boss->IsAlive() && isEligible)
        {
            return true;
        }
    }
    return false;
}

bool Aq40EmperorVeklorTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "emperor vek'lor"))
    {
        bool isCaster = bot->IsClass(CLASS_MAGE) || bot->IsClass(CLASS_WARLOCK) || bot->IsClass(CLASS_SHAMAN) ||
                        bot->IsClass(CLASS_DRUID);
        bool isTank = botAI->IsTank(bot);
        bool isHealer = botAI->IsHeal(bot);
        bool isRanged = botAI->IsRangedDps(bot);
        bool isEligible = isCaster && isRanged && !isHealer && !isTank;

        if (boss->IsInCombat() && boss->IsAlive() && isEligible)
        {
            return true;
        }
    }
    return false;
}
