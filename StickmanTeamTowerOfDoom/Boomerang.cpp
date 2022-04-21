#include "pch.h"
#include "Boomerang.h"

Boomerang::Boomerang(const Point2f& pos, const Vector2f& direction)
	:Projectile(Type::boomerang,pos,5)
{
	m_Velocity = direction * 100.f;
}

void Boomerang::Update(float elapsedSec)
{
	float turnBackAcceleration{200.f};
	m_Velocity.x -= turnBackAcceleration * elapsedSec;
	m_Velocity.y -= turnBackAcceleration * elapsedSec;

	m_Rect.left += m_Velocity.x * elapsedSec;
	m_Rect.bottom += m_Velocity.y * elapsedSec;

	m_TimeAlive.Update(elapsedSec);
}
