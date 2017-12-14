// Pins 
#define BLUE 11
#define GREEN 10
#define RED 9

// vars
long color;
int redValue;
int greenValue;
int blueValue;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    delay(3);
    color = Serial.parseInt();
  }

  if (color != 0) {
    Serial.println(color);
    switch (color) {
      case 1:
        redValue = 255;
        greenValue = 0;
        blueValue = 0;
        switchLed();
        break;

      case 2:
        redValue = 0;
        greenValue = 0;
        blueValue = 255;
        switchLed();
        break;

       case 3:
        redValue = 0;
        greenValue = 255;
        blueValue = 0;
        switchLed();
        break;
    }
  }
}

void switchLed() {
  analogWrite(BLUE, blueValue);
  analogWrite(RED, redValue);
  analogWrite(GREEN, greenValue);
}

