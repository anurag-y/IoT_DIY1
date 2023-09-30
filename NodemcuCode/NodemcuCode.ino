#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
// Initialize the LiquidCrystal library with your LCD pin numbers
//LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
LiquidCrystal lcd(D7,D4, D3, D2,D1,D0);

#define pingPin D5
#define echoPin D6
#define alarm D8
WiFiClient client;

long myChannelNumber = 2285158;
const char myWriteAPIKey[] = "xxxxxxxxxxxxx; //put your api here
const char* ssid = "WiFi Name";
const char* password = "WiFi Password";

long myChannelNumber2 = 2287036;
const char myreadAPIKey[] = "apiKey";

void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode(echoPin, INPUT);
  pinMode(pingPin, OUTPUT);
  pinMode(alarm, OUTPUT);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
  lcd.begin(16, 2);
  delay(1000);
  lcd.print("Distance in cm:");
}

void loop() {
  long duration, cm=7;
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);

  Serial.print("Distance in cm: ");
  Serial.println(cm);
    // Display distance on LCD
  lcd.setCursor(0, 1);
  lcd.print("                "); // Clear the previous reading
  lcd.setCursor(0, 1);
  lcd.print(cm);
  // delay(2000);
  ThingSpeak.writeField(myChannelNumber, 1, cm, myWriteAPIKey);
  delay(15000);
  bool danger=false;
  danger=ThingSpeak.readLongField(myChannelNumber2, 1,myreadAPIKey);
  if (danger) {
    Serial.println("Danger ");
    digitalWrite(alarm,HIGH);
    tone(alarm, 5000); // Send 1KHz sound signal...
  }
  else{
    Serial.println("Safe ");
    digitalWrite(alarm,LOW);
    noTone(alarm);     // Stop sound...
  }
  delay(15000);
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}