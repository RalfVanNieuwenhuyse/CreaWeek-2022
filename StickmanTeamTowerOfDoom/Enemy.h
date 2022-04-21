#pragma once
#include "Actor.h"
class Enemy : public Actor
{
public:

	Enemy();
	virtual ~Enemy();

	enum class TypeOfEnemy
	{
		Undead,
		Knight,
		Boss
	};

	Enemy(const Enemy& other) = delete;
	Enemy& operator=(const Enemy& rhs) = delete;
	Enemy(Enemy&& other) = delete;
	Enemy& operator=(Enemy&& rhs) = delete;

	virtual void Draw()const override;
	virtual void Update(float elapsedSec) override;


protected:
	virtual void Movement(float elapsedSec);


private:



};

