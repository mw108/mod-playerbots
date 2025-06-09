#include "RaidSerpentShrineCavernTriggers.h"
#include "SharedDefines.h"

bool SerpentShrineCavernEnchantedElementalTrigger::IsActive()
{
    if (Unit* elemental = AI_VALUE2(Unit*, "find target", "enchanted elemental"))
    {
        bool isDps = botAI->IsDps(bot);
        bool isEligible = isDps;
        return isEligible;
    }
    return false;
}

bool SerpentShrineCavernTaintedElementalTrigger::IsActive()
{
    if (Unit* elemental = AI_VALUE2(Unit*, "find target", "tainted elemental"))
    {
        bool isDps = botAI->IsDps(bot);
        bool isEligible = isDps;
        return isEligible;
    }
    return false;
}
