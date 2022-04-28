#include "Color.h"

Color::Color(int rgb)
{
	m_color = rgb;
}

Color::Color(uint8 r, uint8 g, uint8 b)
{
	//m_color = ( (((color) & 0xFF) << 16) | ((color) & 0xFF00FF00) | (((color) & 0xFF0000) >> 16) )
	m_color = ((Dword)(((Byte)(r) | ((Word)((Byte)(g)) << 8)) | (((Dword)(Byte)(b)) << 16)));
}

uint32 Color::toRgb() const
{
	return m_color;
}

uint32 Color::rgb(uint8 r, uint8 g, uint8 b)
{
	return ((Dword)(((Byte)(r) | ((Word)((Byte)(g)) << 8)) | (((Dword)(Byte)(b)) << 16)));
}
