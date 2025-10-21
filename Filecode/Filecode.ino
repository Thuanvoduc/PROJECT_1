cpp
Copy code
#include <Servo.h>
#include <LiquidCrystal.h>

Servo servo;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int ldrPin = A0;
const int relayPin = 7;
const int buttonPin = 8;
int lightLevel = 0;
bool isLightOn = false;
const int threshold = 500; // Ngưỡng ánh sáng để bật/tắt đèn

void setup() {
  servo.attach(9);
  lcd.begin(16, 2);
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  lcd.print("Light System");
  delay(2000);
  lcd.clear();
}

void loop() {
  lightLevel = analogRead(ldrPin);
  int buttonState = digitalRead(buttonPin);
  
  lcd.setCursor(0, 0);
  lcd.print("ĐÈN: ");
  lcd.print(lightLevel);
  
  if (lightLevel < threshold && !isLightOn) {
    digitalWrite(relayPin, HIGH);
    isLightOn = true;
    lcd.setCursor(0, 1);
    lcd.print("ĐÈN: BẬT");
  } else if (lightLevel >= threshold && isLightOn) {
    digitalWrite(relayPin, LOW);
    isLightOn = false;
    lcd.setCursor(0, 1);
    lcd.print("ĐÈN: TẮT");
  }

  if (buttonState == LOW) {
    servo.write(90); // Giả sử 90 độ là vị trí mở màn che
    lcd.setCursor(8, 1);
    lcd.print("CỬA: MỞ");
  } else {
    servo.write(0); // Giả sử 0 độ là vị trí đóng màn che
    lcd.setCursor(8, 1);
    lcd.print("CỬA: ĐÓNG");
  }
  delay(500);
}
