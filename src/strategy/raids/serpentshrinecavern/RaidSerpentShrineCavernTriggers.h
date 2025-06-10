#ifndef _PLAYERBOT_RAIDSERPENTSHRINECAVERNTRIGGERS_H
#define _PLAYERBOT_RAIDSERPENTSHRINECAVERNTRIGGERS_H

#include "PlayerbotAI.h"
#include "Playerbots.h"
#include "Trigger.h"

class SerpentShrineCavernLadyVashjTrigger : public Trigger
{
public:
    SerpentShrineCavernLadyVashjTrigger(PlayerbotAI* botAI) : Trigger(botAI, "lady vashj") {}
    bool IsActive() override;
};

#endif
