# ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class	ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;
	
	public:
		ShrubberyCreationForm( const std::string &t );
		ShrubberyCreationForm( const ShrubberyCreationForm &old );
		ShrubberyCreationForm	&operator=( const ShrubberyCreationForm &old );
		~ShrubberyCreationForm( void );
		void		        execute( const Bureaucrat &slave );
		const std::string   &getTarget( void ) const;
};

void		check_file( const std::ofstream &file );
void		draw_tree( std::ofstream &file );

# endif
