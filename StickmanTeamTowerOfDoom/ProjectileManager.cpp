#include "pch.h"
#include "ProjectileManager.h"
#include "Projectile.h"

ProjectileManager::ProjectileManager()
	:m_Projectiles()
{
	m_Projectiles.reserve(16);
}

ProjectileManager::~ProjectileManager()
{
	for (size_t i{ 0 }; i < m_Projectiles.size(); ++i)
	{
		delete m_Projectiles[i];
		m_Projectiles[i] = nullptr;
	}
}

void ProjectileManager::PushBack(Projectile* projectile)
{
	bool pointerPushed{ false };
	for (size_t i{ 0 }; i < m_Projectiles.size(); ++i)
	{
		if (m_Projectiles[i]) continue;
		if (pointerPushed) continue;
		m_Projectiles[i] = projectile;
		pointerPushed = true;
	}
	if (!pointerPushed) m_Projectiles.push_back(projectile);
}

void ProjectileManager::Update(float elapsedSec)
{
	for (size_t i{ 0 }; i < m_Projectiles.size(); ++i)
	{
		if (!m_Projectiles[i]) continue;
		m_Projectiles[i]->Update(elapsedSec);
		if (m_Projectiles[i]->ShouldBeDeleted())
		{
			if (m_Projectiles[i]->GetType() == Projectile::Type::boomerang);
			else
			{
				delete m_Projectiles[i];
				m_Projectiles[i] = nullptr;
			}
		}
	}
}

bool ProjectileManager::IsOverlappingWithAProjectile(const Rectf& other, Projectile& returnProjectile)
{
	for (size_t i{ 0 }; i < m_Projectiles.size(); ++i)
	{
		if (m_Projectiles[i]->IsOverlapping(other))
		{
			returnProjectile = *m_Projectiles[i];
			return true;
		}
	}
	return false;
}

Projectile* ProjectileManager::GiveBoomerang()
{
	for (size_t i{ 0 }; i < m_Projectiles.size(); ++i)
	{
		if (m_Projectiles[i]->GetType() == Projectile::Type::boomerang)
		{
			if (m_Projectiles[i]->ShouldBeDeleted())
			{
				Projectile* p{ m_Projectiles[i] };
				m_Projectiles[i] = nullptr;
				return p;
			}
		}
	}
	return nullptr;
}
