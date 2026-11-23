#include <iostream>
#include <raylib.h>

int main() {



	InitWindow(1280, 720, "Polar game Maze Survival");
	SetTargetFPS(60);


	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(GREEN);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}