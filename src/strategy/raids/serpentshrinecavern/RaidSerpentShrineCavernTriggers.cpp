#include "RaidSerpentShrineCavernTriggers.h"
#include "SharedDefines.h"

bool SerpentShrineCavernLadyVashjTrigger::IsActive()
{
    if (Unit* elemental = AI_VALUE2(Unit*, "find target", "lady vashj"))
    {
        return true;
    }
    return false;
}

bool SerpentShrineCavernHasTaintedCoreTrigger::IsActive()
{
    return bot->HasItemCount(31088) > 0;
}