#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	slave1;
	Bureaucrat	slave2(150, "slave");

	std::cout << slave2 << std::endl;
	slave2.decrement_grade();
	std::cout << slave2 << std::endl;
	slave2.increment_grade();
	std::cout << slave2 << std::endl;
	slave2.decrement_grade();
	std::cout << slave2 << std::endl;
	for(int i = 0; i < 150; i++)
		slave2.increment_grade();
	std::cout << slave2 << std::endl;
		slave2.increment_grade();
	std::cout << slave2 << std::endl;

}
