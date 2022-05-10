#include "../inc/Intern.hpp"
#include "../inc/Form.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

Intern::Intern()
{
	
}

Intern::Intern(const Intern& to_copy)
{
	*this = to_copy;
}

Intern::~Intern()
{
	
}

Intern& Intern::operator=(const Intern& to_assign)
{
	if (this != &to_assign)
	{
		
	}
	return (*this);
}

static Form* makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

static Form*	makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

static Form*	makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form*	Intern::makeForm(std::string form, std::string target) const
{
	Form*		(*temp[3])(std::string);
	std::string form_arr[3];
	int			i;

	form_arr[0] = "presidential pardon";
	form_arr[1] = "robotomy request";
	form_arr[2] = "shrubbery creation";
	temp[0] = makePresidentialPardonForm;
	temp[1] = makeRobotomyRequestForm;
	temp[2] = makeShrubberyCreationForm;
	i = 0;
	while ((i < 3) && (form != form_arr[i]))
		i++;
	if (i == 3)
		throw FormDoesNotExistException();
	return ((temp[i])(target));
}

const char*	Intern::FormDoesNotExistException::what() const throw()
{
	return ("Intern::FormDoesNotExistException");
}