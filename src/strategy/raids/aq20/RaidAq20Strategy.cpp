#include "RaidAq20Strategy.h"

#include "RaidAq20Multipliers.h"

void RaidAq20Strategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode("move behind the boss",
        NextAction::array(0, new NextAction("melee", ACTION_RAID), nullptr)));

    // Kurinaxx
    triggers.push_back(new TriggerNode("kurinnaxx tank mortal wound",
        NextAction::array(0, new NextAction("taunt spell", ACTION_RAID + 1), nullptr)));

    /*
    triggers.push_back(new TriggerNode("kurinnaxx find sand trap",
        NextAction::array(0, new NextAction("kurinnaxx move away from sand trap", ACTION_RAID + 1), nullptr)));
    */

    // Ossirian
    triggers.push_back(new TriggerNode("aq20 move to crystal",
        NextAction::array(0, new NextAction("aq20 use crystal", ACTION_RAID), nullptr)));
}

void RaidAq20Strategy::InitMultipliers(std::vector<Multiplier*>& multipliers)
{

}
