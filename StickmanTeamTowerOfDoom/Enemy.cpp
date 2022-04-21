#include "pch.h"
#include "Enemy.h"
#include "Actor.h"

Enemy::Enemy(TypeOfEnemy enemyType)
	:Actor::Actor(actorType::enemy)
	,m_EnemyType{ enemyType }
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

Enemy::TypeOfEnemy Enemy::GetTypeOfEnemy(){return m_EnemyType;}

void Enemy::Movement(float elapsedSec)
{
}
