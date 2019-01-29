

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>


#define FIREBASE_HOST ""
#define FIREBASE_AUTH ""
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

int n,o,p,q;
int a=D2;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 
  // connect to wifi.
  pinMode(a,OUTPUT);
   digitalWrite(a,LOW);
 pinMode(D3,INPUT); 
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.set("person1",0);
  Firebase.set("person2",0);

 
}

void loop() {
   
  // put your main code here, to run repeatedly:
  if(digitalRead(D2)==HIGH)
  {
    Firebase.set("person1",1);
    
  }
  if(digitalRead(D2)==LOW)
  {
    Firebase.set("person1",0);
    
  }
  
  n=Firebase.getInt("person2");
  if(n==1)
  {
    digitalWrite(a,HIGH);
  }
  if(n=0)
  {
    digitalWrite(a,LOW);
  }
  


delay(500);
}
