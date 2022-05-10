#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_status;
	const int			_sign_grade;
	const int			_execute_grade;
public:
	Form();
	Form(std::string, int sign_grade, int execute_grade);
	Form(const Form& to_copy);
	~Form();
	Form& operator=(const Form& to_assign);
	std::string	getName() const;
	bool		getStatus() const;
	int			getSignGrade() const;
	int			getExecuteGrade() const;
	void		beSigned(const Bureaucrat&);
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

std::ostream& operator<<(std::ostream&, const Form&);

#endif