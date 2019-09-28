const int led1Pin =  9; // pin number for LED output 
const int sensorPin = 0; // pin number for sensing potentiometer
int brightness = 0;    // variable for indicating how bright the LED is

void setup() {
  pinMode(led1Pin, OUTPUT);  // Set up the LED pin to be an output:  
  Serial.begin(9600); // initialize the serial for communication
}

void loop() {
  int sensorValue;
  sensorValue = analogRead(sensorPin); // read from the potentiometer 
  brightness = map(sensorValue, 0, 1023, 0, 255); // map the value from potentiometer (range from 0 to 1023) to the brightness (from 0 to 255)
  // control the brightenss based on the sensor value
  if (sensorValue >= 0) {
    analogWrite(led1Pin, brightness);  // turn the LED on with certain brightness
    Serial.write(brightness); 
  } else{
    digitalWrite(led1Pin, LOW);  // turn the LED off
  }
}
