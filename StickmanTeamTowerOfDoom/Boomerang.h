#pragma once
#include "Projectile.h"
class Boomerang : public Projectile
{
public:
	Boomerang(const Point2f& pos, const Vector2f& direction = Vector2f{1,0});

	void Update(float elapsedSec) override;
};

