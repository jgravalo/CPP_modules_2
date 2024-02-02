#include<Bureaucrat.hpp>
#include<All.h>

/*
void	testDefault()
{
	std::cout << "\ndefault:" << std::endl;
	try
	{
		Bureaucrat  Bureaucrat;

		std::cout << Bureaucrat << std::endl;
		Bureaucrat.gradeDemotion();
		std::cout << Bureaucrat << std::endl;
		std::cout << "finish" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testArgs()
{
	std::cout << "\nArgs:" << std::endl;
	try
	{
		Bureaucrat  Bureaucrat("perro sanchez", 151);

		std::cout << Bureaucrat << std::endl;
		std::cout << "finish" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testCopy()
{
	std::cout << "\nCopy:" << std::endl;
	try
	{
		Bureaucrat  one("perro sanchez", 3);
		Bureaucrat  two(one);

		std::cout << one << std::endl;
		std::cout << two << std::endl;
		one.gradePromotion();
		std::cout << one << std::endl;
		std::cout << two << std::endl;
		one.gradePromotion();
		two = one;
		std::cout << one << std::endl;
		std::cout << two << std::endl;
		one.gradePromotion();
		std::cout << one << std::endl;
		std::cout << "finish" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testExecuteOK()
{
	try
	{
		AForm		A;
		Bureaucrat	one;

		std::cout << "\nexecute OK:" << std::endl;
		std::cout << one << std::endl;
		std::cout << A << std::endl;
		one.signForm(A);
		one.executeForm(A);
		std::cout << "finish" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

void	testExecuteLow()
{
	try
	{
		AForm		A("nuclear", 150, 149);
		Bureaucrat	one;

		std::cout << "\nexecute low:" << std::endl;
		std::cout << one << std::endl;
		std::cout << A << std::endl;
		one.signForm(A);
		one.executeForm(A);
		std::cout << "finish" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

void	testExecuteNotSigned()
{
	try
	{
		AForm		A("nuclear", 150, 150);
		Bureaucrat	one;

		std::cout << "\nexecute not signed:" << std::endl;
		std::cout << one << std::endl;
		std::cout << A << std::endl;
		one.executeForm(A);
		std::cout << "finish" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testWorngAForms()
{
	std::cout << "\nform low:" << std::endl;
	try
	{
		AForm		A("nuclear", 150, 151);
		std::cout << "finish" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\nform high:" << std::endl;
	try
	{
		AForm		A("nuclear", 150, 0);
		std::cout << "finish" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
 */
void	testShrubberyCreationFormKO()
{
	try
	{
		std::cout << "\nShrubberyCreationForm KO:" << std::endl;
		//ShrubberyCreationForm	A;
		Bureaucrat				one;
		Intern I;
		AForm *A = I.makeForm("shrubbery creation", "perro sanchez");

		std::cout << one << std::endl;
		std::cout << *A << std::endl;
		one.signForm(*A);
		one.executeForm(*A);
		std::cout << "finish" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testShrubberyCreationFormOK()
{
	try
	{
		//ShrubberyCreationForm	A;
		Bureaucrat				one("perro sanchez", 130);
		Intern I;
		AForm *A = I.makeForm("shrubbery creation", "perro sanchez");

		std::cout << "\nShrubberyCreationForm OK:" << std::endl;
		std::cout << one << std::endl;
		std::cout << *A << std::endl;
		one.signForm(*A);
		one.executeForm(*A);
		std::cout << "finish" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testRobotomyRequestFormKO()
{
	try
	{
		std::cout << "\nRobotomyRequestForm KO:" << std::endl;
		//RobotomyRequestForm	A;
		Bureaucrat				one;
		Intern I;
		AForm *A = I.makeForm("robotomy request", "perro sanchez");

		std::cout << one << std::endl;
		std::cout << *A << std::endl;
		one.signForm(*A);
		one.executeForm(*A);
		std::cout << "finish" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testRobotomyRequestFormOK()
{
	try
	{
		std::cout << "\nRobotomyRequestForm OK:" << std::endl;
		//RobotomyRequestForm	A;
		Bureaucrat				one("perro sanchez", 40);
		Intern I;
		AForm *A = I.makeForm("robotomy request", "perro sanchez");

		std::cout << one << std::endl;
		std::cout << *A << std::endl;
		one.signForm(*A);
		one.executeForm(*A);
		std::cout << "finish" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testPresidentialPardonFormKO()
{
	try
	{
		//PresidentialPardonForm	A;
		Bureaucrat				one;
		Intern I;
		AForm *A = I.makeForm("presidential pardon", "perro sanchez");

		std::cout << "\nPresidentialPardonForm KO:" << std::endl;
		std::cout << one << std::endl;
		std::cout << *A << std::endl;
		one.signForm(*A);
		one.executeForm(*A);
		std::cout << "finish" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testPresidentialPardonFormOK()
{
	try
	{
		std::cout << "\nPresidentialPardonForm OK:" << std::endl;
		//PresidentialPardonForm	A;
		Bureaucrat				one("perro sanchez", 5);
		Intern I;
		AForm *A = I.makeForm("presidential pardon", "perro sanchez");

		std::cout << one << std::endl;
		std::cout << *A << std::endl;
		one.signForm(*A);
		one.executeForm(*A);
		std::cout << "finish" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
/* 
void testIntern()
{
	try
	{
		Intern I;

		AForm *A = I.makeForm("shrubbery creation", "perro sanchez");
		AForm *A = new ShrubberyCreationForm();
		std::cout << *A << std::endl;
		//if (A)
		//	delete A;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
} */

int main()
{
	/*
	testDefault();
	testArgs();
	testCopy();
	testExecuteOK();
	testExecuteLow();
	testExecuteNotSigned();
	testWorngAForms(); */
	testShrubberyCreationFormKO();
	testShrubberyCreationFormOK();
	testRobotomyRequestFormKO();
	testRobotomyRequestFormOK();
	testPresidentialPardonFormKO();
	testPresidentialPardonFormOK();
	//testIntern();
	return 0;
}
