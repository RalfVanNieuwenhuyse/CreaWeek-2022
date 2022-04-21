#pragma once
#include "Actor.h"
class Enemy : public Actor
{
public:
	enum class TypeOfEnemy
	{
		Undead,
		Knight,
		Boss
	};

	Enemy(TypeOfEnemy enemyType);
	virtual ~Enemy();


	Enemy(const Enemy& other) = delete;
	Enemy& operator=(const Enemy& rhs) = delete;
	Enemy(Enemy&& other) = delete;
	Enemy& operator=(Enemy&& rhs) = delete;

	virtual void Draw()const override;
	virtual void Update(float elapsedSec) override;
	TypeOfEnemy GetTypeOfEnemy();

protected:
	virtual void Movement(float elapsedSec);

private:
	TypeOfEnemy m_EnemyType;
	


};

