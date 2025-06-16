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
    static constexpr uint8_t SKULL_ICON_INDEX = 7;

    if (!bot->IsAlive())
    {
        return false;
    }

    bool isMainTank = botAI->IsMainTank(bot);
    bool isPhase2 = false;

    if (!isMainTank)
    {
        return false;
    }

    Unit* currentTarget = context->GetValue<Unit*>("current target")->Get();
    Unit* target = nullptr;
    Unit* target_boss = nullptr;
    Unit* target_elemental = nullptr;
    Unit* target_tainted_elemental = nullptr;
    Unit* target_strider = nullptr;
    Unit* target_elite = nullptr;
    Unit* target_spore_bat = nullptr;

    target_boss = AI_VALUE2(Unit*, "find target", "lady vashj");
    if (!target_boss)
    {
        return false;
    }

    if (target_boss->HasAura(38112))  // SPELL_MAGIC_BARRIER
    {
        isPhase2 = true;
    }

    if (isPhase2)
    {
        float distanceElemental = 1000.0f;

        GuidVector targets = context->GetValue<GuidVector>("possible targets")->Get();
        for (GuidVector::iterator i = targets.begin(); i != targets.end(); ++i)
        {
            Unit* unit = botAI->GetUnit(*i);
            if (!unit || !unit->IsAlive())
            {
                continue;
            }

            if (botAI->EqualLowercaseName(unit->GetName(), "tainted elemental"))
            {
                target_tainted_elemental = unit;
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

            // Focus tainted elemental, if possible
            if (target_tainted_elemental)
            {
                target = target_tainted_elemental;
                break;
            }

            // Pick closest strider, if possible
            if (target_strider)
            {
                target = target_strider;
                break;
            }

            // Pick closest elite, if possible
            if (target_elite)
            {
                target = target_elite;
                break;
            }

            // Get distance from Lady Vashj to enchanted elemental, if possible
            float distance = 1000.0f;
            if (target_elemental)
            {
                distance = target_boss->GetDistance2d(target_elemental);
            }

            // Pick closest
            if (target_elemental && distance < distanceElemental)
            {
                distanceElemental = distance;
                target = target_elemental;
            }
        }

        // If no target is assigned and there is an enchanted elemental, attack it
        if (!target && target_elemental)
        {
            target = target_elemental;
        }

        if (target)
        {
            // Thanks to Noscopezz ❤️
            // https://github.com/liyunfan1223/mod-playerbots/discussions/1372#discussioncomment-13429030
            if (Group* group = bot->GetGroup())
            {
                const ObjectGuid currentSkull = group->GetTargetIcon(SKULL_ICON_INDEX);
                Unit* currentSkullUnit = botAI->GetUnit(currentSkull);

                const bool needsUpdate =
                    !currentSkullUnit || !currentSkullUnit->IsAlive() || currentSkullUnit != target;

                if (needsUpdate)
                    group->SetTargetIcon(SKULL_ICON_INDEX, bot->GetGUID(), target->GetGUID());
            }
            return false;
        }
    }

    return false;
}

bool ThrowTaintedCoreAction::Execute(Event event)
{
    if (bot->HasItemCount(31088) > 0)
    {
        Player* master = botAI->GetMaster();
        float distance = bot->GetDistance2d(master);
        if (distance >= 10.0f && distance < sPlayerbotAIConfig->spellDistance)
        {
            Item* item = bot->GetItemByEntry(31088);
            if (!item)
            {
                return false;
            }

            //LOG_INFO("ssc_strategies", "{} using item {} on {}", bot->GetName().c_str(), item->GetTemplate()->Name1.c_str(), master->GetName().c_str());
            
            /* Doesn't work
            bot->SetTarget(master->GetGUID());
            bool useResult = UseItemAuto(item); 
            */

            bool useResult = UseItem(item, ObjectGuid::Empty, nullptr, master); // Doesn't work either.
            LOG_INFO("ssc_strategies", "Item use result {} = {}", item->GetTemplate()->Name1.c_str(), useResult);
            
            return useResult;
        }
    }
    return false;
}

bool ThrowTaintedCoreAction::isPossible() { return bot->GetMapId() == 548; /* Serpent Shrine Cavern */ }
