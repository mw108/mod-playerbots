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
    AddBuff(27683);  // Prayer of Shadow Protection
    AddBuff(23737);  // Dark Moon Fair stamina
    AddBuff(23768);  // Dark Moon Fair damage
    AddBuff(23769);  // Dark Moon Fair resistance
    AddBuff(24425);  // Zul'Gurub
    AddBuff(22888);  // Onyxia
    AddBuff(41610);  // Mighty Restoration of Shattrath
    AddBuff(46837);  // Pure Death of Shattrath
    AddBuff(41611);  // Supreme Power of Shattrath
    AddBuff(46839);  // Blinding Light of Shattrath
    AddBuff(41609);  // Fortification of Shattrath
    AddBuff(41608);  // Relentless Assault of Shattrath
    AddBuff(28511);  // Fire protection
    AddBuff(28536);  // Arcane protection
    AddBuff(28537);  // Shadow protection
    AddBuff(28513);  // Nature protection
    AddBuff(28512);  // Frost protection
    AddBuff(6346);   // Fear ward
    return true;
}

bool SerpentShrineCavernCheckBuffsAction::isUseful()
{
    // No extra buffs
    return !bot->HasAura(27683) ||  // Prayer of Shadow Protection
           !bot->HasAura(23737) ||  // Dark Moon Fair stamina
           !bot->HasAura(23768) ||  // Dark Moon Fair damage
           !bot->HasAura(23769) ||  // Dark Moon Fair resistance
           !bot->HasAura(24425) ||  // Zul'Gurub
           !bot->HasAura(22888) ||  // Onyxia
           !bot->HasAura(41610) ||  // Mighty Restoration of Shattrath
           !bot->HasAura(46837) ||  // Pure Death of Shattrath
           !bot->HasAura(41611) ||  // Supreme Power of Shattrath
           !bot->HasAura(46839) ||  // Blinding Light of Shattrath
           !bot->HasAura(41609) ||  // Fortification of Shattrath
           !bot->HasAura(41608) ||  // Relentless Assault of Shattrath
           !bot->HasAura(28511) ||  // Fire protection
           !bot->HasAura(28536) ||  // Arcane protection
           !bot->HasAura(28537) ||  // Shadow protection
           !bot->HasAura(28513) ||  // Nature protection
           !bot->HasAura(28512) ||  // Frost protection
           !bot->HasAura(6346);     // Fear ward
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
        if (currentTarget && currentTarget->GetGUID() == unit->GetGUID())
        {
            target = unit;
            break;
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
