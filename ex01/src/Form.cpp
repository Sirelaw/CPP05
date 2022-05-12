#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: _name("default_Form"), _status(false), _sign_grade(150), _execute_grade(150)
{

}

Form::Form(std::string name, int sign_grade, int execute_grade)
	: _name(name), _status(false), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
	if (sign_grade < 1 || execute_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (sign_grade > 150 || execute_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Form::Form(const Form& to_copy)
	: _name(to_copy._name), _status(to_copy._status), 
		_sign_grade(to_copy._sign_grade), _execute_grade(to_copy._execute_grade)
{
	
}

Form::~Form()
{
	
}

Form& Form::operator=(const Form& to_assign)
{
	if (this != &to_assign)
	{
		_status = to_assign._status;
		throw std::invalid_argument("can't assign const attributes.");
	}
	return (*this);
}

std::string	Form::getName() const
{
	return (_name);
}

bool		Form::getStatus() const
{
	return (_status);
}

int			Form::getSignGrade() const
{
	return (_sign_grade);
}

int			Form::getExecuteGrade() const
{
	return (_execute_grade);
}

void		Form::beSigned(const Bureaucrat& authority)
{
	if (authority.getGrade() > _sign_grade)
		throw Form::GradeTooHighException();
	_status = true;
}

std::ostream& operator<<(std::ostream& out, const Form& rhs)
{
	out << "Form name: " << rhs.getName() << std::endl;
	out << "Form status: " << (rhs.getStatus() ? "Signed" : "Unsigned") << std::endl;
	out << "Form sign_grade: " << rhs.getSignGrade() << std::endl;
	out << "Form execute_grade: " << rhs.getExecuteGrade() << std::endl;
	return (out);
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Form::GradeTooLowException");
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Form::GradeTooHighException");
}