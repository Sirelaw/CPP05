#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

class Form;

class Intern
{
public:
	Intern();
	Intern(const Intern& to_copy);
	~Intern();
	Intern& operator=(const Intern& to_assign);
	Form*	makeForm(std::string form, std::string target) const;
	class	FormDoesNotExistException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif