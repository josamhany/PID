const int motorPin = 9;          
const int speedSensorPin = A0;   
PIDController pid(2.0, 5.0, 1.0); 

void setup() {
    pinMode(motorPin, OUTPUT);
    pid.setSetpoint(100); 

void loop() {
    
    double rawInput = analogRead(speedSensorPin);
    
   
    double smoothedInput = exponentialSmoothing(rawInput);
    
    
    double output = pid.compute(smoothedInput);
    
    
    analogWrite(motorPin, output);
}