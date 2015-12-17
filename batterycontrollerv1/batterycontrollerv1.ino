#include <Bridge.h>
#include <BridgeServer.h>
#include <BridgeClient.h>

BridgeServer server;

const int temperaturePin = A0;

void setup() {
  //general
  Serial.begin(9600);

  //restfulServer
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH);
  server.listenOnLocalhost();
  server.begin();
}

void loop() {

  // restfulServer
  BridgeClient client = server.accept();
  if (client) {
    process(client);
    client.stop();
  }

  // getTemp
  float degreesC;
  degreesC = getTemp(temperaturePin);
  Serial.print("  deg C: ");
  Serial.print(degreesC);

  // general 
  delay(1000);
}
