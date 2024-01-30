#include<All.h>

Form::Form() : name("confidential"), grade_to_sign(150), grade_to_execute(150)
{
	sign = false;
}

Form::Form(std::string _name, int _grade_to_sign, int _grade_to_execute) : 
		name(_name), grade_to_sign(_grade_to_sign), grade_to_execute(_grade_to_execute)
{
	sign = false;
	check();
}

Form::Form(class Form& Copy) : name(Copy.getName()), grade_to_sign(Copy.getGradetoSign()),
		grade_to_execute(Copy.getGradetoExecute())
{
	sign = getStatus();
}

Form::~Form()
{
}

int		Form::beSigned(Bureaucrat& one)
{
	if (one.getGrade() > grade_to_sign)
	{
		GradeTooLowException();
		return -1;
	}
	sign = true;
	return (0);
}

std::string	Form::getName()
{
	return (name);
}

int			Form::getGradetoSign()
{
	return (grade_to_sign);
}

int			Form::getGradetoExecute()
{
	return (grade_to_execute);
}

bool		Form::getStatus()
{
	return (sign);
}

void		Form::check()
{
	if (grade_to_sign > 150)
		GradeTooLowException();
	else if (grade_to_sign < 1)
		GradeTooHighException();
	else if (grade_to_execute > 150)
		GradeTooLowException();
	else if (grade_to_execute < 1)
		GradeTooHighException();
}

Form::GradeTooHighException::GradeTooHighException()
{
	throw std::out_of_range("grade too high");
}

Form::GradeTooLowException::GradeTooLowException()
{
	throw std::out_of_range("grade too low");
}

std::ostream&   operator<<(std::ostream& out, class Form& Copy)
{
    out << Copy.getName() << ", form for sign with a grade " << Copy.getGradetoSign() << " and execute with a grade " << Copy.getGradetoExecute();
    return (out);
}
