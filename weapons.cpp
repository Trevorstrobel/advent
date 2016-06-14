#include "Weapons.h"


Weapons::Weapons(SDL_Renderer *renderer)
{
	this->renderer = renderer;
};

void Weapons::Shoot(Vector2 position, Vector2 direction, double angle)
{
	projectiles.emplace_back(renderer, position, direction, angle);

}

void Weapons::Render(SDL_Renderer *renderer)
{
	for (int i = 0; i < projectiles.size(); i++)
	{
		projectiles[i].Render(renderer);
	}
}

void Weapons::Update()
{

	for (std::vector<Projectile>::iterator iter = projectiles.begin(); iter != projectiles.end();)
	{
		if ((*iter).isDead)
		{
			iter = projectiles.erase(iter);
			continue;
		}
		else
		{
			(*iter).Update();
			++iter;
		}
	}
}