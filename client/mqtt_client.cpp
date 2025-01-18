#include "mqtt_callback.h"
#include "gui.h"
#include <cstdlib> // Для rand()
#include <ctime>   // Для srand()

int main() {
    srand(static_cast<unsigned>(time(0))); // Инициализация генератора случайных чисел
    const std::string SERVER_ADDRESS = "tcp://192.168.4.1:1883";
    const std::string CLIENT_ID = "client_" + std::to_string(rand());

    mqtt::async_client client(SERVER_ADDRESS, CLIENT_ID);
    callback_handler cb_handler(client); // Передаем клиент в callback_handler
    std::string current_topic = "chat/general";

    try {
        client.set_callback(cb_handler);

        std::cout << "Connecting to the MQTT server..." << std::endl;
        mqtt::token_ptr conntok = client.connect();
        conntok->wait();
        std::cout << "Connected to MQTT server!" << std::endl;

        client.subscribe(current_topic, 1)->wait();
        std::cout << "Subscribed to topic: " << current_topic << std::endl;

        while (true) {
            display_menu(); // Отображение GUI
            std::string input = get_user_input();

            if (input == "exit") {
                break;
            } else if (input.rfind("switch ", 0) == 0) { // Если команда начинается с "switch "
                std::string new_topic = input.substr(7); // Получить новую тему
                client.unsubscribe(current_topic)->wait();
                current_topic = new_topic;
                client.subscribe(current_topic, 1)->wait();
                std::cout << "Switched to topic: " << current_topic << std::endl;
            } else {
                auto msg = mqtt::make_message(current_topic, input);
                client.publish(msg)->wait();
                std::cout << "Message sent: " << input << std::endl;
            }
        }

        client.disconnect()->wait();
        std::cout << "Disconnected from MQTT server!" << std::endl;

    } catch (const mqtt::exception& exc) {
        std::cerr << "Error: " << exc.what() << std::endl;
        return 1;
    }

    return 0;
}







