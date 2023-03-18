/*
Pushbutton and an LED, where the LED turns on or off every time the pushbutton is pressed.
Defines the behavior of a pushbutton and an LED connected to an Arduino board.
Defines the pin numbers for the pushbutton and LED as constants buttonPin and ledPin.
Two classes: PushButton and Led. The PushButton class defines the behavior of the pushbutton, including its pin number, last and current states, and a method to check if it has been pressed. 
The Led class defines the behavior of the LED, including its pin number and methods to turn it on or off.
Creating objects of the PushButton and Led classes using the pin numbers.
In the setup function, nothing needs to be done.
In the loop function, checks if the pushbutton has been pressed. 
If it has been pressed, the LED's state is toggled between on and off. If the LED is currently on, the off() method is called to turn it off, and vice versa.
*/

// define the pin number for the pushbutton and LED
const int buttonPin = 2; //psuhbutton is on digital pin 2
const int ledPin = 13; //built in LED on Ardu

// create a class for the pushbutton
class PushButton {
  private:
    int pin;
    bool lastState;
    bool currentState;
  public:
    PushButton(int buttonPin) {
      pin = buttonPin;
      pinMode(pin, INPUT_PULLUP);
      lastState = currentState = digitalRead(pin);
    }
    bool isPressed() {
      lastState = currentState;
      currentState = digitalRead(pin);
      return (lastState == HIGH && currentState == LOW);
    }
};

// create a class for the LED
class Led {
  private:
    int pin;
  public:
    Led(int ledPin) {
      pin = ledPin;
      pinMode(pin, OUTPUT);
    }
    void on() {
      digitalWrite(pin, HIGH);
    }
    void off() {
      digitalWrite(pin, LOW);
    }
};

// create objects for the pushbutton and LED
PushButton button(buttonPin);
Led led(ledPin);

void setup() {
  // nothing to do here
}

void loop() {
  // check if the pushbutton is pressed
  if (button.isPressed()) {
    // toggle the LED
    if (digitalRead(ledPin) == HIGH) {
      led.off();
    } else {
      led.on();
    }
  }
}
