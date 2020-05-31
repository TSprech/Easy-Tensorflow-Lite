/*Created May 2020 by Trey Sprecher.

Licensed under the GPL, Version 3.0 (the "License");
software distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*/

#include <Arduino.h>

#ifndef BUTTON_HANDLER_H
#define BUTTON_HANDLER_H

class Button_Handler {
 public:
  Button_Handler(uint8_t _pin_0, uint8_t _pin_1, uint8_t _pin_2, uint8_t _led_0, uint8_t _led_1, uint8_t _led_2);  // Setup for pins used for buttons and LEDs
  void Button_Setup();                                                                                             // Sets pinMode for each pin
  void Button_Wipe(uint8_t _number_of_cycles);                                                                     // Cycles through light patterns to show different states
  uint8_t Button_Read();                                                                                           // Read each button pin and return if any are pressed
  void LED_Output(uint8_t _button_input);                                                                          // Light the LED corresponding to a number

 private:
  // Pins used for IO
  uint8_t _pin_0;
  uint8_t _pin_1;
  uint8_t _pin_2;
  uint8_t _led_0;
  uint8_t _led_1;
  uint8_t _led_2;
};

#endif