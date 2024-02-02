#include<Bureaucrat.hpp>
#include<All.h>

void	testDefault()
{
	std::cout << "\ndefault:" << std::endl;
	try
	{
		Bureaucrat  Bureaucrat;
		Form		Form;

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
		Bureaucrat  Bureaucrat("pedro sanchez", 151);

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
		Bureaucrat  one("pedro sanchez", 3);
		Bureaucrat  two(one);

		std::cout << "one: " << one << std::endl;
		std::cout << "two: " << two << std::endl;
		one.gradePromotion();
		std::cout << "one: " << one << std::endl;
		std::cout << "two: " << two << std::endl;
		one.gradePromotion();
		two = one;
		std::cout << "one: " << one << std::endl;
		std::cout << "two: " << two << std::endl;
		one.gradePromotion();
		std::cout << "one: " << one << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testSignOK()
{
	try
	{
		Form		A;
		Bureaucrat	one;

		std::cout << "\nsign OK:" << std::endl;
		std::cout << one << std::endl;
		std::cout << A << std::endl;
		one.signForm(A);
		std::cout << "finish" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	testSignLow()
{
	try
	{
		Form		A("nuclear", 149, 150);
		Bureaucrat	one;

		std::cout << "\nsign low:" << std::endl;
		std::cout << one << std::endl;
		std::cout << A << std::endl;
		one.signForm(A);
		std::cout << "finish" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	testWorngForms()
{
	std::cout << "\nform low:" << std::endl;
	try
	{
		Form		A("nuclear", 151, 150);
		std::cout << "finish" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\nform high:" << std::endl;
	try
	{
		Form		A("nuclear", 0, 150);
		std::cout << "finish" << std::endl;
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
	testSignOK();
	testSignLow();
	testWorngForms();
	return 0;
}