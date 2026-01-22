# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <bits/stdc++.h>

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

		class	GradeTooHighException : public std::exception
		{
			const char *what() const throw()
			{
				return "Your grade is too high :/";
			}
		};

		class	GradeTooLowException : public std::exception
		{
			const char *what() const throw()
			{
				return "Your grade is too low :/";
			}
		};

		~Bureaucrat( void );
};

void	check_grade( int grade );

std::ostream	&operator<<( std::ostream &out, const Bureaucrat &B );

# endif
