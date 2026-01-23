#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <exception>
#include <iostream>

const char	*Form::GradeTooHighException::what() const throw()
{
	return "form grade too high :/";
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return "form grade too low :/";
}

void			check_grades( int signGrade, int execGrade )
{
	if (signGrade < 1 || execGrade < 1)
		throw	Form::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw	Form::GradeTooLowException();
	else
		return ;
}

void			compare_status( int bureaucrat_grade, int required_grade )
{
	if (bureaucrat_grade > required_grade)
		throw Form::GradeTooLowException();
	else
		return ;

}

Form::Form( void ) : name(""), signed_(false), signGrade(0), execGrade(0)
{
	try
	{
		throw "";
	}
	catch(...)
	{
		std::cerr << "The form is empty :/" << '\n';
	}
}

Form::Form( std::string n, const int sg, const int eg ) 
		: name(n), signed_(false), signGrade(sg), execGrade(eg)
{
	try
	{
		check_grades(sg, eg);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

Form::Form( const Form &old )
		: name(old.name), signed_(old.signed_), signGrade(old.signGrade), execGrade(old.execGrade)
{
	try
	{
		check_grades(signGrade, execGrade);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

Form	&Form::operator=( const Form &old )
{
	if (this != &old)
	{
		signed_ = old.signed_;
	}
	return (*this);
}

std::string	Form::getName( void ) const
{
	return (name);
}

bool	Form::getSign( void ) const
{
	return (signed_);
}

int	Form::getSignGrade( void ) const
{
	return (signGrade);
}

int	Form::getExecGrade( void ) const
{
	return (execGrade);
}

void				Form::beSigned( const Bureaucrat &slave )
{
	// if (bureaucrat_grade > required_grade)
	// 	throw Form::GradeTooLowException();
	// else
	// 	return ;

	if (slave.getGrade() > signGrade)
		throw Form::GradeTooLowException();
	else
		signed_ = true;
}

std::ostream	&operator<<( std::ostream &out, const Form &form )
{
	out << "Form " << form.getName() << " | signed: ";
	if (form.getSign() == true)
		out << "yes";
	else
		out << "no";
	out << " | grade to sign: " << form.getSignGrade();
	out << " | grade to execute: " << form.getExecGrade();

	return (out);
}

Form::~Form( void ) {}
