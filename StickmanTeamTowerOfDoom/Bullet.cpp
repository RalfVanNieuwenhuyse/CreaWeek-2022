#include "pch.h"
#include "Bullet.h"

Bullet::Bullet(const Point2f& pos, const Vector2f& vel)
	:Projectile(Type::bullet,pos)
{
	SetVelocity(vel);
}

void Bullet::Update(float elapsedSec)
{
	m_Rect.left += m_Velocity.x * elapsedSec;
	m_Rect.bottom += m_Velocity.y * elapsedSec;

	m_TimeAlive.Update(elapsedSec);
}
