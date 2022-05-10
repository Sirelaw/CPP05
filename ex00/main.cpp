#include "inc/Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat	one("one", 2);
		Bureaucrat	two(one);
		std::cout << one << std::endl;
		two.promote();
		two.demote();
		two.demote();
		std::cout << two << std::endl;
		Bureaucrat	three("three", 151);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (0);
}