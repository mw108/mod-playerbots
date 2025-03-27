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
    static PartybotMgr* instance()
    {
        static PartybotMgr instance;
        return &instance;
    }

    static bool HandlePartybotMgrCommand(ChatHandler* handler, char const* args);

    Player* GetMaster() const { return master; };

private:
    Player* const master;
};

#define sPartybotMgr PartybotMgr::instance()

#endif
