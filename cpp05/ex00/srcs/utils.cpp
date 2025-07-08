#include "Bureaucrat.hpp"

std::ostream& operator<<( std::ostream& os, const Bureaucrat & beau)
{
    os << beau.getName() << ", bureaucrat grade " << beau.getGrade() << "." << std::endl;
    return (os);
}