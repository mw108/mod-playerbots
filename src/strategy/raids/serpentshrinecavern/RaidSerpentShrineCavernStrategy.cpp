#include "RaidSerpentShrineCavernStrategy.h"

#include "Strategy.h"

void RaidSerpentShrineCavernStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    triggers.push_back(
        new TriggerNode("often", NextAction::array(0, new NextAction("serpentshrinecavern check buffs", ACTION_RAID), NULL)));

    triggers.push_back(new TriggerNode(
        "enchanted elemental", NextAction::array(0, new NextAction("serpentshrinecavern attack enchanted elemental", ACTION_RAID + 1), nullptr)));

    triggers.push_back(new TriggerNode(
        "tainted elemental", NextAction::array(0, new NextAction("serpentshrinecavern attack tainted elemental", ACTION_RAID + 2), nullptr)));
}
