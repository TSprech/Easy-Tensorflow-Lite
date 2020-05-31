/*Created May 2020 by Trey Sprecher.

Licensed under the GPL, Version 3.0 (the "License");
software distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*/

#include <Arduino.h>
#include <Button_Handler.h>
#include <simple_model_data.h>

#include "tensorflow/lite/experimental/micro/kernels/all_ops_resolver.h"  // Contains all operations required to run the model
#include "tensorflow/lite/experimental/micro/micro_error_reporter.h"      // Used for outputting errors
#include "tensorflow/lite/experimental/micro/micro_interpreter.h"

// Create a memory pool for the nodes in the network
constexpr int tensor_pool_size = 2 * 1024;
uint8_t tensor_pool[tensor_pool_size];

// Define the model to be used
const tflite::Model *simple_model;

// Define the interpreter
tflite::MicroInterpreter *interpreter;

// Input and output nodes for the network
TfLiteTensor *input;
TfLiteTensor *output;

Button_Handler Buttons(0, 1, 2, 17, 18, 19);  // Construct a button handler to control buttons and LEDs

void setup() {
  Buttons.Button_Setup();  // Set all buttons as input and LEDs as outputs

  Serial.begin(9600);  // Start serial at 9600 baud
  while(!Serial);

  // Load the model
  Serial.println("Loading Tensorflow model");
  simple_model = tflite::GetModel(simple_model_data);
  Serial.println("Simple model loaded");

  // Define ops resolver and error reporting
  static tflite::ops::micro::AllOpsResolver resolver;
  static tflite::ErrorReporter *error_reporter;
  static tflite::MicroErrorReporter micro_error;
  error_reporter = &micro_error;

  // Instantiate the interpreter
  static tflite::MicroInterpreter static_interpreter(
      simple_model, resolver, tensor_pool, tensor_pool_size, error_reporter);

  interpreter = &static_interpreter;

  // Allocate the the model's tensors in the memory pool that was created.
  Serial.println("Allocating tensor memory pool");
  if (interpreter->AllocateTensors() != kTfLiteOk) {
    Serial.println("There was an error allocating memory");
    return;
  }

  // Define input and output nodes
  input = interpreter->input(0);
  output = interpreter->output(0);
  Serial.println("Press a button");

  Buttons.Button_Wipe(2);  // Cycle through LEDs to signify setup was successful when not using a serial monitor
}

void loop() {
  float user_input = 0;  // Holds the button press
  int out_num = 0;       // Holds the predicted number

  user_input = Buttons.Button_Read();  // Reads the buttons and returns a number based off which is pressed, returns 3 if none are pressed

  if (user_input != 3) {
    input->data.f[0] = user_input;  // Set the input node to the user input

    Serial.println("Running inference");

    if (interpreter->Invoke() != kTfLiteOk) {
      Serial.println("Error invoking the interpreter");
      return;
    }

    out_num = round(output->data.f[0]);  // Round the output to the closest int and store it

    Buttons.LED_Output(out_num);  // Flash corresponding LED

    // Print the output of the model
    Serial.print("Button Input: ");
    Serial.println(int(user_input));
    Serial.print("Light Output: ");
    Serial.println(out_num);
    Serial.println();
    delay(100);
  }
  delay(100);  // Prevent serial monitor from filling up as much
}