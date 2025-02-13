#include "PhoneBook.hpp"

int	main()
{
	PhoneBook phone;
	std::string user_input = "";

	std::cout << "Welcome to your phonebook" << std::endl;
	while (user_input != "EXIT")
	{
		std::cout << "Three possible commands:\n"<< std::endl;
		std::cout << "ADD: adds new contact"<< std::endl;
		std::cout << "SEARCH: display a list with indexes that you choose for more details" << std::endl;
		std::cout << "EXIT: you exit the program\n" << std::endl;
		std::cout << "Enter command: ";
		std::cin >> user_input;
		std::cin.ignore();
		if (user_input == "ADD")
			phone.add();
		else if (user_input == "SEARCH")
			phone.search();
		else if (user_input != "EXIT")
			std::cout << "···Command doesn't exist, going back to main menu···\n\n";
	}
		return (0);
}
