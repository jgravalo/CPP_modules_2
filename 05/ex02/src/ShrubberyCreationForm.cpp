#include<All.h>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("confidential", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(class ShrubberyCreationForm& Copy) :
		AForm(Copy.getName(), Copy.getGradetoSign(), Copy.getGradetoExecute())
{
	(void)Copy;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(class ShrubberyCreationForm& Copy)
{
	(void)Copy;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

/*
void		AForm::function() const
{
	std::cout << "adios" << std::endl;
}
*/