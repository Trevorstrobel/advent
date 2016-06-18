#pragma once
#include <SDL.h>
#include "Texture.h"
#include "Vector2.h"
#include "Weapons.h"
#include "Audio.h"

class Enemy
{
public:
	Enemy(SDL_Renderer *renderer, Audio *Audio, Vector2 targetPos);
	~Enemy();

	void Update();
	SDL_Texture* GetEnemyTexture();
	void Render(SDL_Renderer *renderer);
	Vector2 SetPosition() const;
	Vector2 GetPosition() const;

	bool IsDead = false;
	
private:
	void shoot();
	void checkBoundaries();
	int getMoveSpeed();
	void moveEnemy();
	double enemyHealth;
	Texture enemyTexture;
	SDL_Texture *enemyTextureRenderable;
	//SDL_Texture *

	SDL_Rect SpriteClips[1];
	Texture RenderTexture;

	Mix_Chunk* shootSound;

	Vector2 enemyPosition;
	Vector2 enemyCenter;

	Vector2 targetPosition;
	

	//enemy's dimensions 
	float width;
	float height;
	float moveSpeed;
	double spriteAngle;
	double angle;
	
	float maxMoveSpeed;
	Vector2 velocity;

	//Weapon Properties
	Weapons *lazer;
	Uint32 lastShotTime;
	Uint32 currentTime;
	double shotInterval;

};