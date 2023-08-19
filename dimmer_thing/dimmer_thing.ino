int pin1 = 3;
int pin2 = 5;
int pin3 = 6;
int pin4 = 9;
int pin5 = 10;
int pin6 = 11;
int readPin0 = A0;

int readVal;
float v2;
int brightnessVal;
int bufferTime = 100;

void updateRead() {
  brightnessVal = readVal / 4;
  if (brightnessVal > 255) {
    brightnessVal = 255;
  }
}

void changeBrightness(int pin) {
  analogWrite(pin, brightnessVal);
}

void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(readPin0, INPUT);
  Serial.begin(9600);
}

void loop() {
  readVal = analogRead(readPin0);
  v2 = (5./1023.)*readVal;
  changeBrightness(pin1);
  changeBrightness(pin2);
  changeBrightness(pin3);
  changeBrightness(pin4);
  changeBrightness(pin5);
  changeBrightness(pin6);
  
  updateRead();
  Serial.print("Brightness: ");
  Serial.print(brightnessVal);
  Serial.print(" || ");
  Serial.print("V2: ");
  Serial.print(v2);

  Serial.print("\n");
  delay(bufferTime);
}
