#pragma once
#include "Projectile.h"
// Sprite 11
class Bullet final : public Projectile
{
public:
	Bullet(const Point2f& pos = {}, const Vector2f& vel = {});

	void Update(float elapsedSec) override;

private:
};

