#include "pixy2/Intersection.h"


IntersectionLine::IntersectionLine(int index, int reserved, short angle)
{
	this->index = index;
	this->reserved = reserved;
	this->angle = angle;
}

int IntersectionLine::getIndex()
{
	return index;
}

int IntersectionLine::getReserved()
{
	return reserved;
}

short IntersectionLine::getAngle()
{
	return angle;
}

Intersection::Intersection(int x, int y, int number, int reserved, std::vector<IntersectionLine*> &lines)
{
	this->x = x;
	this->y = y;
	this->number = number;
	this->reserved = reserved;
	this->lines = lines;
}

void Intersection::print()
{
	std::wcout << L"intersection: (" << x << L" " << y << L")" << std::endl;
	for (int i = 0; i < lines.size(); i++)
	{
		IntersectionLine *line = lines[i];
		std::wcout << L" " << i << L" index: " << line->getIndex() << L" angle: " << line->getAngle() << std::endl;
	}
}

int Intersection::getX()
{
	return x;
}

int Intersection::getY()
{
	return y;
}

int Intersection::getNumber()
{
	return number;
}

int Intersection::getReserved()
{
	return reserved;
}

std::vector<IntersectionLine*> Intersection::getLines()
{
	return lines;
}

