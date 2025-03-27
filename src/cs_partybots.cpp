/*
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "BattleGroundTactics.h"
#include "Chat.h"
#include "GuildTaskMgr.h"
#include "PerformanceMonitor.h"
#include "PartybotMgr.h"
#include "ScriptMgr.h"

using namespace Acore::ChatCommands;

class partybots_commandscript : public CommandScript
{
public:
    partybots_commandscript() : CommandScript("partybots_commandscript") {}

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable commandTable = {
            {"partybots", HandlePartybotCommand, SEC_PLAYER, Console::No},
        };

        return commandTable;
    }

    static bool HandlePartybotCommand(ChatHandler* handler, char const* args)
    {
        return PartybotMgr::HandlePartybotMgrCommand(handler, args);
    }
};

void AddSC_partybots_commandscript() { new partybots_commandscript(); }
