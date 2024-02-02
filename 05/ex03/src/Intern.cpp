#include<All.h>

Intern::Intern()
{
}

Intern::Intern(class Intern& Copy)
{
	(void)Copy;
}

Intern&	Intern::operator=(class Intern& Copy)
{
	(void)Copy;
	return (*this);
}

Intern::~Intern()
{
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	std::string	type[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm	*A = NULL;

	name == type[0] ? A = new ShrubberyCreationForm(target) :
	name == type[1] ? A = new RobotomyRequestForm(target) :
	name == type[2] ? A = new PresidentialPardonForm(target) :
	A = NULL;

	A == NULL ? std::cout << "Intern cannot create this form" << std::endl :
	std::cout << "Intern creates " << name << std::endl ;
	return (A);
}