#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

int main(int argc, char *argv[])
{
	int	i;
	std::vector<std::string>input(argv, argv + argc);

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (argc > i)
	{
		std::transform(input[i].begin(), input[i].end(), input[i].begin(), ::toupper);
		std::cout << input[i];
		i++;
	}
	std::cout << std::endl;
	return (0);
}
