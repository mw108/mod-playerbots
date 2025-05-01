#include "RaidAq40Triggers.h"

#include "SharedDefines.h"
#include "RaidAq40Utils.h"

bool Aq40MovePhysicalsToVeknilashTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "emperor vek'nilash"))
    {
        if (boss->IsInCombat())
        {
            bool isMelee = bot->IsClass(CLASS_WARRIOR) ||
                bot->IsClass(CLASS_ROGUE) ||
                bot->IsClass(CLASS_DEATH_KNIGHT) ||
                bot->IsClass(CLASS_PALADIN) ||
                bot->IsClass(CLASS_HUNTER) ||
                bot->IsClass(CLASS_SHAMAN) ||
                bot->IsClass(CLASS_DRUID);
            bool isTank = botAI->IsTank(bot);
            bool isHealer = botAI->IsHeal(bot);
            bool isRanged = botAI->IsRangedDps(bot);
            if (!isMelee || isTank || isHealer || isRanged)
                return false;

            float botDist = bot->GetDistance(boss);
            if (botDist < 5.0f)
                return true;
        }
    }
    return false;
}

bool Aq40MoveCastersToVeklorTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "emperor vek'lor"))
    {
        if (boss->IsInCombat())
        {
            bool isCaster = bot->IsClass(CLASS_MAGE) ||
                bot->IsClass(CLASS_WARLOCK) ||
                bot->IsClass(CLASS_SHAMAN) ||
                bot->IsClass(CLASS_DRUID);
            bool isTank = botAI->IsTank(bot);
            bool isHealer = botAI->IsHeal(bot);
            if (!isCaster || isTank || isHealer)
                return false;

            float botDist = bot->GetDistance(boss);
            if (botDist < 20.0f)
                return true;
        }
    }
    return false;
}
