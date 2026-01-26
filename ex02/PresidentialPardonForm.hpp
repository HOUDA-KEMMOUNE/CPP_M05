# ifndef PRESIDENTIALPARSONFORM_HPP
# define PRESIDENTIALPARSONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class	PresidentialPardonForm : public AForm
{
	private:
		std::string	target;

	public:
		PresidentialPardonForm( const std::string &t );
		PresidentialPardonForm( const PresidentialPardonForm &old );
		PresidentialPardonForm	&operator=( const PresidentialPardonForm &old );
		~PresidentialPardonForm( void );

		void		execute( const Bureaucrat &executor ) const;
};


# endif
