#include "RPN.hpp"

/* Convert the input string into a stream (std::istringstream) in order to
	perform input operations => actions that involve reading or extracting data from an input source.
	A stream allows us to parse and/or extract values from a string.
	The extraction operator ">>" is used for reading or extracting data from a stream. */

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		std::stack<int>		stack;
		std::istringstream	oss(av[1]);
		std::string			token;

		while (oss >> token)
		{
			if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1 && isdigit(token[1])))
				stack.push(std::atoi(token.substr(0, 1).c_str()));
			else if (token[0] != '+' && token[0] != '-' && token[0] != '/' && token[0] != '*')
			{
				std::cout << RED << "Error: Invalid character" << NC << std::endl;
				return (EXIT_FAILURE);
			}
			else
			{
				if (stack.size() >= 2)
				{
					int		value1 = stack.top();
					stack.pop();
					int		value2 = stack.top();
					stack.pop();

					switch (token[0])
					{
						case '+':
							stack.push(value2 + value1);
							break ;
						case '-':
							stack.push(value2 - value1);
							break ;
						case '/':
							if (value1 == 0 || value2 == 0)
							{
								std::cout << RED << "Error: division with zero" << NC <<std::endl;
								return (EXIT_FAILURE);
							}
							else
							{
								stack.push(value2 / value1);
								break ;
							}
						case '*':
							stack.push(value2 * value1);
							break ;
						default:
							std::cout << RED << "Error: Invalid operator" << NC << std::endl;
					}
				}
			}
		}
		if (stack.empty() == false)
			std::cout << stack.top() << std::endl;
		else
			std::cout << RED << "Error: Empty Stack" << NC << std::endl;
	}
	else
		std::cout << RED << "Error: Invalid number of arguments." << NC << std::endl;
	return (EXIT_SUCCESS);
}
