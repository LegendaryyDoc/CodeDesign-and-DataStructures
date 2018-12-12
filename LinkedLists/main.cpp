#include <iostream>
#include "raylib.h"
#include "tLinkedList.h"

int main()
{
	tForwardList<int> link;
	tForwardList<int> cTemp;
	link.begin();
	link.push_front(5);
	link.push_front(6);
	link.push_front(5);
	link.push_front(5);
	link.push_front(9);
	link.push_front(5);
	link.push_front(5);
	link.remove(5);
	link.end();
	//link.~tForwardList();

	//cTemp.operator=(link);
	cTemp = link;

	tForwardList<int> copy(link);
	
	std::cout << "Iterator" << std::endl;
	for (auto it = link.begin(); it != link.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}

	std::cout << "Original" << std::endl;
	while (!link.empty())
	{
		std::cout << link.front() << std::endl;
		link.pop_front();
	}
	std::cout << "\n\n" << std::endl;

	std::cout << "cTemp" << std::endl;
	while (!cTemp.empty())
	{
		std::cout << cTemp.front() << std::endl;
		cTemp.pop_front();
	}
	std::cout << "\n\n" << std::endl;

	std::cout << "Copy" << std::endl;
	while (!copy.empty())
	{
		std::cout << copy.front() << std::endl;
		copy.pop_front();
	}

	

	system("pause");
	return 0;
}