#pragma once
#include "Grid.h"
#include "Tile.h"
#include "OAMEntry.h"
class Level
{
public:
	Level();
	virtual ~Level() = default;
	Level(const Level& c) = delete;
	Level& operator=(const Level& rhs) = delete;
	Level(Level&& c) = delete;
	Level& operator=(Level&& rhs) = delete;

	virtual void Update(float elapsedSec) = 0;
	virtual void Draw() const = 0;
	void Render(const unsigned char sprite[256][16], const unsigned char backGround[256][16], 
		const OAMEntry oam[40], const unsigned char grid[1024], const unsigned char x, const unsigned char y) const;
	virtual bool HasReachedEnd() = 0;

protected:
	unsigned char m_Sprites[256][16];
	unsigned char m_BackGround[256][16];
	OAMEntry m_OAM[40];
	unsigned char m_Grid[1024];
	unsigned char m_X;
	unsigned char m_Y;
};

