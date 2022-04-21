#pragma once
#include "Timer.h"
#include "Vector2f.h"
class Projectile
{
public:
	enum class Type
	{
		bullet,boomerang,laser
	};

	explicit Projectile(Type type = Type::bullet, const Point2f& pos = {}, int damage = 2);
	Projectile(Projectile& p) = delete;
	Projectile& operator=(Projectile& p);
	Projectile(Projectile&& p) = delete;
	Projectile& operator=(Projectile&& p) = delete;
	virtual ~Projectile();

	// See if a rect is overlapping with the internal rect
	bool IsOverlapping(const Rectf& other);
	virtual void Update(float elapsedSec) = 0;

	void SetDamage(int dmg);
	void SetVelocity(const Vector2f& velocity);
	// Changes internal velocity's x component
	void SetHorVelocity(float xVel);
	// Changes bottom left of internal rect
	void SetPosition(const Point2f& pos);

	Type GetType() const;
	int GetDamage() const;
	bool ShouldBeDeleted() const;
protected:
	Type m_Type;
	Timer m_TimeAlive;
	Rectf m_Rect;

	Vector2f m_Velocity;

	int m_Damage;
};

