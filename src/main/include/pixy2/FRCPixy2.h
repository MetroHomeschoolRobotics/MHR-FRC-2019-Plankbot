#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <frc/WPILib.h>
#include "pixy2/FRCPixyVersion.h"
#include "pixy2/FRCPixyBlock.h"
#include "pixy2/LineFeatures.h"
#include "stringhelper.h"

class FRCPixy2
{

private:
	frc::SPI *pixySPI;
	frc::I2C *pixyI2C;
	static constexpr int pixySPIClock = 1000000; //2MHZ maximum from Arduino Spec
	static constexpr int pixyI2CClock = 1000000; //2MHZ maximum from Arduino Spec

	//Command Bytes
public:
	static const std::uint8_t PIXYSTARTNOCHECK1 = static_cast<std::uint8_t>(0xae);
	static const std::uint8_t PIXYSTARTNOCHECK2 = static_cast<std::uint8_t>(0xc1);

	static const std::uint8_t PIXY00 = static_cast<std::uint8_t>(0x00);
	static const std::uint8_t PIXY02 = static_cast<std::uint8_t>(0x02);

	static const std::uint8_t PIXY_TYPE_REQUEST_VERSION = static_cast<std::uint8_t>(0x0e);
	static const std::uint8_t PIXY_TYPE_RESPONSE_VERSION = static_cast<std::uint8_t>(0x0f);

	static const std::uint8_t PIXY_CCC_RESPONSE_BLOCKS = static_cast<std::uint8_t>(0x21);
	static const std::uint8_t PIXY_CCC_REQUEST_BLOCKS = static_cast<std::uint8_t>(0x20);

	static const std::uint8_t PIXY_TYPE_REQUEST_SET_LAMP = static_cast<std::uint8_t>(0x16);
	static const std::uint8_t PIXY_TYPE_RESPONSE_SET_LAMP = static_cast<std::uint8_t>(0x01);

	static const std::uint8_t LINE_REQUEST_GET_FEATURES = static_cast<std::uint8_t>(0x30);
	static const std::uint8_t LINE_RESPONSE_GET_FEATURES = static_cast<std::uint8_t>(0x31);
	static const std::uint8_t LINE_REQUEST_SET_MODE = static_cast<std::uint8_t>(0x36);
	static const std::uint8_t LINE_REQUEST_SET_VECTOR = static_cast<std::uint8_t>(0x38);
	static const std::uint8_t LINE_REQUEST_SET_NEXT_TURN_ANGLE = static_cast<std::uint8_t>(0x3a);
	static const std::uint8_t LINE_REQUEST_SET_DEFAULT_TURN_ANGLE = static_cast<std::uint8_t>(0x3c);
	static const std::uint8_t LINE_REQUEST_REVERSE_VECTOR = static_cast<std::uint8_t>(0x3e);

	static const std::uint8_t LINE_GET_MAIN_FEATURES = static_cast<std::uint8_t>(0x00);
	static const std::uint8_t LINE_GET_ALL_FEATURES = static_cast<std::uint8_t>(0x01);

	static const std::uint8_t LINE_MODE_TURN_DELAYED = static_cast<std::uint8_t>(0x01);
	static const std::uint8_t LINE_MODE_MANUAL_SELECT_VECTOR = static_cast<std::uint8_t>(0x02);
	static const std::uint8_t LINE_MODE_WHITE_LINE = static_cast<std::uint8_t>(0x80);

	// features
	static const std::uint8_t LINE_VECTOR = static_cast<std::uint8_t>(0x01);
	static const std::uint8_t LINE_INTERSECTION = static_cast<std::uint8_t>(0x02);
	static const std::uint8_t LINE_BARCODE = static_cast<std::uint8_t>(0x04);
	static const std::uint8_t LINE_ALL_FEATURES = (LINE_VECTOR | LINE_INTERSECTION | LINE_BARCODE);

	static const std::uint8_t LINE_FLAG_INVALID = static_cast<std::uint8_t>(0x02);
	static const std::uint8_t LINE_FLAG_INTERSECTION_PRESENT = static_cast<std::uint8_t>(0x04);


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
		delete pixySPI;
		delete pixyI2C;
	}

	FRCPixy2();

	FRCPixy2(frc::SPI::Port port);

	FRCPixy2(frc::I2C::Port port, int address);

public:
	virtual FRCPixyVersion* CheckVersion();

	virtual FRCPixyBlock* GetBlocks(int sigmap);

	virtual FRCPixyBlock* GetBlocks(int sigmap, int maxBlocks);
	int8_t ChangeProg(const char *prog);
	int8_t SetServos(uint16_t s0, uint16_t s1);
	int8_t SetCameraBrightness(uint8_t brightness);
	int8_t SetLED(uint8_t r, uint8_t g, uint8_t b);
	void SetLamp(uint8_t upper, uint8_t lower);
	int8_t GetResolution();
	int8_t GetFPS();

	LineFeatures* GetFeatures(char type, char features, bool wait);

/**
	 * Gets all features from Pixy2
	 * 
	 * @return Pixy2 error code
	 */
	LineFeatures* GetAllFeatures();

	/**
	 * Gets the main features from the Pixy2. This is a more constrained line
	 * tracking algorithm.
	 * 
	 * @return Pixy2 error code
	 */
	LineFeatures* GetMainFeatures();
		/**
	 * Sets Pixy2 line tracking mode
	 * 
	 * @param mode Pixy2 mode
	 * 
	 * @return Pixy2 error code
	 */
	void SetLineMode(int mode);

	/**
	 * Sets turn angle to use for next intersection
	 * 
	 * @param angle Turn angle
	 * 
	 * @return Pixy2 error code
	 */
	void SetNextTurn(short angle);

	/**
	 * Sets default angle to turn to at an intersection
	 * 
	 * @param angle Turn angle
	 * 
	 * @return Pixy2 error code
	 */
	void SetDefaultTurn(short angle);

	/**
	 * Choose vector to track manually
	 * 
	 * @param index Index of vector
	 * 
	 * @return Pixy2 error code
	 */
	void SetVector(int index);

	/**
	 * Requests to invert vector
	 * 
	 * @return Pixy2 error code
	 */
	void ReverseVector();


private:
	std::vector<std::uint8_t> SendCommand(FRCPixy2::PixyCommands pCommand);
	std::vector<std::uint8_t> SendBytes(std::vector<std::uint8_t> sendBytes);

};
