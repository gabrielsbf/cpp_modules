# ifndef CONTACT_HPP
#  define CONTACT_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <limits>
#include <cstdlib>

class Contact
{
private:
	int contact_index;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
	Contact();
	~Contact();
	void register_contact(int index);
	void display_contact(void);
	void assert_input(std::string *value, std::string prompt);
	std::string len_valid(std::string *text);
	std::string len_nbr_valid(int i);
	void list_contact(void);
	int show_index(void);
};
#endif

