// Project 20: Smart City Lighting System 
// Features: Auto ON/OFF using LDR + Time-based Control (RTC DS1307 or DS3231)

#include <Wire.h>
#include <RTClib.h>   // Library for DS1307 / DS3231 RTC

RTC_DS1307 rtc;       // Use DS1307 (or change to RTC_DS3231 if needed)

const int LDR_PIN = A0;           // LDR Sensor pin
const int LED_PIN = 9;            // LED (Street Light)
const int DARKNESS_THRESHOLD = 251; // Adjust based on your LDR readings

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("--- Smart City Lighting System Initialized ---");

  // Initialize RTC
  if (!rtc.begin()) {
    Serial.println("RTC not found! Check connections.");
    while (1);
  }

  // DS1307 doesn’t have lostPower(), so set time manually if needed
  // You can uncomment this once to set time at upload:
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  Serial.println("RTC ready.");
}

void loop() {
  // Read LDR value
  int lightValue = analogRead(LDR_PIN);

  // Read current time from RTC
  DateTime now = rtc.now();
  int hour = now.hour();    // 0–23 format
  int minute = now.minute();

  // Determine night based on time or darkness
  bool isDark = (lightValue < DARKNESS_THRESHOLD);
  bool isNightTime = (hour >= 18 || hour < 5); // Night: 6PM–5AM

  // Debug info on Serial Monitor
  Serial.print("Time: ");
  if (hour < 10) Serial.print('0');
  Serial.print(hour);
  Serial.print(":");
  if (minute < 10) Serial.print('0');
  Serial.print(minute);
  Serial.print(" | LDR: ");
  Serial.print(lightValue);
  Serial.print(" | Dark: ");
  Serial.print(isDark);
  Serial.print(" | NightTime: ");
  Serial.print(isNightTime);

  // Control Logic
  if (isDark || isNightTime) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println(" → LIGHT ON");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println(" → LIGHT OFF");
  }

  delay(1000); // 1 second delay
}
