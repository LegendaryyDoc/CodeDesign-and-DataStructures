#include <iostream>
#include "raylib.h"
#include "tLinkedList.h"

int main()
{
	tForwardList<int> link;

	link.push_front(5);
	link.push_front(6);
	link.push_front(5);
	link.push_front(12);
	link.push_front(3);
	link.push_front(6);
	link.push_front(9);
	link.push_front(5);
	link.push_front(5);
	link.push_front(5);
	link.remove(5);

	while (!link.empty())
	{
		std::cout << link.front() << std::endl;
		link.pop_front();
	}

	return 0;
}