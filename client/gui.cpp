#include "gui.h"

void display_menu() {
    std::cout << "\n=== MQTT Chat Client ===" << std::endl;
    std::cout << "Commands:" << std::endl;
    std::cout << "  [message] - Send a message" << std::endl;
    std::cout << "  switch [topic] - Change chat topic" << std::endl;
    std::cout << "  exit - Quit the client" << std::endl;
}

std::string get_user_input() {
    std::string input;
    std::cout << "Enter command: ";
    std::getline(std::cin, input);
    return input;
}

