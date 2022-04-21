#pragma once
#include "Vector2f.h"

class Actor
{
public:
	enum class actorType
	{
		enemy,
		player
	};

	Actor( actorType actorType );

	virtual ~Actor();
	Actor(const Actor& other) = delete;
	Actor& operator=(const Actor& other) = delete;
	Actor(Actor&& other) = delete;
	Actor& operator=(Actor&& other) = delete;

	virtual void Draw() const;
	virtual void Update(float elapsedSec);

	virtual bool isDead() const;
	virtual Rectf getRect() const;
	actorType getActorType() const;

protected:
	Vector2f m_Velocity;
	Rectf m_ActorRect;

	int m_Health;
	int m_MaxHealth;

private:
	actorType m_ActorType;



};

