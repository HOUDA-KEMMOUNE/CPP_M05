# ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
	private:
		std::string	target;
	
	public:
		RobotomyRequestForm( const std::string &t );
		RobotomyRequestForm( const RobotomyRequestForm &old );
		RobotomyRequestForm	&operator=( const RobotomyRequestForm &old );
		~RobotomyRequestForm( void );

		// const std::string	
};

# endif
