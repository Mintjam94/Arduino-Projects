// pins 1-6 require PWM
int pin1 = 3;
int pin2 = 5;
int pin3 = 6;
int pin4 = 9;
int pin5 = 10;
int pin6 = 11;
int readPin0 = A0; 

int readVal;
float v2;
int bufferTime = 83;
int brightnessVal = 0;
int brightnessInterval = 35;

float getBrightness () {
  return (255./1023.)*readVal;
}

void monitorLog() {
  v2 = (5./1023.)*readVal;
  Serial.print("Potentiometer Value: ");
  Serial.print(readVal);
  Serial.print(" || ");
  Serial.print("Potentiometer Voltage: ");
  Serial.print(v2);
  Serial.print("V");
  Serial.print(" || ");
  Serial.print("Current Brightness Value: ");
  Serial.print(brightnessVal);
  Serial.print(" || ");
  Serial.print("Max Brightness Value: ");
  Serial.print(getBrightness());

  Serial.print("\n");
}

void changeBrightness(int pin) {
  analogWrite(pin, brightnessVal);
  delay(bufferTime);
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

  while (brightnessVal < getBrightness()) {
    monitorLog();
    changeBrightness(pin1);
    changeBrightness(pin2);
    changeBrightness(pin3);
    changeBrightness(pin4);
    changeBrightness(pin5);
    changeBrightness(pin6);
    brightnessVal += brightnessInterval;
    readVal = analogRead(readPin0);
    if (brightnessVal > 255) {
      brightnessVal = 255;
    }
  }

  while (brightnessVal > 0) {
    monitorLog();
    changeBrightness(pin1);
    changeBrightness(pin2);
    changeBrightness(pin3);
    changeBrightness(pin4);
    changeBrightness(pin5);
    changeBrightness(pin6);
    brightnessVal -= brightnessInterval;
    readVal = analogRead(readPin0);
    if (brightnessVal < 0 || readVal < brightnessVal) {
      brightnessVal = 0;
    }
  }
}