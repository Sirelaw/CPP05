#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& to_copy);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm& to_assign);
	void	action() const;
};

#endif