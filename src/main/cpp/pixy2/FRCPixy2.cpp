#include "pixy2/FRCPixy2.h"
#include "pixy2/LineFeatures.h"

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

std::vector<std::uint8_t> FRCPixy2::SendBytes(std::vector<std::uint8_t> sendBytes) {
	std::vector<std::uint8_t> receiveBytes(3);

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
	std::vector<std::uint8_t> receiveBytes(3);

	sendBytes[0] = PIXYSTARTNOCHECK1;
	sendBytes[1] = PIXYSTARTNOCHECK2;
	sendBytes[2] = PIXY_TYPE_REQUEST_SET_LAMP;
	sendBytes[3] = PIXY02;
	sendBytes[4] = upper;
	sendBytes[5] = lower;

	receiveBytes = FRCPixy2::SendBytes(sendBytes);
}

LineFeatures* FRCPixy2::GetAllFeatures()
{
	return GetFeatures(LINE_GET_ALL_FEATURES, LINE_ALL_FEATURES, true);
}

LineFeatures* FRCPixy2::GetMainFeatures()
{
	return GetFeatures(LINE_GET_MAIN_FEATURES, LINE_ALL_FEATURES, true);
}


LineFeatures* FRCPixy2::GetFeatures(char type, char features, bool wait)
{
	char res;
	int offset, fsize, ftype;
	std::vector<std::uint8_t> fdata;
	std::vector<std::uint8_t> sendBytes(17);
	std::vector<std::uint8_t> receiveBytes(3);

	sendBytes[0] = PIXYSTARTNOCHECK1;
	sendBytes[1] = PIXYSTARTNOCHECK2;

	std::vector<Vector*> vectors;
	std::vector<Intersection*> intersections;
	std::vector<Barcode*> barcodes;


	while (true)
	{
		// fill in request data
		sendBytes[2] = LINE_REQUEST_GET_FEATURES;
		sendBytes[3] = type;
		sendBytes[4] = features;

		// send request
		receiveBytes = SendBytes(sendBytes);
		if (receiveBytes.size() == 0)
		{
			if (receiveBytes[1] == LINE_RESPONSE_GET_FEATURES)
			{
				// parse line response
				for (offset = 0, res = 0; receiveBytes.size() > offset; offset += fsize + 2)
				{
					ftype = receiveBytes[offset];
					fsize = receiveBytes[offset + 1];
					// TODO read bytes correctly
					//fdata = std::copy(receiveBytes, offset + 2,receiveBytes.size());
    				for(int i=0; i<10; i=i+2){
       	 				fdata[i] = receiveBytes[i];
					}
					if (ftype == LINE_VECTOR)
					{
						vectors = std::vector<Vector*>(static_cast<int>(std::floor(fdata.size() / 6)));
						for (int i = 0; (i + 1) * 6 <= fdata.size(); i++)
						{
							vectors[i] = new Vector(fdata[(6 * i)] & 0xFF, fdata[(6 * i) + 1] & 0xFF, fdata[(6 * i) + 2] & 0xFF, fdata[(6 * i) + 3] & 0xFF, fdata[(6 * i) + 4] & 0xFF, fdata[(6 * i) + 5] & 0xFF);
						}
						res |= LINE_VECTOR;
					}
					else if (ftype == LINE_INTERSECTION)
					{
						int size = 4 + (4 * Intersection::LINE_MAX_INTERSECTION_LINES);
						intersections = std::vector<Intersection*>(static_cast<int>(std::floor(fdata.size() / (4 + (4 * Intersection::LINE_MAX_INTERSECTION_LINES)))));
						for (int i = 0; (i + 1) * size < fdata.size(); i++)
						{
							std::vector<IntersectionLine*> lines(Intersection::LINE_MAX_INTERSECTION_LINES);
							for (int l = 0; l <= Intersection::LINE_MAX_INTERSECTION_LINES; l++)
							{
								int arr = ((size * i) + 4);
								int index = fdata[arr + (4 * l)];
								int reserved = fdata[arr + (4 * l) + 1];
								short angle = static_cast<short>(((fdata[arr + (4 * l) + 3] & 0xff) << 8) | (fdata[arr + (4 * l) + 2] & 0xff));
								IntersectionLine *intLine = new IntersectionLine(index, reserved, angle);
								lines[l] = intLine;

								delete intLine;
							}
							intersections[i] = new Intersection(fdata[size * i] & 0xFF, fdata[(size * i) + 1] & 0xFF, fdata[(size * i) + 2] & 0xFF, fdata[(size * i) + 3] & 0xFF, lines);
						}
						res |= LINE_INTERSECTION;
					}
					else if (ftype == LINE_BARCODE)
					{
						barcodes = std::vector<Barcode*>(static_cast<int>(std::floor(fdata.size() / 4)));
						for (int i = 0; (i + 1) * 4 <= fdata.size(); i++)
						{
							barcodes[i] = new Barcode(fdata[(4 * i)] & 0xFF, fdata[(4 * i) + 1] & 0xFF, fdata[(4 * i) + 2] & 0xFF, fdata[(4 * i) + 3] & 0xFF);
						}
						res |= LINE_BARCODE;
					}
					else
					{
						break; // parse error
					}
				}
				return new LineFeatures(vectors, intersections, barcodes);
			}
		}
	}
	return new LineFeatures(vectors, intersections, barcodes);
}


void FRCPixy2::SetLineMode(int mode)
{
	int res;
	std::wcout << L"Pixy - set line mode " << mode << std::endl;
	std::vector<std::uint8_t> sendBytes(7);
	std::vector<std::uint8_t> receiveBytes(3);

	sendBytes[0] = PIXYSTARTNOCHECK1;
	sendBytes[1] = PIXYSTARTNOCHECK2;
	sendBytes[2] = LINE_REQUEST_SET_MODE;
	sendBytes[3] = static_cast<char>(mode & 0xff);
	sendBytes[4] = static_cast<char>((mode >> 8) & 0xff);
	sendBytes[5] = static_cast<char>((mode >> 16) & 0xff);
	sendBytes[6] = static_cast<char>((mode >> 24) & 0xff);
	receiveBytes = FRCPixy2::SendBytes(sendBytes);
}

void FRCPixy2::SetNextTurn(short angle)
{
	int res;
	std::wcout << L"Pixy - set next turn " << angle << std::endl;
	std::vector<std::uint8_t> sendBytes(5);
	std::vector<std::uint8_t> receiveBytes(3);

	sendBytes[0] = PIXYSTARTNOCHECK1;
	sendBytes[1] = PIXYSTARTNOCHECK2;
	sendBytes[2] = LINE_REQUEST_SET_NEXT_TURN_ANGLE;
	sendBytes[3] = static_cast<char>(angle & 0xff);
	sendBytes[4] = static_cast<char>((angle >> 8) & 0xff);
	receiveBytes = SendBytes(sendBytes);
}

void FRCPixy2::SetDefaultTurn(short angle)
{
	int res;
	std::wcout << L"Pixy - set default turn " << angle << std::endl;
	std::vector<std::uint8_t> sendBytes(5);
	std::vector<std::uint8_t> receiveBytes(3);

	sendBytes[0] = PIXYSTARTNOCHECK1;
	sendBytes[1] = PIXYSTARTNOCHECK2;
	sendBytes[2] = LINE_REQUEST_SET_DEFAULT_TURN_ANGLE;
	sendBytes[3] = static_cast<char>(angle & 0xff);
	sendBytes[4] = static_cast<char>((angle >> 8) & 0xff);
	receiveBytes = SendBytes(sendBytes);
}

void FRCPixy2::SetVector(int index)
{
	int res;
	std::wcout << L"Pixy - set vector " << index << std::endl;
	std::vector<std::uint8_t> sendBytes(4);
	std::vector<std::uint8_t> receiveBytes(3);

	sendBytes[0] = PIXYSTARTNOCHECK1;
	sendBytes[1] = PIXYSTARTNOCHECK2;
	sendBytes[2] = LINE_REQUEST_SET_VECTOR; 
	sendBytes[3] = static_cast<char>(index);
	receiveBytes = SendBytes(sendBytes);
}

void FRCPixy2::ReverseVector()
{
	int res;
	std::wcout << L"Pixy - reverse vector " << std::endl;
	std::vector<std::uint8_t> sendBytes(3);
	std::vector<std::uint8_t> receiveBytes(3);

	sendBytes[0] = PIXYSTARTNOCHECK1;
	sendBytes[1] = PIXYSTARTNOCHECK2;
	sendBytes[2] = LINE_REQUEST_REVERSE_VECTOR;
	receiveBytes = SendBytes(sendBytes);
}
