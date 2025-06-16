#include "includes/Harl.hpp"

std::string	convert_lower(std::string level)
{
	int	i = 0;
	std::string newStr = level;

	while (level[i])
	{
		if (std::isalpha(level[i]))
			newStr[i] = std::tolower(level[i]);
		i++;
	}
	return newStr;
}

int main(int argc, char *argv[])
{
	Harl myHarl;
	if (argc != 2)
	{
		std::cerr << "Invalid Number of Arguments" << std::endl;
		return (1);
	}
	myHarl.complain(convert_lower(argv[1]));
}