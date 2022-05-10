#include <fstream>
#include "../inc/ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("default_ShrubberyCreationForm", 150, 150)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: Form(target, 145, 137)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& to_copy)
	: Form(to_copy.getName(), to_copy.getSignGrade(), to_copy.getExecuteGrade())
{
	setStatus(to_copy.getStatus());
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& to_assign)
{
	if (this != &to_assign)
	{
		setStatus(to_assign.getStatus());
	}
	return (*this);
}

void	ShrubberyCreationForm::action() const
{
	std::ofstream	file;

	
	try
	{
		file.open(getName(), std::ios::out | std::ios::trunc);
		file <<"           ^           "<< std::endl;
		file <<"          ^^^          "<< std::endl;
		file <<"         ^^^^^         "<< std::endl;
		file <<"        ^^^^^^^        "<< std::endl;
		file <<"       ^^^^^^^^^       "<< std::endl;
		file <<"      ^^^^^^^^^^^      "<< std::endl;
		file <<"          |  |         "<< std::endl;
		file <<"     ^^^^^^^^^^^^^     "<< std::endl;
		file <<"    ^^^^^^^^^^^^^^^    "<< std::endl;
		file <<"   ^^^^^^^^^^^^^^^^^   "<< std::endl;
		file <<"         |   |         "<< std::endl;
		file <<"  ^^^^^^^^^^^^^^^^^^^  "<< std::endl;
		file <<" ^^^^^^^^^^^^^^^^^^^^^ "<< std::endl;
		file <<"        |     |        "<< std::endl;
		file.close();
	}
	catch (const std::ofstream::failure& e)
	{
		std::cout << "Exception opening/writing file";
		throw ;
	}
}
