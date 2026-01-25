#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string &t )
	: AForm(145, 137)
{
	target = t;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &old )
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
	file << "   /\    \n";
	file << "  /**\   \n";
	file << " /****\  \n";
	file << "   ||    \n";

	std::cout << std::endl;

	file << "   /\    \n";
	file << "  /**\   \n";
	file << " /****\  \n";
	file << "   ||    \n";

	std::cout << std::endl;

	file << "   /\    \n";
	file << "  /**\   \n";
	file << " /****\  \n";
	file << "   ||    \n";

	std::cout << std::endl;

	file << "   /\    \n";
	file << "  /**\   \n";
	file << " /****\  \n";
	file << "   ||    \n";

	std::cout << std::endl;
}

void		        ShrubberyCreationForm::execute( const Bureaucrat &slave )
{
	std::string		file;
	
	file = target + "_shrubbery ";
	std::ofstream	file_(file.c_str());
	try
	{
		check_file(file_);
	}
	catch(...)
	{
		std::cerr << file << ": does not exist :/\n";
	}
	draw_tree(file_);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}
