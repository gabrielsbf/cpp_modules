#include "PhoneBook.hpp"

void PhoneBook::add()
{
	contacts[phone_index % phone_limit].register_contact(phone_index + 1);
	phone_index++;
	
}

void PhoneBook::list_all()
{
	int i;

	i = 0;
	std::cout << "|     Index|";
	std::cout << "  Last Name|";
	std::cout << " First Name|";
	std::cout << "   Nickname|";
	std::cout << "      Phone|" << std::endl;
	while (i < phone_limit && i < phone_index)
		contacts[i++].list_contact();
}

int PhoneBook::showContactByIndex(int index)
{
	int	i;

	i = 0;
	while (i < phone_limit)
	{
		if (contacts[i].show_index() == index)
		{
			contacts[i].display_contact();
			return i;
		}
		i++;
	}
	std::cout << "Sorry, Couldn't find the index!" << std::endl;
	return (-1);
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
		std::cout << "No Contacts on the PhoneBook yet" << std::endl;
	else if (phone_index < i)
		std::cout << "The contact index you are searching doesn't exist" << std::endl;
	else
		showContactByIndex(i);
}
