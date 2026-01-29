# ifndef FORM_HPP
# define FORM_HPP

// #include "Bureaucrat.hpp"

class	Bureaucrat;

#include <string>
#include <exception>
#include <iostream>


class	Form
{
	private:
		const std::string	name;
		bool				signed_;
		const int			signGrade;
		const int			execGrade;
	
	public:
		Form( std::string n, const int sg, const int eg );
		Form( const Form &old );
		Form	&operator=( const Form &old );
		~Form( void );

		const std::string	&getName( void ) const;
		bool				getSign( void ) const;
		int					getSignGrade( void ) const;
		int					getExecGrade( void ) const;

		void				beSigned( const Bureaucrat &slave );

		class	GradeTooHighException : public std::exception
		{
			const char	*what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			const char	*what() const throw();
		};
};

std::ostream	&operator<<( std::ostream &out, const Form &form );
void			check_grades( int signGrade, int execGrade );
void			compare_status( int bureaucrat_grade, int required_grade );

# endif
