# ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class	Intern
{
	public:
		Intern( void );
		Intern( const Intern &old );
		Intern	&operator=( const Intern &old );
		~Intern( void );

		AForm	*makeForm( const std::string &name, const std::string &target ); 

};

# endif
