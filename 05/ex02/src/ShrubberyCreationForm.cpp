#include<All.h>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Confidential Shrubbery Creation Form", 145, 137)
{
	target = "confidential";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm(_target + " Shrubbery Creation Form", 145, 137)
{
	target = _target;
}

ShrubberyCreationForm::ShrubberyCreationForm(class ShrubberyCreationForm& Copy) :
		AForm(Copy.getName(), Copy.getGradetoSign(), Copy.getGradetoExecute())
{
	target = Copy.getTarget();
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(class ShrubberyCreationForm& Copy)
{
	target = Copy.getTarget();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void		ShrubberyCreationForm::function() const
{
	std::cout << "ShrubberyCreationForm function" << std::endl;
	//std::ofstream	infile;
	std::ofstream	outfile;
/* 
	infile.open(".ascii_tree");
	if (infile.is_open())
	{
        std::cout << "Error to open infile" << std::endl;
        return ;
    }*/
	outfile.open(target + "_shrubbery");
	if (!outfile)
    {
        std::cout << "Error to open outfile" << std::endl;
        return ;
    }
	outfile << ASCII_TREE << std::endl;
}

std::string	ShrubberyCreationForm::getTarget()
{
	return (target);
}
