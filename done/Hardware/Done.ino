//กำหนดขาของแต่ละคน
int sensorPin = A0;
#define LEDRED D0
#define sound D6  
#define LEDGREEN D1
#define LEDBLUE D2

void setup() {
  Serial.begin(9600); 
  //pinmodeของแต่ละตัว 
  pinMode(LEDRED, OUTPUT);
  pinMode(LEDGREEN, OUTPUT);
  pinMode(LEDBLUE, OUTPUT); 
  pinMode(sound, OUTPUT); 
}

void loop() {
  int sensorValue;
  sensorValue = analogRead(sensorPin);
  sensorValue = map(sensorValue, 0, 1023, 0, 100);//อ่านค่าความชื้น
  Serial.print(sensorValue);
  Serial.println("%");
 if(sensorValue <=35)
 {
     setColor(0, 0, 255); //สีฟ้า
     digitalWrite(sound,HIGH);
     delay(3000);
     digitalWrite(sound,LOW);
     delay(1000); 
  }
  else  if(sensorValue =37)
     {
          setColor(0,  255,0);//สีเขียว
     }
  else   if(sensorValue >=38){
          setColor(255,0, 0);//สีแดง
          digitalWrite(sound,HIGH);
          delay(500);
          digitalWrite(sound,LOW);
          delay(500); 
  }
    delay(500);
}           //กำหนดค่าสี
  void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(LEDRED, red);
  analogWrite(LEDGREEN, green);
  analogWrite(LEDBLUE, blue);  
}
