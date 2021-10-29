#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	std::fstream	dataFile;
	std::string		buffer;
	size_t			temp;
	int				ret;

	if (argc != 4)
	{
		std::cout << "you have to put 3 arguments" << std::endl;
		return (-1);
	}
	std::cout << "|" << argv[1] << "|" <<std::endl;
	dataFile.open(argv[1], std::ios::in);
	if (dataFile.fail())
	{
		std::cout << "Error : open" << std::endl;
		return (-1);
	}
	if (getline(dataFile, buffer))
	{
		while(buffer != "") //????
		{
			temp = buffer.find(argv[2], 0);
			//있으면 변환 처리 필요
			buffer = buffer[temp];
		}
	}
	else
    {
        std::cout << "failed to read file" << std::endl;
    }
	return (0);
}
