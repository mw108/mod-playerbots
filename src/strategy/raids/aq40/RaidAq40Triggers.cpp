#include "RaidAq40Triggers.h"

#include "RaidAq40Utils.h"
#include "SharedDefines.h"

bool Aq40MoveToVeknilashTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "emperor vek'nilash"))
    {
        if (boss->IsInCombat())
        {
            bool isMelee = bot->IsClass(CLASS_WARRIOR) || bot->IsClass(CLASS_ROGUE) ||
                           bot->IsClass(CLASS_DEATH_KNIGHT) || bot->IsClass(CLASS_PALADIN) ||
                           bot->IsClass(CLASS_HUNTER) || bot->IsClass(CLASS_SHAMAN) || bot->IsClass(CLASS_DRUID);
            bool isTank = botAI->IsTank(bot);
            bool isHealer = botAI->IsHeal(bot);
            bool isRanged = botAI->IsRangedDps(bot);
            if (!isMelee || isTank || isHealer || isRanged)
                return false;

            float botDist = bot->GetDistance(boss);
            if (botDist < 5.0f)
            {
                botAI->TellMaster("Moving to Emperor Vek'nilash", PLAYERBOT_SECURITY_TALK);
                return true;
            }
        }
    }
    else
    {
        botAI->TellMaster("Emperor Vek'nilash not found", PLAYERBOT_SECURITY_TALK);
    }
    return false;
}

bool Aq40MoveToVeklorTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "emperor vek'lor"))
    {
        if (boss->IsInCombat())
        {
            bool isCaster = bot->IsClass(CLASS_MAGE) || bot->IsClass(CLASS_WARLOCK) || bot->IsClass(CLASS_SHAMAN) ||
                            bot->IsClass(CLASS_DRUID);
            bool isTank = botAI->IsTank(bot);
            bool isHealer = botAI->IsHeal(bot);
            if (!isCaster || isTank || isHealer)
                return false;

            float botDist = bot->GetDistance(boss);
            if (botDist < 20.0f)
            {
                botAI->TellMaster("Moving to Emperor Vek'lor", PLAYERBOT_SECURITY_TALK);
                return true;
            }
        }
    }
    else
    {
        botAI->TellMaster("Emperor Vek'lor not found", PLAYERBOT_SECURITY_TALK);
    }
    return false;
}
