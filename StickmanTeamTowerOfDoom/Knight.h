#pragma once
#include "SmallEnemy.h"

class Knight : public SmallEnemy
{
public:
	Knight( Point2f pos );
	virtual ~Knight();

	Knight(const Knight& other) = delete;
	Knight& operator=(const Knight& other) = delete;
	Knight(Knight&& other) = delete;
	Knight& operator=(Knight&& other) = delete;

protected:
	virtual void doAttack() override;


};

