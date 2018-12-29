
# Installation
Simply drag the header file into your project and include it where needed.

# MathFunctions
Assorted math functions
## (float) mf_lerp(float from, float to, float weight)
```
mf_lerp(0.5, 1.5, 0.5); // Returns 1.0
```

# ConfigParser
Header library that parses config files in games.

## Example config file
The library is designed for basic game config files e.g
```
Width=1280
Height=720
Fullscreen=1
Vsync=0
AA=3
AnyVariableNameYouWant=AnyValueYouWant
```
These values are then loaded to a map with the variable name being the key
## Usage
```cpp
#include "ConfigParser.h"
int main() {
  //Load the map
  std::map<std::string, std::string> configMap = cp_get_config("Example.conf");
  
  //Get value from the map
  createWindow(configMap["Width"], configMap["Height"]);
  
  //Add a new element or update the map
  configMap["Fullscreen"] = "0";
  
  //Save the changed map
  cp_write_config(configMap, "Example.conf");
}
```
