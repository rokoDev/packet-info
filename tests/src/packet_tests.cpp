#include <fmt/core.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <ndt/core.h>
#include <packet_info/packet_info.h>

TEST(PacketInfo, Join)
{
    client::JoinPacket joinPacket;
    ASSERT_EQ(joinPacket.packetId(), 0);
}