#include <iostream>
#include "merge.h"
#include <vector>
#include <string>


int main()
{
	int arr[] = { 12, 4, 5, 3, 1, 6, 7, 9, 2, 4, 3, 8 };

	merge m;

	m.MergeSort(arr, 0, 11);

	system("pause");

	return 0;
}