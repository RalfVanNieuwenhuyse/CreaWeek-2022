#include "pch.h"
#include "SmallEnemy.h"
#include "utils.h"

SmallEnemy::SmallEnemy(Point2f pos)
	: Enemy(TypeOfEnemy::smallEnemy)
	, m_Action{ actionState::idle }
	, m_Attack{ attacks::none }
{
	//Fill in actor info
	m_MaxHealth = 3;
	m_Health = m_MaxHealth;

	m_ActorRect = Rectf{ pos.x, pos.y, 0, 0 };
	m_Velocity = Vector2f{};

	//Attack range
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
	//movement "AI" of the small enemy
	float offset{ m_pPlayer->getRect().width };

	if (m_pPlayer->getRect().left + offset < m_ActorRect.left)
	{
		//move to left
		m_Velocity.x = m_MaxSpeed * -1;
	}
	else if (m_pPlayer->getRect().left - offset > m_ActorRect.left)
	{
		//move right
		m_Velocity.x = m_MaxSpeed;
	}

	if (m_pPlayer->getRect().bottom + offset < m_ActorRect.bottom)
	{
		//move to down
		m_Velocity.y = m_MaxSpeed * -1;
	}
	else if (m_pPlayer->getRect().bottom - offset > m_ActorRect.bottom)
	{
		//move up
		m_Velocity.y = m_MaxSpeed;
	}
}

void SmallEnemy::changeActionState()
{
	if (m_Health <= 0)
	{
		m_Action = actionState::dying;
	}
	else if (m_Attack != attacks::none)
	{
		m_Action = actionState::idle;
	}
	else
	{
		m_Action = actionState::moving;
	}
}
void SmallEnemy::changeAttack()
{
	int randomAttack{};
	randomAttack = rand() % 3;
	m_Attack = static_cast<attacks>(randomAttack);
}
bool SmallEnemy::isActorOverlapping(Actor* player)
{
	return utils::IsOverlapping(player->getRect(), m_ActorRect);
}
void SmallEnemy::IsInRange(Actor* player)
{
	m_pPlayer = player;

	if (isActorOverlapping(player))
	{
		changeAttack();
	}
	else
	{
		m_Attack = attacks::none;
	}
}

void SmallEnemy::doAttack()
{
	switch (m_Attack)
	{
	case SmallEnemy::attacks::none:
		//Do nothing
		break;
	case SmallEnemy::attacks::melee:
		//Do melee attack
		break;
	case SmallEnemy::attacks::reflect:
		//reflect
		break;
	}
}

bool SmallEnemy::isReflecting() const
{
	if (m_Attack == attacks::reflect)
	{
		return true;
	}
	return false;
}
