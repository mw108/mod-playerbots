#ifndef _PLAYERBOT_RAIDAQ20TRIGGERS_H
#define _PLAYERBOT_RAIDAQ20TRIGGERS_H

#include "EventMap.h"
#include "GenericTriggers.h"
#include "PlayerbotAI.h"
#include "PlayerbotAIConfig.h"
#include "Playerbots.h"
#include "RaidAq20BossHelper.h"
#include "RaidAq20Scripts.h"
#include "Trigger.h"

class Aq20MoveToCrystalTrigger : public Trigger
{
public:
    Aq20MoveToCrystalTrigger(PlayerbotAI* botAI) : Trigger(botAI, "aq20 move to crystal") {}
    bool IsActive() override;
};
#endif

class KurinnaxxAvoidCleaveTrigger : public IsNotBehindTargetTrigger
{
public:
    KurinnaxxAvoidCleaveTrigger(PlayerbotAI* ai) : IsNotBehindTargetTrigger(ai) {}
    virtual bool IsActive();
};

class KurinnaxxMainTankMortalWoundTrigger : public Trigger
{
public:
    KurinnaxxMainTankMortalWoundTrigger(PlayerbotAI* botAI) : Trigger(botAI, "kurinnaxx main tank mortal wound trigger") {}
    bool IsActive() override;
};
