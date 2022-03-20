  ________________
/|                |
/|  SNAKE EDITOR  |
/|________________|
//////////////////

BUILD INSTRUCTIONS:
	- For windows run "Windows/resource_compile.bat" to generate resource object file needed for icon
	- Run cmake build either through Visual studio or command line.


TODO:
	- Game modes:
		+ Longest snake challenge
		+ Fastest snake challenge
		+ Spit 'em up challenge
		+ Story mode ???
		+ Tic-Tac-Toe challenge

	- Scenes:
		+ Leaderboard
		+ After a good few seconds of showing the splash screen change to show AI game play for a 20 seconds or so.
		+ After completing all levels display 

	- Mechanics
		+ Add mongoose enemies
		+ Add moving targets 
		+ Add item to make snake go in turbo boost mode for a few seconds.
		+ Add item to make snake go in turbo boost mode for a few seconds.
		+ Add rocks that snake will collide with although these shouldn't make you get a game over but rather delay in hurt
		+ Add underground holes where snake can hide in. Enter tunnel and exit tunnel. In between enter and exit nothing can touch snake
		+ snake must spit out apples too to fight enemies and bosses
		+ Add boss levels
		+ Add multiple targets and when snake is able to hit these targets in quick succession keep track of a combo counter

	- Assets:
		+ Better graphics
		+ Better font
		+ Draw assets for snake itself

	- Editor:
		+ THE ACTUAL EDITOR?!!!
		+ In the snake editor add in a UI designer to create text and shape elements and generate c++ code.

	- Technical:
		+ Add a tile map editor
		+ pack all game assets into a binary data format
		+ Attempt to use smart pointers 
		+ Replace all variable declarations away from types to using auto keyword
		+ Add shader effects: https://www.sfml-dev.org/tutorials/2.0/graphics-shader.php
		+ Implement scene stacks for Scene Manager especially for GUI driven scenes like Main menu
		+ Create an Entity pattern for things like the apple target. It should handle correct drawing and collisions etc.
		+ Create a sound repository for commonly used music and sound effects that can be used accross scenes
		+ Record in game video
		+ Add config file the game uses on startup.
		+ Add check and warning message when assets aren't found in executable directory.
		+ Keep line column size to approximately 80 chars. Write a perl script to pick this up
		+ Fix #pragma message ("This TextUtils::CreateText method has a memory leak. Gradually allocates memory. Only allocate new Text instances for new strings on the console.")
		  in Console.cpp
		+ Move string file names of assets into utility class
		+ Make use of a doc tool like doxygen (https://www.doxygen.nl/index.html) to map out types and objects in the project
		+ Make leaderboard read from leaderboard file
		+ After quiting game to the main menu, stop the music
		+ Set initial music volume to be at most 60%
	
	- Console:
		+ Add the ability to run debug scripts.
		+ Handle backspace control character
		+ Spawn new apple random location
		+ Remove all apples
		+ Spawn new entity x random/specific location
		+ Set snake speed
		+ Exit Game scene
		+ Load level
		+ record in game video with command

	- Distribution:
		+ Create game distribution scripts to pack assets
		+ Add game store sdks: Steam, gog & epic

	- Misc:
		+ Add dev docs to source control
		+ Add libs to source control
		+ Make SFML lib dependencies more relative for CI/CD builds etc.
		+ Add all scene names to a header file called SceneNames with #defines "SCENE_"

BUGS:
	- when level complete there's a stuttering effect
