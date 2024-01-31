#include<All.h>

AForm::AForm() : name("confidential"), grade_to_sign(150), grade_to_execute(150)
{
	sign = false;
}

AForm::AForm(std::string _name, int _grade_to_sign, int _grade_to_execute) : 
		name(_name), grade_to_sign(_grade_to_sign), grade_to_execute(_grade_to_execute)
{
	sign = false;
	check();
}

AForm::AForm(class AForm& Copy) : name(Copy.getName()), grade_to_sign(Copy.getGradetoSign()),
		grade_to_execute(Copy.getGradetoExecute())
{
	sign = getStatus();
}

AForm::~AForm()
{
}

int		AForm::beSigned(Bureaucrat& one)
{
	if (one.getGrade() > grade_to_sign)
	{
		GradeTooLowException();
		return -1;
	}
	sign = true;
	return (0);
}

int		AForm::execute(Bureaucrat const& one) const
{
	if (sign == false)
	{
		FormNotSigned();
		return -1;
	}
	if (one.getGrade() > grade_to_execute)
	{
		GradeTooLowException();
		return -1;
	}
	return 0;
}

std::string	AForm::getName() const
{
	return (name);
}

int			AForm::getGradetoSign()
{
	return (grade_to_sign);
}

int			AForm::getGradetoExecute()
{
	return (grade_to_execute);
}

bool		AForm::getStatus()
{
	return (sign);
}

void		AForm::check()
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

AForm::GradeTooHighException::GradeTooHighException()
{
	throw std::out_of_range("grade too high");
}

AForm::GradeTooLowException::GradeTooLowException()
{
	throw std::out_of_range("grade too low");
}

AForm::FormNotSigned::FormNotSigned()
{
	throw std::out_of_range("form not signed");
}

std::ostream&   operator<<(std::ostream& out, class AForm& Copy)
{
    out << Copy.getName() << ", form for sign with a grade " << Copy.getGradetoSign() << " and execute with a grade " << Copy.getGradetoExecute();
    return (out);
}
