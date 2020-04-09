# Sonic R Speedometer 0.0.1

This is a mod for Sonic R PC 2004 that prints player 1's horizontal speed on
the top of the screen. It looks really grimy for now, and I don't know why
because I think I'm calling the draw2d functions the same way that the timer
does.

## Build Instructions

The project file was made for Visual Studio 2019, but you can definitely change
the version in the project properties if you wanna build on another version.

1. Open SonicRSpeedometer.sln
2. Choose build configuration (Release will be faster, but it shouldn't matter too much)
3. Build
4. After it finishes, copy the `Speedometer` folder at the root to your `mods`
folder in your Sonic R install

From there, you can activate the mod in the Sonic R Mod Loader.