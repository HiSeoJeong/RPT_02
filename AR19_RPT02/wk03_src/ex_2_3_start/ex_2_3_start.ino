const int ledPin = 13;
int blinkNumber = 0;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()){
  char val = Serial.read();
  if(isDigit(val)){
    blinkNumber = (val-'0');
  }
  Serial.print("입력한 수:");
  Serial.println(blinkNumber);
  delay(2000);

  for(char i=0; i<blinkNumber; i++){
    digitalWrite(ledPin,HIGH);
    delay(100);
    digitalWrite(ledPin,LOW);
    delay(100);
    }
}
blinkNumber = 0;
}
