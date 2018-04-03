#include "config.h"
AdafruitIO_Feed *coffeecups = io.feed("coffeecups");

//int buttonOnTheCup = 1;
//int button = 2;
//int tilt = 6;
int i = 0;
int x_tilt = 1;
int x_button = 1;


void setup(){
  io.connect();
  Serial.begin(9600);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(6, INPUT);
}

void loop(){
  
  io.run();
  int button_Switch = digitalRead(2);
  int buttonOnTheCup_Switch = digitalRead(1);
  int tilt_Switch = digitalRead(6);

    //user tilts the cup
    if (tilt_Switch == HIGH && x_tilt==1){
    //if the cup is tilted, then encrease the cup number
    i++;

    //show it in the Serial-print window 
    Serial.println(i);
    
    //and save the data to the Adafruit feed called "coffeecups".
    coffeecups->save(i);
z
    //, set x to something other than 1 to only record one cup at the time
    x_tilt=2;
  }
  
  else if(tilt_Switch == LOW){
    x_tilt = 1;
  }

    //if the button is switched off, it means that the user just lifted the cup.     
  if (buttonOnTheCup_Switch == LOW){
    if(x_button==1){
    Serial.println("John just lifted the cup");
    coffeecups->save("John just lifted the cup");
    x_button = 2;
  }}
  
  if(buttonOnTheCup_Switch == HIGH){
        if(x_button==2){
         x_button = 1;    
  }}

    //if the second button is pressed
if (button_Switch == HIGH){
    //then reset the value
    i=0;
    Serial.println(i);
    coffeecups->save(i);
}}




