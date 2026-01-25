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

RobotomyRequestForm::~RobotomyRequestForm( void ) {}
