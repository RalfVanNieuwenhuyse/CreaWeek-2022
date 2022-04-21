#include "pch.h"
#include "Player.h"


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
	
{
	m_Health = 6;
	m_MaxHealth = 6;
}

void Player::Draw() const
{
}

void Player::Update(float elapsedSec)
{
}

int Player::GetHealth()
{
	return m_Health;
}

int Player::GetEnergy()
{
	return m_Energy;
}

void Player::HandleMovment(float elapsedSec)
{	 
	const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	if ( pStates[SDL_SCANCODE_W] )
	{
		
	}
	if ( pStates[SDL_SCANCODE_A] )
	{
		
	}
	if (pStates[SDL_SCANCODE_S])
	{

	}
	if (pStates[SDL_SCANCODE_D])
	{

	}
}

void Player::HandleAttackInputs(float elapsedSec)
{
}


