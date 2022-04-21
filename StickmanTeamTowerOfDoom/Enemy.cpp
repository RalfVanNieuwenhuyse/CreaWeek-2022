#include "pch.h"
#include "Enemy.h"
#include "Actor.h"

Enemy::Enemy(TypeOfEnemy enemyType)
	: Actor(actorType::enemy, 250.f)
	, m_EnemyType{ enemyType }
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

OAMEntry Enemy::sendOAM()
{
	//int posX, int posY, int tileID, bool flipX, bool flipY
	int posX{ m_ActorRect.left };
	int posY{ m_ActorRect.bottom };
	int TileID{ 10 };
	bool flipX{ false };
	bool flipY{ false };

	OAMEntry entry = OAMEntry{ posX, posY, TileID, flipX, flipY };

	return entry;
}

