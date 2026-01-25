# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "AForm.hpp"

class	Bureaucrat
{
	private:
		const std::string	name;
		int					grade;

	public:
		Bureaucrat( void );
		Bureaucrat( int grade_, std::string name_);
		Bureaucrat( const Bureaucrat &old );
		Bureaucrat	&operator=( const Bureaucrat &old );
		const std::string	getName( void ) const;
		int					getGrade( void ) const;
		void	increment_grade( void );
		void	decrement_grade( void );

		void	signForm( AForm &form );

		class	GradeTooHighException : public std::exception
		{
			const char *what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};

		~Bureaucrat( void );
};

void	check_grade( int grade );

std::ostream	&operator<<( std::ostream &out, const Bureaucrat &B );

# endif
