#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include<iostream>

class Bureaucrat
{
private:
    const std::string   name;
    int                 grade;
public:
    Bureaucrat();
    Bureaucrat(std::string _name, int _grade);
    Bureaucrat(class Bureaucrat& Copy);
    Bureaucrat& operator=(class Bureaucrat& Copy);
    ~Bureaucrat();
    std::string getName();
    int         getGrade();
    void        setGrade(int _grade);
    void        gradePromotion();
    void        gradeDemotion();
	void		check();
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