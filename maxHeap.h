#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include "node.h"

using namespace std;

class maxHeap
{
public:
	vector<node> heap;
	int leftChildIndex(int parent);
	int rightChildIndex(int parent);
	int parentIndex(int child);

	void heapifyup(int index);

	void Insert(node element);
};

