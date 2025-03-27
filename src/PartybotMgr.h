/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _PLAYERBOT_PARTYBOTMGR_H
#define _PLAYERBOT_PARTYBOTMGR_H

#include "ObjectGuid.h"
#include "PlayerbotMgr.h"

class ChatHandler;
class WorldLocation;

class PartybotMgr : public PlayerbotHolder
{
public:
    PartybotMgr(Player* const master);
    virtual ~PartybotMgr();

    static bool HandlePartybotMgrCommand(ChatHandler* handler, char const* args);
    void HandleCommand(uint32 type, std::string const text);

    Player* GetMaster() const { return master; };

protected:

private:
    Player* const master;
    PlayerBotErrorMap errors;
    time_t lastErrorTell;
};

class PartybotsMgr
{
public:
    PartybotsMgr() {}
    ~PartybotsMgr() {}

    static PartybotsMgr* instance()
    {
        static PartybotsMgr instance;
        return &instance;
    }

    PlayerbotAI* GetPlayerbotAI(Player* player);
    PartybotMgr* GetPartybotMgr(Player* player);

private:
    std::unordered_map<ObjectGuid, PlayerbotAIBase*> _playerbotsAIMap;
    std::unordered_map<ObjectGuid, PlayerbotAIBase*> _partybotsMgrMap;
};

#define sPartybotsMgr PartybotsMgr::instance()

#endif
