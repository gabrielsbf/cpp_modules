# ifndef PHONEBOOK_HPP
#  define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[3];
	int phone_index;
	int	phone_limit;
	bool filled;
	
	/* data */
public:
	PhoneBook():phone_index(0), 
				phone_limit(sizeof(contacts) / sizeof(contacts[0])), 
				filled(true) {};
	~PhoneBook(){};

	void add();
	void search();
	void list_all();
	int showContactByIndex(int index);
};


#endif
