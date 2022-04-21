#include "pch.h"
#include "OAMEntry.h"


OAMEntry::OAMEntry()
	:OAMEntry(0, 0, 0)
{

}

OAMEntry::OAMEntry(int posX, int posY, int tileID, bool flipX, bool flipY)
	:m_PosX{posX}
	,m_PosY{posY}
	,m_TileId{tileID}
	,m_FlipX{flipX}
	,m_FlipY{flipY}
{
}

void OAMEntry::SetPosition(int posX, int posY)
{
	m_PosX = posX;
	m_PosY = posY;
}

void OAMEntry::AddPosition(int posX, int posY)
{
	m_PosX += posX;
	m_PosY += posY;
}

Point2f OAMEntry::GetPosition() const
{
	return Point2f{ float(m_PosX), float(m_PosY) };
}

void OAMEntry::FlipX(bool flip)
{
	m_FlipX = flip;
}

void OAMEntry::FlipY(bool flip)
{
	m_FlipY = flip;
}

bool OAMEntry::GetFlipX() const
{
	return m_FlipX;
}

bool OAMEntry::GetFlipY() const
{
	return m_FlipY;
}

int OAMEntry::GetTileId() const
{
	return m_TileId;
}


