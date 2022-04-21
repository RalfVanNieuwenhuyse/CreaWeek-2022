#include "pch.h"
#include "Boss.h"
#include "Vector2f.h"
#include "utils.h"

Boss::Boss(Point2f pos)
	:Enemy::Enemy(TypeOfEnemy::Boss)
	,m_BossState{BossState::waiting}
	,m_attackState{ attackState::none }
	,isLookingLeft{true}
{
	m_MaxHealth = 200;
	m_Health = m_MaxHealth;
	m_Velocity = Vector2f{ 0,0 };
	m_HasReachedEnd = false;
	m_pTimer = new Timer();
	
	m_ActorRect.left = pos.x;
	m_ActorRect.bottom = pos.y;

	m_Range = Rectf{ m_ActorRect.left - (m_ActorRect.width / 2),m_ActorRect.bottom,(m_ActorRect.width / 2),m_ActorRect.height };
}

Boss::~Boss()
{
}


void Boss::Update(float elapsedSec)
{
	if (m_BossState != BossState::Dead)
	{
		if (m_BossState == BossState::moving)
		{
			Movement();
			m_ActorRect.left += m_Velocity.x * elapsedSec;
			m_ActorRect.bottom += m_Velocity.y * elapsedSec;
		}
		else if(m_BossState == BossState::waiting)
		{

		}
		doAttack();
		changeActionState();

	}
	else if(m_BossState == BossState::Dead)
	{
		m_pTimer->Update(elapsedSec);
		m_pTimer->setTimeGoal(2);
		m_HasReachedEnd = true;

	}

}

void Boss::changeAttack()
{
	int randomAttack = rand() % 4;
	m_attackState = static_cast<attackState>(randomAttack);
}

void Boss::doAttack()
{
	switch (m_attackState)
	{
	case Boss::attackState::none:

		break;
	case Boss::attackState::drill:

		break;
	case Boss::attackState::bullet:

		break;
	case Boss::attackState::launcher:
		
		break;
	default:
		break;
	}
}

void Boss::isInRange(Actor* player)
{
	if (m_attackState == attackState::drill)
	{
		if (utils::IsOverlapping(player->getRect(),m_Range))
		{
			changeAttack();
		}

	}
	else
	{
		m_attackState = attackState::none;
	}
}

void Boss::changeActionState()
{
	if (m_Health <= 0)
	{
		m_BossState = BossState::Dead;
	}
	else if (m_attackState != attackState::none)
	{
		m_BossState = BossState::waiting;
	}
	else
	{
		m_BossState = BossState::moving;
	}

}

bool Boss::isActorOverlapping(Actor* player)
{
	if (isLookingLeft)
	{
		m_Range.left = m_ActorRect.left - (m_ActorRect.width / 2);
	}
	else
	{
		m_Range.left = m_ActorRect.left - (m_ActorRect.width / 2);
	}
	return utils::IsOverlapping(player->getRect(),m_Range);
}

bool Boss::isAtEnd()
{
	return m_HasReachedEnd;
}

void Boss::Movement()
{



}


