#pragma once
#include "Actor.h"
class Player final : public Actor
{
public:
	enum class Attacks
	{
 		light_Attack = 0, //tap  j
		knok_up		 = 1, //hold j
		heavy_fist   = 2, //tap  k
		boomerang	 = 3, //hold k
	};

	Player();
	
	void Draw() const override;
	void Update(float elapsedSec) override;

	int GetHealth();
	int GetEnergy();


private:
	//Membervariabels
	bool m_IsInvincible;
	const float m_MaxInvincibleTime;
	float m_InvincibleTime;
		
	int m_Energy;
	const int m_MaxEnergy;

	const float m_MaxHoldTime;
	const float m_MinChargTime;
	float m_ChargedTime;

	//functions
	void HandleMovment(float elapsedSec);
	void HandleAttackInputs(float elapsedSec);

};

