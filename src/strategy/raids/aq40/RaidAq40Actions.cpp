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
    bool isTank = botAI->IsTank(bot) && !botAI->IsAssistTank(bot);
    bool isAssistTank = botAI->IsAssistTank(bot);
    bool isHealer = botAI->IsHeal(bot);
    bool isRanged = botAI->IsRangedDps(bot);
    isMelee = isMelee && !isHealer && !isRanged;

    Unit* currentTarget = context->GetValue<Unit*>("current target")->Get();
    Unit* boss = AI_VALUE2(Unit*, "find target", "emperor vek'nilash");

    // Let assist tank take care of hostile bugs
    if (isAssistTank)
    {
        GuidVector bugs = context->GetValue<GuidVector>("possible targets")->Get();
        for (GuidVector::iterator i = bugs.begin(); i != bugs.end(); ++i)
        {
            Unit* unit = botAI->GetUnit(*i);
            if (!unit)
            {
                continue;
            }
            if (!unit->IsAlive())
            {
                continue;
            }
            if (!unit->IsHostileTo(bot))
            {
                continue;
            }
            if (botAI->EqualLowercaseName(unit->GetName(), "emperor vek'lor"))
            {
                continue;
            }
            if (botAI->EqualLowercaseName(unit->GetName(), "emperor vek'nilash"))
            {
                continue;
            }
            if (unit->GetDistance2d(bot) > 5.0f)
            {
                LOG_INFO("playerbots", "Bot {} is attacking {}", bot->GetName().c_str(), unit->GetName().c_str());
                return Attack(unit);
            }
        }
    }

    if (boss && boss->IsInCombat() && (isTank || isMelee))
    {
        if (currentTarget != boss)
        {
            LOG_INFO("playerbots", "Bot {} is attacking {}", bot->GetName().c_str(), currentTarget->GetName().c_str());
            return Attack(boss);
        }
        else
        {
            LOG_INFO("playerbots", "Bot {} is already attacking {}", bot->GetName().c_str(),
                     currentTarget->GetName().c_str());
            return false;
        }
    }

    LOG_INFO("playerbots", "Bot {} can't attack Emperor Vek'nilash", bot->GetName().c_str());
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

    Unit* currentTarget = context->GetValue<Unit*>("current target")->Get();
    Unit* boss = AI_VALUE2(Unit*, "find target", "emperor vek'lor");

    if (boss && boss->IsInCombat() && isCaster)
    {
        if (currentTarget != boss)
        {
            LOG_INFO("playerbots", "Bot {} is attacking {}", bot->GetName().c_str(), currentTarget->GetName().c_str());
            return Attack(boss);
        }
        else
        {
            LOG_INFO("playerbots", "Bot {} is already attacking {}", bot->GetName().c_str(),
                     currentTarget->GetName().c_str());
            return false;
        }
    }

    LOG_INFO("playerbots", "Bot {} can't attack Emperor Vek'nilash", bot->GetName().c_str());
    return false;
}