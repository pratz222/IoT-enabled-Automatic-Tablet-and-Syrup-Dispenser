#include <Firebase_ESP_Client.h>
#include <WiFi.h>

#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

// Insert your network credentials
#define WIFI_SSID "Pratz"
#define WIFI_PASSWORD "**********"

// Insert Firebase project API Key
#define API_KEY "************************"

/* 3. Define the RTDB URL */
#define DATABASE_URL "**********************"  

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
bool signupOK = false;


//************DEFINE ALL PINS USED IN THE CODE *********************//

const int pumpPin = 4;
const int peltierPin = 5; 
const int DCPin1 = 6;
const int DCPin2 = 7;
int maxTemperature = 29;
int minTemperature = 24;



void setup() {
  
  Serial.begin(115200);
  
  dht.begin();
  pinMode(pumpPin, OUTPUT); 

  pinMode(peltierPin, OUTPUT);
  digitalWrite(peltierPin, LOW); // Initially turn off the Peltier module

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  } Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  
  /* Assign the api key (required) */
  config.api_key = API_KEY;
  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;
  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")) {
    Serial.println("ok");
    signupOK = true;
  } else {
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }
  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

}


void loop() {
  
if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 10000 || sendDataPrevMillis == 0)) {
  sendDataPrevMillis = millis();

  //DC Motor running the Entire Dispenser
    if (Firebase.RTDB.getInt(&fbdo, "Val1")){
      if (fbdo.dataType() == "int"){ 
    int Val1 =  fbdo.intData();      
    int delVal1= Val*500;                        //One rotation takes 500ms
    digitalWrite(DCPin1, HIGH);
    delay(delVal);        
    digitalWrite(DCPin1, LOW);
     }
    }

    if (Firebase.RTDB.getInt(&fbdo, "Val2")){
      if (fbdo.dataType() == "int"){ 
    int Val2 =  fbdo.intData();      
    int delVal2= Val*500;                        //One rotation takes 500ms
    digitalWrite(DCPin2, HIGH);
    delay(delVal);        
    digitalWrite(DCPin2, LOW);
     }
    }

   //PERISTALTIC PUMP connected to pump_pin
     
    if (Firebase.RTDB.getInt(&fbdo, "liqVal")){
    if (fbdo.dataType() == "int"){ 
    int liqVal =  fbdo.intData();    
    if (liqVal == 1) {
    digitalWrite(pumpPin, HIGH);
    delay(1800);                                     //Based on pumping power of the pump
    digitalWrite(pumpPin, LOW);
      }
     }
    }
  
  //TEMPERATURE & HUMIDITY
  float humid = dht.readHumidity();
  float temp = dht.readTemperature();
  Firebase.RTDB.setFloat(&fbdo, "Temp", temp);
  Firebase.RTDB.setFloat(&fbdo, "Humid", humid);

  
  //Peltier Module
  if (temp > maxTemperature) {
    // Turn on Peltier module 
    digitalWrite(peltierPin, HIGH);
  } 
  else if (temp < minTemperature) {
    // Turn off Peltier module 
    digitalWrite(peltierPin, LOW);
  }

  }
}
