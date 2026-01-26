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
	try
	{
		check_slave(slave, 25);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		check_slave(slave, 5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "<target> has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}
