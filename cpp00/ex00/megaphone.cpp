#include <iostream>
#include <string>

void	print_upper(char *argv)
{
	int	i;
	std::string text_new = argv;

	i = 0;
	while (text_new[i] != '\0')
	{
		text_new[i] = ::toupper(text_new[i]);
		i++;
	}
	std::cout << text_new;

}

int		main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (argc > i)
		print_upper(argv[i++]);
	std::cout << std::endl;
	return (0);
}
