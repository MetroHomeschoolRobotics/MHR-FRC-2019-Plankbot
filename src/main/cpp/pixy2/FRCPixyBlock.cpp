#include "pixy2/FRCPixyBlock.h"

FRCPixyBlock::FRCPixyBlock(int x, int y, int width, int height, int age, int idxTracking)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->age = age;
	this->idxTracking = idxTracking;
}

int FRCPixyBlock::getX()
{
	return x;
}

int FRCPixyBlock::getY()
{
	return y;
}

int FRCPixyBlock::getWidth()
{
	return width;
}

int FRCPixyBlock::getHeight()
{
	return height;
}

int FRCPixyBlock::getAge()
{
	return age;
}

int FRCPixyBlock::getIdxTracking()
{
	return idxTracking;
}
