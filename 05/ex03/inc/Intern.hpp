#ifndef INTERN_HPP
#define INTERN_HPP

#include<All.h>

class Intern
{
	public:
		Intern();
		Intern(class Intern& Copy);
		Intern&	operator=(class Intern& Copy);
		~Intern();
		AForm*	makeForm(std::string name, std::string target);
};

#endif