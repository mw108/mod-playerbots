#include "RaidAq20Triggers.h"

#include "EventMap.h"
#include "Playerbots.h"
#include "RaidAq20Utils.h"
#include "ScriptedCreature.h"
#include "SharedDefines.h"
#include "Trigger.h"

bool MoveBehindTheBossTrigger::IsActive()
{
    Unit* kurinnaxx = AI_VALUE(Unit*, "kurinnaxx");
    if (!kurinnaxx)
    {
        return false;
    }

    Unit* boss = kurinnaxx;

    // Don't move if boss is already targeting the bot
    if (boss->GetTarget() == bot->GetGUID())
    {
        return false;
    }

    // Don't move if bot is the main tank
    if (botAI->IsMainTank(bot))
    {
        return false;
    }

    // Don't move if bot is ranged
    if (botAI->IsRanged(bot))
    {
        return false;
    }

    return IsNotBehindTargetTrigger::IsActive();
    /*
    // If bot is the assist tank, move to the flank of the boss
    float modifier = 1.0f;
    if (botAI->IsAssistTank(bot))
    {
        modifier = 2.0f;
    }

    // Position* pos = boss->GetPosition();
    float orientation = boss->GetOrientation() + M_PI + (delta_angle / modifier);
    float x = boss->GetPositionX();
    float y = boss->GetPositionY();
    float z = boss->GetPositionZ();
    float rx = x + cos(orientation) * distance;
    float ry = y + sin(orientation) * distance;
    return MoveTo(bot->GetMapId(), rx, ry, z, false, false, false, false, MovementPriority::MOVEMENT_COMBAT);
    */
}

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

bool KurinnaxxTankMortalWoundTrigger::IsActive()
{
    Unit* kurinnaxx = AI_VALUE(Unit*, "kurinnaxx");
    if (!kurinnaxx)
    {
        return false;
    }

    Unit* boss = kurinnaxx;
    if (boss->IsInCombat())
    {
        Unit* target = botAI->GetUnit(boss->GetTarget());
        if (!target)
        {
            return false;
        }

        Aura* aura = botAI->GetAura("mortal wound", target, false, true);
        if (!aura || aura->GetStackAmount() < 3)
        {
            return false;
        }

        return true;
    }

    return false;
}
