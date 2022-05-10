#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

Bureaucrat::Bureaucrat()
	: _name("default_Bureaucrat"), _grade(150)
{
    
}

Bureaucrat::Bureaucrat(std::string name, int grade)
    : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& to_copy)
	: _name(to_copy._name), _grade(to_copy._grade)
{

}

Bureaucrat::~Bureaucrat()
{
    
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& to_assign)
{
	if (this != &to_assign)
	{
		_grade = to_assign._grade;
	}
	return (*this);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

void	Bureaucrat::promote()
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::demote()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(Form& to_sign)
{
	try
	{
		to_sign.beSigned(*this);
		std::cout << _name << " signed Form: " << to_sign.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't sign Form; " << to_sign.getName() 
					<< "; because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const Form& form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed Form: " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't sign Form; " << form.getName() 
					<< "; because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (out);
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat::GradeTooLowException");
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat::GradeTooHighException");
}