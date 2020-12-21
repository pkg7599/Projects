#include <ESP8266WiFi.h>
#define DEVICE1 D6
#define DEVICE2 D2
#define DEVICE3 D5

const char* ssid = "Enter_SSID";
const char* password = "Enter_Pass";
unsigned char status_led=0;

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(DEVICE1, OUTPUT);
  digitalWrite(DEVICE1, LOW);
  pinMode(DEVICE2, OUTPUT);
  digitalWrite(DEVICE2, LOW);
  pinMode(DEVICE3, OUTPUT);
  digitalWrite(DEVICE3, LOW);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started at...");
  Serial.println(WiFi.localIP());

}

void loop() {

  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  Serial.println("new client");
  while (! client.available())
  {
    delay (1);
  }


  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();

  // Match the request

  if (req.indexOf("/dev1_off") != -1)  {
    status_led=0;
    digitalWrite(LED, LOW);
    Serial.println("DEVICE1 OFF");
  }
  else if(req.indexOf("/dev1_on") != -1)
  {
    status_led=1;
    digitalWrite(LED,HIGH);
    Serial.println("DEVICE1 ON");
  }
  if (req.indexOf("/dev1_off") != -1)  {
    status_led=0;
    digitalWrite(DEVICE2, LOW);
    Serial.println("DEVICE2 OFF");
  }
  else if(req.indexOf("/dev1_on") != -1)
  {
    status_led=1;
    digitalWrite(DEVICE2,HIGH);
    Serial.println("DEVICE2 ON");
  }
  if (req.indexOf("/dev1_off") != -1)  {
    status_led=0;
    digitalWrite(DEVICE3, LOW);
    Serial.println("DEVICE3 OFF");
  }
  else if(req.indexOf("/dev1_on") != -1)
  {
    status_led=1;
    digitalWrite(DEVICE3,HIGH);
    Serial.println("DEVICE3 ON");
  }
// Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");
  client.println("");

  client.println("<!DOCTYPE HTML>");
  client.println("<HTML>");
  client.println("<head><title>HOME AUTOMATION</title></head>");
  client.println("<H align=\"center\"1><b> HOME AUTOMATION </b></H1>");
  client.println("<br />");
  client.println("<body align=\"center\">");
  client.println("<a href=\"/dev1_on\"\"> <button style='FONT-SIZE: 50px; HEIGHT: 200px;WIDTH: 300px; 126px; Z-INDEX: 0; TOP: 200px;'> DEVICE1 ON </button> </a>");
  client.println("<a href=\"/dev1_off\"\"> <button style='FONT-SIZE: 50px; HEIGHT: 200px; WIDTH: 300px; 126px; Z-INDEX: 0; TOP: 200px;'> DEVICE1 OFF </button> </a>");
  client.println("<br />");
  client.println("<a href=\"/dev2_on\"\"> <button style='FONT-SIZE: 50px; HEIGHT: 200px;WIDTH: 300px; 126px; Z-INDEX: 0; TOP: 200px;'> DEVICE2 ON </button> </a>");
  client.println("<a href=\"/dev2_off\"\"> <button style='FONT-SIZE: 50px; HEIGHT: 200px; WIDTH: 300px; 126px; Z-INDEX: 0; TOP: 200px;'> DEVICE2 OFF </button> </a>");
  client.println("<br />");
  client.println("<a href=\"/dev3_on\"\"> <button style='FONT-SIZE: 50px; HEIGHT: 200px;WIDTH: 300px; 126px; Z-INDEX: 0; TOP: 200px;'> DEVICE3 ON </button> </a>");
  client.println("<a href=\"/dev3_off\"\"> <button style='FONT-SIZE: 50px; HEIGHT: 200px; WIDTH: 300px; 126px; Z-INDEX: 0; TOP: 200px;'> DEVICE3 OFF </button> </a>");
  client.println("</body>");
  client.println("</html>");

  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");

}
