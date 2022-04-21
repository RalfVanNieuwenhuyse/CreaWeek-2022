#pragma once
#include "Vector2f.h"

class Actor
{
public:
	Actor();
	virtual ~Actor();
	Actor(const Actor& other) = delete;
	Actor& operator=(const Actor& other) = delete;
	Actor(Actor&& other) = delete;



	virtual void Draw() const;
	virtual void Update(float elapsedSec);

protected:
	Vector2f m_Velocity;
	Rectf m_ActorRect;

	float m_Health;

private:



};

