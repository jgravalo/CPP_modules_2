#include<All.h>

RobotomyRequestForm::RobotomyRequestForm() : AForm("confidential Robotomy Request Form", 72, 45)
{
	target = "confidential";
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm(_target + " Robotomy Request Form", 72, 45)
{
	target = _target;
}

RobotomyRequestForm::RobotomyRequestForm(class RobotomyRequestForm& Copy) :
		AForm(Copy.getName(), Copy.getGradetoSign(), Copy.getGradetoExecute())
{
	target = Copy.getTarget();
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(class RobotomyRequestForm& Copy)
{
	target = Copy.getTarget();
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void		RobotomyRequestForm::function() const
{
	std::cout << "RobotomyRequestForm function" << std::endl;
}

std::string	RobotomyRequestForm::getTarget()
{
	return (target);
}
