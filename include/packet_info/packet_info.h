#include "ndt/core.h"

namespace client
{
enum class ePacketType : uint8_t
{
    kJoin,
    kLeave,
    kInput,
    kRequestTime,
    Count,
    Error = Count
};

class UserInput
{
   public:
    inline uint8_t actionKey() const noexcept { return actionKey_; }
    inline void actionKey(const uint8_t aActionKey) noexcept
    {
        actionKey_ = aActionKey;
    }
    constexpr std::size_t minBitSize() const noexcept
    {
        return sizeof(actionKey_) * 8;
    }
    inline void deserialize(ndt::BinReader &aReader) noexcept
    {
        actionKey_ = aReader.get<uint8_t>();
    }
    inline void serialize(ndt::BinWriter &aWriter) const noexcept
    {
        aWriter.add<uint8_t>(actionKey_);
    }

   private:
    uint8_t actionKey_ = 0;
};

using JoinPacket = ndt::Packet<ePacketType, ePacketType::kJoin, ndt::PacketId>;
using LeavePacket =
    ndt::Packet<ePacketType, ePacketType::kLeave, ndt::PacketId, ndt::UserId>;
using InputPacket = ndt::Packet<ePacketType, ePacketType::kInput, ndt::PacketId,
                                ndt::UserId, UserInput>;
using RequestTimePacket = ndt::Packet<ePacketType, ePacketType::kRequestTime,
                                      ndt::PacketId, ndt::UserId>;
}  // namespace client

namespace server
{
enum class ePacketType : uint8_t
{
    kJoin,
    kGSUpdate,
    kReplyTime,
    Count,
    Error = Count
};

class GameState
{
   public:
    inline uint8_t stateKey() const noexcept { return stateKey_; }
    inline void stateKey(const uint8_t aStateKey) noexcept
    {
        stateKey_ = aStateKey;
    }
    constexpr std::size_t minBitSize() const noexcept
    {
        return sizeof(stateKey_) * 8;
    }
    inline void deserialize(ndt::BinReader &aReader) noexcept
    {
        stateKey_ = aReader.get<uint8_t>();
    }
    inline void serialize(ndt::BinWriter &aWriter) const noexcept
    {
        aWriter.add<uint8_t>(stateKey_);
    }

   private:
    uint8_t stateKey_ = 0;
};

using JoinPacket =
    ndt::Packet<ePacketType, ePacketType::kJoin, ndt::PacketId, ndt::UserId>;
using GSUpdatePacket =
    ndt::Packet<ePacketType, ePacketType::kGSUpdate, ndt::PacketId, GameState>;
using ReplyTimePacket = ndt::Packet<ePacketType, ePacketType::kReplyTime,
                                    ndt::PacketId, ndt::TimeStamp>;
}  // namespace server