#include "Projectile.h"

static Texture texture;
static SDL_Texture* projectileTexture = nullptr;


Projectile::Projectile(SDL_Renderer *renderer, Vector2 position, Vector2 direction, double angle)
{
	projectileTexture;
	if (projectileTexture == nullptr)
	{
		texture.LoadFromFile(renderer, "resources/bulletSprite_1.png");
		projectileTexture = texture.GetTexture();
	}

	this->position = position;
	rotation = angle;
	this->direction = direction;

	velocity = 0.6;
	ttl = 100;
	lifetime = 0;
	isDead = false;

}

Projectile::~Projectile()
{
}

void Projectile::Render(SDL_Renderer *renderer)
{
	SDL_Rect renderQuad = { position.X, position.Y, 8, 8};
	SDL_RenderCopyEx(renderer, projectileTexture, NULL, &renderQuad, rotation, NULL, SDL_FLIP_NONE); 
}

void Projectile::Update()
{
	position.X += direction.X * velocity;
	position.Y += direction.Y * velocity;

	lifetime++;
	if (lifetime >= ttl) {
		isDead = true;
	}
}

