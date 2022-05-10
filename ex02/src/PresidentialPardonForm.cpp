#include "../inc/PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: Form("default_PresidentialPardonForm", 150, 150)
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: Form(target, 25, 5)
{
	
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& to_copy)
	: Form(to_copy.getName(), to_copy.getSignGrade(), to_copy.getExecuteGrade())
{
	setStatus(to_copy.getStatus());
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& to_assign)
{
	if (this != &to_assign)
	{
		setStatus(to_assign.getStatus());
	}
	return (*this);
}

void	PresidentialPardonForm::action() const
{
	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
