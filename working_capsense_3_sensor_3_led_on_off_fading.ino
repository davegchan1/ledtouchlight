// video and site are not in english. code was copied from a translated site. 

// you tube https://www.youtube.com/watch?v=IGZt8YidUsE
// code pulled from : http://crepusculotecnologico.blogspot.com.br/2012/04/interruptor-touch-diagrama-e-codigo.html

// working sensor, working on and off fade.  ( single color )
// all 3 sensors fade on and off. moved closing curly bracket to close first cap 10 statement,
/* 
 *  youtube pushbutton and fading led with arduino
 *  https://www.youtube.com/watch?v=8ua3U3xwqJA&t=4s
project name fading led
description. a demonsration using arduino inpu ( external pushbtton
on pin 2)
to control an output ( led on pin 9)

*/


#include <CapacitiveSensor.h>



 const int led1 = 3; // red led  indicator
 const int led2 = 11; // green
 const int led3 = 9; // blue



const int cap1 = 12;
const int cap2 = 2; // cap sensor input pin  

const int cap3 = 5; //red white sensor wires
const int cap4 = 6;

const int cap5 = 7; //green white sensor wires
const int cap6 = 8;

const int sensibil1 = 600;  // varies depending on the resistor and size of the capacitive surface, change to test. 
const int sensibil2 = 600;  // varies depending on the resistor and size of the capacitive surface, change to test.
const int sensibil3 = 600;  // varies depending on the resistor and size of the capacitive surface, change to test.



CapacitiveSensor cs1 = CapacitiveSensor(cap1,cap2);     
CapacitiveSensor cs2 = CapacitiveSensor(cap3,cap4);
CapacitiveSensor cs3 = CapacitiveSensor(cap5,cap6);


bool on1 = 0;
bool on2 = 0;
bool on3 = 0;



void setup()                    
{
  cs1.set_CS_AutocaL_Millis( 0xFFFFFFFF);   
  cs2.set_CS_AutocaL_Millis( 0xFFFFFFFF); 
  cs3.set_CS_AutocaL_Millis( 0xFFFFFFFF); 
 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);


}


void loop()  
  
{
  long cap10 =  cs1.capacitiveSensor(30);  // call function that gives you capacitance ... 
  if (cap10 > sensibil1 ) //... if it is greater than stipulated, turns on or off the light,
  {if (on1)
    {on1 = !on1;
      
     for (int i = 255; i >=0; i -= 5){
     // loop is to gradually dim the led. During this period (2sec) the caption is not called, 
      // which ensures that the lamp will not blink and erase again. The same goes for the other for. 
      {analogWrite(led1, i);
        delay(5); // delay speed increment higher number for slower 
      }
    } 
    }  
    else
     {on1 = !on1;
      for (int i = 0; i <= 255; i += 5){
   
      {
        analogWrite(led1, i);
        delay(5);
      }
    }
   }
  }  
  
   long cap20 =  cs2.capacitiveSensor(30);  // call function that gives you capacitance ... 
 

  if (cap20 > sensibil2 ) //... if it is greater than stipulated, turns on or off the light,
  
    if (on2)
    {
      on2 = !on2;
    
    
     for (int i2 = 255; i2 >=0; i2 -= 5){
     // loop is to gradually dim the led. During this period (2sec) the caption is not called, 
      // which ensures that the lamp will not blink and erase again. The same goes for the other for. 
      {
        analogWrite(led2, i2);
        delay(5); // delay speed increment higher number for slower 
      }
    } 
    }  
    else
    
     {
    
      on2 = !on2;
    
    
      for (int i2 = 0; i2 <= 255; i2 += 5){
   
      {
        analogWrite(led2, i2);
        delay(5);
      }
    }
   }  


          long cap30 =  cs3.capacitiveSensor(30);  // call function that gives you capacitance ... 
 

  if (cap30 > sensibil3 ) //... if it is greater than stipulated, turns on or off the light,
  {
    if (on3)
    {
      on3 = !on3;
    
    
     for (int i3 = 255; i3 >=0; i3 -= 5){
     // loop is to gradually dim the led. During this period (2sec) the caption is not called, 
      // which ensures that the lamp will not blink and erase again. The same goes for the other for. 
      {
        analogWrite(led3, i3);
        delay(5); // delay speed increment higher number for slower 
      }
    } 
    }  
    else
    
     {
    
      on3 = !on3;
    
    
      for (int i3 = 0; i3 <= 255; i3 += 5){
   
      {
        analogWrite(led3, i3);
        delay(5);
      }
  } 
  }
  }
}


  



 
      
 


