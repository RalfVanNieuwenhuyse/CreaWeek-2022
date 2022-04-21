#include "pch.h"
#include "Laser.h"

Laser::Laser(const Point2f& pos, float verticalVel)
	:Projectile(Type::laser,pos,3)
{
	SetVelocity(Vector2f{ 0,verticalVel });
	m_Rect.width = 500.f;
}

void Laser::Update(float elapsedSec)
{
	m_TimeAlive.Update(elapsedSec);
}
