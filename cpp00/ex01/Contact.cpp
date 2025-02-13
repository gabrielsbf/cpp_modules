#include "Contact.hpp"

void Contact::assert_input(std::string *value, std::string prompt)
{
	*value = "";
	while (value->empty())
	{
		std::cout << prompt;
		std::getline(std::cin, *value);
		if (value->empty())
			std::cout << "Empty Values cannot be accepted, try again!" <<std::endl;
	}
}

void Contact::register_contact(int index)
{
	contact_index = index;

	std::cout << "\n·······Add contact module·······\n" <<std::endl;
	std::cout << "Enter the necessary information!";
	std::cout << "";
	assert_input(&first_name, "\n···················First Name: ");

	assert_input(&last_name, "\n····················Last Name: ");

	assert_input(&nickname, "\n·····················Nickname: ");

	assert_input(&phone_number, "\n·················Phone Number: ");

	assert_input(&darkest_secret, "\n··················Dark Secret: ");

	std::cout << "······Contact Added With Success!······" << std::endl;
}

std::string Contact::len_nbr_valid(int i)
{
	int nbr_len;
	std::stringstream convert;
	std::string text_nbr;
	convert << i;
	text_nbr = convert.str();
	std::string return_value(10 - text_nbr.length(),  ' ');
	return (return_value + text_nbr);
}

std::string Contact::len_valid(std::string *text)
{
	int text_length;

	text_length = (text)->length();
	if ((text)->length() > 10)
	{
		return (text->substr(0, 9) + ".");
	}
	else
	{
		std::string spaces_bfr(10 - text_length, ' ');
		return (spaces_bfr + *text);
	}

}

void Contact::display_contact()
{
	std::cout << "··································" << std::endl;
	std::cout << " Contact Index: " << contact_index << std::endl;
	std::cout << "    First Name: " << first_name << std::endl;
	std::cout << "     Last Name: " << last_name << std::endl;
	std::cout << "      Nickname: " << nickname << std::endl;
	std::cout << "  Phone Number: " << phone_number << std::endl;
	std::cout << "Darkest Secret: " << darkest_secret << std::endl;
	std::cout << "··································" << std::endl;
}

void Contact::list_contact()
{
	std::cout << " " << len_nbr_valid(contact_index) << "|";
	std::cout << " " << len_valid(&first_name) << "|";
	std::cout << " " << len_valid(&last_name) << "|";
	std::cout << " " << len_valid(&nickname) << "|";
	std::cout << " " << len_valid(&phone_number) << "|" << std::endl;

}
