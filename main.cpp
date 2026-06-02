#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

WebServer server(80);

#define RELAY1 26
#define RELAY2 27
#define RELAY3 14
#define RELAY4 12

bool relay1State = false;
bool relay2State = false;
bool relay3State = false;
bool relay4State = false;

String webpage()
{
  String page = "<!DOCTYPE html><html>";
  page += "<head><meta name='viewport' content='width=device-width, initial-scale=1'>";
  page += "<style>";
  page += "body{font-family:Arial;text-align:center;background:#f4f4f4;}";
  page += "button{width:200px;height:60px;font-size:20px;margin:10px;}";
  page += "</style></head><body>";

  page += "<h1>ESP32 Home Automation</h1>";

  page += "<p>Light 1</p>";
  page += "<a href='/relay1'><button>Toggle</button></a>";

  page += "<p>Light 2</p>";
  page += "<a href='/relay2'><button>Toggle</button></a>";

  page += "<p>Fan</p>";
  page += "<a href='/relay3'><button>Toggle</button></a>";

  page += "<p>Socket</p>";
  page += "<a href='/relay4'><button>Toggle</button></a>";

  page += "</body></html>";

  return page;
}

void handleRoot()
{
  server.send(200, "text/html", webpage());
}

void toggleRelay1()
{
  relay1State = !relay1State;
  digitalWrite(RELAY1, relay1State);
  server.sendHeader("Location", "/");
  server.send(303);
}

void toggleRelay2()
{
  relay2State = !relay2State;
  digitalWrite(RELAY2, relay2State);
  server.sendHeader("Location", "/");
  server.send(303);
}

void toggleRelay3()
{
  relay3State = !relay3State;
  digitalWrite(RELAY3, relay3State);
  server.sendHeader("Location", "/");
  server.send(303);
}

void toggleRelay4()
{
  relay4State = !relay4State;
  digitalWrite(RELAY4, relay4State);
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup()
{
  Serial.begin(115200);

  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);

  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, LOW);
  digitalWrite(RELAY3, LOW);
  digitalWrite(RELAY4, LOW);

  WiFi.begin(ssid, password);

  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/relay1", toggleRelay1);
  server.on("/relay2", toggleRelay2);
  server.on("/relay3", toggleRelay3);
  server.on("/relay4", toggleRelay4);

  server.begin();
}

void loop()
{
  server.handleClient();
}
