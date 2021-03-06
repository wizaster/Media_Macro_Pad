#include <HID-Project.h>
#include <HID-Settings.h>

//Media buttons
  const int playButtonCtrlA = 10;
  const int nextButtonCtrlV = 11;
  const int prevButtonCtrlC = 12;
  const int switchButtonSnip = 13;
//Volume buttons
  const int volDownAltTab = 7;
  const int volUpCtrlTab = 9;
  const int clickBtnEncoder = 5;
//Profile led
  const int mmpLed = 3;
  const int eoaLed = 2;
  int mmpLedStatus = digitalRead(mmpLed);
  int eoaLedStatus = digitalRead(eoaLed);
void setup() {
  // put your setup code here, to run once:
    pinMode(playButtonCtrlA, INPUT_PULLUP);
    pinMode(clickBtnEncoder, INPUT_PULLUP);
    pinMode(nextButtonCtrlV, INPUT_PULLUP);
    pinMode(prevButtonCtrlC, INPUT_PULLUP);
    pinMode(switchButtonSnip, INPUT_PULLUP);    
    pinMode(mmpLed, OUTPUT);
    pinMode(eoaLed, OUTPUT);
 //Volume setup
    pinMode(volDownAltTab, INPUT_PULLUP);
    digitalWrite(volDownAltTab, HIGH);
    pinMode(volUpCtrlTab, INPUT_PULLUP);
    digitalWrite(volUpCtrlTab, HIGH);
    pinMode(clickBtnEncoder, INPUT_PULLUP);
    digitalWrite(clickBtnEncoder, HIGH);
    

    // Sends a clean report to the host. This is important on any Arduino type.
    Consumer.begin();
    Serial.begin(9600);  
    digitalWrite(mmpLed, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  //Volume, TODO check if inverted
  if(!digitalRead(clickBtnEncoder))
    {
      if(digitalRead(mmpLed == HIGH)){
        digitalWrite(mmpLed, LOW);
        digitalWrite(eoaLed, HIGH);
      }
      else{
        digitalWrite(eoaLed, LOW);
        digitalWrite(mmpLed, HIGH);
      }
    }
  if(!digitalRead(mmpLed == HIGH)){
      if (digitalRead(volDownAltTab) == 0)
      {
          Consumer.write(MEDIA_VOLUME_DOWN);
          delay(25);
      }
      if (digitalRead(volUpCtrlTab) == 0)
      {
          Consumer.write(MEDIA_VOLUME_UP);
          delay(25);
      }
        if (!digitalRead(playButtonCtrlA))
        {
            Consumer.write(MEDIA_PLAY_PAUSE);
            delay(300);
        }
        if (!digitalRead(nextButtonCtrlV))
        {
             Consumer.write(MEDIA_NEXT);
            delay(300);
        }
        if (!digitalRead(prevButtonCtrlC))
        {
            Consumer.write(MEDIA_PREVIOUS);
            delay(300);
        }
        if (!digitalRead(switchButtonSnip))
        {
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.write('a');
            Keyboard.release(KEY_LEFT_ALT);
            delay(300);
        } 
  }
  else{//while maybe?
      if (digitalRead(volDownAltTab) == 0)
      {
          Keyboard.press(KEY_LEFT_ALT );
          Keyboard.press(KEY_TAB);
          Keyboard.releaseAll();
          delay(25);
      }
      if (digitalRead(volUpCtrlTab) == 0)
      {
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press(KEY_TAB);
          Keyboard.releaseAll();
          delay(25);
      }
        if (!digitalRead(playButtonCtrlA))
        {
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.write('a');
            Keyboard.releaseAll();
            delay(300);
        }
        if (!digitalRead(nextButtonCtrlV))
        {
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.write('v');
            Keyboard.releaseAll();
            delay(300);
        }
        if (!digitalRead(prevButtonCtrlC))
        {
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.write('c');
            Keyboard.releaseAll();
            delay(300);
        }
        if (!digitalRead(switchButtonSnip))
        {
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.write('/');
            Keyboard.releaseAll();
            delay(300);
        }
  }
}