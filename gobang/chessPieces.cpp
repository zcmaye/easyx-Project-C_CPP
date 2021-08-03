#include "chessPieces.h"
#include<easyx.h>
ChessPieces::ChessPieces()
	:m_x(-1), m_y(-1), m_colorPiece(None)
{
}
ChessPieces::ChessPieces(int x, int y, ChessPieces::ColorPiece colorPiece)
	:m_x(x),m_y(y),m_colorPiece(colorPiece)
{
}

void ChessPieces::draw()
{
	switch (m_colorPiece)
	{
	case ChessPieces::None:
		break;
	case ChessPieces::Black:
		setfillcolor(BLACK);
		::solidcircle(m_x, m_y, 10);
		break;
	case ChessPieces::White:
		setfillcolor(WHITE);
		::solidcircle(m_x, m_y, 10);
		break;
	default:
		break;
	}
	
}

bool ChessPieces::operator==(const ChessPieces& right)const
{
	return (m_x == right.m_x && m_y == right.m_y && m_colorPiece != ChessPieces::None);
}

bool ChessPieces::operator<(const ChessPieces& right)const
{
	/*
	00 01 02 03 04 05
	10 11 12 13 14 15
	20 21 22 23 24 25
	*/
	return (m_x * 100 + m_y < right.m_x * 100 + right.m_y);
}

int ChessPieces::operator[](int index) const
{
	return m_colorPiece;
}

ChessPieces::operator int()
{
	return m_colorPiece;
}
