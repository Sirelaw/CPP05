#include "inc/Bureaucrat.hpp"
#include "inc/Form.hpp"

int main()
{
	try
	{
		Bureaucrat	one("one", 2);
		Form		form_one("declare", 4, 3);
		Form		form_two("surrender", 1, 10);
		std::cout << one << std::endl;
		Bureaucrat	three("three", 150);
		one.signForm(form_one);
		one.signForm(form_two);
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (0);
}