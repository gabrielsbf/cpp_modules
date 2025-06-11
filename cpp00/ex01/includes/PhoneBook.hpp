#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#ifndef CONTACT_LIMIT
#define CONTACT_LIMIT 10
#endif

class PhoneBook
{
private:
	Contact contacts[CONTACT_LIMIT];
	int phone_index;
	int phone_limit;

public:
	PhoneBook();
	~PhoneBook();
	void add(void);
	void search(void);
	void list_all(void);
	int showContactByIndex(int index);
};
#endif
