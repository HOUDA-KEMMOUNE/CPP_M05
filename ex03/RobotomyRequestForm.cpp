#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"


RobotomyRequestForm::RobotomyRequestForm( const std::string &t )
	: AForm(72, 45)
{
	target = t;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &old )
: AForm(72, 45)
{
	*this = old;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=( const RobotomyRequestForm &old )
{
	if (this != &old)
		target = old.target;
	return (*this);
}

void		RobotomyRequestForm::execute( const Bureaucrat &executor ) const
{
	if (!this->getSign())
		throw	AForm::GradeTooLowException();
	if (executor.getGrade() > 45)
		throw	AForm::GradeTooLowException();

	std::cout << "Drilling noises...\n";
	int		r = rand();
	if (r % 2 == 0)
		std::cout << target << " has been robotomized successfully\n";
	else
		std::cout << "Robotomy on " << target << " failed\n";
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}
