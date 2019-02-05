#include "pixy2/FRCPixy2.h"

FRCPixy2::FRCPixy2() : FRCPixy2(frc::SPI::Port::kMXP)
{
}

FRCPixy2::FRCPixy2(frc::SPI::Port port)
{
	std::wcout << L"Pixy - Init SPI " << port << std::endl;
	pixySPI = new frc::SPI(port);
	pixyI2C = nullptr;

	//Setup as per Pixycam SPI spec
	pixySPI->SetClockRate(pixySPIClock); //Set Clockrate, FRC = 500khz default
	pixySPI->SetMSBFirst(); //Most Least Bit First
	pixySPI->SetClockActiveHigh(); //SPI SCK is low when idle
	pixySPI->SetChipSelectActiveLow(); //Slave Select is LOW

}

FRCPixy2::FRCPixy2(frc::I2C::Port port, int address){
	std::wcout << L"Pixy - Init I2C " << port << " (" << address<< ")" << std::endl;
	pixyI2C = new frc::I2C(port, address);
	

	pixySPI = nullptr;
}

std::vector<std::uint8_t> FRCPixy2::SendCommand(FRCPixy2::PixyCommands pCommand)
{
	std::vector<std::uint8_t> sendBytes(17);
	std::vector<std::uint8_t> receiveBytes(34);

	switch (pCommand)
	{
		case FRCPixy2::PixyCommands::VERSION:

			sendBytes[0] = PIXYSTARTNOCHECK1;
			sendBytes[1] = PIXYSTARTNOCHECK2;
			sendBytes[2] = PIXY_TYPE_REQUEST_VERSION;
			sendBytes[3] = PIXY00;
		case FRCPixy2::PixyCommands::GETBLOCKS:

			sendBytes[0] = PIXYSTARTNOCHECK1;
			sendBytes[1] = PIXYSTARTNOCHECK2;
			sendBytes[2] = PIXY_CCC_REQUEST_BLOCKS;
			sendBytes[3] = PIXY02;
			sendBytes[4] = 0x01;
			sendBytes[5] = 0x01;
	}

	if (pixySPI != nullptr) {
		std::wcout << L"Pixy - SPI - ";
		pixySPI->Transaction(sendBytes.data(), receiveBytes.data(), sendBytes.size());
	} else if (pixyI2C != nullptr){
		std::wcout << L"Pixy - I2C - ";
		pixyI2C->Transaction(sendBytes.data(), sendBytes.size(), receiveBytes.data(),  receiveBytes.size());
	}
	for (int i = 0; i < receiveBytes.size(); i++)
	{
		std::wcout << receiveBytes[i] << ",";
	}

	std::wcout << std::endl;
	return receiveBytes;
}

FRCPixyVersion* FRCPixy2::CheckVersion()
{
	std::wcout << L"Pixy - check version" << std::endl;

	std::vector<std::uint8_t> response = SendCommand(PixyCommands::VERSION);

	if (response[2] == PIXY_TYPE_RESPONSE_VERSION)
	{
		int major = response[8] & 0xff;
		int minor = response[9] & 0xff;
		int build = (response[11] & 0xff) + (response[10] & 0xff);
		std::wstring fwType = L"";

		for (int i = 0; i < 10; i++)
		{
			fwType = fwType + StringHelper::toString(static_cast<wchar_t>(response[10 + i] & 0xff));
		}

		return new FRCPixyVersion(major, minor, build, fwType);
	}
	else
	{
			return nullptr; //Noresponse
	}

}

FRCPixyBlock* FRCPixy2::GetBlocks(int sigmap)
{
	return GetBlocks(sigmap, 2);
}

FRCPixyBlock* FRCPixy2::GetBlocks(int sigmap, int maxBlocks)
{
	std::wcout << L"Pixy - get blocks" << std::endl;

	std::vector<std::uint8_t> response = SendCommand(PixyCommands::GETBLOCKS);

	int size = response.size();

	int blockShift = 0;
	int responseType = 0;
	bool foundBlock = false;
	if (pixySPI != nullptr) {
		responseType = response[16];
		foundBlock = response[0] > 0;
	} else if (pixyI2C != nullptr) {
		responseType = response[2];
		foundBlock = response[3] > 0;
		blockShift = 3;
	}

	std::wcout << L"Pixy - response type: " << responseType << std::endl;

	if (responseType == PIXY_CCC_RESPONSE_BLOCKS && foundBlock)
	{
		std::wcout << L"Pixy - Block Found" << std::endl;
		int x = ((response[5 + blockShift] & 0xff) << 8) | (response[6 + blockShift] & 0xff);
		int y = ((response[7 + blockShift] & 0xff) << 8) | (response[8 + blockShift] & 0xff);
		int width = ((response[9 + blockShift] & 0xff) << 8) | (response[10 + blockShift] & 0xff);
		int height = ((response[11 + blockShift] & 0xff) << 8) | (response[12 + blockShift] & 0xff);
		int idx = (response[13 + blockShift] & 0xff);
		int age = (response[14 + blockShift] & 0xff);

		return new FRCPixyBlock(x,y,width,height,idx,age);
	}
	else
	{
		return nullptr;
	}
}

void FRCPixy2::SetLamp(uint8_t upper, uint8_t lower){
	std::wcout << L"Pixy - set lamp" << std::endl;
	std::vector<std::uint8_t> sendBytes(17);
	std::vector<std::uint8_t> receiveBytes(34);

	sendBytes[0] = PIXYSTARTNOCHECK1;
	sendBytes[1] = PIXYSTARTNOCHECK2;
	sendBytes[2] = PIXY_TYPE_REQUEST_SET_LAMP;
	sendBytes[3] = PIXY02;
	sendBytes[4] = upper;
	sendBytes[5] = lower;

	if (pixySPI != nullptr) {
		std::wcout << L"Pixy - SPI - ";
		pixySPI->Transaction(sendBytes.data(), receiveBytes.data(), sendBytes.size());
	} else if (pixyI2C != nullptr){
		std::wcout << L"Pixy - I2C - ";
		pixyI2C->Transaction(sendBytes.data(), sendBytes.size(), receiveBytes.data(),  receiveBytes.size());
	
	for (int i = 0; i < receiveBytes.size(); i++)
	{
		std::wcout << receiveBytes[i] << ",";
	}

	std::wcout << std::endl;
	}
}

