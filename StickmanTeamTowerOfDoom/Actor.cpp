#include "pch.h"
<<<<<<< Updated upstream
#include"Actor.h"

Actor::Actor()
{
=======
#include "Actor.h"
#include "utils.h"

Actor::Actor(actorType actorType)
	: m_Velocity{}
	, m_ActorRect{}
	, m_Health{}
	, m_ActorType{ actorType }
{

>>>>>>> Stashed changes
}

Actor::~Actor()
{
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
}

void Actor::Draw() const
{
<<<<<<< Updated upstream
=======
	//Draw actor
	utils::SetColor(Color4f{ 1, 0, 0, 1 });
	utils::FillRect(m_ActorRect);
>>>>>>> Stashed changes
}

void Actor::Update(float elapsedSec)
{
<<<<<<< Updated upstream
=======
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
>>>>>>> Stashed changes
}
