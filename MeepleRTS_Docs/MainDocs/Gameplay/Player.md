# Overview
Inspired from games such as Tooth and Tail, Pikmin where the game could be played on a controller and it is made for controller.

The player will have things like SELECT to select the type of units and COMMANDS to order units to do things.

```cpp
// Holds things such as the Camera, Mesh, etc
MRTSPawn.h

// Just holds the inputs to reduce clutter on Pawn
MRTSController.h

// Holds all information about the player
MRTSPlayerState.h

// Used for setting up binding tags for ability inputs
MRTSInputComponent.h

// Data Asset for setting up modular ability inputs
MRTSInputConfig.h
```

# Controls
Need an image of a controller with all the basic control scheme of the game

# Player Level
Levelling up the main player character.
More like a MOBA style levelling where the player can chose what kind of ability they would like on the player?

# Camera
Camera Control IDEAS: 

The right thumbstick allows the player to control the camera. 

**Camera Modes:** The player can press down on the right thumbstick to lock back to the main character the player is playing as and resets the zoom level.

**Right Thumb Stick:** Horizontal axis to look around, vertical axis to zoom in or out. Most of the time the player will be only be able to zoom or look around and not both at the same time.