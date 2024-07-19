#include <Servo.h>
#define RELAY_lamp 2
#define RELAY_fan 5
#define R_led 4

#define buzzer 3
#define gas A0

Servo servo;

void setup()
{
  servo.attach(9);
  servo.write(0);
  Serial.begin(9600);
  pinMode(RELAY_lamp,OUTPUT);
pinMode(RELAY_fan,OUTPUT);
  pinMode(R_led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(gas,INPUT);
}

int read_gas=0;
int count=0;
void loop(){  
  if(Serial.available()){
    char data=Serial.read();

    if(data=='L')
      digitalWrite(RELAY_lamp,HIGH); 

   else if (data=='F')
            digitalWrite(RELAY_fan,0); 

    else if(data=='l')
         digitalWrite(RELAY_lamp,1);

    else if (data=='f')
         digitalWrite(RELAY_fan,1); 

    else if(data=='p'){
    count=0;
    servo.write(0);  }

    else if(data=='N')count++;

    else if (data=='P')
{
      servo.write(90); 
} 
 }

  if(count==3){
    digitalWrite(buzzer,0);
    delay(3000);
    digitalWrite(buzzer,1);
    count=0;
  }
 check_Gas();
    
}

void check_Gas()
{
  
  read_gas=analogRead(gas); 
   if(read_gas>=150)
   {
    digitalWrite(R_led,HIGH);
   }
   else
   {
    digitalWrite(R_led,LOW);
   }

}