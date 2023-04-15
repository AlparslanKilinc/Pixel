#include <DFRobotDFPlayerMini.h>
#include "Arduino.h"
#include "SoftwareSerial.h"
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(128, 64, &Wire, OLED_ADDRESS);
// Create the Player
int serial1 = 10;
int serial2 = 11;
SoftwareSerial mySoftwareSerial(serial1,serial2);
DFRobotDFPlayerMini player;

/// Helper Shapes
// Mouth
int smile(){
  display.fillCircle(64, 50, 12, WHITE);    // full smile
  display.fillRect(0, 38, 128, 12, BLACK);  // hide top half of smile
  return 0;
}
int mouth(){
  display.fillRect(32, 55, 64, 8, WHITE);
  display.fillCircle(32, 58, 3, WHITE);
  display.fillCircle(96, 58, 3, WHITE);
  return 0;
}
int smallest_mouth(){
  display.fillRect(54, 54, 22, 4, WHITE);
  display.fillRect(44, 28, 10, 4, WHITE);
  display.fillRect(76, 28, 10, 4, WHITE);
  return 0;
}
int small_mouth(){
  display.fillRect(48, 45, 32, 8, WHITE);
  display.fillCircle(48, 48, 3, WHITE);
  display.fillCircle(80, 48, 3, WHITE);
  return 0;
}
// eyes
int left_heart(){
  int x1 = 44;
  int y1 = 27;
  int radius1 = 10;
  display.fillTriangle(x1 - radius1, y1, x1, y1 + radius1, x1 + radius1, y1, WHITE);
  display.fillCircle(x1 - 5, y1, 5.5, WHITE);
  display.fillCircle(x1 + 5, y1, 5.5, WHITE);
  return 0;
}
int right_heart(){
  int x2 = 84;
  int y2 = 27;
  int radius2 = 10;
  display.fillTriangle(x2 - radius2, y2, x2, y2 + radius2, x2 + radius2, y2, WHITE);
  display.fillCircle(x2 - 5, y2, 5.5, WHITE);
  display.fillCircle(x2 + 5, y2, 5.5, WHITE);
  return 0;
}
int blink(){
  display.fillRect(36,28,20,8,WHITE);
  display.fillRect(76,28,20,8,WHITE); 
  return 0;
}
int left_wink(){
  display.fillCircle(46, 32, 8, WHITE);
  display.fillRect(76, 28, 20, 8, WHITE);
  return 0;
}
int right_wink(){
  display.fillRect(36, 28, 20, 8, WHITE);
  display.fillCircle(80, 32, 8, WHITE);
  return 0;
}
int eyes(){
  display.fillCircle(48, 27, 8, WHITE);
  display.fillCircle(80, 27, 8, WHITE);
  return 0;
}
int side_eye(){
  display.fillCircle(32, 32, 8, WHITE);
  display.fillCircle(96, 32, 8, WHITE);
  return 0;
}
// Draw ^ Symbol
int left_carrot_eye(){
  int centerX = 42;
  int centerY = 32;
  int lineLength = 10;
  display.drawLine(centerX - lineLength, centerY + lineLength, centerX, centerY - lineLength, WHITE);
  display.drawLine(centerX, centerY - lineLength, centerX + lineLength, centerY + lineLength, WHITE);
  return 0;
}
int right_carrot_eye(){
  int centerXl = 90;
  int centerYl = 32;
  int lineLength = 10;
  display.drawLine(centerXl - lineLength, centerYl + lineLength, centerXl, centerYl - lineLength, WHITE);
  display.drawLine(centerXl, centerYl - lineLength, centerXl + lineLength, centerYl + lineLength, WHITE);
  return 0;
}
/// Faces
int heart_face(){
  player.playMp3Folder(3);
  display.clearDisplay();
  left_heart();
  right_heart();
  smallest_mouth();
  display.display();
  delay(2000);
  return 0;
}
int yawn_face(){
  display.clearDisplay();
  blink();
  display.fillCircle(64, 50, 8, WHITE);
  display.display();
  delay(1000);
  return 0;
}
int blink_face(){
  display.clearDisplay();
  blink();
  small_mouth();
  display.display();
  delay(400);
  return 0;
}
int left_winkey_face(){
  display.clearDisplay();
  left_wink();
  small_mouth();
  display.display();
  delay(400);
  return 0;
}
int right_winkey_face(){
  display.clearDisplay();
  right_wink();
  small_mouth();
  display.display();
  delay(400);
  return 0;
}
int reg_face(){
  display.clearDisplay();
  eyes();
  small_mouth();
  display.display();
  delay(400);
  return 0;
}
int side_eye_face(){
  display.clearDisplay();
  side_eye();
  mouth();
  display.display();
  delay(2000);
  return 0;
}
int carrot_face(){
  display.clearDisplay();
  left_carrot_eye();
  right_carrot_eye();
  smile();
  display.display();
  delay(3000);
  return 0;
}
int winking_carrot_face(){
  display.clearDisplay();
  display.fillRect(36,28,20,8,WHITE);
  right_carrot_eye();
  smile();
  display.display();
  delay(1000);
  return 0;
}
/// Animations 
int sleep(){
  for(int i=0; i<3; i++){
    blink_face();
    yawn_face();
  }
  return 0;
}
int wake_up(){
  for(int i=0; i<2; i++){
    blink_face();
    left_winkey_face();
  }
  blink_face();
  right_winkey_face();
  blink_face();
  reg_face();
  return 0;
}
int start_up(){
  player.playMp3Folder(1);
  blink_face();
  left_winkey_face();
  blink_face();
  right_winkey_face();
  blink_face();
  reg_face();
  delay(1000);
  return 0;
}
int blinking(){
  reg_face();
  blink_face();
  reg_face();
  blink_face();
  return 0;
}
int give_side_eyes(){
  reg_face();
  side_eye_face();
  reg_face();
  side_eye_face();
  return 0;
}
int carrot_face_blinking(){
  for(int i=0; i<3; i++){
    carrot_face();
    winking_carrot_face();
  }
  return 0;
}

int welcome(){
  player.playMp3Folder(2);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(35, 20);
  display.println("Pixel");
  display.display();
  delay(2500);
  return 0;  
}
int cute_msg(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(25, 0);
  display.println("You");
  display.setCursor(25, 20);
  display.println("Are");
  display.setTextSize(1);
  display.setCursor(25, 40);
  display.println("Amazing <3");
  display.display();
  delay(1000);
  return 0;  
}

// Randomizer 
int randomize(){
  int random_num = random(4);
  switch(random_num){
    case 1:
      carrot_face_blinking();
      break;
    case 2:
      give_side_eyes();
      break;
    case 3:
      heart_face();
      break;
    case 4:
      blinking();
      break;
    default:
      cute_msg();
      break;    
  }  
  return 0;
}

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS);
  pinMode(serial1, INPUT);
  pinMode(serial2, OUTPUT);
  /// Sound Set Up 
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  Serial.println("Initializing DFPlayer ...");
  player.begin(mySoftwareSerial);

  player.volume(20);  //Set volume value. From 0 to 30

  /// Display Set Up 
  start_up();
  welcome();
}

void loop() {
  heart_face();
  player.playMp3Folder(6);
  static unsigned long timer = millis();
  timer=0;
  while(timer<100000) {
    timer = millis();
    carrot_face_blinking();
    give_side_eyes();
    blinking();
  }
}