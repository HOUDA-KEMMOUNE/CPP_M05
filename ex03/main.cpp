#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* form;
    form = someRandomIntern.makeForm("shrubbery creation", "Bender"); 
    delete form;
    return 0;
}
