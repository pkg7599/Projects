#include <ESP8266WiFi.h>
#define DEVICE1 D6
#define DEVICE2 D2
#define DEVICE3 D5
const char* ssid = "Enter_SSID";
 const char* password = "Enter_Pass";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(DEVICE1, OUTPUT);
  pinMode(DEVICE2, OUTPUT);
  pinMode(DEVICE3, OUTPUT);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  server.begin();
  Serial.println("Server started");
  //Below Ip Would be used to communicate from app.
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  Serial.println("new client");
  while(!client.available())
  {
    delay(1);
  }
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();

if (req.indexOf("/dev1_on") != -1)
  {

    digitalWrite(DEVICE1,HIGH);
    Serial.println("DEVICE1 ON");
  }
else if(req.indexOf("/dev1_off") != -1)
  {
    digitalWrite(DEVICE1,LOW);
    Serial.println("DEVICE1 OFF");
  }

if (req.indexOf("/dev2_on") != -1)
  {
    digitalWrite(DEVICE2,HIGH);
    Serial.println("DEVICE2 ON");
  }
else if(req.indexOf("/dev2_off") != -1)
  {
    digitalWrite(DEVICE2,LOW);
    Serial.println("DEVICE2 OFF");
  }
  if (req.indexOf("/dev3_on") != -1)
    {
      digitalWrite(DEVICE3,HIGH);
      Serial.println("DEVICE3 ON");
    }
else if(req.indexOf("/dev3_off") != -1)
    {
      digitalWrite(DEVICE3,LOW);
      Serial.println("DEVICE3 OFF");
    }
}
