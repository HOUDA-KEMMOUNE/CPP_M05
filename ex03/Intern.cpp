#include "Intern.hpp" 

Intern::Intern( void ) {}

Intern::Intern( const Intern &old ) 
{
	*this = old;
}

Intern	&Intern::operator=( const Intern &old ) 
{
	(void)old;
	return (*this);
}

int		form_fun( std::string name, std::string arr[3] )
{
	int	i = 0;
	while (i < 3)
	{
		if (name == arr[i])
			return (i);
		i++;
	}
	return (1);
}

AForm	*create_PresidentialPardonForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*create_RobotomyRequestForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*create_ShrubberyCreationForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

typedef	AForm *(*Creatos)(const std::string &target); 

AForm	*Intern::makeForm( const std::string &name, const std::string &target )
{
	std::string	shrubbery_name = "shrubbery creation" ;
	std::string	robotomy_name = "robotomy request";
	std::string	pardon_name = "presidential pardon";

	std::string	arr[3] = {shrubbery_name, robotomy_name, pardon_name};
	Creatos		forms[3] = {&create_ShrubberyCreationForm, &create_RobotomyRequestForm, &create_PresidentialPardonForm};

	int			i = 0;
	int			res = 0;

	// res = form_fun(name, arr);
	while (i <= res)
	{
		if (name == arr[i])
		{
			std::cout << "Intern creates " << name << "\n";
			return (forms[i](target));
		}
		i++;
	}
	std::cout << "Intern cannot create " << name << "\n";
	return (NULL);
}

Intern::~Intern( void ) {}
