#include "RaidSerpentShrineCavernActions.h"

#include "Playerbots.h"
#include "RaidAq40Utils.h"

void SerpentShrineCavernCheckBuffsAction::AddBuff(int32 spellId)
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

bool SerpentShrineCavernCheckBuffsAction::Execute(Event event)
{
    // No extra buffs
    /*
    AddBuff(27683);  // Prayer of Shadow Protection
    AddBuff(23737);  // Dark Moon Fair stamina
    AddBuff(23768);  // Dark Moon Fair damage
    AddBuff(23769);  // Dark Moon Fair resistance
    AddBuff(24425);  // Zul'Gurub
    AddBuff(22888);  // Onyxia
    AddBuff(17626);  // Flask of Titans
    AddBuff(17543);  // Fire protection
    AddBuff(17549);  // Arcane protection
    AddBuff(17548);  // Shadow protection
    AddBuff(17546);  // Nature protection
    AddBuff(17544);  // Frost protection
    AddBuff(6346);   // Fear ward
    */
    return true;
}

bool SerpentShrineCavernCheckBuffsAction::isUseful()
{
    // No extra buffs
    /*
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
    */
    return false;
}

bool SerpentShrineCavernAttackEnchantedElementalAction::Execute(Event event)
{
    if (!bot->IsAlive())
    {
        return false;
    }

    bool isDps = botAI->IsDps(bot);
    if (!isDps)
    {
        return false;
    }

    Unit* currentTarget = context->GetValue<Unit*>("current target")->Get();
    Unit* target = nullptr;

    GuidVector targets = context->GetValue<GuidVector>("possible targets")->Get();
    for (GuidVector::iterator i = targets.begin(); i != targets.end(); ++i)
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
        if (!botAI->EqualLowercaseName(unit->GetName(), "enchanted elemental"))
        {
            continue;
        }
        if (currentTarget && currentTarget->GetName() == unit->GetName())
        {
            continue;
        }

        if (unit->GetDistance2d(bot) > 5.0f)
        {
            LOG_INFO("ssc_strategies", "Bot {} is attacking {}", bot->GetName().c_str(), unit->GetName().c_str());
            target = unit;
            break;
        }
    }

    if (target)
    {
        return Attack(target);
    }

    return false;
}

bool SerpentShrineCavernAttackTaintedElementalAction::Execute(Event event)
{
    if (!bot->IsAlive())
    {
        return false;
    }

    bool isDps = botAI->IsDps(bot);
    if (!isDps)
    {
        return false;
    }

    Unit* currentTarget = context->GetValue<Unit*>("current target")->Get();
    Unit* target = nullptr;

    GuidVector targets = context->GetValue<GuidVector>("possible targets")->Get();
    for (GuidVector::iterator i = targets.begin(); i != targets.end(); ++i)
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
        if (!botAI->EqualLowercaseName(unit->GetName(), "tainted elemental"))
        {
            continue;
        }
        if (currentTarget && currentTarget->GetName() == unit->GetName())
        {
            continue;
        }

        if (unit->GetDistance2d(bot) > 5.0f)
        {
            LOG_INFO("ssc_strategies", "Bot {} is attacking {}", bot->GetName().c_str(), unit->GetName().c_str());
            target = unit;
        }
    }

    if (target)
    {
        return Attack(target);
    }

    return false;
}
