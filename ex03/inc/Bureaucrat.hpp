#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Form;

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;  
public:
	Bureaucrat();
	Bureaucrat(std::string, int);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& to_copy);
	Bureaucrat& operator=(const Bureaucrat& to_assign);
	int 		getGrade() const;
	std::string getName() const;
	void		promote();
	void		demote();
	void		signForm(Form&);
	void		executeForm(const Form& form);
	class	GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class	GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif
