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

	void Draw() const override;
	void Update(float elapsedSec) override;
	bool HasReachedEnd() override;

private:
	float m_ElapsedSec;
	ProjectileManager* m_ProjectileManager;
};

