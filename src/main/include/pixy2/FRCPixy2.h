#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <frc/WPILib.h>
#include "pixy2/FRCPixyVersion.h"
#include "pixy2/FRCPixyBlock.h"
#include "stringhelper.h"

class FRCPixy2
{

private:
	frc::SPI *pixy;
	static constexpr int pixySPIClock = 1000000; //2MHZ maximum from Arduino Spec

	//Command Bytes
public:
	static const std::uint8_t PIXYSTARTNOCHECK1 = static_cast<std::uint8_t>(0xae);
	static const std::uint8_t PIXYSTARTNOCHECK2 = static_cast<std::uint8_t>(0xc1);

	static const std::uint8_t PIXY00 = static_cast<std::uint8_t>(0x00);

	static const std::uint8_t PIXY_TYPE_REQUEST_VERSION = static_cast<std::uint8_t>(0x0e);
	static const std::uint8_t PIXY_TYPE_RESPONSE_VERSION = static_cast<std::uint8_t>(0x0f);

	static const std::uint8_t PIXY_CCC_RESPONSE_BLOCKS = static_cast<std::uint8_t>(0x21);
	static const std::uint8_t PIXY_CCC_REQUEST_BLOCKS = static_cast<std::uint8_t>(0x20);

public:
	enum class PixyCommands
	{
		VERSION,
		GETBLOCKS
	};

	//Assume Port 0 if none supplied
public:
	virtual ~FRCPixy2()
	{
		delete pixy;
	}

	FRCPixy2();

	FRCPixy2(frc::SPI::Port port);


private:
	std::vector<std::uint8_t> SendCommand(FRCPixy2::PixyCommands pCommand);


public:
	virtual FRCPixyVersion* CheckVersion();

	virtual FRCPixyBlock* GetBlocks(int sigmap);

	virtual FRCPixyBlock* GetBlocks(int sigmap, int maxBlocks);
	  
	int8_t ChangeProg(const char *prog);
	int8_t SetServos(uint16_t s0, uint16_t s1);
	int8_t SetCameraBrightness(uint8_t brightness);
	int8_t SetLED(uint8_t r, uint8_t g, uint8_t b);
	int8_t SetLamp(uint8_t upper, uint8_t lower);
	int8_t GetResolution();
	int8_t GetFPS();
};
