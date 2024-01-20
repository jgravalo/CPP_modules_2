#include<Bureaucrat.hpp>

Bureaucrat::Bureaucrat() : name("confidential")
{
    grade = 150;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name)
{
    grade = _grade;
	check();
}

Bureaucrat::Bureaucrat(class Bureaucrat& Copy) : name(Copy.getName())
{
    grade = Copy.getGrade();
}

Bureaucrat& Bureaucrat::operator=(class Bureaucrat& Copy)
{
    grade = Copy.getGrade();
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName()
{
    return(name);
}

int         Bureaucrat::getGrade()
{
    return (grade);
}
/* 
void        Bureaucrat::setName(std::string _name)
{
    name = _name;
}
 */
void        Bureaucrat::setGrade(int _grade)
{
    grade = _grade;
}

void        Bureaucrat::gradePromotion()
{
    grade--;
	check();
}

void        Bureaucrat::gradeDemotion()
{
    grade++;
	check();
}

void		Bureaucrat::check()
{
	if (grade > 150)
		GradeTooLowException();
	else if (grade < 1)
		GradeTooHighException();
}

Bureaucrat::GradeTooHighException::GradeTooHighException() : std::out_of_range("grade too high") {}

Bureaucrat::GradeTooLowException::GradeTooLowException() : std::out_of_range("grade too low") {}

std::ostream&   operator<<(std::ostream& out, class Bureaucrat& Copy)
{
    std::cout << Copy.getName() << ", bureaucrat grade " << Copy.getGrade() << std::endl;
    return (out);
}
