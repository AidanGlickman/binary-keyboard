#include <stdio.h>
#include <Keyboard.h>

int buttonPin0 = 2;
int buttonPin1 = 3;

int binarr [7];
int curr = 0;

int arrToInt(int arr[]){
  int out = 0;
  for(int i = 0; i < 7; i++){
    if(arr[i] == 1){
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
  
}

void loop() {
  
  if (digitalRead(buttonPin0) == 0){
    Serial.println("Button 0 Pressed");
    binarr[curr] = 0;
  }
  else if (digitalRead(buttonPin1) == 0){
    Serial.println("Button 1 Pressed");
    binarr[curr] = 1;
  }
  else {
    return;
  }
  printArr(binarr);
  Serial.println(curr);

  curr++;
  if(curr == 7){
    int toType = arrToInt(binarr);
    Serial.println("Done!");
    Serial.println(toType);
    Keyboard.write(toType);
    curr = 0;
  }

  delay(250);
}
