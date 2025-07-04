#include "RaidBwlActions.h"

#include "Playerbots.h"

bool BwlOnyxiaScaleCloakAuraCheckAction::Execute(Event event)
{
    bot->AddAura(22683, bot);
    if (Pet* pet = bot->GetPet())
    {
        pet->AddAura(22683, pet);
    }
    return true;
}

bool BwlOnyxiaScaleCloakAuraCheckAction::isUseful() { return !bot->HasAura(22683); }

bool BwlFearwardAuraCheckAction::Execute(Event event)
{
    bot->AddAura(6346, bot);
    if (Pet* pet = bot->GetPet())
    {
        pet->AddAura(6346, pet);
    }
    return true;
}

bool BwlFearwardAuraCheckAction::isUseful() { return !bot->HasAura(6346); }

bool BwlTurnOffSuppressionDeviceAction::Execute(Event event)
{
    GuidVector gos = AI_VALUE(GuidVector, "nearest game objects");
    for (GuidVector::iterator i = gos.begin(); i != gos.end(); i++)
    {
        GameObject* go = botAI->GetGameObject(*i);
        if (!go)
        {
            continue;
        }
        if (go->GetEntry() != 179784 || go->GetDistance(bot) >= 15.0f || go->GetGoState() != GO_STATE_READY)
        {
            continue;
        }
        go->SetGoState(GO_STATE_ACTIVE);
    }
    return true;
}

bool BwlUseHourglassSandAction::Execute(Event event) { return botAI->CastSpell(23645, bot); }
