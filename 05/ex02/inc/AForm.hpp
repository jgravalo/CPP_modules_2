#ifndef AFORM_HPP
#define AFORM_HPP

#include<All.h>

class Bureaucrat;

class AForm
{
	private:
		std::string	name;
		bool		sign;
		const int	grade_to_sign;
		const int	grade_to_execute;
	public:
		AForm();
		AForm(std::string _name, int _grade_to_sign, int _grade_to_execute);
		AForm(class AForm& Copy);
		AForm&			operator=(class AForm& Copy);
		~AForm();
		std::string		getName() const;
		int				getGradetoSign();
		int				getGradetoExecute();
		bool			getStatus();
		int				beSigned(Bureaucrat& one);
		int				execute(Bureaucrat const & one) const;
		virtual void	function() const = 0;
		void			check();
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
		class		FormNotSigned
		{
			public:
				FormNotSigned();
		};

};

std::ostream&   operator<<(std::ostream& out, class AForm& Copy);

#endif
