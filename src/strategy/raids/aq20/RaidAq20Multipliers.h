#ifndef _PLAYERRBOT_RAIDAQ20MULTIPLIERS_H_
#define _PLAYERRBOT_RAIDAQ20MULTIPLIERS_H_

#include "Multiplier.h"
#include "RaidAq20BossHelper.h"

class KurinnaxxGenericMultiplier : public Multiplier
{
public:
    KurinnaxxGenericMultiplier(PlayerbotAI* ai) : Multiplier(ai, "kurinnaxx generic") {}
    float GetValue(Action* action) override;
};

#endif