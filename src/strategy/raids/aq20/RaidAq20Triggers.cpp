#include "RaidAq20Triggers.h"

#include "EventMap.h"
#include "Playerbots.h"
#include "RaidAq20Utils.h"
#include "ScriptedCreature.h"
#include "SharedDefines.h"
#include "Trigger.h"

bool Aq20MoveToCrystalTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "ossirian the unscarred"))
    {
        if (boss->IsInCombat())
        {
            // if buff is active move to crystal
            if (RaidAq20Utils::IsOssirianBuffActive(boss))
                return true;

            // if buff is not active a debuff will be, buff becomes active once debuff expires
            // so move to crystal when debuff almost done, or based debuff time left and
            // distance bot is from crystal (ie: start moving early enough to make it)
            int32 debuffTimeRemaining = RaidAq20Utils::GetOssirianDebuffTimeRemaining(boss);
            if (debuffTimeRemaining < 5000)
                return true;
            if (debuffTimeRemaining < 30000)
            {
                if (GameObject* crystal = RaidAq20Utils::GetNearestCrystal(boss))
                {
                    float botDist = bot->GetDistance(crystal);
                    float timeToReach = botDist / bot->GetSpeed(MOVE_RUN);
                    // bot should ideally activate crystal a ~5 seconds early (due to time it takes for crystal
                    // to activate) so aim to get there in time to do so
                    return debuffTimeRemaining - 5000 < timeToReach * 1000.0f;
                }
            }
        }
    }
    return false;
}

bool KurinnaxxAvoidCleaveTrigger::IsActive()
{
    Unit* boss = AI_VALUE2(Unit*, "find target", "kurinnaxx");
    if (!boss)
    {
        return false;
    }
    bool result = IsNotBehindTargetTrigger::IsActive() && botAI->GetState() == BOT_STATE_COMBAT &&
                  !botAI->IsRanged(bot) && !botAI->IsMainTank(bot) && boss->GetTarget() != bot->GetGUID();
    if (result)
    {
        botAI->Yell("Moving behind boss");
    }
    return result;
}

bool KurinnaxxMainTankMortalWoundTrigger::IsActive()
{
    bool bossPresent = false;
    if (AI_VALUE2(Unit*, "find target", "kurinnaxx"))
        bossPresent = true;

    if (!bossPresent)
        return false;

    if (!botAI->IsAssistTankOfIndex(bot, 0))
    {
        return false;
    }
    Unit* mt = AI_VALUE(Unit*, "main tank");
    if (!mt)
    {
        return false;
    }

    Aura* aura = botAI->GetAura("mortal wound", mt, false, true);
    if (!aura || aura->GetStackAmount() < 4)
    {
        return false;
    }

    if (result)
    {
        botAI->Yell("Taunting boss");
    }

    return true;
}
