#include"Font.h"

Font::Font()
{
}

Font::Font(const std::string& family, int Weight, bool italic)
{
	strcpy_s(lfFaceName, family.c_str());
	lfWeight = Weight;
	lfItalic = italic;
	lfcolor = Color::Black;	//黑色
}



void Font::setHeight(int height)
{
	lfHeight = height;
}

void Font::setWidth(int width)
{
	lfWidth = width;
}

void Font::setBold(bool enable)
{
	
}

void Font::setItalic(bool enable)
{
	lfItalic = enable;
}

void Font::setWeight(int weight)
{
	lfWeight = weight;
}

void Font::setQuality(int Quality)
{
	lfQuality = lfQuality;
}

void Font::setFamily(const std::string& family)
{
	strcpy_s(lfFaceName, family.c_str());
}

void Font::setColor(const Color& color)
{
	lfcolor = color;
}

const Color& Font::color()
{
	return lfcolor;
}

int Font::Height()
{
	return lfHeight;
}

int Font::Width()
{
	return lfWidth;
}

bool Font::Bold()
{
	return false;
}

bool Font::Italic()
{
	return lfItalic;
}

int Font::Weight()
{
	return lfWeight;
}

int Font::Quality()
{
	return lfQuality;
}

std::string Font::Family()
{
	return lfFaceName;
}
