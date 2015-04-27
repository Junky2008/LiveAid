#include "mosquittoTestClient.h"

using namespace std;

mosquittoTestClient::mosquittoTestClient(const string& clientname,
                                 const string& topic = string(DEFAULT_SERVER_TOPIC),
                                 const string& host = string(DEFAULT_HOST),
                                 int port = DEFAULT_PORT,
                                 int timeout = DEFAULT_TIMEOUT)
    :  mosqpp::mosquittopp {clientname.c_str()}
{
    _topic = topic;
    _lastMessage = "NONE";

    connect(host.c_str(), port, timeout);
}

mosquittoTestClient::~mosquittoTestClient()
{
    disconnect();
}

void mosquittoTestClient::sendMessage(const std::string topic, const std::string &message)
{
    publish(nullptr, topic.c_str(), message.size(), message.c_str());
}

void mosquittoTestClient::sendMessage(const string &message)
{
    sendMessage(_topic, message);
}

string mosquittoTestClient::getLastMessage()
{
    return _lastMessage;
}

void mosquittoTestClient::on_connect(int rc)
{
    if(rc == 0)
    {
      subscribe(nullptr, _topic.c_str());
    }
}

void mosquittoTestClient::on_message(const mosquitto_message *message)
{
    _lastMessage = string((char *)message->payload);
}
