/*
  Web client

 This sketch connects to a website (http://www.google.com)
 using an Arduino Wiznet Ethernet shield.

 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13

 created 18 Dec 2009
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe, based on work by Adrian McEwen

 */

#include <SPI.h>
#include <Ethernet.h>
#define AIR_SENSOR 0
#define SOUND_SENSOR 1
// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFD, 0xEB };
// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
IPAddress server(192,168,1,10);  // numeric IP for Google (no DNS)
//char server[] = "www.google.com";    // name address for Google (using DNS)

// Set the static IP address to use if the DHCP fails to assign
IPAddress ip(192, 168, 1, 77);

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
EthernetClient client;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip);
  }else{
    Serial.println("Ethernet connection configured!");  
  }
  // give the Ethernet shield a second to initialize:
}

void loop() {
  // if there are incoming bytes available
  // from the server, read them and print them:
  delay(1000);
  Serial.println("Sending request....");
  int airSensor=analogRead(AIR_SENSOR);
  int soundSensor=analogRead(SOUND_SENSOR);
  Serial.print("Air Sensor: ");
  Serial.println(airSensor);
  Serial.print("Sound Sensor: ");
  Serial.println(soundSensor);
  if (client.connect(server, 80)) {
    Serial.println("connected");
    // Make a HTTP request:
    //+airSensor+"&sensor_value2="+soundSensor+" HTTP/1.1"
    client.print("GET /air_sound/insert.php?sensor_value1=");
    client.print(airSensor);
    client.print("&sensor_value2=");
    client.print(soundSensor);
    client.println(" HTTP/1.1");
    client.println("Host: localhost");
    client.println("Connection: close");
    client.println();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
  while (client.available()) {
    char c;
    if(c = client.read()){
      Serial.print(c);  
    }
  }
  client.stop();
}

