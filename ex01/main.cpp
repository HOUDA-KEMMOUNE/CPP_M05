#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "===== TEST 1: Create valid Bureaucrat and Form =====" << std::endl;
    try
    {
        Bureaucrat alice(40, "Alice");
        Form taxForm("Tax Form", 50, 30);

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

    std::cout << "\n===== TEST 2: Grade too low to sign =====" << std::endl;
    try
    {
        Bureaucrat bob(120, "Bob");
        Form secretForm("Secret Form", 50, 10);

        std::cout << bob << std::endl;
        std::cout << secretForm << std::endl;

        std::cout << "\nBob tries to sign the form..." << std::endl;
        bob.signForm(secretForm);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 3: Invalid Form creation (grade too high) =====" << std::endl;
    try
    {
        Form invalidForm("Invalid", 0, 10);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 4: Invalid Form creation (grade too low) =====" << std::endl;
    try
    {
        Form invalidForm("Invalid", 200, 10);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 5: Copy constructor & assignment =====" << std::endl;
    try
    {
        Bureaucrat boss(1, "Boss");
        Form original("Original Form", 10, 5);

        boss.signForm(original);

        Form copy(original);
        Form assigned = original;

        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy:     " << copy << std::endl;
        std::cout << "Assigned: " << assigned << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}