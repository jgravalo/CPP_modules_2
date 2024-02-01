#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include<All.h>
#include<cstdlib>

class RobotomyRequestForm : public AForm
{
	private:
		std::string	target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string _target);
		RobotomyRequestForm(class RobotomyRequestForm& Copy);
		RobotomyRequestForm&	operator=(class RobotomyRequestForm& Copy);
		~RobotomyRequestForm();
		void	function() const;
		std::string	getTarget();
};

#endif
