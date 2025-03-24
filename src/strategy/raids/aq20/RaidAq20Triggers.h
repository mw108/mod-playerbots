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

class MoveBehindTheBossTrigger : public IsNotBehindTargetTrigger
{
public:
    MoveBehindTheBossTrigger(PlayerbotAI* botAI) : IsNotBehindTargetTrigger(botAI) {}
    bool IsActive() override;

protected:
    float distance, delta_angle;
};

class KurinnaxxFindSandTrapTrigger : public SpellTrigger
{
public:
    KurinnaxxFindSandTrapTrigger(PlayerbotAI* botAI) : SpellTrigger(botAI, "sand trap") {}
};

class KurinnaxxTankMortalWoundTrigger : public Trigger
{
public:
    KurinnaxxTankMortalWoundTrigger(PlayerbotAI* botAI) : Trigger(botAI, "kurinnaxx tank mortal wound trigger") {}
    bool IsActive() override;
};
