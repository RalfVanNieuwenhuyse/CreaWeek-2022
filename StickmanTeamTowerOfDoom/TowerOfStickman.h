#pragma once
#include "Level.h"
class ProjectileManager;
class TowerOfStickman final : public Level
{
public:
	TowerOfStickman();
	TowerOfStickman(TowerOfStickman& t) = delete;
	TowerOfStickman& operator=(TowerOfStickman& t) = delete;
	TowerOfStickman(TowerOfStickman&& t) = delete;
	TowerOfStickman& operator= (TowerOfStickman && t) = delete;
	~TowerOfStickman();

	void Update(float elapsedSec) override;
	bool HasReachedEnd() override;

private:
	float m_ElapsedSec;
	ProjectileManager* m_ProjectileManager;
	unsigned char m_Sprites[256][16];
};

