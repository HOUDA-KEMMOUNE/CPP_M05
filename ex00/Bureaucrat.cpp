#include "Bureaucrat.hpp" 

Bureaucrat::Bureaucrat( void )
{
	grade = 0;
}

Bureaucrat::Bureaucrat( int grade_ )
{
	grade = grade_;
}

Bureaucrat::Bureaucrat( const Bureaucrat &old )
{
	*this = old;
}

Bureaucrat	&Bureaucrat::operator=( const Bureaucrat &old )
{
	if (this != &old)
		grade = old.grade;
	return (*this);
}

const std::string	Bureaucrat::getName( void ) const
{
	return (name);
}

int					Bureaucrat::getGrade( void ) const
{
	return (grade);
}

std::ostream	&operator<<( std::ostream &out, const Bureaucrat &B )
{
	// <name>, bureaucrat grade <grade>.
	out << B.getName() << ", bureaucrat grade " << B.getGrade() << ".";
	return (out);
}

Bureaucrat::~Bureaucrat( void ) {}
