#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	std::fstream	dataFile;
	std::fstream	newFile;
	std::string		buffer;
	std::string		name;
	size_t			temp;
	size_t			idx;

	dataFile.exceptions(std::fstream::failbit | std::fstream::badbit);
	if (argc != 4)
	{
		std::cout << "you have to put 3 arguments" << std::endl;
		return (-1);
	}
	try
	{
		dataFile.open(argv[1], std::ios::in);
	}
	catch (std::fstream::failure e)
	{
		std::cout << "Error : open" << std::endl;
		return (-1);
	}
	name = argv[1];
	try
	{
		newFile.open(name + ".replace", std::ios::out);
	}
	catch (std::fstream::failure e)
	{
		std::cout << "Error : open" << std::endl;
		dataFile.close();
		return (-1);
	}
	try
	{
		while (42)
		{
			getline(dataFile, buffer);
			temp = 0;
			idx = 0;
			while (42)
			{
				temp = buffer.find(argv[2], temp);
				if (temp == std::string::npos)
				{
					newFile << buffer << std::endl;
					break ;
				}
				else
				{
					buffer.erase(temp, strlen(argv[2]));
					buffer.insert(temp, argv[3]);
				}
			}
		}
	}
	catch (std::fstream::failure e)
	{
		if(!dataFile.eof())
			std::cout << "Error : getline" << std::endl;
	}
	dataFile.close();
	newFile.close();
	return (0);
}
