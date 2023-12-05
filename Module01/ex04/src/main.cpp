#include "Sed.hpp"

int	main(int ac, char **av)
{
	std::string		buffer;

	if (ac == 4)
	{
		Sed		sed = Sed(av[1], av[2], av[3]);

		std::ifstream	inputFile(sed.getInputFile().c_str());
		if (inputFile.is_open() == true)
		{
			std::ofstream	outFile(sed.getOutputFile().c_str());
			if (outFile.is_open() == true)
			{
				while (std::getline(inputFile, buffer))
				{
					buffer = sed.replaceString(buffer, sed.getStringOne(), sed.getStringTwo());
					outFile << buffer;
					if (inputFile.peek() != EOF)
						outFile << std::endl;
				}
				outFile.close();
				if (outFile.fail() == true)
				{
					std::cerr << "Error closing outfile. " << std::endl;
					return (EXIT_FAILURE);
				}
			}
			else
			{
				std::cerr << "Error opening outfile." << std::endl;
				return (EXIT_FAILURE);
			}
			inputFile.close();
			if (inputFile.fail() == true)
			{
				std::cerr << "Error closing infile." << std::endl;
				return (EXIT_FAILURE);
			}
		}
		else
		{
			std::cerr << "Error opening infile." << std::endl;
			return (EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	std::cout << "Incorrect number of arguments." << std::endl;
	return (EXIT_FAILURE);
}
