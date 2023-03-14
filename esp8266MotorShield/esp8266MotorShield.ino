#define BLYNK_PRINT Serial

//여기에 BLYNK DEVICE INFO 값을 넣어주세요

#define BLYNK_TEMPLATE_ID "*******************"
#define BLYNK_TEMPLATE_NAME "*******************"
#define BLYNK_AUTH_TOKEN "********************"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "KT_GiGA_2G_makeitnow";
char pass[] = "makeitnow1";

#define L_MOTOR_DIR D3
#define L_MOTOR_ROT D2
#define R_MOTOR_DIR D4
#define R_MOTOR_ROT D1

//전진
BLYNK_WRITE(V0){
  forward();
}
//후진
BLYNK_WRITE(V1){
  backward();
}

//후진
BLYNK_WRITE(V2){
  turnLeft();
}

//후진
BLYNK_WRITE(V3){
  turnRight();
}

//후진
BLYNK_WRITE(V4){
  stop();
}

void setup() {
  Serial.begin(9600);
  pinMode(R_MOTOR_DIR, OUTPUT);
  pinMode(R_MOTOR_ROT, OUTPUT);
  pinMode(L_MOTOR_DIR, OUTPUT);
  pinMode(L_MOTOR_ROT, OUTPUT);
  Blynk.begin(auth, ssid, pass);

}

//왼쪽모터 DIR HIGH 일때 앞으로
//오른쪽모터 DIR LOW일때 앞으로
void loop() {
  Blynk.run();
}

void forward(){
  digitalWrite(R_MOTOR_DIR, LOW); 
  digitalWrite(R_MOTOR_ROT, HIGH);
  digitalWrite(L_MOTOR_DIR, HIGH);
  digitalWrite(L_MOTOR_ROT, HIGH);
}

void backward(){
  digitalWrite(R_MOTOR_DIR, HIGH); 
  digitalWrite(R_MOTOR_ROT, HIGH);
  digitalWrite(L_MOTOR_DIR, LOW);
  digitalWrite(L_MOTOR_ROT, HIGH);
}

void turnRight(){
  digitalWrite(R_MOTOR_DIR, HIGH); 
  digitalWrite(R_MOTOR_ROT, LOW);
  digitalWrite(L_MOTOR_DIR, HIGH);
  digitalWrite(L_MOTOR_ROT, HIGH);
}

void turnLeft(){
  digitalWrite(R_MOTOR_DIR, LOW); 
  digitalWrite(R_MOTOR_ROT, HIGH);
  digitalWrite(L_MOTOR_DIR, LOW);
  digitalWrite(L_MOTOR_ROT, LOW);
}


void stop(){
  digitalWrite(R_MOTOR_ROT, LOW);
  digitalWrite(L_MOTOR_ROT, LOW);
}

