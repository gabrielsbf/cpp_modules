#include "PhoneBook.hpp"

void PhoneBook::add()
{
	contacts[phone_index % 3].register_contact(phone_index + 1);
	phone_index++;

}

void PhoneBook::list_all()
{
	int i;

	i = 0;
	std::cout << "      Index|";
	std::cout << "  Last Name|";
	std::cout << " First Name|";
	std::cout << "   Nickname|";
	std::cout << "      Phone|" << std::endl;
	while (i <= 2 && i < phone_index)
		contacts[i++].list_contact();
}

void PhoneBook::search()
{
	int	i;
	list_all();

	std::cout << "Select the number of the contact index you want to display: ";
	std::cin >> i;
	if (std::cin.fail())
	{
		std::cout << "Input is not valid! Returning to menu!\n" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	std::cin.ignore();

	if (i <= 0)
		std::cout << "Invalid Index! Needs to be bigger than 0" << std::endl;
	else if (phone_index == 0)
		std::cout << "No Contacts yet" << std::endl;
	else if (phone_index < i)
		std::cout << "The contact index you are searching doesn't exist" << std::endl;
	else
		contacts[i - 1].display_contact();
}
