
# MQTT Client

This project contains an MQTT client that connects to the ESP32 MQTT broker. It allows users to send and receive messages over MQTT topics.

---

## Features

- Connects to the broker (TCP or TLS).
- Sends messages to specified topics.
- Subscribes to topics to receive messages.
- Simple command-line interface for ease of use.

---

## Prerequisites

1. **C++ Compiler** (e.g., `g++` on Linux or MinGW on Windows)
2. **Paho MQTT C++ Library**
3. **OpenSSL** (if using TLS/SSL)

---

## Setup Guide

### Step 1: Clone the Repository

Clone this repository to your local machine:

```bash
git clone https://github.com/Maksikos-ctrl/MqttClient.git
cd MqttClient
```

### Step 2: Install Dependencies

Ensure the Paho MQTT C++ library is installed and compiled. Follow [this guide](https://www.eclipse.org/paho/).

### Step 3: Build the Client

Use the provided `Makefile` to compile the client:

```bash
make all
```

### Step 4: Run the Client

Run the executable:

```bash
./mqtt_client
```

---

## Usage

### Commands

Once the client starts, you can:

- Send messages:
  ```
  message [content]
  ```
- Switch topics:
  ```
  switch [topic_name]
  ```
- Exit the client:
  ```
  exit
  ```

### Notes

- Update the server address in `mqtt_client.cpp` if necessary:
  ```cpp
  const std::string SERVER_ADDRESS = "tcp://192.168.4.1:1883";
  ```
- If using TLS/SSL, ensure the client uses the same certificate as the server.

---

## Example Output

```text
Connecting to the MQTT server...
Connected to MQTT server!
Subscribed to topic: chat/general

Commands:
  [message] - Send a message
  [switch] [topic] - Change chat topic
  [exit] - Quit the client

Enter command: message Hello, MQTT!
Message sent: Hello, MQTT!
Message received: chat/general -> Hello, MQTT!
```
