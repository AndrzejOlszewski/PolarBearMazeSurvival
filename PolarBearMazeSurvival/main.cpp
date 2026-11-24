#include <raylib.h>

const int ROWS = 11;
const int COLS = 15;

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

// Helper function to glide smoothly from current position to target position
float MoveTowards(float current, float target, float maxDelta) {
	if (target - current > maxDelta) return current + maxDelta;
	if (current - target > maxDelta) return current - maxDelta;
	return target;
}

class PolarBear
{
public:
	Texture2D sprite;
	int row = 1;
	int col = 1;
	float x = 0.0f;
	float y = 0.0f;
	int direction = 2;
	int frame = 1;
	float animTimer = 0.0f;

	PolarBear(int tileW, int tileH) {
		sprite = LoadTexture("Assets/PolarBearPlayer.png");
		x = (float)(col * tileW);
		y = (float)(row * tileH);
	}

	~PolarBear() { UnloadTexture(sprite); }

	void Update(int tileW, int tileH) {
		float targetX = (float)(col * tileW);
		float targetY = (float)(row * tileH);
		float speed = 350.0f * GetFrameTime();

		x = MoveTowards(x, targetX, speed);
		y = MoveTowards(y, targetY, speed);

		if (x != targetX || y != targetY)
		{
			animTimer += GetFrameTime();
			if (animTimer >= 0.1f)
			{
				animTimer = 0.0f;
				frame = (frame + 1) % 3;
			}
			return;
		}



int nextRow = row;
int nextCol = col;

if (IsKeyDown(KEY_W)) { nextRow--; direction = 0; }
else if (IsKeyDown(KEY_D)) { nextCol++; direction = 1; }
else if (IsKeyDown(KEY_S)) { nextRow++; direction = 2; }
else if (IsKeyDown(KEY_A)) { nextCol--; direction = 3; }
else { frame = 1; return; }

if (map[nextRow][nextCol] != 1) {
	row = nextRow;
	col = nextCol;
}
	}

	void Draw(int tileW, int tileH) {
		float w = sprite.width / 3.0f;
		float h = sprite.height / 4.0f;

		Rectangle source = { frame * w, direction * h, w, h };
		Rectangle dest = { x, y, (float)tileW, (float)tileH };

		DrawTexturePro(sprite, source, dest, { 0, 0 }, 0.0f, WHITE);
	}
};

int main() {
	InitWindow(1280, 720, "Polar game Maze Survival");
	ToggleFullscreen();
	SetTargetFPS(60);

	int tileW = GetScreenWidth() / COLS;
	int tileH = GetScreenHeight() / ROWS;

	PolarBear player(tileW, tileH);

	while (!WindowShouldClose())
	{
		player.Update(tileW, tileH);

		BeginDrawing();
		ClearBackground(GREEN);

		for (int r = 0; r < ROWS; r++) {
			for (int c = 0; c < COLS; c++) {
				if (map[r][c] == 1) {
					DrawRectangle(c * tileW, r * tileH, tileW, tileH, DARKBLUE);
				}
			}
		}

		player.Draw(tileW, tileH);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
