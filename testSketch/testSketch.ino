// Keyboard Dependencies
#include <Keyboard.h>

// OLED Dependencies
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED Definitions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Key definitions
#define BUTTONPIN0 4
#define BUTTONPIN1 5

// Data Buffer
int binarr[7];
int curr = 0;

// Char Arr for second line of OLED
char last[] = {'L', 'a', 's', 't', ':', ' ', ' '};

void setup()
{
  // Set Keyboard pins
  pinMode(BUTTONPIN0, INPUT_PULLUP);
  pinMode(BUTTONPIN1, INPUT_PULLUP);

  // Start all outputs
  Serial.begin(9600);
  Keyboard.begin();
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
}

void loop(){
  if (digitalRead(BUTTONPIN0) == 0){
    Serial.println("0 Pressed");
    binarr[curr] = 0;
  }
  else if (digitalRead(BUTTONPIN1) == 0){
    Serial.println("1 Pressed");
    binarr[curr] = 1;
  }
  // avoids infinite loop
  else{
    return;
  }
  display.print(binarr[curr]);
  display.display();

  curr++;
  // On last char print last to OLED, type char and reset pointer
  if (curr == 7){
    int toType = arrToInt(binarr);
    Serial.println(toType);
    lastCharDisplay(toType);
    Keyboard.write(toType);
    curr = 0;
  }
  // small delay to avoid double presses
  delay(250);
}

void lastCharDisplay(char toType){
  display.clearDisplay();
  display.setCursor(0, 16);
  last[6] = toType;
  display.print(last);
  display.setCursor(0, 0);
  display.print("_______");
  display.setCursor(0, 0);
  display.display();
}

// converts the built array to an integer using bit shifts
int arrToInt(int arr[]){
  int out = 0;
  for (int i = 0; i < 7; i++){
    // Can remove '6 -' if you want to type in reverse
    if (arr[6 - i] == 1){
      out += 1 << i;
    }
  }
  return out;
}
