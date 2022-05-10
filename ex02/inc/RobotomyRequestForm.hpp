#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& to_copy);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm& to_assign);
	void	action() const;
};

#endif