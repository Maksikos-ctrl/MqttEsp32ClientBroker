#include "mqtt_callback.h"

callback_handler::callback_handler(mqtt::async_client& cli) : client(cli) {}

void callback_handler::message_arrived(mqtt::const_message_ptr msg) {
    std::cout << "Message received: " << msg->get_topic() << " -> " << msg->to_string() << std::endl;
}

void callback_handler::connection_lost(const std::string& cause) {
    std::cerr << "Connection lost! Cause: " << cause << std::endl;
}

void callback_handler::delivery_complete(mqtt::delivery_token_ptr token) {
    std::cout << "Delivery complete for token: " << (token ? token->get_message_id() : -1) << std::endl;
}

