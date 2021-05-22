#include <stdio.h>
#include <raylib.h>

//clang-7 -pthread -lralyib -lm -o main main.c

int main(void) {
	const int screenWidth = 576;
	const int screenHeight = 1024;

	// INITIALIZATION
	// Initiliazing windows screen
	InitWindow(screenWidth, screenHeight, "Flappy bird");

	// Initializing audio device
	InitAudioDevice();

	// Initializing sounds
	Sound dieSound = LoadSound("src/assets/die.wav");
	Sound hitSound = LoadSound("src/assets/hit.wav");
	Sound pointSound = LoadSound("src/assets/point.wav");
	Sound swooshSound = LoadSound("src/assets/swoosh.wav");

	// Initialiazing images
	// Numbers images
	Texture2D number0 = LoadTexture("src/assets/0.png");
	Texture2D number1 = LoadTexture("src/assets/1.png");
	Texture2D number2 = LoadTexture("src/assets/2.png");
	Texture2D number3 = LoadTexture("src/assets/3.png");
	Texture2D number4 = LoadTexture("src/assets/4.png");
	Texture2D number5 = LoadTexture("src/assets/5.png");
	Texture2D number6 = LoadTexture("src/assets/6.png");
	Texture2D number7 = LoadTexture("src/assets/7.png");
	Texture2D number8 = LoadTexture("src/assets/8.png");
	Texture2D number9 = LoadTexture("src/assets/9.png");

	// Bluebird images
	Texture2D bluebird_downflap = LoadTexture("src/assets/bluebird-downflap.png");
	Texture2D bluebird_midflap = LoadTexture("src/assets/bluebird-midflap.png");
	Texture2D bluebird_upflag = LoadTexture("src/assets/bluebird-upflag.png");

	// Background image
	Texture2D background = LoadTexture("src/assets/background-day.png");

	// Initializing camera
	Camera2D camera = { 0 };
	camera.target = (Vector2){ 20.0f, 20.0f };
	camera.offset = (Vector2){ 2.0f, 2.0f };
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;

	// Initializing music
	// Main menu music
	Music menuMusic = LoadMusicStream("src/assets/soundtrack/assassins-creed-soundtrack.mp3");
	menuMusic.looping = false;

	// Background music
	Music darksouls = LoadMusicStream("src/assets/soundtrack/darksouls-soundtrack.mp3");
	darksouls.looping = false;

	// Play background music
	PlayMusicStream(darksouls);

	// Initializing game fps
	SetTargetFPS(60);

	// Declaring variable
	bool isInMenu = false;

	//Main game loop
	while (!WindowShouldClose())
	{
		if (IsKeyPressed(KEY_SPACE)) {
			if (isInMenu) {
				StopMusicStream(menuMusic);
				ResumeMusicStream(darksouls);
				isInMenu = false;
			}
			else {
				PauseMusicStream(darksouls);
				PlayMusicStream(menuMusic);
				isInMenu = true;
			}
		}

		// Starting drawing
		BeginDrawing();

		// Changing backgound color
		ClearBackground(BLACK);

		// Showing the menu or the game
		if (isInMenu) {
			UpdateMusicStream(menuMusic);
			ClearBackground(BLACK);
			DrawRectangle(0, 0, 100, 30, RED);
		}
		else {
			UpdateMusicStream(darksouls);
			DrawTextureEx(background, (Vector2) { 0, 0 }, 0, 2, RAYWHITE);
		}

		// Ending drawing
		EndDrawing();
	}

	// De-Initialization
	UnloadMusicStream(darksouls);          // Unload music stream buffers from RAM

	CloseAudioDevice();     // Close audio device (music streaming is automatically stopped)

	CloseWindow();          // Close window and OpenGL context

	return 0;
}