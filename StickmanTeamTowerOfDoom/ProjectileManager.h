#pragma once
#include <vector>
class Projectile;
class ProjectileManager final
{
public:
	explicit ProjectileManager();
	ProjectileManager(ProjectileManager& p) = delete;
	ProjectileManager& operator=(ProjectileManager& p) = delete;
	ProjectileManager(ProjectileManager&& p) = delete;
	ProjectileManager& operator=(ProjectileManager&&) = delete;
	~ProjectileManager();

	void PushBack(Projectile* projectile);
	void Update(float elapsedSec);
	
	// Returns nullptr if none is found or if it is not done flying around
	Projectile* GiveBoomerang();

private:
	std::vector<Projectile*> m_Projectiles;
};

