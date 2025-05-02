#include "RaidAq40Actions.h"

#include "Playerbots.h"
#include "RaidAq40Utils.h"

bool Aq40CheckShadowProtectionPotionBuffAction::Execute(Event event)
{
    LOG_INFO("playerbots", "Applying shadow protection buff to bot {}", bot->GetName().c_str());
    bot->AddAura(17548, bot);
    return true;
}

bool Aq40CheckShadowProtectionPotionBuffAction::isUseful() { return !bot->HasAura(17548); }

bool Aq40CheckNatureProtectionPotionBuffAction::Execute(Event event)
{
    LOG_INFO("playerbots", "Applying nature protection buff to bot {}", bot->GetName().c_str());
    bot->AddAura(17546, bot);
    return true;
}

bool Aq40CheckNatureProtectionPotionBuffAction::isUseful() { return !bot->HasAura(17546); }

bool Aq40CheckFearWardBuffAction::Execute(Event event)
{
    LOG_INFO("playerbots", "Applying fear ward buff to bot {}", bot->GetName().c_str());
    bot->AddAura(6346, bot);
    if (Pet* pet = bot->GetPet())
    {
        pet->AddAura(6346, pet);
    }
    return true;
}

bool Aq40CheckFearWardBuffAction::isUseful() { return !bot->HasAura(6346); }

bool Aq40AttackVeknilashAction::Execute(Event event)
{
    if (Unit* boss = AI_VALUE2(Unit*, "find target", "emperor vek'nilash"))
    {
        float botDist = bot->GetDistance(boss);
        if (botDist > INTERACTION_DISTANCE)
            return MoveTo(bot->GetMapId(), boss->GetPositionX(), boss->GetPositionY(), boss->GetPositionZ());
        bot->Attack(boss, true);
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
        bot->Attack(boss, false);
        return true;
    }
    return false;
}