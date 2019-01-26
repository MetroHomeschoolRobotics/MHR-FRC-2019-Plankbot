#include "pixy2/FRCPixy2.h"

FRCPixy2::FRCPixy2() : FRCPixy2(frc::SPI::Port::kMXP)
{
}

FRCPixy2::FRCPixy2(frc::SPI::Port port)
{
	pixySPI = new frc::SPI(port);

	//Setup as per Pixycam SPI spec
	pixySPI->SetClockRate(pixySPIClock); //Set Clockrate, FRC = 500khz default
	pixySPI->SetMSBFirst(); //Most Significant Bit First
	pixySPI->SetClockActiveHigh(); //SPI SCK is low when idle
	pixySPI->SetChipSelectActiveLow(); //Slave Select is LOW

}

FRCPixy2::FRCPixy2(frc::I2C::Port port, int address){
	pixyI2C = new frc::I2C(port, address);

}

std::vector<std::uint8_t> FRCPixy2::SendCommand(FRCPixy2::PixyCommands pCommand)
{
	std::vector<std::uint8_t> sendBytes(17);
	std::vector<std::uint8_t> receiveBytes(17);

	switch (pCommand)
	{
		case FRCPixy2::PixyCommands::VERSION:

			sendBytes[0] = PIXYSTARTNOCHECK1;
			sendBytes[1] = PIXYSTARTNOCHECK2;
			sendBytes[2] = PIXY_TYPE_REQUEST_VERSION;
			sendBytes[3] = PIXY00;
	}

	if (pixySPI != nullptr) {
		pixySPI->Transaction(sendBytes.data(), receiveBytes.data(), sendBytes.size());
	}
	if (pixyI2C != nullptr){
		pixyI2C->Transaction(sendBytes.data(), sendBytes.size(), receiveBytes.data(),  receiveBytes.size());
	}
	for (int i = 0; i < receiveBytes.size(); i++)
	{
		std::wcout << StringHelper::formatSimple(L"%02X ", receiveBytes[i]) << std::endl;
	}

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

	if (response[2] == PIXY_CCC_RESPONSE_BLOCKS)
	{
		int x = ((response[8] & 0xff) << 8) | (response[7] & 0xff);
		int y = ((response[10] & 0xff) << 8) | (response[9] & 0xff);
		int width = ((response[12] & 0xff) << 8) | (response[11] & 0xff);
		int height = ((response[14] & 0xff) << 8) | (response[13] & 0xff);
		int idx = (response[16] & 0xff);
		int age = (response[17] & 0xff);

		return new FRCPixyBlock(x,y,width,height,idx,age);
	}
	else
	{
		return nullptr;
	}
}
