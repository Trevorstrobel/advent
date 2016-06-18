#include "Enemy.h"
#include "Engine.h"

Enemy::Enemy(SDL_Renderer* renderer, Audio *Audio, Vector2 targetPos) 
{
	lazer = new Weapons(renderer);

	targetPosition = targetPos;

	enemyTexture.LoadFromFile(renderer, "resources/shipSprite_1.png");
	width = enemyTexture.GetWidth();
	height = enemyTexture.GetHeight();
	spriteAngle = 0.0;
	enemyPosition.X = (Engine::GetScreenWidth() / 2) - (width / 2);
	enemyPosition.Y = (Engine::GetScreenHeight() / 6);

	moveSpeed = 0.2;
	maxMoveSpeed = 10;
	shotInterval = 75;

	enemyTextureRenderable = enemyTexture.GetTexture();
	lastShotTime = 0;
}

void Enemy::checkBoundaries()
{
	if ((enemyPosition.X + (width*0.5))> Engine::GetScreenWidth())
	{
		enemyPosition.X = 0 - (width*0.5);
	}
	else if ((enemyPosition.X + (width*0.5)) < 0)
	{
		enemyPosition.X = Engine::GetScreenWidth() - (width*0.5);
	}
	else if ((enemyPosition.Y + (height*0.5)) > Engine::GetScreenHeight())
	{
		enemyPosition.Y = 0 - (height*0.5);
	}
	else if ((enemyPosition.Y + (height*0.5)) < 0)
	{
		enemyPosition.Y = Engine::GetScreenHeight() - (height*0.5);
	}
}

void Enemy::moveEnemy()
{
	enemyPosition.X += velocity.X;
	enemyPosition.Y += velocity.Y;
}

int Enemy::getMoveSpeed()
{
	return moveSpeed;
}

Vector2 Enemy::GetPosition() const
{
	return enemyPosition;
}

SDL_Texture *Enemy::GetEnemyTexture()
{
	return enemyTextureRenderable;
}

void Enemy::Render(SDL_Renderer *renderer)
{
	lazer->Render(renderer);
	SDL_Rect renderQuad = { enemyPosition.X, enemyPosition.Y, width, height, };
	SDL_RenderCopyEx(renderer, enemyTextureRenderable, NULL, &renderQuad, angle, NULL, SDL_FLIP_NONE);
}

void Enemy::shoot()
{
	Vector2 directionVector = { targetPosition.X, targetPosition.Y };
	Vector2 normalizedDirection = directionVector.Normalize();
	Vector2 direction = { normalizedDirection.X *width / 2, normalizedDirection.Y * height / 2 };
	Vector2 bulletPos = { enemyCenter.X + direction.X, enemyCenter.Y + direction.Y };
	lazer->Shoot(bulletPos, direction, angle);
}

void Enemy::Update()
{
	moveEnemy();
	checkBoundaries();
	lazer->Update();
}