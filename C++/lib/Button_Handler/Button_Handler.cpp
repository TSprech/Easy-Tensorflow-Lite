/*Created May 2020 by Trey Sprecher.

Licensed under the GPL, Version 3.0 (the "License");
software distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*/

#include "Button_Handler.h"

#include <Arduino.h>

Button_Handler::Button_Handler(uint8_t _pin_0, uint8_t _pin_1, uint8_t _pin_2, uint8_t _led_0, uint8_t _led_1, uint8_t _led_2) {
  this->_pin_0 = _pin_0;
  this->_pin_1 = _pin_1;
  this->_pin_2 = _pin_2;
  this->_led_0 = _led_0;
  this->_led_1 = _led_1;
  this->_led_2 = _led_2;
}

void Button_Handler::Button_Setup() {
  pinMode(_pin_0, INPUT);
  pinMode(_pin_1, INPUT);
  pinMode(_pin_2, INPUT);
  pinMode(_led_0, OUTPUT);
  pinMode(_led_1, OUTPUT);
  pinMode(_led_2, OUTPUT);
}

void Button_Handler::Button_Wipe(uint8_t _number_of_cycles) {
  for (int _i = 0; _i < _number_of_cycles; _i++) {
    digitalWrite(_led_0, HIGH);
    delay(50);
    digitalWrite(_led_0, LOW);
    digitalWrite(_led_1, HIGH);
    delay(50);
    digitalWrite(_led_1, LOW);
    digitalWrite(_led_2, HIGH);
    delay(50);
    digitalWrite(_led_2, LOW);
  }
}

uint8_t Button_Handler::Button_Read() {
  if (digitalRead(0) == true) {
    return (0);
  }

  else if (digitalRead(1) == true) {
    return (1);
  }

  else if (digitalRead(2) == true) {
    return (2);
  } else {
    return (3);
  }
}

void Button_Handler::LED_Output(uint8_t _button_input) {
  switch (_button_input) {
    case 0:
      digitalWrite(_led_0, HIGH);
      delay(100);
      digitalWrite(_led_0, LOW);
      break;
    case 1:
      digitalWrite(_led_1, HIGH);
      delay(100);
      digitalWrite(_led_1, LOW);
      break;
    case 2:
      digitalWrite(_led_2, HIGH);
      delay(100);
      digitalWrite(_led_2, LOW);
      break;

    default:
      digitalWrite(_led_0, HIGH);
      digitalWrite(_led_1, HIGH);
      digitalWrite(_led_2, HIGH);
      delay(100);
      digitalWrite(_led_0, LOW);
      digitalWrite(_led_1, LOW);
      digitalWrite(_led_2, LOW);
      break;
  }
}