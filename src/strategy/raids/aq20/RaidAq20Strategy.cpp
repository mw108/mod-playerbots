#include "RaidAq20Strategy.h"

#include "RaidAq20Multipliers.h"

void RaidAq20Strategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    // Kurinaxx
    triggers.push_back(new TriggerNode(
        "cleave",
        NextAction::array(0, new NextAction("kurinnaxx go behind the boss", ACTION_RAID + 2), nullptr)));

    triggers.push_back(new TriggerNode("kurinnaxx main tank mortal wound",
                                       NextAction::array(0, new NextAction("taunt spell", ACTION_RAID + 1), nullptr)));

    // Ossirian
    triggers.push_back(
        new TriggerNode("aq20 move to crystal",
            NextAction::array(0, new NextAction("aq20 use crystal", ACTION_RAID), nullptr)));

}

void RaidAq20Strategy::InitMultipliers(std::vector<Multiplier*>& multipliers)
{
    multipliers.push_back(new KurinnaxxGenericMultiplier(botAI));
}
