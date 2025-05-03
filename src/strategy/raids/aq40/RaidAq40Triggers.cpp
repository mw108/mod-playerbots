#include "RaidAq40Triggers.h"

#include "RaidAq40Utils.h"
#include "SharedDefines.h"

bool Aq40EmperorVeknilashTrigger::IsActive()
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "emperor vek'nilash"))
    {
        if (boss->IsInCombat() && boss->IsAlive())
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
        if (boss->IsInCombat() && boss->IsAlive())
        {
            return true;
        }
    }
    return false;
}
