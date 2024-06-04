#include <LiquidCrystal.h>
//Creating an object.Parameters(rs, enable ,DB4 ,DB5 ,DB6 ,DB7)
LiquidCrystal lcdx(11,8,7,6,5,4);

#include <Servo.h>
Servo servox;           //Giving a name to motor.

#define servo_pin 9 
#define pir 12


void setup()
{
  pinMode(pir, INPUT);  //taking input from pir sensor
  servox.attach(servo_pin);
  servox.write(0);      //initialising angle of servo motor
  lcdx.begin(16, 2);
  lcdx.setCursor(0,1);   //setting position
  lcdx.print("System activated");  //prints a message
}

void loop()
{
  int p_input=digitalRead(pir);
   
  if(p_input==HIGH)    //putting condition to open door
  {
    servox.write(95);  //opening door
    lcdx.clear();
    lcdx.setCursor(3,0);
    lcdx.print("DOOR__OPEN");
    delay(500);
    
    servox.write(0);   //closing door
    lcdx.clear();
    lcdx.print("!!DOOR__CLOSED!!");
  }
   
}
