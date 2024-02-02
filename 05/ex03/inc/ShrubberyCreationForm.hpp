#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include<All.h>
#include<fstream>

#define ASCII_TREE "\t\t    ___\n\t   __ (		) __\n\t (				 )\n   (				   )\n  (						)\n  (___.				.___)\n\t(___. \\ \\ / / .___)\n\t\t(__\\   /__)\n\t\t\t) (\n\t\t\t) (\n\t\t\t) (\n\t\t   /   \\\n"

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