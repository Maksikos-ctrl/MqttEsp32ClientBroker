TARGET = mqtt_client
CXX = g++
CXXFLAGS = -Wall -std=c++17 -I./paho.mqtt.cpp/include
LDFLAGS = -L./paho.mqtt.cpp/build/src
LIBS = -lpaho-mqttpp3 -lpaho-mqtt3as

SRC = client/mqtt_client.cpp client/mqtt_callback.cpp client/gui.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ $(LDFLAGS) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)




