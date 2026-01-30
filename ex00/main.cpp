#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	slave2(150, "slave");

		std::cout << slave2 << std::endl;
		slave2.decrement_grade();
		std::cout << slave2 << std::endl;
		slave2.increment_grade();
		std::cout << slave2 << std::endl;
		slave2.decrement_grade();
		std::cout << slave2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
