  const int joystickXpin = A0;
  const int joystickYpin = A1;

  const int pwmLeftPin = 9;
  const int pwmRightPin=10;

  const int zAxisPin = 11; //
void setup() {
  pinMode(joystickXpin, INPUT);
  pinMode(joystickYpin, INPUT);

  pinMode(pwmLeftPin,OUTPUT);
  pinMode(pwmRightPin,OUTPUT);

  pinMode(zAxisPin,INPUT);
}
void Fire(){
  //code to authorize firing when zAxis is pressed goes here
}
void loop() {
  // put your main code here, to run repeatedly:
  int joystickXvalue = analogRead(joystickXpin);
  int joystickYvalue = analogRead(joystickYvalue);

  int pwmXValueMapped = map(joystickXvalue,0,1023,0,255);
  int pwmYValueMapped = map(joystickYvalue,0,1023,0,255);

  int RightOutputMotor = pwmYValueMapped + pwmXValueMapped;
  int LeftOutputMotor = pwmYValueMapped - pwmXValueMapped;

  analogWrite(pwmLeftPin,LeftOutputMotor);
  analogWrite(pwmRightPin,RightOutputMotor);

  if(digitalRead(zAxisPin)){
    Fire();
  }
  delay(10);
}
