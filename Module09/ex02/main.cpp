#include "PmergeMe.hpp"

/*
	STD::VECTOR >> main_chain
	- Insertions and deletions at the end are efficient (middle and beginning not so much)

	STD::DEQUE >> store b numbers
	- Efficient for insertions and deletions at both ends.
		Insertions/deletions in the middle are less efficient than in std::vector
	- Not as efficient for accessing elements by index, since it needs to shift all elements forward or
		backwards when an element is added/removed

	BOTH
	- Random access iterators, allowing efficient traversal of elements.
	- Constant time O(1) access, which means that accessing an element at a specific position
		in the container takes the same amount of time, regardless of how many elements are in the container.
	- Both containers manage memory for their elements and handle reallocation as needed.

*/

int main(int ac, char **av)
{
	if (ac > 1)
	{
		PMergeMe obj;

		if (obj.isValidInput(ac, av) == false)
		{
			std::cout << RED << "Error: invalid input" << NC << std::endl;
			return (EXIT_FAILURE);
		}

		return (EXIT_SUCCESS);
	}
	else
	{
		std::cout << RED << "Error: Invalid number of arguments." << NC << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
