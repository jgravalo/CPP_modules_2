#include<Bureaucrat.hpp>

int main()
{

//	/*
	try
	{
		//Bureaucrat  Bureaucrat("perro", 151);
		Bureaucrat  Bureaucrat;
		std::cout << Bureaucrat << std::endl;
		Bureaucrat.gradeDemotion();
		//Bureaucrat.check();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
//	 */
	return 0;
}