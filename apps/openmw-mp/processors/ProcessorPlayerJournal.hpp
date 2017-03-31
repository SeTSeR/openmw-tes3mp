//
// Created by koncord on 01.04.17.
//

#ifndef OPENMW_PROCESSORPLAYERJOURNAL_HPP
#define OPENMW_PROCESSORPLAYERJOURNAL_HPP


#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorPlayerJournal : public PlayerProcessor
    {
    public:
        ProcessorPlayerJournal()
        {
            BPP_INIT(ID_PLAYER_JOURNAL)
        }

        void Do(PlayerPacket &packet, Player &player) override
        {
            DEBUG_PRINTF(strPacketID.c_str());

            packet.setPlayer(&player);
            packet.Read();

            Script::Call<Script::CallbackIdentity("OnPlayerJournalChange")>(player.getId());
        }
    };
}

#endif //OPENMW_PROCESSORPLAYERJOURNAL_HPP
