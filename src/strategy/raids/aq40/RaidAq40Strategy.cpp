#include "RaidAq40Strategy.h"

#include "Strategy.h"

void RaidAq40Strategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "often", NextAction::array(0, new NextAction("aq40 check shadow protection potion buff", ACTION_RAID), NULL)));

    triggers.push_back(new TriggerNode(
        "often", NextAction::array(0, new NextAction("aq40 check nature protection potion buff", ACTION_RAID), NULL)));

    triggers.push_back(new TriggerNode(
        "often", NextAction::array(0, new NextAction("aq40 check frost protection potion buff", ACTION_RAID), NULL)));

    triggers.push_back(new TriggerNode(
        "often", NextAction::array(0, new NextAction("aq40 check fear ward buff", ACTION_RAID), NULL)));

    triggers.push_back(new TriggerNode(
        "emperor veknilash", NextAction::array(0, new NextAction("aq40 attack veknilash", ACTION_RAID), nullptr)));

    triggers.push_back(new TriggerNode(
        "emperor veklor", NextAction::array(0, new NextAction("aq40 attack veklor", ACTION_RAID), nullptr)));
}
