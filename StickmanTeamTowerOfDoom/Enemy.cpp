#include "pch.h"
#include "Enemy.h"
#include "Actor.h"

Enemy::Enemy()
	:Actor::Actor()
{
}

Enemy::~Enemy()
{
}

void Enemy::Draw() const
{
}

void Enemy::Update(float elapsedSec)
{
}

bool Enemy::isDead()
{
	return false;
}

void Enemy::Movement(float elapsedSec)
{
}
