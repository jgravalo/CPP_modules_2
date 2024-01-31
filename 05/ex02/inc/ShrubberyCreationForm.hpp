#ifndef SHRUBBERYCREATION_HPP
#define SHRUBBERYCREATION_HPP

#include<All.h>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(class ShrubberyCreationForm& Copy);
		ShrubberyCreationForm&	operator=(class ShrubberyCreationForm& Copy);
		~ShrubberyCreationForm();
		//void	function() const;
};

#endif