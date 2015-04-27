#ifndef MOSQUITTOTESTCLIENT_H
#define MOSQUITTOTESTCLIENT_H

#include "../Inc/config.h"
#include <mosquittopp.h>
#include <string>
#include <iostream>

using namespace std;

class mosquittoTestClient : public mosqpp::mosquittopp
{
public:
  mosquittoTestClient(const string& clientname,
                  const string& topic,
                  const string& host,
                  int port,
                  int timeout);
  virtual ~mosquittoTestClient();
  void sendMessage(const string topic, const string& message);
  void sendMessage(const string& message);
  string getLastMessage();
private:
  string _topic;
  string _lastMessage;
protected:
  virtual void on_connect(int rc) override;
  virtual void on_message(const mosquitto_message *message) override;
};

#endif //MOSQUITTOTESTCLIENT_H

