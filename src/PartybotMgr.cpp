/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "PartybotMgr.h"

#include <algorithm>
#include <boost/thread/thread.hpp>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <random>

#include "AccountMgr.h"
#include "AiFactory.h"
#include "ArenaTeamMgr.h"
#include "Battleground.h"
#include "BattlegroundMgr.h"
#include "CellImpl.h"
#include "ChannelMgr.h"
#include "DBCStores.h"
#include "DBCStructure.h"
#include "DatabaseEnv.h"
#include "Define.h"
#include "FleeManager.h"
#include "GameTime.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "GuildMgr.h"
#include "GuildTaskMgr.h"
#include "LFGMgr.h"
#include "MapMgr.h"
#include "NewRpgInfo.h"
#include "NewRpgStrategy.h"
#include "PerformanceMonitor.h"
#include "Player.h"
#include "PlayerbotAI.h"
#include "PlayerbotAIConfig.h"
#include "PlayerbotCommandServer.h"
#include "PlayerbotFactory.h"
#include "Playerbots.h"
#include "Position.h"
#include "Random.h"
#include "RandomPlayerbotFactory.h"
#include "RandomPlayerbotMgr.h"
#include "ServerFacade.h"
#include "SharedDefines.h"
#include "TravelMgr.h"
#include "Unit.h"
#include "UpdateTime.h"
#include "World.h"

PartybotMgr::PartybotMgr(Player* const master) : PlayerbotHolder(), master(master), lastErrorTell(0) {}

PartybotMgr::~PartybotMgr() {}

void PartybotMgr::HandleCommand(uint32 type, std::string const text)
{
    Player* master = GetMaster();
    if (!master)
        return;

    master->Yell("Hello, World!", LANG_COMMON);
}

bool PartybotMgr::HandlePartybotMgrCommand(ChatHandler* handler, char const* args)
{
    if (!sPlayerbotAIConfig->enabled)
    {
        handler->PSendSysMessage("|cffff0000Playerbot system is currently disabled!");
        return false;
    }

    WorldSession* m_session = handler->GetSession();
    if (!m_session)
    {
        handler->PSendSysMessage("You may only add bots from an active session");
        return false;
    }

    Player* player = m_session->GetPlayer();

    handler->PSendSysMessage("|cffff0000Hello, {}!", player->GetName());

    /*
    std::vector<std::string> messages = mgr->HandlePlayerbotCommand(args, player);
    if (messages.empty())
        return true;

    for (std::vector<std::string>::iterator i = messages.begin(); i != messages.end(); ++i)
    {
        handler->PSendSysMessage("{}", i->c_str());
    }
    */

    return true;
}

PlayerbotAI* PartybotsMgr::GetPlayerbotAI(Player* player)
{
    if (!(sPlayerbotAIConfig->enabled) || !player)
    {
        return nullptr;
    }
    // if (player->GetSession()->isLogingOut() || player->IsDuringRemoveFromWorld()) {
    //     return nullptr;
    // }
    auto itr = _partybotsMgrMap.find(player->GetGUID());
    if (itr != _partybotsMgrMap.end())
    {
        if (itr->second->IsBotAI())
            return reinterpret_cast<PlayerbotAI*>(itr->second);
    }

    return nullptr;
}

PartybotMgr* PartybotsMgr::GetPartybotMgr(Player* player)
{
    if (!(sPlayerbotAIConfig->enabled) || !player)
    {
        return nullptr;
    }
    auto itr = _partybotsMgrMap.find(player->GetGUID());
    if (itr != _partybotsMgrMap.end())
    {
        if (!itr->second->IsBotAI())
            return reinterpret_cast<PartybotMgr*>(itr->second);
    }

    return nullptr;
}
