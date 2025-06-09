#ifndef _PLAYERBOT_RAIDSERPENTSHRINECAVERNSTRATEGY_H
#define _PLAYERBOT_RAIDSERPENTSHRINECAVERNSTRATEGY_H

#include "AiObjectContext.h"
#include "Multiplier.h"
#include "Strategy.h"

class RaidSerpentShrineCavernStrategy : public Strategy
{
public:
    RaidSerpentShrineCavernStrategy(PlayerbotAI* ai) : Strategy(ai) {}
    virtual std::string const getName() override { return "serpentshrinecavern"; }
    virtual void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    // virtual void InitMultipliers(std::vector<Multiplier*> &multipliers) override;
};

#endif
