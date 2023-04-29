String inString = "0";

void setup() {
  Serial.begin(9600);
}

int x;
String str;
const long interval = 1000;  // interval at which to blink (milliseconds)
unsigned long previousMillis = 0;  // will store last time LED was updated
  
void loop() {
  unsigned long currentMillis = millis();
  int inChar = Serial.read();
  if (isDigit(inChar)) {
    // convert the incoming byte to a char and add it to the string:
    inString += (char)inChar;
  }
  // if you get a newline, print the string, then the string's value:
  if (inChar == '\n') {
    x=inString.toInt();
//    Serial.println("Value:");
//    Serial.println(inString.toInt());
    // clear the string for new input:
    inString = "";
  }

  int sensorValue = analogRead(A0);
  analogWrite(5, x);
  if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      Serial.println(sensorValue/204.6);
  }  
}
