#include<Bureaucrat.hpp>

int main()
{

//	/*
	try
	{
		Bureaucrat  Bureaucrat;
		std::cout << Bureaucrat << std::endl;
		Bureaucrat.gradeDemotion();
		if(Bureaucrat.getGrade() > 150)
			throw (Bureaucrat::GradeTooLowException());
		std::cout << Bureaucrat << std::endl;
	}
	catch(const std::out_of_range& e)
	//catch(const char *e)
	{
		//std::cerr << e << std::endl;
		std::cerr << e.what() << std::endl;
	}
//	 */
	return 0;
}