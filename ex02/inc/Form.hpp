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
protected:
	Form();
	Form(std::string name, int sign_grade, int execute_grade);
	Form(const Form& to_copy);
public:
	virtual ~Form();
	Form& operator=(const Form& to_assign);
	std::string		getName() const;
	bool			getStatus() const;
	int				getSignGrade() const;
	int				getExecuteGrade() const;
	void			setStatus(bool status);
	virtual void	beSigned(const Bureaucrat& authority);
	virtual	void	execute(const Bureaucrat& executer) const;
	virtual void	action() const = 0;
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
	class	Unsigned : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream&, const Form&);

#endif