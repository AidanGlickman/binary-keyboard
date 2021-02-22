#include <stdio.h>
#include <Keyboard.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int buttonPin0 = 4;
int buttonPin1 = 5;

int binarr [7];
int curr = 0;

char last[] = {'L', 'a', 's', 't', ':', ' ', ' '};

int arrToInt(int arr[]){
  int out = 0;
  for(int i = 0; i < 7; i++){
    if(arr[6-i] == 1){
      out += 1 << i;
    }
  }
  return out;
}

void printArr(int arr[]){
  for(int i = 0; i < 7; i++){
    if(arr[i] == 0){
      Serial.print("0");
    }
    else{
      Serial.print("1");
    }
  }
  Serial.println();
}

void setup() {
  pinMode(buttonPin0, INPUT_PULLUP);
  pinMode(buttonPin1, INPUT_PULLUP);

  Serial.begin(9600);
  Keyboard.begin();
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();
}

void loop() {
  
  if (digitalRead(buttonPin0) == 0){
    binarr[curr] = 0;
  }
  else if (digitalRead(buttonPin1) == 0){
    binarr[curr] = 1;
  }
  else {
    return;
  }
  if(curr == 0){
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
  }
  display.print(binarr[curr]);
  display.display();
  
  curr++;
  if(curr == 7){
    display.clearDisplay();
    int toType = arrToInt(binarr);
    display.setCursor(0, 16);
    last[6] = toType;!
    display.print(last);
    display.display();
    Keyboard.write(toType);
    curr = 0;
  }

  delay(250);
}
