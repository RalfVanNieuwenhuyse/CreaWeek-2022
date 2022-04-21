#pragma once
#include "Enemy.h"
#include "Timer.h"

class Boss: public Enemy
{
public:
	Boss(Point2f pos);
	virtual ~Boss();
	Boss(const Boss& other) = delete;
	Boss& operator=(const Boss& rhs) = delete;
	Boss(Boss&& other) = delete;
	Boss& operator=(Boss&& rhs) = delete;

	virtual void Update(float elapsedSec);

	void changeAttack();
	void doAttack();
	void isInRange(Actor* player);
	void changeActionState();

	bool isLookingLeft;
	bool isActorOverlapping(Actor* player);

	bool isAtEnd();

protected:
	enum class BossState 
	{
		alive,
		moving,
		takingDamage,
		waiting,
		Dead
	};

	enum class attackState
	{
		none,
		drill,
		bullet,
		launcher,

	};
	void Movement();


private:
	
	BossState m_BossState;
	attackState m_attackState;
	Timer* m_pTimer;
	bool m_HasReachedEnd;
	Rectf m_Range;
};

