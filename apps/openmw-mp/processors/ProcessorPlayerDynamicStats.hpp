//
// Created by koncord on 01.04.17.
//

#ifndef OPENMW_PROCESSORPLAYERDYNAMICSTATS_HPP
#define OPENMW_PROCESSORPLAYERDYNAMICSTATS_HPP


#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorPlayerDynamicStats : public PlayerProcessor
    {
    public:
        ProcessorPlayerDynamicStats()
        {
            BPP_INIT(ID_PLAYER_DYNAMICSTATS)
        }

        void Do(PlayerPacket &packet, Player &player) override
        {
            DEBUG_PRINTF(strPacketID.c_str());

            packet.setPlayer(&player);
            packet.Read();

            player.sendToLoaded(&packet);
        }
    };
}


#endif //OPENMW_PROCESSORPLAYERDYNAMICSTATS_HPP
