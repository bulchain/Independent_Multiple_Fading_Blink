
//multiple fading blink LED 
//can use with Ardino 
//Use with Attiny85 only 2 PWM available so can use with only 2 LED
//Multiple blink without delay. 4 Leds with independent random blink time, sleep time, slow or fast, 
//step of fading. All 4 LEDs run in parallel. Use millis() function as scheduler.

//Following pin assignment is for Aduino Nano compiled with ATmega168

#define greenLED 3
#define redLED 5
#define yellowLED 9
#define blueLED 11 

//you can add more LED as long as the amount of PWM pin support
//define fade parameters
//play around all these number to see the effect
#define fadetime_min 50 //interval per cycle in millisec
#define fadetime_max 300 //the higher value increase flashing frequency
#define fadevalue_min 10 //step per cycle of 255
#define fadevalue_max 200 //
#define sleeptime_min 500 //LED sleep after completely off
#define sleeptime_max 3000

//Variable to control green
bool greenUpDown = true;
int green_fadeTiming = 10; //fade time interval value
int green_fadeValue = 1; //fade Value per cycle
int green_lastFade = 5;
unsigned long green_sleeptime = 0;
unsigned long green_lastTime = millis();

//Variable to control red
bool redUpDown = true;
int red_fadeTiming = 10; //fade time interval value
int red_fadeValue = 1; //fade Value per cycle
int red_lastFade = 5;
unsigned long red_sleeptime = 0;
unsigned long red_lastTime = millis();



//Variable to control yellow
bool yellowUpDown = true;
int yellow_fadeTiming = 10; //fade time interval value
int yellow_fadeValue = 1; //fade Value per cycle
int yellow_lastFade = 5;
unsigned long yellow_sleeptime = 0;
unsigned long yellow_lastTime = millis();

//Variable to control blue
bool blueUpDown = true;
int blue_fadeTiming = 10; //fade time interval value
int blue_fadeValue = 1; //fade Value per cycle
int blue_lastFade = 5;
unsigned long blue_sleeptime = 0;
unsigned long blue_lastTime = millis();

void setup()  { 
  pinMode(greenLED,OUTPUT);      
  pinMode(redLED,OUTPUT);
  pinMode(yellowLED,OUTPUT);
  pinMode(blueLED,OUTPUT);
  Serial.begin(115200);
  delay(100);// Ensure "now" variable > 0 when start the blink function
}
void loop(){
 blink_yellow(); 
 blink_green();
 blink_red(); 
 blink_blue();
}

void blink_green(){
unsigned long now = millis(); 
  if (now < green_sleeptime) {
  return;
  }
  // Set up random global variable for green
  if (green_lastFade <= 0){
    green_fadeTiming = random(fadetime_min, fadetime_max);
    green_fadeValue = random(fadevalue_min, fadevalue_max);
    greenUpDown = true;
    green_lastFade = 1; //not set to 0 to prevent comeagain next cycle
    green_sleeptime = random(sleeptime_min, sleeptime_max);
    Serial.print("green sleep ");
    Serial.println(green_sleeptime);
    green_sleeptime += now;
    return;
  }

  //start fading green up
  if ((now - green_lastTime) >= green_fadeTiming) {
    if (greenUpDown == true){
      green_lastFade += green_fadeValue;
        if (green_lastFade > 255){
           green_lastFade = 255;
           greenUpDown = false;
        }            
    }
    else {
        green_lastFade -= green_fadeValue;  
        if (green_lastFade < 0){
          green_lastFade = 0;
        }      
    }
  
//    Serial.print("Green_lastfade: ");
//    Serial.println(green_lastFade);    
    analogWrite(greenLED, green_lastFade);
    green_lastTime = millis();
  }
}

void blink_red(){
unsigned long now = millis(); 
  if (now < red_sleeptime) {
  return;
  }
  // Set up random global variable for red
  if (red_lastFade <= 0){
    red_fadeTiming = random(fadetime_min, fadetime_max);
    red_fadeValue = random(fadevalue_min, fadevalue_max);
    redUpDown = true;
    red_lastFade = 1; //not set to 0 to prevent comeagain next cycle
    red_sleeptime = random(sleeptime_min, sleeptime_max);
    Serial.print("red sleep ");
    Serial.println(red_sleeptime);
    red_sleeptime += now;
    return;

  }

  //start fading red up
  if ((now - red_lastTime) >= red_fadeTiming) {
    if (redUpDown == true){
      red_lastFade += red_fadeValue;
        if (red_lastFade > 255){
           red_lastFade = 255;
           redUpDown = false;         
      }
    }
    else {
        red_lastFade -= red_fadeValue;  
        if (red_lastFade < 0){
          red_lastFade = 0;
        }      
    }
  
//    Serial.print("red_lastfade: ");
//    Serial.println(red_lastFade);    
    analogWrite(redLED, red_lastFade);
    red_lastTime = millis();
 }
}

void blink_yellow(){
unsigned long now = millis(); 
  if (now < yellow_sleeptime) {
  return;
  }
  // Set up random global variable for yellow
  if (yellow_lastFade <= 0){
    yellow_fadeTiming = random(fadetime_min, fadetime_max);
    yellow_fadeValue = random(fadevalue_min, fadevalue_max);
    yellowUpDown = true;
    yellow_lastFade = 1; //not set to 0 to prevent comeagain next cycle
    yellow_sleeptime = random(sleeptime_min, sleeptime_max);
    Serial.print("yellow sleep ");
    Serial.println(yellow_sleeptime);
    yellow_sleeptime += now;
    return;
  }

  //start fading yellow up
  if ((now - yellow_lastTime) >= yellow_fadeTiming) {
    if (yellowUpDown == true){
      yellow_lastFade += yellow_fadeValue;
        if (yellow_lastFade > 255){
           yellow_lastFade = 255;
           yellowUpDown = false;
        }            
    }
    else {
        yellow_lastFade -= yellow_fadeValue;  
        if (yellow_lastFade < 0){
          yellow_lastFade = 0;
        }      
    }
  
//    Serial.print("yellow_lastfade: ");
//    Serial.println(yellow_lastFade);    
    analogWrite(yellowLED, yellow_lastFade);
    yellow_lastTime = millis();
  }
}

void blink_blue(){
unsigned long now = millis(); 
  if (now < blue_sleeptime) {
  return;
  }
  // Set up random global variable for blue
  if (blue_lastFade <= 0){
    blue_fadeTiming = random(fadetime_min, fadetime_max);
    blue_fadeValue = random(fadevalue_min, fadevalue_max);
    blueUpDown = true;
    blue_lastFade = 1; //not set to 0 to prevent comeagain next cycle
    blue_sleeptime = random(sleeptime_min, sleeptime_max);
    Serial.print("blue sleep ");
    Serial.println(blue_sleeptime);
    blue_sleeptime += now;
    return;
  }

  //start fading yellow up
  if ((now - blue_lastTime) >= blue_fadeTiming) {
    if (blueUpDown == true){
      blue_lastFade += blue_fadeValue;
        if (blue_lastFade > 255){
           blue_lastFade = 255;
           blueUpDown = false;
        }            
    }
    else {
        blue_lastFade -= blue_fadeValue;  
        if (blue_lastFade < 0){
          blue_lastFade = 0;
        }      
    }
  
//    Serial.print("blue_lastfade: ");
//    Serial.println(blue_lastFade);    
    analogWrite(blueLED, blue_lastFade);
    blue_lastTime = millis();
  }
}
