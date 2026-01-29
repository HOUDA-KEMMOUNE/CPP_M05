#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <exception>
#include <iostream>

const char	*AForm::GradeTooHighException::what() const throw()
{
	return "form grade too high :/";
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return "form grade too low :/";
}

void			check_grades( int signGrade, int execGrade )
{
	if (signGrade < 1 || execGrade < 1)
		throw	AForm::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw	AForm::GradeTooLowException();
	else
		return ;
}

void			compare_status( int bureaucrat_grade, int required_grade )
{
	if (bureaucrat_grade > required_grade)
		throw AForm::GradeTooLowException();
	else
		return ;

}

AForm::AForm( std::string n, const int sg, const int eg ) 
		: name(n), signed_(false), signGrade(sg), execGrade(eg)
{
	check_grades(sg, eg);
}

AForm::AForm( const AForm &old )
: name(old.name), signed_(old.signed_), signGrade(old.signGrade), execGrade(old.execGrade)
{
	check_grades(signGrade, execGrade);
}

AForm	&AForm::operator=( const AForm &old )
{
	if (this != &old)
	{
		signed_ = old.signed_;
	}
	return (*this);
}

const std::string	&AForm::getName( void ) const
{
	return (name);
}

bool	AForm::getSign( void ) const
{
	return (signed_);
}

int	AForm::getSignGrade( void ) const
{
	return (signGrade);
}

int	AForm::getExecGrade( void ) const
{
	return (execGrade);
}

void				AForm::beSigned( const Bureaucrat &slave )
{
	if (slave.getGrade() > signGrade)
		throw AForm::GradeTooLowException();
	else
		signed_ = true;
}

void			check_slave( const Bureaucrat &slave, int sg )
{
	if (slave.getGrade() > sg)
		throw	AForm::GradeTooLowException();
	else
		return ;
}

std::ostream	&operator<<( std::ostream &out, const AForm &form )
{
	out << "AForm " << form.getName() << " | signed: ";
	if (form.getSign() == true)
		out << "yes";
	else
		out << "no";
	out << " | grade to sign: " << form.getSignGrade();
	out << " | grade to execute: " << form.getExecGrade();

	return (out);
}

AForm::~AForm( void ) {}
