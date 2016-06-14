#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Input.h"
#include "Texture.h"
#include "Vector2.h"
#include "Weapons.h"

class Player
{
public:
	Player(SDL_Renderer *renderer);
	~Player();

	void Update();
	SDL_Texture* GetPlayerTexture();
	void Render(SDL_Renderer *renderer);
	void HandleInput(Input *input, float dt);
	Vector2 GetPosition() const;

	bool IsDead = false;
	double SpriteAngle;

private:
	void shoot();

	Uint32 lastShotTime;
	Uint32 currentTime;
	double shotInterval;
	int getMoveSpeed();
	void movePlayer();
	double playerHealth;
	Texture playerTexture;
	SDL_Texture *SDLTexture;
	SDL_Rect SpriteClips[1];
	Texture RenderTexture;

	//vector2 to hold position. 
	Vector2 position;
	Vector2 playerCenter;
	//Vector2 bulletPos;
	Vector2* mousePosition;

	float width;
	float height;
	int moveSpeed;

	Vector2 velocity;
	Weapons *blaster;

	//Player rotation in degrees
	double angle;
};