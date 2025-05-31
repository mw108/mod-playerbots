#include "RaidAq40Actions.h"

#include "Playerbots.h"
#include "RaidAq40Utils.h"

void Aq40CheckBuffsAction::AddBuff(int32 spellId)
{
    if (!bot->HasAura(spellId))
    {
        bot->AddAura(spellId, bot);
        if (Pet* pet = bot->GetPet())
        {
            pet->AddAura(spellId, pet);
        }
    }
}

bool Aq40CheckBuffsAction::Execute(Event event)
{
    AddBuff(27683); // Prayer of Shadow Protection
    AddBuff(23737); // Dark Moon Fair stamina
    AddBuff(23768); // Dark Moon Fair damage
    AddBuff(23769); // Dark Moon Fair resistance
    AddBuff(24425); // Zul'Gurub
    AddBuff(22888); // Onyxia
    AddBuff(17626); // Flask of Titans
    AddBuff(17543); // Fire protection
    AddBuff(17549); // Arcane protection
    AddBuff(17548); // Shadow protection
    AddBuff(17546); // Nature protection
    AddBuff(17544); // Frost protection
    AddBuff(6346);  // Fear ward
    return true;
}

bool Aq40CheckBuffsAction::isUseful()
{
    return !bot->HasAura(27683) ||  // Prayer of Shadow Protection
           !bot->HasAura(23737) ||  // Dark Moon Fair stamina
           !bot->HasAura(23768) ||  // Dark Moon Fair damage
           !bot->HasAura(23769) ||  // Dark Moon Fair resistance
           !bot->HasAura(24425) ||  // Zul'Gurub
           !bot->HasAura(22888) ||  // Onyxia
           !bot->HasAura(17626) ||  // Flask of Titans
           !bot->HasAura(17543) ||  // Fire protection
           !bot->HasAura(17549) ||  // Arcane protection
           !bot->HasAura(17548) ||  // Shadow protection
           !bot->HasAura(17546) ||  // Nature protection
           !bot->HasAura(17544) ||  // Frost protection
           !bot->HasAura(6346);     // Fear ward
}

bool Aq40AttackVeknilashAction::Execute(Event event)
{
    if (!bot->IsAlive())
    {
        return false;
    }

    bool isPhysical = bot->IsClass(CLASS_WARRIOR) || bot->IsClass(CLASS_ROGUE) || bot->IsClass(CLASS_DEATH_KNIGHT) ||
                   bot->IsClass(CLASS_PALADIN) || bot->IsClass(CLASS_HUNTER) || bot->IsClass(CLASS_SHAMAN) ||
                   bot->IsClass(CLASS_DRUID);
    bool isTank = botAI->IsTank(bot) && !botAI->IsAssistTank(bot);
    bool isAssistTank = botAI->IsAssistTank(bot);
    bool isHealer = botAI->IsHeal(bot);
    bool isRanged = botAI->IsRangedDps(bot);
    isPhysical = isPhysical && !isHealer && !isRanged;

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
                LOG_INFO("aq40_strategies", "Bot {} is attacking {}", bot->GetName().c_str(), unit->GetName().c_str());
                return Attack(unit);
            }
        }
    }

    if (boss && boss->IsInCombat() && (isTank || isAssistTank || isPhysical))
    {
        if (currentTarget != boss)
        {
            LOG_INFO("aq40_strategies", "Bot {} is attacking {}", bot->GetName().c_str(), boss->GetName().c_str());
            return Attack(boss);
        }
        else
        {
            LOG_INFO("aq40_strategies", "Bot {} is already attacking {}", bot->GetName().c_str(),
                     currentTarget->GetName().c_str());
            return false;
        }
    }

    LOG_INFO("aq40_strategies", "Bot {} can't attack Emperor Vek'nilash", bot->GetName().c_str());
    return false;
}

bool Aq40AttackVeklorAction::Execute(Event event)
{
    if (!bot->IsAlive())
    {
        return false;
    }

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
            LOG_INFO("aq40_strategies", "Bot {} is attacking {}", bot->GetName().c_str(), boss->GetName().c_str());
            return Attack(boss);
        }
        else
        {
            LOG_INFO("aq40_strategies", "Bot {} is already attacking {}", bot->GetName().c_str(),
                     currentTarget->GetName().c_str());
            return false;
        }
    }

    LOG_INFO("aq40_strategies", "Bot {} can't attack Emperor Vek'lor", bot->GetName().c_str());
    return false;
}