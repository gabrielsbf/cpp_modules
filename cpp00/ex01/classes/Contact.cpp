#include "Contact.hpp"
#include "utils.hpp"
Contact::Contact(): contact_index(0), first_name(""), last_name(""),
	nickname(""), phone_number(""){}

Contact::~Contact(){}

void Contact::assert_input(std::string *value, std::string prompt)
{
	*value = "";
	while (value->empty())
	{
		std::cout << prompt;
		std::getline(std::cin, *value);
		verifyKeyError();
		if (value->empty())
			std::cout << "Empty Values cannot be accepted, try again!" <<std::endl;
	}
}

void Contact::register_contact(int index)
{
	this->contact_index = index;

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

int Contact::show_index(void)
{
	return (contact_index);
}


void Contact::display_contact(void)
{
	std::cout << "··································" << std::endl;
	std::cout << " Contact Index: " << this->contact_index << std::endl;
	std::cout << "    First Name: " << this->first_name << std::endl;
	std::cout << "     Last Name: " << this->last_name << std::endl;
	std::cout << "      Nickname: " << this->nickname << std::endl;
	std::cout << "  Phone Number: " << this->phone_number << std::endl;
	std::cout << "Darkest Secret: " << this->darkest_secret << std::endl;
	std::cout << "··································" << std::endl;
}

void Contact::list_contact(void)
{
	std::cout << "|" << len_nbr_valid(this->contact_index) << "|";
	std::cout << " " << len_valid(&this->first_name) << "|";
	std::cout << " " << len_valid(&this->last_name) << "|";
	std::cout << " " << len_valid(&this->nickname) << "|";
	std::cout << " " << len_valid(&this->phone_number) << "|" << std::endl;
	std::cout<< "------------------------------------------------------------"<< std::endl;
}
