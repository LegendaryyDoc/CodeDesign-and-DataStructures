#include "merge.h"
#include <iostream>
#include <string>
#include <vector>

void merge::Merge(int * arr, size_t p, size_t q, size_t r)
{
	int leftEnd = q - p + 1;
	int rightEnd = r - q;

	int *  ls = new int[leftEnd];

	int * rs = new int[rightEnd];

	//std::vector<int> l;
	//std::vector<int> ri;

	//std::string l;
	//std::string ri;

	//l.capacity = leftEnd;
	//ri.capacity = rightEnd;

	//l[leftEnd];
	//ri[rightEnd];



	for (int i = 0; i < leftEnd; i++)
	{
		ls[i] = arr[p + i];
	}
	for (int j = 0; j < rightEnd; j++)
	{
		rs[j] = arr[q + j + 1];
	}

	int i = 0;
	int j = 0;
	
	for (int k = p; k <= r; k++)
	{
		if (j >= rightEnd || (i < leftEnd && ls[i] <= rs[j]))
		{
			arr[k] = ls[i];
			i++;
		}
		else
		{
			arr[k] = rs[j];
			j++;
		}
	}
	
	
	std::cout << "current status" << std::endl;
	for (int l = 0; l < 12; l++)
	{
		std::cout << arr[l] << std::endl;
	}
	delete[] ls;
	delete[] rs;
}

void merge::MergeSort(int * arr, size_t p, size_t r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		MergeSort(arr, p, q);
		MergeSort(arr, q + 1, r);
		Merge(arr, p, q, r);
	}
}

merge::merge()
{
}

merge::~merge()
{
}
