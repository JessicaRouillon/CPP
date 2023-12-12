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

		// Check if the file is empty
		inputFile.seekg(0, std::ios::end); // seekg moves the pointer to the end of the file

		// Check if file can be opened and where file pointer position is
		if (inputFile.is_open() == true && inputFile.tellg() != 0)
		{
			inputFile.seekg(0, std::ios::beg); // move the pointer back to the start of the file
			std::ofstream	outputFile(sed.getOutputFile().c_str());
			// Check if output file can be opened
			if (outputFile.is_open() == true)
			{
				char	delimiter = '\n'; // newline will be managed by getline
				while (std::getline(inputFile, buffer, delimiter))
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
			std::cerr << "Error opening infile. Check that the file exists, that you have permission or that it is not empty." << std::endl;
			return (EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	std::cout << "Incorrect number of arguments." << std::endl;
	return (EXIT_FAILURE);
}
