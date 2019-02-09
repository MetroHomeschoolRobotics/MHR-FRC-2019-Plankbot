#pragma once


class FRCPixyBlock
{

private:
	int x = 0;
	int y = 0;
	int width = 0;
	int height = 0;
	int age = 0;
	int idxTracking = 0;

public:
	FRCPixyBlock(int x, int y, int width, int height, int age, int idxTracking);

	virtual int getX();

	virtual int getY();

	virtual int getWidth();

	virtual int getHeight();

	virtual int getAge();

	virtual int getIdxTracking();
};
