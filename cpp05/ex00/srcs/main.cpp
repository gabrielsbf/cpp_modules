#include "Bureaucrat.hpp"

int main(void)
{
	std::cout<< "---------" << "Creating Alphonse : " << "---------"<< std::endl;
	Bureaucrat defaultConst = Bureaucrat("Alphonse", -1561);
	std::cout << defaultConst;
	std::cout<< "---------" << "Creating Edward : " << "---------"<< std::endl;
	Bureaucrat errorConst = Bureaucrat("Edward", 155);
	std::cout << errorConst;
	std::cout<< "---------" << "Creating Assignment Edward : " << "---------"<< std::endl;
	Bureaucrat assignConst;
	assignConst = errorConst;
	std::cout << assignConst;
	std::cout<< "---------" << "Creating Copy Alphonse : " << "---------"<< std::endl;
	Bureaucrat copyConst(defaultConst);
	std::cout << copyConst;
	std::cout<< "---------" << "Ending sentence" << "---------" <<  std::endl;
}