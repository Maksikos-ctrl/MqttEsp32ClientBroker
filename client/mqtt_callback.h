#ifndef MQTT_CALLBACK_H
#define MQTT_CALLBACK_H

#include <mqtt/async_client.h>
#include <iostream>

class callback_handler : public virtual mqtt::callback {
private:
    mqtt::async_client& client;

public:
    explicit callback_handler(mqtt::async_client& cli);

    void message_arrived(mqtt::const_message_ptr msg) override;

    void connection_lost(const std::string& cause) override;

    void delivery_complete(mqtt::delivery_token_ptr token) override;
};

#endif




