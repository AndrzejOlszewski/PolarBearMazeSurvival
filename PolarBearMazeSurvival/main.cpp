#include <iostream>
#include <raylib.h>


class PolarBear
{
public:

	Texture2D sprite;

	PolarBear() {
		sprite = LoadTexture("Assets/PolarBearPlayer.png");
	}

	~PolarBear() {
		UnloadTexture(sprite);
	}

	void Draw() {
		DrawTexture(sprite, 100, 100, WHITE);
	}

private:

};




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
	ToggleFullscreen();
	SetTargetFPS(60);

		int tileW = GetScreenWidth() / COLS;
		int tileH = GetScreenHeight() / ROWS;

		PolarBear player;

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(GREEN);

		for (int r = 0; r < ROWS; r++)
		{
			for (int c = 0; c < COLS; c++)
			{
				if (map[r][c] == 1) {
					DrawRectangle(c * tileW, r * tileH, tileW, tileH, DARKBLUE);
				}
			}
		}

		player.Draw();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
