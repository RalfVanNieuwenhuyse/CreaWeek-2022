#pragma once
#include "SmallEnemy.h"

class Undead : public SmallEnemy
{
public:
	Undead(Point2f pos);
	virtual ~Undead();

	Undead(const Undead& other) = delete;
	Undead& operator=(const Undead& other) = delete;
	Undead(Undead&& other) = delete;
	Undead& operator=(Undead&& other) = delete;
protected:
	virtual void doAttack() override;



};

