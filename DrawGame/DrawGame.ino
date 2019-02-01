#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>
#include <SPI.h>
boolean shot = false; 
String firstShot;
unsigned long timer = 0;
int INTERVAL = 100; 

void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
}

void reset(){ 
  
  shot = false; 
  firstShot = "";
}
void setAllWhite(){ 
  for (int i = 0; i <= 9; i++){ 
  CircuitPlayground.setPixelColor(i,255,255,255);
  }
} 
void setHalfBlue(){ 
   CircuitPlayground.setPixelColor(0,0,0,250);
   CircuitPlayground.setPixelColor(1,0,0,250);
   CircuitPlayground.setPixelColor(2,0,0,250);
   CircuitPlayground.setPixelColor(3,0,0,250);
   CircuitPlayground.setPixelColor(4,0,0,250);
}
void setHalfRed(){ 
  CircuitPlayground.setPixelColor(5,250,0,0);
  CircuitPlayground.setPixelColor(6,250,0,0);
  CircuitPlayground.setPixelColor(7,250,0,0);
  CircuitPlayground.setPixelColor(8,250,0,0);
  CircuitPlayground.setPixelColor(9,250,0,0);
}
void anim(){ 
  CircuitPlayground.clearPixels();
  setAllWhite(); 
  CircuitPlayground.playTone(90,200);
  delay(50); 
  CircuitPlayground.clearPixels();
  //CircuitPlayground.playTone(150,50);
  delay(50); 
  setAllWhite(); 
  //CircuitPlayground.playTone(150,50);
  delay(50); 
  CircuitPlayground.clearPixels();
  //CircuitPlayground.playTone(150,50);
  delay(50);
  setAllWhite(); 
  //CircuitPlayground.playTone(150,50);
  delay(50);
  CircuitPlayground.clearPixels(); 
  delay(700);

  
}

void loop() {
    
    while(CircuitPlayground.leftButton() == false && CircuitPlayground.rightButton() == false){
    
     delay(480*2); 
    CircuitPlayground.clearPixels();
   
    CircuitPlayground.setPixelColor(1,250,35,0);  
    CircuitPlayground.setPixelColor(3,250,35,0); 
    CircuitPlayground.setPixelColor(5,250,35,0); 
    CircuitPlayground.setPixelColor(7,250,35,0); 
    CircuitPlayground.setPixelColor(9,250,35,0); 
    
    CircuitPlayground.setPixelColor(0,250,35,0);
    CircuitPlayground.setPixelColor(2,250,35,0); 
    CircuitPlayground.setPixelColor(4,250,35,0); 
    CircuitPlayground.setPixelColor(6,250,35,0); 
    CircuitPlayground.setPixelColor(8,250,35,0); 
    CircuitPlayground.playTone(440,100); 
   
    delay(480*2); 
    CircuitPlayground.clearPixels();               
    CircuitPlayground.setPixelColor(1,250,35,0);  
    CircuitPlayground.setPixelColor(3,250,35,0); 
    CircuitPlayground.setPixelColor(7,250,35,0); 
    CircuitPlayground.setPixelColor(2,250,35,0); 
    CircuitPlayground.setPixelColor(6,250,35,0); 
    CircuitPlayground.setPixelColor(8,250,35,0); 
    CircuitPlayground.playTone(440,100);  
    
     
    delay(480*2); 
    
    CircuitPlayground.clearPixels();                 
    CircuitPlayground.setPixelColor(2,250,35,0);
    CircuitPlayground.setPixelColor(7,250,35,0); 
     CircuitPlayground.playTone(440,100);         //play tone
   if (CircuitPlayground.leftButton() == false && CircuitPlayground.rightButton() == false){ 
     delay(random(480*2,480*8)); 
   
    CircuitPlayground.clearPixels(); 
    CircuitPlayground.playTone(700,250);
   }
   //play tone
    while(shot == false){ 
      //if (CircuitPlayground.leftButton()==true  && CircuitPlayground.rightButton()==true)
      
      if (CircuitPlayground.leftButton() == true){ 
         anim();
        shot = true;
        firstShot = "left";
        break;
      } 
      else if (CircuitPlayground.rightButton()==true){ 
        anim();
        shot = true; 
        firstShot = "right";
        break;
      
      
    }
    
    
    } 
    if (firstShot.equals("left")){ 
      setHalfBlue();
      delay(480);
      CircuitPlayground.clearPixels();
      delay(480); 
      setHalfBlue(); 
      delay(480); 
      CircuitPlayground.clearPixels();
      delay(480); 
      setHalfBlue(); 
      delay(480);
      reset();
      
    }
    else if (firstShot.equals("right")){ 
      setHalfRed(); 
      delay(480);
      CircuitPlayground.clearPixels();
      delay(480); 
      setHalfRed(); 
      delay(480); 
      CircuitPlayground.clearPixels();
      delay(480); 
      setHalfRed(); 
      delay(480);
      reset();
    }
    
    }
    if(CircuitPlayground.leftButton() == true){ 
       Serial.println("too fast");
      setHalfRed(); 
      delay(480);
      CircuitPlayground.clearPixels();
      delay(480); 
      setHalfRed(); 
      delay(480); 
      CircuitPlayground.clearPixels();
      delay(480); 
      setHalfRed(); 
      delay(480);
      reset();
    } 
    else if (CircuitPlayground.rightButton() == true){ 
       Serial.println("too fast");
      setHalfBlue();
      delay(480);
      CircuitPlayground.clearPixels();
      delay(480); 
      setHalfBlue(); 
      delay(480); 
      CircuitPlayground.clearPixels();
      delay(480); 
      setHalfBlue(); 
      delay(480);
      reset();
    }

    

}
