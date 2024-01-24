#include "MutantStack.hpp"

int main()
{
	std::cout << "\033[34m=========== Test avec mStack ===========\033[0m" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top of stack = " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Stack size = " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	std::cout << "Stack size après ajouts = " << mstack.size() << std::endl;
	std::cout << "Stack content = " << std::endl;
	while (it != ite)
	{
		std::cout << "  " << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << std::endl;

// ***********************************************************************

	std::cout << "\033[34m=========== Test avec std::list ===========\033[0m" << std::endl;

	std::list<int> list;

	list.push_back(5);
	list.push_back(17);

	std::cout << "Top of list = " << list.back() << std::endl;

	list.pop_back();

	std::cout << "List size = " << list.size() << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	//[...]
	list.push_back(0);

	std::list<int>::iterator	itList = list.begin();
	std::list<int>::iterator	iteList = list.end();

	++itList;
	--itList;
	std::cout << "List size après ajouts = " << mstack.size() << std::endl;
	std::cout << "List content = " << std::endl;
	while (itList != iteList)
	{
		std::cout << "  " << *itList << std::endl;
		++itList;
	}
	std::list<int> m(list);

	return 0;
}
