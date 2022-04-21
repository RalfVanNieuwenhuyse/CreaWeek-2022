#include "pch.h"
#include "TestLevel.h"

TestLevel::TestLevel()
	:Level()
{
	for (int i{}; i < 40; ++i)
	{
		m_OAM[i] = OAMEntry(0, 0, 0);
	}
	unsigned char values[] {  0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0xFF, 0x00, 0xFF, 0x00	};
	for (int i{}; i < 256; ++i)
	{
		for (int j{}; j < 16; ++j)
		{
			m_BackGround[i][j] = values[j];
		}

	}

	unsigned char values2[]{ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0x00, 0xFF, 0x00 };
	for (int i{}; i < 256; ++i)
	{
		for (int j{}; j < 16; ++j)
		{
			m_Sprites[i][j] = values2[j];
		}

	}

	for (int i{}; i < 1024; ++i)
	{
		m_Grid[i] = m_BackGround[0][0];
	}
}
void TestLevel::Draw() const
{
	Level::Render(m_Sprites, m_BackGround, m_OAM, m_Grid, 0, 0);
}


void TestLevel::Update(float elapsedSec)
{

}

bool TestLevel::HasReachedEnd()
{
	return false;
}
