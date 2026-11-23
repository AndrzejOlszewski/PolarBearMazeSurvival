#include <iostream>
#include <raylib.h>

int main() {

	const int ROWS = 11;
	const int COLS = 15;
	const int TILE = 40;

	int map[ROWS][COLS] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
		{1,0,1,1,0,1,0,1,0,1,0,1,1,0,1},
		{1,0,0,0,0,1,0,0,0,1,0,0,0,0,1},
		{1,0,1,1,0,1,1,2,1,1,0,1,1,0,1},
		{1,0,0,0,0,0,0,2,0,0,0,0,0,0,1},
		{1,0,1,1,0,1,1,1,1,1,0,1,1,0,1},
		{1,0,0,1,0,0,0,1,0,0,0,1,0,0,1},
		{1,1,0,1,0,1,0,0,0,1,0,1,0,1,1},
		{1,0,0,0,0,1,0,1,0,1,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	InitWindow(1280, 720, "Polar game Maze Survival");
	SetTargetFPS(60);


	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(GREEN);

		for (int r = 0; r < ROWS; r++)
		{
			for (int c = 0; c < COLS; c++)
			{
				if (map[r][c] == 1) {
					DrawRectangle(c * TILE, r * TILE, TILE, TILE, DARKBLUE);
				}
			}
		}

		EndDrawing();
	}

	CloseWindow();

	return 0;
}