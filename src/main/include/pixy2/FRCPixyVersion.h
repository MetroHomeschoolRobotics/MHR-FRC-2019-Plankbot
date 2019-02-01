#pragma once

#include <stringhelper.h>

class FRCPixyVersion
{

private:
	int fwMajor = 0;
	int fwMinor = 0;
	int fwBuild = 0;
	std::wstring fwType;


public:
	FRCPixyVersion(int major, int minor, int build, const std::wstring &type);

	virtual std::wstring getFirmware();

	virtual int getFirmwareMajor();

	virtual int getFirmwareMinor();

	virtual int getFirmwareBuild();

	virtual std::wstring getFirmwareType();

};
