#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << RED << "Error: Please insert positive int sequence." << NC << std::endl;
		return (EXIT_FAILURE);
	}

	try
	{
		PMergeMe<std::vector> vec(av + 1);

		std::cout << "Before : ";
		vec.printData();
		// vec.sort();

		std::cout << "After : ";
		// vec.printData();
		// std::cout << "Sorted : ";
		vec.printSorted();

		PMergeMe<std::deque> deq(av + 1);
		deq.sort();
		deq.printSorted();

		vec.printTime("vector");
		// deq.printTime("deque");
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return (EXIT_SUCCESS);
}

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

/*
	Steps :
	1/ Determine if aray has even or odd number of ints
	2/ Create pairs
	3/ Sort each pair
	4/ Sort pair sequence by its greater value
	5/ Create sorted 'S'sequence with the larger values
	6/ Create sequence to optimally insert remaining ints in 'S' array
	7/ If size of array was odd, add the remaining value in the 'S' array, in its right place
*/