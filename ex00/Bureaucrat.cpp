#include "Bureaucrat.hpp" 

Bureaucrat::Bureaucrat( void )
{
	// grade = 0;
	try
	{
		throw ""; 
	}
	catch(...)
	{
		std::cerr << "The Bureaucrat has no grade :/" << '\n';
	}
}

Bureaucrat::Bureaucrat( int grade_, std::string name_) : name(name_)
{
	try
	{
		check_grade(grade_);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		// return ;
	}
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

void	check_grade( int grade )
{	
	if (grade <= 0)
		throw	Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw	Bureaucrat::GradeTooLowException();
	else
		return ;
}

void	Bureaucrat::increment_grade( void )
{
	if (grade >= 1)	
		grade--;
	try
	{
		check_grade(grade);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Bureaucrat::decrement_grade( void )
{
	if (grade <= 150)	
		grade++;
	try
	{
		check_grade(grade);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

Bureaucrat::~Bureaucrat( void ) {}
