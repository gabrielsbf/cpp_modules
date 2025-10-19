#include "Intern.hpp"

Intern::Intern(void):form(NULL)
{
    std::cout << "[INFO]: Instance of Intern is being created | Standard Parameters " << std::endl << std::endl;
}

Intern::Intern(Intern & src): form(NULL)
{
    *this->form = src.getForm();
    std::cout << "[INFO]: Instance of Intern is being created | Copy Method " << std::endl << std::endl;
}

Intern & Intern::operator=(Intern &copy)
{
    std::cout << "[INFO]: Instance of Intern is being created | Assignment Operator " << std::endl << std::endl;
    if (&copy != this)
    {
        *this->form = copy.getForm();
    }
    return *this;
}

Intern::~Intern(void)
{
    std::cout << "[INFO]: Instance of Intern | is being Destroyed" << std::endl << std::endl;
}

AForm & Intern::getForm(void)
{
    // TODO: this function, as the public parameter in the class are not necessary, see what i can do to make a memory address to this variable to access when any recent form is created in the class.
    return *this->form;
}

AForm * Intern::makeForm(std::string form_name, std::string target)
{
    // TODO: Make function pointers in that function | to avoid if-else big statements
    if (form_name == "presidential")
    {
        return new PresidentialPardonForm(target);
    }
    return NULL;
}
