#include "inc/Bureaucrat.hpp"
#include "inc/Form.hpp"
#include "inc/ShrubberyCreationForm.hpp"
#include "inc/RobotomyRequestForm.hpp"
#include "inc/PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat	one("one", 15);
		Bureaucrat	two("three", 150);
		Bureaucrat	three(two);
		ShrubberyCreationForm	form_one("Garden");
		RobotomyRequestForm		form_two("Alien");
		PresidentialPardonForm	form_three("Mike");

		std::cout << one << std::endl;
		std::cout << form_one;
		std::cout << form_two;
		std::cout << form_three;
		one.signForm(form_one);
		one.signForm(form_two);
		one.signForm(form_three);
		three.signForm(form_two);
		one.executeForm(form_one);
		one.executeForm(form_two);
		one.executeForm(form_three);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}