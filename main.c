#include <stdio.h>
#include "raylib.h"

//clang-7 -pthread -lralyib -lm -o main main.c

int main(void) {
	const int screenWidth = 576;
	const int screenHeight = 1024;

	InitWindow(screenWidth, screenHeight, "Flappy bird");

	// Initialize audio device
	InitAudioDevice();

	Texture2D background = LoadTexture("C:\\Users\\diego\\source\\repos\\SecondTryReylie\\SecondTryReylie\\src\\assets\\background-day.png");

	// Initializing camera
	Camera2D camera = { 0 };
	camera.target = (Vector2){ 20.0f, 20.0f };
	camera.offset = (Vector2){ 2.0f, 2.0f };
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		//Main game loop
		BeginDrawing();

		ClearBackground(BLACK);

		DrawTextureEx(background, (Vector2){0, 0}, 0, 2, RAYWHITE);

		EndDrawing();
	}
	UnloadTexture(background);
	CloseWindow();

	return 0;
}