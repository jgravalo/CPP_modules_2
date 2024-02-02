#include<Bureaucrat.hpp>

void	testDefault()
{
	std::cout << "\ndefault:" << std::endl;
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
	std::cout << "\nLow Exception:" << std::endl;
	try
	{
		Bureaucrat  Bureaucrat("pedro sanchez", 151);
		std::cout << Bureaucrat << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testCopy()
{
	std::cout << "\nHigh Exception:" << std::endl;
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

int main()
{
	testDefault();
	testArgs();
	testCopy();
	return 0;
}