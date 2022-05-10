#include "../inc/RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	: Form("default_RobotomyRequestForm", 150, 150)
{
	
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: Form(target, 72, 45)
{
	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& to_copy)
	: Form(to_copy.getName(), to_copy.getSignGrade(), to_copy.getExecuteGrade())
{
	setStatus(to_copy.getStatus());
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& to_assign)
{
	if (this != &to_assign)
	{
		setStatus(to_assign.getStatus());
	}
	return (*this);
}

void	RobotomyRequestForm::action() const
{
	std::time_t	rawtime;
	std::tm*	timeinfo;

    std::time(&rawtime);
    timeinfo = std::localtime(&rawtime);
	std::cout << "Whrrrrr!!! Whhhhrrrrrrrrrr! Whhhhhhhrrrrrrrrrrrrrrrr!" << std::endl;
	if (timeinfo->tm_sec % 2)
		std::cout << getName() << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Failed to robotomize " << getName() << std::endl;
}
