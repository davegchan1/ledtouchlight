
#include <CapacitiveSensor.h>


long time = 0;
int state1 = LOW; // flipping to low tp see if it will disable led turn on boot seq
boolean yes1;
boolean previous1 = false;
int debounce1 = 200;

#define REDPIN 3
#define GREENPIN 11
#define BLUEPIN 9

int state2 = LOW;
boolean yes2;
boolean previous2 = false;
int debounce2 = 200;

int state3 = LOW;
boolean yes3;
boolean previous3 = false;
int debounce3 = 200;

CapacitiveSensor   cs_2_12 = CapacitiveSensor(2, 12);  // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired// To add more sensors...//CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,6);        // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil//CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foilvoidsetup()
CapacitiveSensor   cs_5_6 = CapacitiveSensor(5, 6);       //red  2M resistor between pins 5 & 6, pin 5 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_7_8 = CapacitiveSensor(7, 8);       // green 3.3M resistor between pins 7 & 8, pin 7 is sensor pin, add a wire and or foil if desired

void setup()
{
  cs_2_12.set_CS_AutocaL_Millis(0xFFFFFFFF);  //Calibrate the sensor...
  cs_5_6.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 2 - just as an example
  cs_7_8.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 3 - just as an example

  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  Serial.begin(9600); 
}

void loop()
{

  long start = millis(); // dc added
  long total1 =  cs_2_12.capacitiveSensor(30);
  long sensorValue1 =  cs_2_12.capacitiveSensor(30); 
  long total2 =  cs_5_6.capacitiveSensor(30);
  long sensorValue2 =  cs_5_6.capacitiveSensor(30);
  long total3 =  cs_7_8.capacitiveSensor(30);
  long sensorValue3 =  cs_7_8.capacitiveSensor(30);

  Serial.print(sensorValue1);  // tab character for debug windown spacing  
  Serial.print(sensorValue2);                    // tab character for debug windown spacing
  Serial.print(sensorValue3);                    // tab character for debug windown spacing

  Serial.print(millis() - start);        // check on performance in milliseconds dc added


  Serial.print(total1);                  // print sensor output 1
  Serial.print("\t");
  Serial.print(total2);                  // print sensor output 2
  Serial.print("\t");
  Serial.print(total3);                  // print sensor output 3
  Serial.println("\t");

  if (total1 > 600) {yes1 = true;}
  else {yes1 = false; // to toggle the state of state
  }
  if (yes1 == true && previous1  == false && (millis() - time > debounce1 || millis() < time)) {

  if (state1 == HIGH) {state1 = LOW;}
  else
  state1 = HIGH;
    time = millis();
  }
  digitalWrite(GREENPIN, state1);
  previous1 = yes1;
  

  if (total2 > 600) {yes2 = true;}
  else {yes2 = false; // to toggle the state of state
  }
  if (yes2 == true && previous2  == false && (millis() - time > debounce2 || millis() < time)) {

    if (state2 == HIGH) {state2 = LOW;}
    else
      state2 = HIGH;
    time = millis();
  }

  digitalWrite(REDPIN, state2);
  previous2 = yes2;
  
  {
    if (total3 > 600) {yes3 = true;
    }
    else {yes3 = false; // to toggle the state of state
    }
    if (yes3 == true && previous3  == false && (millis() - time > debounce3 || millis() < time)) {

      if (state3 == HIGH) {state3 = LOW;}
      else
        state3 = HIGH;
      time = millis();
    }

    digitalWrite(BLUEPIN, state3);
    previous3 = yes3;
    {
      Serial.println(millis() - time);
      delay(10);


    }
  }
}





