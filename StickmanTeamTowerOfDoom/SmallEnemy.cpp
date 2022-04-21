#include "pch.h"
#include "SmallEnemy.h"
#include "utils.h"

SmallEnemy::SmallEnemy(Point2f pos)
	: Enemy()
	, m_Action{ actionState::idle }
	, m_Attack{ attacks::none }
{
	//Fill in actor info
	m_Health = 10;
	m_ActorRect = Rectf{ pos.x, pos.y, 0, 0 };
	m_Velocity = Vector2f{};

	float range{ m_ActorRect.width / 2 };
	m_RangeRect = Rectf{ m_ActorRect.left, m_ActorRect.bottom, range, range };
}

SmallEnemy::~SmallEnemy()
{

}

void SmallEnemy::Update(float elapsedSec)
{
	if (m_Action != actionState::dying)
	{
		if (m_Action == actionState::moving)
		{
			movement();

			m_ActorRect.left	+= m_Velocity.x * elapsedSec;
			m_ActorRect.bottom	+= m_Velocity.y * elapsedSec;
		}
		else if (m_Action == actionState::idle)
		{

		}
		doAttack();
		changeActionState();
	}	
	else if (m_Action == actionState::dying)
	{
		//DIE
		
	}
}

void SmallEnemy::movement()
{
	//Movement "AI" of the small enemy
}

void SmallEnemy::changeActionState()
{

}

void SmallEnemy::doAttack()
{




	int randomAttack{};
	randomAttack = rand() % 3;
	m_Attack = static_cast<attacks>(randomAttack);
}

bool SmallEnemy::isActorOverlapping(const Actor* player)
{
	return utils::IsOverlapping(player->getRect(), m_ActorRect);
}

