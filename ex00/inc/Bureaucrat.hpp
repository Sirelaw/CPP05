#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat
{
private:
	std::string const	_name;
	int					_grade;
public:
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
	Bureaucrat(std::string, int);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& to_copy);
	Bureaucrat& operator=(const Bureaucrat& to_assign);
	int getGrade() const;
	std::string getName() const;
	void	promote();
	void	demote();
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif