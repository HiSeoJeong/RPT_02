int blinkNumber =0;
String stringValue[]={"Binary","Octal"};

void setup(){
  Serial.begin(9600);
  }
void loop() {
  if(Serial.available()){
  char val = Serial.read();
  if(isDigit(val)){
    blinkNumber = (val-'0');
  if(blinkNumber<8){
  Serial.print("입력한 수:");
  Serial.println(blinkNumber);
  Serial.print("Number =");
  Serial.print(blinkNumber);
  Serial.print(",");
  Serial.print(stringValue[0]);
  Serial.print(blinkNumber,BIN);
  Serial.print(",");
  Serial.print(stringValue[1]);
  Serial.println(blinkNumber,OCT);
  delay(1000);
  }
  }
  }
}
 
