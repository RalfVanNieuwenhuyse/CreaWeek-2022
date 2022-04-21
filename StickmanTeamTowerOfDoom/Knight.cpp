#include "pch.h"
#include "Knight.h"

Knight::Knight(Point2f pos)
	: SmallEnemy{pos}
{

}

Knight::~Knight()
{

}

void Knight::doAttack()
{
	switch (m_Attack)
	{
	case SmallEnemy::attacks::none:
		//Do nothing
		break;
	case SmallEnemy::attacks::melee:
		//Do melee attack
		break;
	case SmallEnemy::attacks::reflect:
		//reflect
		break;
	}
}