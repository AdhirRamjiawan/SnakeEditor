  __________________
/|					|
/|	SNAKE EDITOR	|
/|__________________|
/////////////////////

BUILD INSTRUCTIONS:
	- For windows run "Windows/resource_compile.bat" to generate resource object file needed for icon
	- Run cmake build either through Visual studio or command line.


TODO:
	- better graphics
	- THE ACTUAL EDITOR?!!!
	- Add dev docs to source control
	- Add libs to source control
	- Create menu scene (Load game, Options)
	- Add mongoose enemies
	- Add moving targets
	- Add rocks that snake will collide with
	- Add underground holes where snake can hide in. Enter tunnel and exit tunnel. In between enter and exit nothing can touch snake
	- Create a level file format
	- Add a tile map editor
	- Create music and sound fx
	- pack all game assets into a binary data format
	- Create a scoring system. Mabye time alive and length of snake?
	- After a good few seconds of showing the splash screen change to show AI game play for a 20 seconds or so.
	- Attempt to use smart pointers
	- Add cmake instructions to copy game assets to output folder
	- Add cmake instructions to create distributable version of game.
	- Look at double buffering techniques
	- Add shader effects: https://www.sfml-dev.org/tutorials/2.0/graphics-shader.php
	- snake must spit out apples too to fight enemies and bosses
	- Add multiple targets and when snake is able to hit these targets in quick succession keep track of a combo counter
	- In the snake editor add in a UI designer to create text and shape elements and generate c++ code.
	- Make SFML lib dependencies more relative for CI/CD builds etc.
	- Implement scene stacks for Scene Manager especially for GUI driven scenes like Main menu
	- Create an Entity pattern for things like the apple target. It should handle correct drawing and collisions etc.
	- Remove setFrameRateLimit from Draw scene calls.


BUGS:
	- Can't exit game once in game.
