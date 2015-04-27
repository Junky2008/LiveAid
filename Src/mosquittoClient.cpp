#include "../Inc/mosquittoClient.h"

using namespace std;

mosquittoClient::mosquittoClient(const string& clientname,
                                 const string& topic = string(DEFAULT_SERVER_TOPIC),
                                 const string& host = string(DEFAULT_HOST),
                                 int port = DEFAULT_PORT,
                                 int timeout = DEFAULT_TIMEOUT)
    :  mosqpp::mosquittopp {clientname.c_str()}
{
    _topic = topic;

    will_set(_topic.c_str(), 10, (void*)DISCONNECT_MESSAGE);

    connect(host.c_str(), port, timeout);
}

mosquittoClient::~mosquittoClient()
{
    sendMessage(string(DISCONNECT_MESSAGE));
    disconnect();
}

void mosquittoClient::sendMessage(const std::string topic, const std::string &message)
{
    publish(nullptr, topic.c_str(), message.size(), message.c_str());
}

void mosquittoClient::sendMessage(const string &message)
{
    sendMessage(_topic, message);
}

void mosquittoClient::on_connect(int rc)
{
    if(rc == 0)
    {
      subscribe(nullptr, _topic.c_str());
    }
}

void mosquittoClient::on_message(const mosquitto_message *message)
{
    string m = string((char *)message->payload);
    if(m.compare(string(CHECK_MESSAGE)) == 0)
        sendMessage(string(ACTIVE_MESSAGE));
}
