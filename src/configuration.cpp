#include "configuration.hpp"
#include <iostream>

void load_configuration(const char file[])
{
	FILE* input = fopen(file, "rb");

	if(!input)
	{
		std::cerr << "Failed to open " << file << " (" << errno << ")" << std::endl;
		return;
	}

	fclose(input);
}