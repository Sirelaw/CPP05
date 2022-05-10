#include "inc/Bureaucrat.hpp"
#include "inc/Form.hpp"
#include "inc/ShrubberyCreationForm.hpp"
#include "inc/RobotomyRequestForm.hpp"
#include "inc/PresidentialPardonForm.hpp"
#include "inc/Intern.hpp"

int main()
{
	try
	{
		Intern	one;
		Form	*form;

		form = one.makeForm("shrubbery creatio", "alien");
		form->action();
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}