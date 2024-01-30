#ifndef FORM_HPP
#define FORM_HPP

#include<All.h>

class Bureaucrat;

class Form
{
	private:
		std::string	name;
		bool		sign;
		const int	grade_to_sign;
		const int	grade_to_execute;
	public:
		Form();
		Form(std::string _name, int _grade_to_sign, int _grade_to_execute);
		Form(class Form& Copy);
		Form		operator=(class Form& Copy);
		~Form();
		std::string	getName();
		int			getGradetoSign();
		int			getGradetoExecute();
		bool		getStatus();
		int			beSigned(Bureaucrat& one);

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

std::ostream&   operator<<(std::ostream& out, class Form& Copy);

#endif
