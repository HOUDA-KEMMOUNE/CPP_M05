# ifndef FORM_HPP
# define FORM_HPP

// #include "Bureaucrat.hpp"

class	Bureaucrat;

#include <string>
#include <exception>
#include <iostream>
#include <cstdlib>

#include <ctime>
#include <cstdlib>

class	AForm
{
	private:
		const std::string	name;
		bool				signed_;
		const int			signGrade;
		const int			execGrade;
	
	public:
		AForm( void );
		AForm( std::string n, const int sg, const int eg );
		AForm( const int sg, const int eg );
		AForm( const AForm &old );
		AForm	&operator=( const AForm &old );
		virtual ~AForm( void );

		const std::string	&getName( void ) const;
		bool				getSign( void ) const;
		int					getSignGrade( void ) const;
		int					getExecGrade( void ) const;

		void				beSigned( const Bureaucrat &slave );
		virtual void		execute( const Bureaucrat &slave ) = 0;

		class	GradeTooHighException : public std::exception
		{
			const char	*what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			const char	*what() const throw();
		};
};

std::ostream	&operator<<( std::ostream &out, const AForm &form );
void			check_grades( int signGrade, int execGrade );
void			compare_status( int bureaucrat_grade, int required_grade );
void			check_slave( const Bureaucrat &slave, int sg );

# endif
