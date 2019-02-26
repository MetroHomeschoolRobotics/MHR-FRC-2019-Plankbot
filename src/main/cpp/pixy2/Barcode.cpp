
#include "pixy2/Barcode.h"

Barcode::Barcode(int x, int y, int flags, int code)
{
	this->x = x;
	this->y = y;
	this->flags = flags;
	this->code = code;
}

void Barcode::print()
{
	std::wcout << toString() << std::endl;
}

std::wstring Barcode::toString()
{
	return L"barcode: (" + std::to_wstring(x) + L" " + std::to_wstring(y) + L") value: " + std::to_wstring(code) + L" flags: " + std::to_wstring(flags);
}

int Barcode::getX()
{
	return x;
}

int Barcode::getY()
{
	return y;
}

int Barcode::getFlags()
{
	return flags;
}

int Barcode::getCode()
{
	return code;
}
