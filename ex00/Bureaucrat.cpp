#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Your grade is too high :/";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Your grade is too low :/";
}

Bureaucrat::Bureaucrat( int grade_, std::string name_) : name(name_)
{
	if (grade_ <= 0)
	{
		throw	Bureaucrat::GradeTooHighException();
	}
	else if (grade_ > 150)
	{
		throw	Bureaucrat::GradeTooLowException();
	}
	grade = grade_;
}

Bureaucrat::Bureaucrat( const Bureaucrat &old ) : name(old.name), grade(old.grade)
{
	if (old.grade <= 0)
		throw	Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw	Bureaucrat::GradeTooLowException();
}

Bureaucrat	&Bureaucrat::operator=( const Bureaucrat &old )
{
	if (this != &old)
	{
		if (old.grade <= 0)
			throw	Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw	Bureaucrat::GradeTooLowException();
		grade = old.grade;
	}
	
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
	check_grade(grade);
}

void	Bureaucrat::decrement_grade( void )
{
	if (grade <= 150)
		grade++;
	check_grade(grade);
}

Bureaucrat::~Bureaucrat( void ) {}
