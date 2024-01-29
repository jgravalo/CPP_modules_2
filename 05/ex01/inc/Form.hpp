#ifndef FORM_HPP
#define FORM_HPP

#include<All.h>

class Form
{
	private:
		std::string	name;
		bool		signed;
		const int	grade_to_sign;
		const int	grade_to_execute;
	public:
		Form();
		Form(class Form& Copy);
		Form	operator=(class Form& Copy);
		~Form();
		void		beSigned(Bureaucrat& one);
		std::string	getName();
		bool		getStatus();
		void		check()
		class		GradeTooHighException
		{
			public:
				GradeTooHighException();
		};
		class		GradeTooLowException
		{
			public:
				GradeTooLowException();
		};
};

std::ostream&   operator<<(std::ostream& out, class Bureaucrat& Copy);

#endif

Form::Form() : name("confidential"), grade_to_sign(150), grade_to_execute(150)
{
	signed = false;
}

Form::Form(class Form& Copy) : name(Copy.getName()), grade_to_sign(150), grade_to_execute(150)
{
	signed = getStatus();
}

Form::~Form()
{
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

void		Form::beSigned(Bureaucrat& one)
{
	if (one.getGrade() <)
}

std::string	Form::getName()
{
	return (name);
}

bool		Form::getStatus()
{
	return (signed);
}

Form::GradeTooHighException::GradeTooHighException()
{
	throw std::out_of_range("grade too high");
}

Form::GradeTooLowException::GradeTooLowException()
{
	throw std::out_of_range("grade too low");
}

std::ostream&   operator<<(std::ostream& out, class Bureaucrat& Copy)
{
    std::cout << Copy.getName() << ", bureaucrat grade " << Copy.getGrade();
    return (out);
}
