# 2D Graphics Library using SDL!
Example usage:
```C++
#include "2D_Graphics_Lib.hpp"

int main() {
	// Construct 1280x720 Window object.
	fbg::LoopWin window { "Window Title", 1280, 720 };

	// set window attributes:
	window.background(0, 20); // black with alpha 20
	window.framerate(144.0f);
	
	// Create circle object at (0, 0) with radius 50
	fbg::Circle circle {0.0f, 0.0f, 50.0f};
	
	// draw circle object at every frame update,
	// by attaching it to the window object
	window.attach(circle);

	// define function that will be called at every frame
	window.before_draw = [&](float frametime) -> void {
		// grab the mouse position from the window
		fbg::V2d<int> mpos = window.mouse();

	
	// set the position of the radius to the
		// current mouse position
		circle.pos(mpos);
	};

	// Start the game loop by calling run.
	window.run(); 

	return 0; // :)
}
```

Produces output:
![Screenshot from 2022-03-19 01-28-21](https://user-images.githubusercontent.com/93908883/159099446-f5976859-6240-45c8-a9e5-a05dad4b5cb2.png)
