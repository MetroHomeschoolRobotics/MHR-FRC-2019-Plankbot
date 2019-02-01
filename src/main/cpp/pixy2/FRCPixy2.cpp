#include "pixy2/FRCPixy2.h"

FRCPixy2::FRCPixy2() : FRCPixy2(frc::SPI::Port::kMXP)
{
}

FRCPixy2::FRCPixy2(frc::SPI::Port port)
{
	pixySPI = new frc::SPI(port);

	//Setup as per Pixycam SPI spec
	pixySPI->SetClockRate(pixySPIClock); //Set Clockrate, FRC = 500khz default
	pixySPI->SetLSBFirst(); //Most Least Bit First
	pixySPI->SetClockActiveHigh(); //SPI SCK is low when idle
	pixySPI->SetChipSelectActiveLow(); //Slave Select is LOW

}

FRCPixy2::FRCPixy2(frc::I2C::Port port, int address){
	pixyI2C = new frc::I2C(port, address);

}

std::vector<std::uint8_t> FRCPixy2::SendCommand(FRCPixy2::PixyCommands pCommand)
{
	std::vector<std::uint8_t> sendBytes(17);
	std::vector<std::uint8_t> receiveBytes(34);

	switch (pCommand)
	{
		case FRCPixy2::PixyCommands::VERSION:
			std::wcout << L"Pixy - GetVersion"<< std::endl;

			sendBytes[0] = PIXYSTARTNOCHECK1;
			sendBytes[1] = PIXYSTARTNOCHECK2;
			sendBytes[2] = PIXY_TYPE_REQUEST_VERSION;
			sendBytes[3] = PIXY00;
		case FRCPixy2::PixyCommands::GETBLOCKS:
			std::wcout << L"Pixy - GetBlocks"<< std::endl;

			sendBytes[0] = PIXYSTARTNOCHECK1;
			sendBytes[1] = PIXYSTARTNOCHECK2;
			sendBytes[2] = PIXY_CCC_REQUEST_BLOCKS;
			sendBytes[3] = PIXY02;
			sendBytes[4] = 0x01;
			sendBytes[5] = 0x01;
	}

	if (pixySPI != nullptr) {
		std::wcout << L"Pixy - SPI"<< std::endl;
		pixySPI->Transaction(sendBytes.data(), receiveBytes.data(), sendBytes.size());
	}
	if (pixyI2C != nullptr){
		std::wcout << L"Pixy - I2C" << std::endl;
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

	std::wcout << L"Pixy - response type: " << response[16] << std::endl;

	if (response[16] == PIXY_CCC_RESPONSE_BLOCKS && response[0] > 0)
	{
		std::wcout << L"Pixy - Block Found" << std::endl;
		int x = ((response[5] & 0xff) << 8) | (response[6] & 0xff);
		int y = ((response[7] & 0xff) << 8) | (response[8] & 0xff);
		int width = ((response[9] & 0xff) << 8) | (response[10] & 0xff);
		int height = ((response[11] & 0xff) << 8) | (response[12] & 0xff);
		int idx = (response[13] & 0xff);
		int age = (response[14] & 0xff);

		return new FRCPixyBlock(x,y,width,height,idx,age);
	}
	else
	{
		return nullptr;
	}
}
