#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( const std::string &t )
	: AForm(72, 45)
{
	target = t;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &old )
{
	*this = old;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=( const RobotomyRequestForm &old )
{
	if (this != &old)
		target = old.target;
	return (*this);
}

void		RobotomyRequestForm::execute( const Bureaucrat &slave )
{
	(void)slave;

	std::cout << "Drilling noises...\n";
	int		r = rand();
	// <target> has been robotomized successfully
	// Robotomy on <target> failed

	if (r / 2 == 0)
		std::cout << target << " has been robotomized successfully\n";
	else
		std::cout << "Robotomy on " << target << " failed\n";
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}
