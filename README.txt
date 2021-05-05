  ________________
/|                |
/|  SNAKE EDITOR  |
/|________________|
//////////////////

BUILD INSTRUCTIONS:
	- For windows run "Windows/resource_compile.bat" to generate resource object file needed for icon
	- Run cmake build either through Visual studio or command line.


TODO:
	- Scenes:
		+ Leaderboard
		+ After a good few seconds of showing the splash screen change to show AI game play for a 20 seconds or so.
		+ Multiple levels

	- Mechanics
		+ Add mongoose enemies
		+ Add moving targets 
		+ Add item to make snake go in turbo boost mode for a few seconds.
		+ Add item to make snake go in turbo boost mode for a few seconds.
		+ Add rocks that snake will collide with although these shouldn't make you get a game over but rather delay in hurt
		+ Add underground holes where snake can hide in. Enter tunnel and exit tunnel. In between enter and exit nothing can touch snake
		+ Create a scoring system. Mabye time alive and length of snake?
		+ snake must spit out apples too to fight enemies and bosses
		+ Add multiple levels
		+ Add boss levels
		+ Add multiple targets and when snake is able to hit these targets in quick succession keep track of a combo counter

	- Assets:
		+ Better graphics

	- Editor:
		+ THE ACTUAL EDITOR?!!!
		+ In the snake editor add in a UI designer to create text and shape elements and generate c++ code.

	- Technical:
		+ Create a level file format
		+ Add a tile map editor
		+ pack all game assets into a binary data format
		+ Attempt to use smart pointers 
		+ Look at double buffering techniques
		+ Add shader effects: https://www.sfml-dev.org/tutorials/2.0/graphics-shader.php
		+ Implement scene stacks for Scene Manager especially for GUI driven scenes like Main menu
		+ Create an Entity pattern for things like the apple target. It should handle correct drawing and collisions etc.
		+ Remove setFrameRateLimit from Draw scene calls.
		+ Create a sound repository for commonly used music and sound effects that can be used accross scenes
	
	- Console:
		+ For the dev console add the ability to run debug scripts.
		+ For the dev console add ability to backspace on current line 

	- Distribution:
		+ Create game distribution scripts to pack assets
		+ Add game store sdks: Steam, gog & epic

	- Misc:
		+ Add dev docs to source control
		+ Add libs to source control
		+ Make SFML lib dependencies more relative for CI/CD builds etc.

BUGS:
	- Can't exit game once in game.
