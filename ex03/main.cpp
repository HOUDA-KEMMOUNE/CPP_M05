#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern; 
    AForm* rrf;
    rrf = someRandomIntern.makeForm("shrubbery creation", "Bender"); 

    return 0;
}
