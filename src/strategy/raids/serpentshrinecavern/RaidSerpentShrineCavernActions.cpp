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

    if (botAI->IsHeal(bot))
        AddBuff(41610);  // Mighty Restoration of Shattrath
    else if (botAI->IsRangedDps(bot) && botAI->IsCaster(bot))
        AddBuff(41611);  // Supreme Power of Shattrath
    else if (botAI->IsTank(bot))
        AddBuff(41609);  // Fortification of Shattrath
    else if (botAI->IsDps(bot) && !botAI->IsCaster(bot))
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

bool SerpentShrineCavernLadyVashjCooseTargetAction::Execute(Event event)
{
    if (!bot->IsAlive())
    {
        return false;
    }

    bool isDps = botAI->IsDps(bot);
    bool isRangedDps = botAI->IsRangedDps(bot);
    bool isHeal = botAI->IsHeal(bot);
    bool isTank = botAI->IsTank(bot);
    bool isAssistTank = botAI->IsAssistTank(bot);
    bool isPhase2 = false;

    Unit* currentTarget = context->GetValue<Unit*>("current target")->Get();
    Unit* target = nullptr;
    Unit* target_boss = nullptr;
    Unit* target_elemental = nullptr;
    Unit* target_strider = nullptr;
    Unit* target_elite = nullptr;
    Unit* target_spore_bat = nullptr;    

    GuidVector targets = context->GetValue<GuidVector>("possible targets")->Get();
    for (GuidVector::iterator i = targets.begin(); i != targets.end(); ++i)
    {
        Unit* unit = botAI->GetUnit(*i);
        if (!unit || !unit->IsAlive())
        {
            continue;
        }

        if (botAI->EqualLowercaseName(unit->GetName(), "enchanted elemental"))
        {
            target_elemental = unit;
        }

        if (botAI->EqualLowercaseName(unit->GetName(), "coilfang elite"))
        {
            target_elite = unit;
        }

        if (botAI->EqualLowercaseName(unit->GetName(), "coilfang strider"))
        {
            target_strider = unit;
        }

        if (botAI->EqualLowercaseName(unit->GetName(), "toxic sporebat"))
        {
            target_spore_bat = unit;
        }

        if (botAI->EqualLowercaseName(unit->GetName(), "lady vashj"))
        {
            target_boss = unit;
        }

        if (target_boss && target_boss->HasAura(38112))  // SPELL_MAGIC_BARRIER
        {
            isPhase2 = true;
        }

        if (!isPhase2)
        {
            target = target_boss;
            break;
        }

        float distanceElemental = target_elemental ? bot->GetDistance2d(target_elemental) : 1000.0f;
        float distanceElite = target_elite ? bot->GetDistance2d(target_elite) : 1000.0f;
        float distanceStrider = target_strider ? bot->GetDistance2d(target_strider) : 1000.0f;

        if (!target && target_elemental && distanceElemental < sPlayerbotAIConfig->spellDistance)
        {
            target = target_elemental;
        }

        if (!target && target_elite && distanceElite < sPlayerbotAIConfig->spellDistance)
        {
            target = target_elite;
        }

        if (!target && target_strider && distanceStrider < sPlayerbotAIConfig->spellDistance)
        {
            target = target_strider;
        }

        if(target)
        {
            break;
        }
    }

    if (target && target != currentTarget)
    {
        LOG_INFO("ssc_strategies", "Bot {} is attacking {}", bot->GetName().c_str(), unit->GetName().c_str());
        return Attack(target, true);
    }

    return false;
}
