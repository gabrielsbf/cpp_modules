# ifndef PHONEBOOK_HPP
#  define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[3];
	int phone_index;
	int	phone_limit;
	
public:
	PhoneBook();
	~PhoneBook();
	void add(void);
	void search(void);
	void list_all(void);
	int showContactByIndex(int index);
};


#endif
