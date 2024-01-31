#include<All.h>

PresidentialPardonForm::PresidentialPardonForm() : AForm("Confidential Presidential Pardon Form", 25, 5)
{
	target = "Confidential";
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm(_target + " Presidential Pardon Form", 25, 5)
{
	target = _target;
}

PresidentialPardonForm::PresidentialPardonForm(class PresidentialPardonForm& Copy) :
		AForm(Copy.getName(), Copy.getGradetoSign(), Copy.getGradetoExecute())
{
	target = Copy.getTarget();
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(class PresidentialPardonForm& Copy)
{
	target = Copy.getTarget();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void		PresidentialPardonForm::function() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string	PresidentialPardonForm::getTarget()
{
	return (target);
}
