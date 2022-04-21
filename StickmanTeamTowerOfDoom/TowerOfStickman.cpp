#include "pch.h"
#include "TowerOfStickman.h"
#include "Boss.h"
#include "ProjectileManager.h"

#include "Resources/Export.h"


TowerOfStickman::TowerOfStickman()
	:Level()
{
#pragma region Regret
	int amountOfSprites{17};
	for (int j{ 0 }; j < amountOfSprites; ++j)
	{
		m_Sprites[0][j] = TileLabelTLE0[j];
	}
	for (int j{ 0 }; j < amountOfSprites; ++j)
	{
		m_Sprites[1][j] = TileLabelTLE1[j];
	}
	for (int j{ 0 }; j < amountOfSprites; ++j)
	{
		m_Sprites[2][j] = TileLabelTLE2[j];
	}
	for (int j{ 0 }; j < amountOfSprites; ++j)
	{
		m_Sprites[3][j] = TileLabelTLE3[j];
	}
	for (int j{ 0 }; j < amountOfSprites; ++j)
	{
		m_Sprites[4][j] = TileLabelTLE4[j];
	}
	for (int j{ 0 }; j < amountOfSprites; ++j)
	{
		m_Sprites[5][j] = TileLabelTLE5[j];
	}
	for (int j{ 0 }; j < amountOfSprites; ++j)
	{
		m_Sprites[6][j] = TileLabelTLE6[j];
	}
	for (int j{ 0 }; j < amountOfSprites; ++j)
	{
		m_Sprites[7][j] = TileLabelTLE7[j];
	}
	for (int j{ 0 }; j < amountOfSprites; ++j)
	{
		m_Sprites[8][j] = TileLabelTLE8[j];
	}
	for (int j{ 0 }; j < amountOfSprites; ++j)
	{
		m_Sprites[9][j] = TileLabelTLE9[j];
	}
	for (int j{ 0 }; j < amountOfSprites; ++j)
	{
		m_Sprites[10][j] = TileLabelTLE10[j];
	}
	for (int j{ 0 }; j < amountOfSprites; ++j)
	{
		m_Sprites[11][j] = TileLabelTLE11[j];
	}
	for (int j{ 0 }; j < amountOfSprites; ++j)
	{
		m_Sprites[12][j] = TileLabelTLE12[j];
	}
	for (int j{ 0 }; j < amountOfSprites; ++j)
	{
		m_Sprites[13][j] = TileLabelTLE13[j];
	}
	for (int j{ 0 }; j < amountOfSprites; ++j)
	{
		m_Sprites[14][j] = TileLabelTLE14[j];
	}
	for (int j{ 0 }; j < amountOfSprites; ++j)
	{
		m_Sprites[15][j] = TileLabelTLE15[j];
	}
	for (int j{ 0 }; j < amountOfSprites; ++j)
	{
		m_Sprites[16][j] = TileLabelTLE16[j];
	}
	for (int j{ 0 }; j < amountOfSprites; ++j)
	{
		m_Sprites[17][j] = TileLabelTLE17[j];
	}
	for (int j{ 0 }; j < amountOfSprites; ++j)
	{
		m_Sprites[18][j] = TileLabelTLE18[j];
	}
	for (int j{ 0 }; j < amountOfSprites; ++j)
	{
		m_Sprites[19][j] = TileLabelTLE19[j];
	}
	for (int j{ 0 }; j < amountOfSprites; ++j)
	{
		m_Sprites[20][j] = TileLabelTLE20[j];
	}
	for (int j{ 0 }; j < amountOfSprites; ++j)
	{
		m_Sprites[21][j] = TileLabelTLE21[j];
	}
	for (int j{ 0 }; j < amountOfSprites; ++j)
	{
		m_Sprites[22][j] = TileLabelTLE22[j];
	}
	for (int j{ 0 }; j < amountOfSprites; ++j)
	{
		m_Sprites[23][j] = TileLabelTLE23[j];
	}
	for (int j{ 0 }; j < amountOfSprites; ++j)
	{
		m_Sprites[24][j] = TileLabelTLE24[j];
	}
#pragma endregion
}

TowerOfStickman::~TowerOfStickman()
{
}

void TowerOfStickman::Update(float elapsedSec)
{
	
}

bool TowerOfStickman::HasReachedEnd()
{
	// IsBossFinished
	return false;
}
