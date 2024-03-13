#include<RPN.hpp>

int main(int argc, char **argv)
{
	if (argc != 2)
		RPN::error();
	RPN rpn(argv[1]);
	return (0);
}