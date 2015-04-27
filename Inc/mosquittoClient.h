#ifndef MOSQUITTOCLIENT_H
#define MOSQUITTOCLIENT_H

#include "config.h"
#include <mosquittopp.h>
#include <string>
#include <iostream>

using namespace std;

class mosquittoClient : public mosqpp::mosquittopp
{
public:
  mosquittoClient(const string& clientname,
                  const string& topic,
                  const string& host,
                  int port,
                  int timeout);
  virtual ~mosquittoClient();
  void sendMessage(const string topic, const string& message);
  void sendMessage(const string& message);
private:
  string _topic;
protected:
  virtual void on_connect(int rc) override;
  virtual void on_message(const mosquitto_message *message) override;
};

#endif //MOSQUITTOCLIENT_H
