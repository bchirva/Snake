### Simpe, classic Snake game.
Written in C++ with [SFML](https://sfml-dev.org).

##### Requirements:
* C++ compiler that support 14 standard;
* CMake at least 3.5.2 version;

##### Build
You're able to use installed on your system 3rd party packages (SFML and yaml-cpp) or build them from source. By default, 3rd party dependencies are taking from submodules, but you can set <libname>_USE_SYSTEM cached variables equal ON while configuring cmake to link already installed libraries.

##### Default Control:
Command | Key 
------- | ----------- 
Turn Up | <kbd>W</kbd> 
Turn Down | <kbd>S</kbd> 
Turn Left | <kbd>A</kbd>
Turn Right | <kbd>D</kbd> 
Pause | <kbd>Space</kbd> 
Exit | <kbd>Esc</kbd> 

