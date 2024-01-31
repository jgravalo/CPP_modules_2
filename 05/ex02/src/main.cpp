#include<Bureaucrat.hpp>
#include<All.h>

void	testDefault()
{
	std::cout << "\ndefault:" << std::endl;
	try
	{
		Bureaucrat  Bureaucrat;
		AForm		AForm;

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

void	testShrubberyCreationForm()
{
	try
	{
		ShrubberyCreationForm	A;
		Bureaucrat				one;

		std::cout << "\nShrubberyCreationForm:" << std::endl;
		std::cout << one << std::endl;
		std::cout << A << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

int main()
{
	testDefault();
	testArgs();
	testCopy();
	testExecuteOK();
	testExecuteLow();
	testExecuteNotSigned();
	testWorngAForms();
	testShrubberyCreationForm();
	return 0;
}
