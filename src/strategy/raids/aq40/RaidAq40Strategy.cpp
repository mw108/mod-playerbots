#include "RaidAq40Strategy.h"

#include "Strategy.h"

void RaidAq40Strategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "often", NextAction::array(0, new NextAction("aq40 check buffs", ACTION_RAID), NULL)));

    triggers.push_back(new TriggerNode(
        "emperor veknilash", NextAction::array(0, new NextAction("aq40 attack veknilash", ACTION_RAID + 1), nullptr)));

    triggers.push_back(new TriggerNode(
        "emperor veklor", NextAction::array(0, new NextAction("aq40 attack veklor", ACTION_RAID + 2), nullptr)));
}
