#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <algorithm>
#include "Texture.h"
#include "Player.h"
#include "Enemy.h"
#include "Crosshair.h"
#include "Audio.h"


class Engine
{
public:

	//con/de structors
	Engine();
	~Engine();

	static int GetScreenWidth();
	static int GetScreenHeight();
	static void Quit();

	void Run(int w, int h);
	bool Init();

private:
	void processInputs();
	void update();
	void gameLoop();
	void draw();
	Input* input;
	Crosshair* crosshair;
	Player* player;
	Enemy* enemy;
	SDL_Window* window;
	SDL_Renderer* renderer;
	Texture background;
	Audio* gameAudio;
	Mix_Music* gameBGMusic;
	
	static bool isRunning;
	static int screenWidth;
	static int screenHeight;
	float dt;



};
