#include "Sed.hpp"

int	main(int ac, char **av)
{
	std::string		buffer;

	if (ac == 4)
	{
		if (av[2][0] == '\0')
		{
			std::cout << "s1 cannot be empty." << std::endl;
			return (EXIT_FAILURE);
		}

		Sed		sed = Sed(av[1], av[2], av[3]);

		std::ifstream	inputFile(sed.getInputFile().c_str());
		if (inputFile.is_open() == true)
		{
			std::ofstream	outputFile(sed.getOutputFile().c_str());
			if (outputFile.is_open() == true)
			{
				while (std::getline(inputFile, buffer))
				{
					buffer = sed.replaceString(buffer, sed.getStringOne(), sed.getStringTwo());
					outputFile << buffer;
					if (inputFile.peek() != EOF)
						outputFile << std::endl;
				}
				outputFile.close();
				if (outputFile.fail() == true)
				{
					std::cerr << "Error closing outputfile. " << std::endl;
					return (EXIT_FAILURE);
				}
			}
			else
			{
				std::cerr << "Error opening outputfile." << std::endl;
				return (EXIT_FAILURE);
			}
			inputFile.close();
		}
		else
		{
			std::cerr << "Error opening infile. Check that the file exists or that you have permission." << std::endl;
			return (EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	std::cout << "Incorrect number of arguments." << std::endl;
	return (EXIT_FAILURE);
}
