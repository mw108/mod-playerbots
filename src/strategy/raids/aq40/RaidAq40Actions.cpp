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

bool Aq40CheckFrostProtectionPotionBuffAction::Execute(Event event)
{
    LOG_INFO("playerbots", "Applying frost protection buff to bot {}", bot->GetName().c_str());
    bot->AddAura(17544, bot);
    return true;
}

bool Aq40CheckFrostProtectionPotionBuffAction::isUseful() { return !bot->HasAura(17544); }

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
    bool isMelee = bot->IsClass(CLASS_WARRIOR) || bot->IsClass(CLASS_ROGUE) || bot->IsClass(CLASS_DEATH_KNIGHT) ||
                   bot->IsClass(CLASS_PALADIN) || bot->IsClass(CLASS_HUNTER) || bot->IsClass(CLASS_SHAMAN) ||
                   bot->IsClass(CLASS_DRUID);
    bool isTank = botAI->IsTank(bot);
    bool isHealer = botAI->IsHeal(bot);
    bool isRanged = botAI->IsRangedDps(bot);
    isMelee = isMelee && !isHealer && !isRanged;

    Unit* target = context->GetValue<Unit*>("current target")->Get();
    Unit* boss = AI_VALUE2(Unit*, "find target", "emperor vek'nilash");

    if (boss && boss->IsInCombat() && target != boss && ( isTank || isMelee ) )
    {
        return Attack(boss);
    }

    return false;
}

bool Aq40AttackVeklorAction::Execute(Event event)
{
    bool isCaster = bot->IsClass(CLASS_MAGE) || bot->IsClass(CLASS_WARLOCK) || bot->IsClass(CLASS_SHAMAN) ||
                    bot->IsClass(CLASS_DRUID);
    bool isTank = botAI->IsTank(bot);
    bool isHealer = botAI->IsHeal(bot);
    bool isRanged = botAI->IsRangedDps(bot);
    isCaster = isCaster && isRanged && !isHealer && !isTank;

    Unit* target = context->GetValue<Unit*>("current target")->Get();
    Unit* boss = AI_VALUE2(Unit*, "find target", "emperor vek'lor");

    if (boss && boss->IsInCombat() && target != boss && isCaster)
    {
        return Attack(boss);
    }

    return false;
}