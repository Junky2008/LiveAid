#include <iostream>
#include <mosquittopp.h>
#include "../Inc/mosquittoClient.h"

using namespace std;

int main(int argc, char* argv[])
{
    mosqpp::lib_init();
    mosquittoClient mClient(string("Nightwish"), string(DEFAULT_SERVER_TOPIC), string(DEFAULT_HOST), DEFAULT_PORT, DEFAULT_TIMEOUT);
    while(true)
    {
        mClient.loop();
    }
    mosqpp::lib_cleanup();
}
