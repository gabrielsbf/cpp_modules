# ifndef PHONEBOOK_HPP
#  define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	std::array<Contact, 3> contacts;
	int phone_index = 0;
	int	filled = false;
	/* data */
public:
	PhoneBook(){};
	~PhoneBook(){};

	void add();
	void search();
	void list_all();
};


#endif
