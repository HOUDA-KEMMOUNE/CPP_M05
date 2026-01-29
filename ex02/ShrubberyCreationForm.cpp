#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string &t )
: AForm("ShrubberyCreationForm", 25, 5)
{
	target = t;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &old )
: AForm("ShrubberyCreationForm", 25, 5)
{
	*this = old;
}
ShrubberyCreationForm	&ShrubberyCreationForm::operator=( const ShrubberyCreationForm &old )
{
	if (this != &old)
		target = old.target;
	return (*this);
}

const std::string   &ShrubberyCreationForm::getTarget( void ) const
{
	return (target);
}

void		check_file( const std::ofstream &file )
{
	if (file.fail())
		throw "";
	else
		return ;
}

void		draw_tree( std::ofstream &file )
{
	int	i = 0;

	while (i < 5)
	{
		file << "   /\\    \n";
		file << "  /**\\   \n";
		file << " /****\\  \n";
		file << "   ||    \n";

		file << std::endl;
		i++;
	}
}

void		        ShrubberyCreationForm::execute( const Bureaucrat &executor ) const
{
	if (!this->getSign())
		throw	AForm::GradeTooLowException();
	if (executor.getGrade() > 137)
		throw	AForm::GradeTooLowException();
	std::string		file;
	
	file = target + "_shrubbery";
	std::ofstream	file_(file.c_str());
	if (!file_.is_open())
		throw	AForm::GradeTooLowException();
	draw_tree(file_);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}
