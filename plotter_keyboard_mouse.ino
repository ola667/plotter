

#include "Keyboard.h"
#include "Mouse.h"

const byte R_buttonPin = 2; // input pin for pushbutton
const byte L_buttonPin = 3;
const byte D_buttonPin = 4;
const byte U_buttonPin = 5;
const byte ZO_buttonPin = 6;
const byte ZI_buttonPin = 7;
const byte follow_buttonPin = 8;
const byte select_buttonPin = 9;


byte previous_R_ButtonState = HIGH;   // for checking the state of a pushButton
byte previous_L_ButtonState = HIGH;
byte previous_D_ButtonState = HIGH;
byte previous_U_ButtonState = HIGH;
byte previous_ZO_ButtonState = HIGH;
byte previous_ZI_ButtonState = HIGH;
byte previous_follow_ButtonState = HIGH;


void setup() {
  // make the pushButton pin an input:
  pinMode(R_buttonPin, INPUT);
  pinMode(L_buttonPin, INPUT);
  pinMode(U_buttonPin, INPUT);
  pinMode(D_buttonPin, INPUT);
  pinMode(ZO_buttonPin, INPUT);
  pinMode(ZI_buttonPin, INPUT);
  pinMode(follow_buttonPin, INPUT);
  pinMode(select_buttonPin, INPUT);
  
  // initialize control over the keyboard:
  Keyboard.begin();
  Mouse.begin();
  delay(90000);
  
  Mouse.move(0, 40);
  delay(1000);
  Mouse.move(0, 40);
  delay(1000);
  Mouse.move(0, 40);
  delay(1000);
  Mouse.move(40, 0);
  delay(1000);
  Mouse.move(40, 0);
  delay(1000);
  Mouse.move(40, 0);
  delay(1000);
  Mouse.press();
  Mouse.move(0, 40);
  Mouse.move(40, 0);
  Mouse.release();
  
  //Serial.begin(9600);
}

void loop() {
  
  
  // read the pushbuttons:
  byte R_buttonState = digitalRead(R_buttonPin);
  byte L_buttonState = digitalRead(L_buttonPin);
  byte U_buttonState = digitalRead(U_buttonPin);
  byte D_buttonState = digitalRead(D_buttonPin);
  byte ZO_buttonState = digitalRead(ZO_buttonPin);
  byte ZI_buttonState = digitalRead(ZI_buttonPin);
  byte follow_buttonState = digitalRead(follow_buttonPin);
  byte select_buttonState = digitalRead(select_buttonPin);
  
  if(select_buttonState == HIGH)
        {
          if(R_buttonState == HIGH)
                {
                  // move mouse right
                  Mouse.move(20, 0);
                  delay(100);
                }
          if(L_buttonState == HIGH)
                  {
                  // move mouse left
                  Mouse.move(-20, 0);
                  delay(100);
                  }
          if(U_buttonState == HIGH)
                {
                  // move mouse up
                  Mouse.move(0, -20);
                  delay(100);
                }
           if(D_buttonState == HIGH)
                {
                  // move mouse down
                  Mouse.move(0, 20);
                  delay(100);     
                }
           if ((follow_buttonState != previous_follow_ButtonState)
            //and prev pressed
           &&(follow_buttonState == HIGH))
       
                                  {    
                                    Mouse.click(MOUSE_LEFT);                                    
                                    delay(200);                                                                            
                                  }
     





                                  
           if ((ZI_buttonState != previous_ZI_ButtonState)
            // and it's currently pressed:
            && (ZI_buttonState == HIGH)) 
                                  {    
                                    Mouse.click(MOUSE_RIGHT);
                                    delay(200);      
                                  } 



         goto loopend;       
        }



//_____________________________________________________________________________________
        //keyboard cases:
        
  // if the button state has changed,   

    if ((follow_buttonState != previous_follow_ButtonState)
        //and prev pressed
        &&(follow_buttonState == HIGH))
       
                                  {    
                                    //type out a message
                                    //Serial.println("You pressed the F2 button ");
                                    //Keyboard.print("You pressed the F2 button ");
                                    Keyboard.write(195);
                                    delay(200);                                                                            
                                  }
    
  if ((R_buttonState != previous_R_ButtonState)
      // and it's currently pressed:
      && (R_buttonState == HIGH)) {    
                                    // type out a message
                                    //Serial.println("You pressed the Right button ");
                                    //Keyboard.print("You pressed the Right button ");  
                                    Keyboard.write(215);
                                    delay(200);   
                                  }
                                  
  if ((L_buttonState != previous_L_ButtonState)
      // and it's currently pressed:
      && (L_buttonState == HIGH)) {    
                                    // type out a message
                                    //Serial.println("You pressed the Left button ");
                                    //Keyboard.print("You pressed the Left button ");
                                    Keyboard.write(216);
                                    delay(200);      
                                  }
                                  
   if ((U_buttonState != previous_U_ButtonState)
      // and it's currently pressed:
      && (U_buttonState == HIGH)) {    
                                    // type out a message
                                    //Serial.println("You pressed the Up button ");
                                    //Keyboard.print("You pressed the Up button ");
                                    Keyboard.write(218);
                                    delay(200);      
                                  }
                                  
   if ((D_buttonState != previous_D_ButtonState)
      // and it's currently pressed:
      && (D_buttonState == HIGH)) {    
                                    // type out a message
                                    //Serial.println("You pressed the Down button ");
                                    //Keyboard.print("You pressed the Down button ");
                                    Keyboard.write(217);
                                    delay(200);      
                                  }
                                  
   if ((ZO_buttonState != previous_ZO_ButtonState)
      // and it's currently pressed:
      && (ZO_buttonState == HIGH)) {    
                                    // type out a message
                                    //Serial.println("You pressed the Zoom out button ");
                                    //Keyboard.print("You pressed the Zoom out button ");
                                    Keyboard.write(47);
                                    delay(200);      
                                  }
                                  
   if ((ZI_buttonState != previous_ZI_ButtonState)
      // and it's currently pressed:
      && (ZI_buttonState == HIGH)) {    
                                    // type out a message
                                    //Serial.println("You pressed the Zoom in button ");
                                    //Keyboard.print("You pressed the Zoom in button ");
                                    Keyboard.write(45);
                                    delay(200);      
                                  }  
 
  loopend:                                                                                            
  delay(50);
  // save the current button state for comparison next time:
  previous_R_ButtonState = R_buttonState;
  previous_L_ButtonState = L_buttonState;
  previous_U_ButtonState = U_buttonState;
  previous_D_ButtonState = D_buttonState;
  previous_ZO_ButtonState = ZO_buttonState;
  previous_ZI_ButtonState = ZI_buttonState;
  previous_follow_ButtonState = follow_buttonState;
 
}
