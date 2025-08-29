#include "Bureaucrat.hpp"

int main(void)
{
    try 
    {
        const Bureaucrat & buone = Bureaucrat("Claudin", 150);
        std::cout << buone;
        (void)buone;
        const Bureaucrat & errone = Bureaucrat("Claudin", -1);
        std::cout << "Ending sentence" << std::endl;
        (void)errone;
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
}