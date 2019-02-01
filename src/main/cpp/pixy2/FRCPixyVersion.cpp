#include "pixy2/FRCPixyVersion.h"

FRCPixyVersion::FRCPixyVersion(int major, int minor, int build, const std::wstring &type)
{
	fwMajor = major;
	fwMinor = minor;
	fwBuild = build;
	fwType = type;
}

std::wstring FRCPixyVersion::getFirmware()
{
	return fwMajor + L"." + fwMinor + fwBuild;
}

int FRCPixyVersion::getFirmwareMajor()
{
	return fwMajor;
}

int FRCPixyVersion::getFirmwareMinor()
{
	return fwMinor;
}

int FRCPixyVersion::getFirmwareBuild()
{
	return fwBuild;
}

std::wstring FRCPixyVersion::getFirmwareType()
{
	return fwType;
}
