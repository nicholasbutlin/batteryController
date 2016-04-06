#include <Bridge.h>
#include <BridgeServer.h>
#include <BridgeClient.h>

BridgeServer server;

const int temperaturePin = A0;
const int dcVoltsPin = A1;
const int acVoltsPin = A2;

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

  //
  float voltsAC;
  float ampsAC;
  float pwrAC;
  float voltsDC;
  float ampsDC;
  float pwrDC;
  float tempC;

  tempC = getTemp(temperaturePin);
  voltsDC = getDCVolts(dcVoltsPin);
  voltsAC = getACVolts(acVoltsPin);
  ampsDC = getDCAmps(dcVoltsPin);
  ampsAC = getACAmps(acVoltsPin);

  pwrDC = calcDCPwr(ampsDC, voltsDC);
  pwrAC = calcACPwr(ampsAC, voltsAC);

  // Serial out
  Serial.print(tempC);


  // general
  delay(1000);
}
