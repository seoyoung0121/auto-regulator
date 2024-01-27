#include <LiquidCrystal.h>
#include <Servo.h>

Servo servo;


LiquidCrystal lcd(4,6,10,11,12,13);

int sensor = A1;                           // 수위센서 A0핀 설정

int value = 0;                               // loop에서 사용할 변수 설정


// lowest and highest sensor readings:
const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum


void setup() {   

  servo.attach(9);
  servo.write(0);
  delay(1000);
  Serial.begin (9600); 
  
  lcd.begin(16,2);
  // initialize serial communication @ 9600 baud: 
  lcd.clear();

  servo.write(0);

}
void loop() {

  // read the sensor on analog A0:
 int sensorReading = analogRead(A0);
  // map the sensor range (four options):
  // ex: 'long int map(long int, long int, long int, long int, long int)'
 int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
  // range value:


//강우량 센서 
  lcd.setCursor(0,0);  
  switch (range) {
 case 0:    // Sensor getting wet
    lcd.print("Flood       ");
    
  
    break;
 case 1:    // Sensor getting wet
    lcd.print("Rain Warning");
  
    break;
 case 2:    // Sensor dry - To shut this up delete the " Serial.println("Not Raining"); " below.
    lcd.print("Not Raining ");
    break;}

//수위센서&서보모터
  lcd.setCursor(0,1);
  value = analogRead(sensor);     // 수위센서값을 읽어 변수 value에 저장
  lcd.print("value: ");
  lcd.print(value);                   // 저장된 센서값을 시리얼 모니터에 출력

  if(value>300)
   {
  
    servo.write(180);
    delay(5000);

   }
  else
  {
     servo.write(0);
    
  }
  
  //servo.detach();  서보 종료 함수 
}
