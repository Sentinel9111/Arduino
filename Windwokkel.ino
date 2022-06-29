const int trigPin = 2;  
const int echoPin = 4;  
const int led = 13;     
const int motor =  3;
long duration;          // variabele voor de tijdslengte
 
/*
  Het programmablok void setup wordt eenmaal beschreven
*/
void setup() {
  pinMode(motor, OUTPUT); //motorpin is output
  pinMode (led, OUTPUT);    // LED is output
  pinMode(trigPin, OUTPUT); // TRIG is output
  pinMode(echoPin, INPUT);  // ECHO is input
  Serial.begin(9600);       // start seriele monitor
}
 
/*
  Het programmablok void loop herhaalt zich keer op keer
*/
void loop() {
  digitalWrite(trigPin, LOW);         // LOW op TRIG geeft geen ultrasoon signaal
  delayMicroseconds(2);               // wacht 2 mircoseconden
  digitalWrite(trigPin, HIGH);        // begin het ultrasoon signaal
  delayMicroseconds(10);              // wacht 10 microseconden
  digitalWrite(trigPin, LOW);         // stop het ultrasoon signaal
  duration = pulseIn(echoPin, HIGH);  // lees het signaal wat terugkomt in vertraging
  
  /*
    op de echoPin, de tijd die tussen uitzenden en ontvangen zit is
    maatgevend voor de afstand, de tijd is in microseconden
  */
  
  Serial.print(duration);       // geef de echo-tijd weer in de seriele monitor
  Serial.println();             // print een regel verder
  delay(100);                   // wacht 100 miliseconden
 
  if (duration < 1000) {        // als de echotijd kleiner is dan 100 dan...
    digitalWrite (led, HIGH);   // zet de led aan
    digitalWrite(motor, HIGH);      //indien ingedrukt: motor aan
  }else {                       // anders..
    digitalWrite (led, LOW);    // zet de led uit..
    digitalWrite (motor, LOW);
  }
}
