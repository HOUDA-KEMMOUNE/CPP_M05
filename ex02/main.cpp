#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	try
	{
		srand(time(NULL));
		Bureaucrat	slave(1, "Slave");
		ShrubberyCreationForm	tree("Home");
		RobotomyRequestForm		robot("Forest");
		PresidentialPardonForm	pardon("Galaxy");

		slave.signForm(tree);
		slave.signForm(robot);
		slave.signForm(pardon);
		slave.executeForm(tree);
		slave.executeForm(robot);
		slave.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
