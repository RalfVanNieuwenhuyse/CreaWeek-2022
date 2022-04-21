#pragma once
#include "Projectile.h"
// Sprite 12
class Laser : public Projectile
{
public:
	Laser(const Point2f& pos, float verticalVel);

	void Update(float elapsedSec) override;
};

