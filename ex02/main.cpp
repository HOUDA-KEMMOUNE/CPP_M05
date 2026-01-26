#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"

int	main()
{
	srand(time(NULL));
	Bureaucrat	slave(146, "Slave");
	ShrubberyCreationForm	tree("Home");
	RobotomyRequestForm		robot("Forest");

	tree.execute(slave);
	robot.execute(slave);
	// robot.execute(slave);

}
