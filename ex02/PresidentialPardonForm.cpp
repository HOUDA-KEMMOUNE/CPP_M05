#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( const std::string &t )
: AForm(25, 5)
{
	target = t;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &old )
: AForm(25, 5)
{
	*this = old;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=( const PresidentialPardonForm &old )
{
	if (this != &old)
		target = old.target;
	return (*this);
}

void		PresidentialPardonForm::execute( const Bureaucrat &slave )
{
	if (!this->getSign())
		throw	AForm::GradeTooLowException();
	if (slave.getGrade() > 5)
		throw	AForm::GradeTooLowException();
	std::cout << "<target> has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}
