# ifndef CONTACT_HPP
#  define CONTACT_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <limits>

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
	Contact(): contact_index(0), first_name(""), last_name(""),
	nickname(""), phone_number(""){}
	~Contact(){}

	void register_contact(int index);
	void display_contact();
	void assert_input(std::string *value, std::string prompt);
	std::string len_valid(std::string *text);
	std::string len_nbr_valid(int i);
	void list_contact();
	int show_index();
};


#endif

