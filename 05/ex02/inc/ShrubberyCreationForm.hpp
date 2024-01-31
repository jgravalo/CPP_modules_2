#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include<All.h>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string _target);
		ShrubberyCreationForm(class ShrubberyCreationForm& Copy);
		ShrubberyCreationForm&	operator=(class ShrubberyCreationForm& Copy);
		~ShrubberyCreationForm();
		void		function() const;
		std::string	getTarget();
};

#endif