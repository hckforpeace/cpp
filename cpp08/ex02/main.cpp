#include <iostream>
#include <vector>
#include "MutantStack.hpp"

/* int main()
{
// 	std::vector<int> tab = {1, 2, 3};
// 	for (std::vector<int>::const_iterator it = tab.cbegin() ; it != tab.cend() ; it++)
// 	{
// 		std::cout << *it << std::endl;
// 		*it = 2;
// 	}	
// return (0);

	MutantStack<int> ms;
	ms.push(2);
	ms.push(3);
	ms.push(4);
	ms.push(5);
	ms.push(6);
	ms.push(7);

	for (MutantStack<int>::const_iterator it = ms.begin(); it != ms.end() ; it++)
	{
		std::cout << *it << std::endl;
	}
 
	return (0);
} */

int main()
{
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}