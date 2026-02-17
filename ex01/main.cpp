#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat  alice(40, "Alice");
        Form        taxForm("Tax Form", 50, 30);

        std::cout << alice << std::endl;
        std::cout << taxForm << std::endl;

        std::cout << "\nAlice tries to sign the form..." << std::endl;
        alice.signForm(taxForm);

        std::cout << taxForm << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}