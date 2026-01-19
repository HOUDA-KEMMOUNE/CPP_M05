# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <bits/stdc++.h>

class	Bureaucrat
{
	private:
		const std::string	name = "bureaucrat";
		int					grade;

	public:
		Bureaucrat( void );
		Bureaucrat( int grade_ );
		Bureaucrat( const Bureaucrat &old );
		Bureaucrat	&operator=( const Bureaucrat &old );
		const std::string	getName( void ) const;
		int					getGrade( void ) const;
		int	&increment_grade( void );
		int	&decrement_grade( void );
		~Bureaucrat( void );
};

std::ostream	&operator<<( std::ostream &out, const Bureaucrat &B );

# endif
