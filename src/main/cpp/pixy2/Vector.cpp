#include "pixy2/Vector.h"

Vector::Vector(int x0, int y0, int x1, int y1, int index, int flags)
{
	this->x0 = x0;
	this->y0 = y0;
	this->x1 = x1;
	this->y1 = y1;
	this->index = index;
	this->flags = flags;
}

void Vector::print()
{
	std::wcout << toString() << std::endl;
}

std::wstring Vector::toString()
{
	return L"vector: (" + std::to_wstring(x0) + L" " + std::to_wstring(y0) + L") (" + std::to_wstring(x1) + L" " + std::to_wstring(y1) + L") index: " + std::to_wstring(index) + L" flags: " + std::to_wstring(flags);
}

int Vector::getX0()
{
	return x0;
}

int Vector::getY0()
{
	return y0;
}

int Vector::getX1()
{
	return x1;
}

int Vector::getY1()
{
	return y1;
}

int Vector::getIndex()
{
	return index;
}

int Vector::getFlags()
{
	return flags;
}
