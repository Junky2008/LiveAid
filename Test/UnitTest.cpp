#include "../Inc/gtest/gtest.h"
#include "mosquittoTestClient.h"
#include "../Inc/mosquittoClient.h"
#include <iostream>

using namespace std;

void init()
{
    mosqpp::lib_init();
}

void deinit()
{
    mosqpp::lib_cleanup();
}

class UnitTest : public testing::Test
{
};

TEST_F(UnitTest, Activity)
{
    mosquittoClient client(string("TestServer"), string(DEFAULT_SERVER_TOPIC), string(DEFAULT_HOST), DEFAULT_PORT, DEFAULT_TIMEOUT);
    mosquittoTestClient testClient(string("TestClient"), string(DEFAULT_SERVER_TOPIC), string(DEFAULT_HOST), DEFAULT_PORT, DEFAULT_TIMEOUT);
    int i = 3;
    while(i-- > 0)
    {
        client.loop();
        testClient.loop();
    }
    testClient.sendMessage(string(CHECK_MESSAGE));
    i = 3;
    while(i-- > 0)
    {
        client.loop();
        testClient.loop();
    }
    string ret = testClient.getLastMessage();
    EXPECT_EQ(ret, ACTIVE_MESSAGE);
}

TEST_F(UnitTest, double)
{
    mosquittoClient *client = new mosquittoClient(string("TestServer"), string(DEFAULT_SERVER_TOPIC), string(DEFAULT_HOST), DEFAULT_PORT, DEFAULT_TIMEOUT);
    mosquittoTestClient testClient(string("TestClient"), string(DEFAULT_SERVER_TOPIC), string(DEFAULT_HOST), DEFAULT_PORT, DEFAULT_TIMEOUT);
    int i = 3;
    while(i-- > 0)
    {
        client->loop();
        testClient.loop();
    }
    delete client;
    i = 3;
    while(i-- > 0)
    {
        testClient.loop();
    }
    string ret = testClient.getLastMessage();
    EXPECT_EQ(ret, DISCONNECT_MESSAGE);
}

int main (int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    int returnValue;
    init();
    returnValue = RUN_ALL_TESTS();
    deinit();
    return returnValue;
}
