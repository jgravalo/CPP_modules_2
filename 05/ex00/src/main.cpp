#include<Bureaucrat.hpp>

void	testDefault()
{
	std::cout << "default:" << std::endl;
	try
	{
		Bureaucrat  Bureaucrat;
		std::cout << Bureaucrat << std::endl;
		Bureaucrat.gradeDemotion();
		std::cout << Bureaucrat << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testArgs()
{
	std::cout << "Low Exception:" << std::endl;
	try
	{
		Bureaucrat  Bureaucrat("perro sanchez", 151);
		std::cout << Bureaucrat << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testCopy()
{
	std::cout << "High Exception:" << std::endl;
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
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main()
{
	testDefault();
	testArgs();
	testCopy();
	return 0;
}