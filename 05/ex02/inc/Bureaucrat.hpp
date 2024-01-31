#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include<All.h>

class AForm;

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
		int         getGrade() const;
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
		void	signForm(AForm& F);
		void	executeForm(AForm const & form);
};

std::ostream&   operator<<(std::ostream& out, class Bureaucrat& Copy);

#endif