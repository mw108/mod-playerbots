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
    int count = bot->HasItemCount(31088);
    if (count > 0)
        LOG_INFO("ssc_strategies", "{} has Tainted Core count {}", bot->GetName().c_str(), count);
    return count > 0;
}