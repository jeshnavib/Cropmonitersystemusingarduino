#include <LiquidCrystal.h>
#include <DHT.h>
#define DHTPIN 3        // Pin where the DHT11 is connected
#define DHTTYPE DHT11   // DHT sensor type
const int soilMoisturePin = A0; // Analog pin connected to soil moisture sensor
const int relayPin = 10; 
DHT dht(DHTPIN, DHTTYPE);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 6;  // LCD pins
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);   // Initialize the LCD with 16 columns and 2 rows
  dht.begin();         // Initialize the DHT sensor
  pinMode(soilMoisturePin, INPUT); // Set soil moisture pin as input
  pinMode(relayPin, OUTPUT);       // Set relay pin as output
}

void loop() {
  int moistureLevel = analogRead(soilMoisturePin); // Read moisture level from sensor
  
  
  int mappedMoisture = map(moistureLevel, 0, 1023, 0, 100);
  
 
  if (mappedMoisture < 30) {
    
    digitalWrite(relayPin, HIGH);
  } else {
    
    digitalWrite(relayPin, LOW);
  }

  
  delay(1000);

         
  float humidity = dht.readHumidity();    
  float temperature = dht.readTemperature();
  lcd.clear();    
  lcd.setCursor(0, 0); 
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");
  
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print(" %");
}
