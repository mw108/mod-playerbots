#include "RaidAq40Actions.h"

#include "Playerbots.h"
#include "RaidAq40Utils.h"

bool Aq40CheckShadowProtectionPotionBuffAction::Execute(Event event)
{
    botAI->TellMaster("Applying shadow protection buff", PLAYERBOT_SECURITY_TALK);
    bot->AddAura(17548, bot);
    bot->AttackStop();
    return true;
}

bool Aq40CheckShadowProtectionPotionBuffAction::isUseful() { return !bot->HasAura(17548); }

bool Aq40CheckNatureProtectionPotionBuffAction::Execute(Event event)
{
    botAI->TellMaster("Applying nature protection buff", PLAYERBOT_SECURITY_TALK);
    bot->AddAura(17546, bot);
    return true;
}

bool Aq40CheckNatureProtectionPotionBuffAction::isUseful() { return !bot->HasAura(17546); }

bool Aq40AttackVeknilashAction::Execute(Event event)
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "emperor vek'nilash"))
    {
        float botDist = bot->GetDistance(boss);
        if (botDist > INTERACTION_DISTANCE)
            return MoveTo(bot->GetMapId(), boss->GetPositionX(), boss->GetPositionY(), boss->GetPositionZ());
        bot->Attack(boss);
        return true;
    }
    return false;
}

bool Aq40AttackVeklorAction::Execute(Event event)
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "emperor vek'lor"))
    {
        float botDist = bot->GetDistance(boss);
        if (botDist > 20.0f)
            return MoveTo(bot->GetMapId(), boss->GetPositionX(), boss->GetPositionY(), boss->GetPositionZ());
        bot->Attack(boss);
        return true;
    }
    return false;
}