#include "RaidSerpentShrineCavernStrategy.h"

#include "Strategy.h"

void RaidSerpentShrineCavernStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "often", NextAction::array(0, new NextAction("serpentshrinecavern check buffs", ACTION_RAID), NULL)));

    triggers.push_back(new TriggerNode(
        "has tainted core", NextAction::array(0, new NextAction("throw tainted core", ACTION_RAID), NULL)));

    triggers.push_back(new TriggerNode(
        "lady vashj", NextAction::array(0, new NextAction("lady vashj choose target", ACTION_RAID), nullptr)));
}
