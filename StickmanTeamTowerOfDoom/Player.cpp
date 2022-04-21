#include "pch.h"
#include "Player.h"
#include <iostream>

Player::Player()
	:Actor{ Actor::actorType::player,200.f }
	, m_IsInvincible{ false }
	, m_MaxInvincibleTime{1.f}
	, m_InvincibleTime{0.f}
	, m_Energy{6}
	, m_MaxEnergy{6}
	, m_MaxHoldTime{2.f}
	, m_MinChargTime{1.f}
	, m_ChargedTime{0.f}
	, m_EnergyRegen{0.5f}
	, m_Attack{Player::Attacks::none}
	, m_MaxAnimationsTime{1.f}
	, m_AnimationTime{0.f}
{
	m_Health = 6;
	m_MaxHealth = 6;
}

void Player::Initialize()
{
	m_AttacksHitBoxArr[int(Player::Attacks::light_Attack)-1]=Rectf{0.f,0.f,6.f,1.f};
	m_AttacksHitBoxArr[int(Player::Attacks::knok_up) - 1] = Rectf{ 0.f,0.f,5.f,4.f };
	m_AttacksHitBoxArr[int(Player::Attacks::heavy_fist) - 1] = Rectf{ 0.f,0.f,7.f,5.f };
}

void Player::Draw() const
{
}

void Player::Update(float elapsedSec)
{
	HandleMovment(elapsedSec);	

	if (m_Energy < m_MaxEnergy)
	{
		m_Energy += m_EnergyRegen * elapsedSec;
	}
	switch (m_Attack)
	{
	case Player::Attacks::none:
		break;
	case Player::Attacks::light_Attack:		
	case Player::Attacks::knok_up:		
	case Player::Attacks::heavy_fist:
	case Player::Attacks::boomerang:
		if (m_AnimationTime >= m_MaxAnimationsTime)
		{
			m_Attack = Attacks::none;
			m_AnimationTime = 0;
		}
		break;
	default:
		break;
	}
}

int Player::GetHealth()
{
	return m_Health;
}

int Player::GetEnergy()
{
	return int(m_Energy);
}

void Player::HandleMovment(float elapsedSec)
{	 
	const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	if ( pStates[SDL_SCANCODE_W] )
	{
		m_Velocity.y += m_MaxSpeed;
	}
	if ( pStates[SDL_SCANCODE_A] )
	{
		m_Velocity.y -= m_MaxSpeed;
	}
	if (pStates[SDL_SCANCODE_S])
	{
		m_Velocity.y -= m_MaxSpeed;
	}
	if (pStates[SDL_SCANCODE_D])
	{
		m_Velocity.y += m_MaxSpeed;
	}

	m_ActorRect.left += m_Velocity.x * elapsedSec;
	m_ActorRect.bottom += m_Velocity.y * elapsedSec;

	m_Velocity.x = 0;
	m_Velocity.y = 0;
}

void Player::ProcessKeyDownEvent(const SDL_KeyboardEvent& e, float elapsedSec)
{	
	switch ( e.keysym.sym )
	{
	case SDLK_j:
		m_ChargedTime += elapsedSec;
		if (m_ChargedTime >= m_MaxHoldTime)
		{
			m_Attack = Attacks::knok_up;
		}
		break;
	case SDLK_k:
		m_ChargedTime += elapsedSec;
		if (m_ChargedTime >= m_MaxHoldTime)
		{
			m_Attack = Attacks::boomerang;
			std::cout << "boomerang yeay!!!!!!!!!!!!!!!'\n";
		}
		break;
	}
}

void Player::ProcessKeyUpEvent(const SDL_KeyboardEvent& e)
{
	switch (e.keysym.sym)
	{
	case SDLK_j:
		if (m_ChargedTime < m_MaxHoldTime)
		{
			m_Attack = Attacks::light_Attack;
			m_ChargedTime = 0;
		}
		else if (m_ChargedTime >= m_MaxHoldTime)
		{
			m_Attack = Attacks::knok_up;
			m_ChargedTime = 0;
		}
		break;
	case SDLK_k:
		if (m_ChargedTime < m_MaxHoldTime)
		{
			m_Attack = Attacks::heavy_fist;
			m_ChargedTime = 0;
		}
		else if (m_ChargedTime >= m_MaxHoldTime)
		{
			m_Attack = Attacks::boomerang;
			std::cout << "boomerang yeay!!!!!!!!!!!!!!!'\n";
			m_ChargedTime = 0;
		}
		break;
	}	
}

bool Player::HitEnemy(const Rectf& shapeEnemy)
{
	switch (m_Attack)
	{
	
	case Player::Attacks::light_Attack:			
	case Player::Attacks::knok_up:		
	case Player::Attacks::heavy_fist:
		if (utils::IsOverlapping(m_AttacksHitBoxArr[int(m_Attack)-1], shapeEnemy))
		{
			return true;
		}
		break;
	case Player::Attacks::none:
	default:
		return false;
		break;
	}
	return false;
}

