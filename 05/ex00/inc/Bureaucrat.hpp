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
    //void        setName(std::string _name);
    void        setGrade(int _grade);
    void        gradePromotion();
    void        gradeDemotion();
	void		check();

	/* class exception : std::exception
	{
		public:
			virtual const char*	what() const throw();
	}; */
	class GradeTooHighException : std::out_of_range
	{
		public:
			GradeTooHighException();
	};
	class GradeTooLowException : std::out_of_range
	{
		public:
			GradeTooLowException();
	};
};

std::ostream&   operator<<(std::ostream& out, class Bureaucrat& Copy);

#endif