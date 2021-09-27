/*  Getting_BPM_to_Monitor prints the BPM to the Serial Monitor, using the least lines of code and PulseSensor Library.
 *  Tutorial Webpage: https://pulsesensor.com/pages/getting-advanced
 *
--------Use This Sketch To------------------------------------------
1) Displays user's live and changing BPM, Beats Per Minute, in Arduino's native Serial Monitor.
2) Print: "♥  A HeartBeat Happened !" when a beat is detected, live.
2) Learn about using a PulseSensor Library "Object".
4) Blinks LED on PIN 13 with user's Heartbeat.
--------------------------------------------------------------------*/

#define pot 1
#define pwm1 5
#define pwm2 3
#define pot2 2

#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library.   

//  Variables
const int PulseWire = 0;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
const int LED13 = 13;          // The on-board Arduino LED, close to PIN 13.
int Threshold = 350;           // Determine which Signal to "count as a beat" and which to ignore.
                               // Use the "Gettting Started Project" to fine-tune Threshold Value beyond default setting.
                               // Otherwise leave the default "550" value. 
                               
PulseSensorPlayground pulseSensor;  // Creates an instance of the PulseSensorPlayground object called "pulseSensor"



boolean motor_dir=1;
int motor_speed;



void setup() {   

  Serial.begin(9600);          // For Serial Monitor

  pinMode (pwm1, OUTPUT);
  pinMode (pwm2, OUTPUT);

  // Configure the PulseSensor object, by assigning our variables to it. 
  pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(LED13);       //auto-magically blink Arduino's LED with heartbeat.
  pulseSensor.setThreshold(Threshold);   

  // Double-check the "pulseSensor" object was created and "began" seeing a signal. 
   if (pulseSensor.begin()) {
//    Serial.println("We created a pulseSensor Object !");  //This prints one time at Arduino power-up,  or on Arduino reset.  
  }

  
}


void loop() {

 int myBPM = pulseSensor.getBeatsPerMinute();  // Calls function on our pulseSensor object that returns BPM as an "int".
                                               // "myBPM" hold this BPM value now. 

  if (pulseSensor.sawStartOfBeat()) {            // Constantly test to see if "a beat happened". 
// Serial.println("♥  A HeartBeat Happened ! "); // If test is "true", print a message "a heartbeat happened".
   
  }


  int a = analogRead(pot);
   motor_speed = a/4;
  if(motor_dir){
//    Serial.println("IF");
//    Serial.println(motor_speed);
    analogWrite(pwm1, motor_speed);
  }
//  else{
//    analogWrite(pwm2, motor_speed);
//    }

  long b = analogRead(pot2);
  int battery_level = b*100/1023;

//  Serial.print("BPM: ");                        // Print phrase "BPM: " 
   Serial.println(myBPM);                        // Print the value inside of myBPM. 
  
//  Serial.print(a);
//  Serial.print("   ");
  Serial.println(a/25);
//  Serial.print("   ");
//  Serial.print(motor_speed);
//  Serial.print("   ");


//  Serial.print(b);
//  Serial.print("   ");
  Serial.println(battery_level);
//  Serial.println("%");
Serial.println();
  
  delay(500);                    // considered best practice in a simple sketch.

}
