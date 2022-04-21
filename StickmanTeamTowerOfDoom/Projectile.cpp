#include "pch.h"
#include "Projectile.h"
#include "utils.h"
using namespace utils;

Projectile::Projectile(Type type, const Point2f& pos, int damage)
	:m_Type(type)
	,m_TimeAlive()
	,m_Rect()
	,m_Velocity(100,0)
	,m_Damage(damage)
{
	m_TimeAlive.setTimeGoal(16.f);
}

Projectile::~Projectile()
{
}

bool Projectile::IsOverlapping(const Rectf& other)
{
	return utils::IsOverlapping(m_Rect,other);
}

void Projectile::SetDamage(int dmg)
{
	if (dmg < 0) return;
	m_Damage = dmg;
}

void Projectile::SetVelocity(const Vector2f& velocity)
{
	m_Velocity = velocity;
}

void Projectile::SetHorVelocity(float xVel)
{
	m_Velocity.x = xVel;
}

void Projectile::SetPosition(const Point2f& pos)
{
	m_Rect.left = pos.x;
	m_Rect.bottom = pos.y;
}

Projectile::Type Projectile::GetType() const
{
	return m_Type;
}

int Projectile::GetDamage() const
{
	return m_Damage;
}

bool Projectile::ShouldBeDeleted() const
{
	if (m_Type == Type::boomerang) return (m_TimeAlive.getCurrentTime() > 32.f);
	return (m_TimeAlive.getCurrentTime() > 16.f);
}
