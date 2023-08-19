int inputPin = 3;
int readPin = A0;
int potVal;
float ledVal;

void setup() {
  // put your setup code here, to run once:
  pinMode(inputPin, OUTPUT);
  pinMode(readPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(readPin);
  ledVal = (255./1023.)*potVal;

  Serial.print("Pot val: ");
  Serial.print(potVal);
  Serial.print(" || ");
  Serial.print("LED val: ");
  Serial.print(ledVal);
  Serial.print("\n");

  analogWrite(inputPin, ledVal);
}
