# Easy Tensorflow Lite
A much simpler approach to the basics of implementing machine learning on microcontrollers, specifically Arduino. This strips away most of the extra information when training and running a model in a microcontroller environment. It is also meant to simplify machine learning down to a basic example, number mapping.

- [Easy Tensorflow Lite](#easy-tensorflow-lite)
  - [Circuit](#circuit)
  - [Usage](#usage)
    - [Programming Knowledge](#programming-knowledge)
      - [Python](#python)
      - [C++](#c)
    - [PlatformIO Setup](#platformio-setup)
  - [Credits](#credits)
    - [Library](#library)
  - [Additional Resources](#additional-resources)
  - [License](#license)

## Circuit
![Fritzing diagram for wiring up 3 push buttons and 3 LEDs to the SparkFun Artemis](Graphics/EasyTFBreadboard.png)

This circuit is one of the simplest examples of machine learning. It takes in a button input and outputs to a corresponding LED. This model is designed such that 0 corresponds to 1, 1 to 2, and 2 to 0. While this could be accomplished by much simpler methods, it is intended to be an easier start into training, exporting, and loading a custom Tensorflow model.

*This is not intended to be a full delve into Tensorflow Lite or Micro. This is meant to be a simple, straightforward example of Tensorflow with no extras*

## Usage
### Programming Knowledge
While full understanding is not required, it is **highly** recommended to have some knowledge on these topics
#### Python
- Library knowledge
  - Tensorflow
    - Setting up and training a Keras model
    - Utilizing the docs - What is shown here does not scratch the surface of Tensorflow's capabilities, the docs have almost all the info you could need 
  - Pandas
    - Data manipulation
  - Numpy
    - Focusing especially on arrays
  - Matplot
    - While not used much in the model here to maintain simplicity, this is utilized **heavily** in machine learning
- Other Knowledge
  - Google Colab
    - Colab is the primary platform to train models on
    - Comfort navigating and working with importing and exporting files
  - Importing and installing libraries
#### C++
Required once the model is created to allow it to run on microcontrollers
- Libraries Knowledge
  - Tensorflow
    - Working with loading, allotting, instantiating, and debugging
  - Arduino
    - General board IO
- Other Knowledge
    - C++ Classes - It is important to understand how they work and how to implement

### PlatformIO Setup
To get the SparkFun Artemis boards installed into PlatformIO, follow the instructions on this [repository](https://github.com/nigelb/platform-apollo3blue).

*Notes as of writing this:
1. The path to the project must not contain any spaces to compile correctly
2. Projects must be created from the terminal to generate the proper files
3. The condition ```upload_speed = ``` must be added to the project INI file, ```921600``` works
4. To compile without a connected board, add ```upload_port = ``` to the project INI file

## Credits
### Library
- Condensed Tensorflow Lite library and code references from [wezleysherman](https://github.com/wezleysherman/ESP32-TensorFlow-Lite-Sample)
- As stated above, SparkFun Artemis PlatformIO support from [nigelb](https://github.com/nigelb/platform-apollo3blue)
- Reference for converting models to TFLite models from [tensorflow](https://github.com/tensorflow/tensorflow/tree/master/tensorflow/lite/micro/examples/hello_world/train)

## Additional Resources
- [Udemy course](https://www.udemy.com/course/deep-learning-tensorflow-2/) I used to learn Tensorflow
- [SparkFun Artemis ATP board](https://www.sparkfun.com/products/15442)

## License
[GPL-3.0](https://choosealicense.com/licenses/gpl-3.0/)