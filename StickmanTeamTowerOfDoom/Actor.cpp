#include "pch.h"
#include "Actor.h"
#include "utils.h"

Actor::Actor(actorType actorType, const float& maxSpeed)
	: m_Velocity{}
	, m_ActorRect{}
	, m_Health{}
	, m_MaxHealth{}
	, m_ActorType{ actorType }
	, m_MaxSpeed{ maxSpeed }
{

}

Actor::~Actor()
{

}

void Actor::Draw() const
{
	//Draw actor
	utils::SetColor(Color4f{ 1, 0, 0, 1 });
	utils::FillRect(m_ActorRect);
}

void Actor::Update(float elapsedSec)
{
	//Update actor
	m_ActorRect.left   += m_Velocity.x * elapsedSec;
	m_ActorRect.bottom += m_Velocity.y * elapsedSec;
}

bool Actor::isDead() const
{
	if (m_Health <= 0)
	{
		return true;
	}
	return false;
}
Rectf Actor::getRect() const
{
	return m_ActorRect;
}
Actor::actorType Actor::getActorType() const
{
	return m_ActorType;
}
