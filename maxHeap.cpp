#include "maxHeap.h"

int maxHeap::leftChildIndex(int parent)
{
    int leftIndex = 2 * parent + 1;
    if (leftIndex < heap.size())
        return leftIndex;
    else
        return -1;
}

int maxHeap::rightChildIndex(int parent)
{
    int rightIndex = 2 * parent + 2;
    if (rightIndex < heap.size())
        return rightIndex;
    else
        return -1;
}

int maxHeap::parentIndex(int child)
{
    int parent = (child - 1) / 2;
    if (child == 0)
        return -1;
    else
        return parent;
}

//after inserting, we heapifyup from where that new node ended up
//compares current node to parent and swaps the smaller to the top
//recursive function, each swap means we call heapifyup on the next higher level
//where we swapped a value
void maxHeap::heapifyup(int index)
{
    //IF index is not the root(top of the tree)
    //AND parent index within heap bounds (not negative)
    //AND current nodes rank less then parent nodes number
    if (index >= 0 && parentIndex(index) >= 0 && heap[index].num > heap[parentIndex(index)].num) {
        //if so, swap values between current node and parent
        node temp = heap[index];
        heap[index] = heap[parentIndex(index)];
        heap[parentIndex(index)] = temp;
        //since we swapped, lets run heapifyup again recursively on the parent from here
        heapifyup(parentIndex(index));
    }
}

//inserts at the lowest next free spot in the tree (this keeps things balanced :D)
void maxHeap::Insert(node element) {
    heap.push_back(element);
    heapifyup(heap.size() - 1);
}
