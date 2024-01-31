#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include<All.h>

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string _target);
		PresidentialPardonForm(class PresidentialPardonForm& Copy);
		PresidentialPardonForm&	operator=(class PresidentialPardonForm& Copy);
		~PresidentialPardonForm();
		void		function() const;
		std::string	getTarget();
};

#endif
