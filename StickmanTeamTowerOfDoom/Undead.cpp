#include "pch.h"
#include "Undead.h"

Undead::Undead(Point2f pos)
	: SmallEnemy{ pos }
{

}

Undead::~Undead()
{

}

void Undead::doAttack()
{
	switch (m_Attack)
	{
	case SmallEnemy::attacks::none:
		//Do nothing
		break;
	case SmallEnemy::attacks::melee:
		//Do melee attack
		m_pPlayer->takeDamage(2)
;		break;
	case SmallEnemy::attacks::reflect:
		//reflect
		break;
	}
}