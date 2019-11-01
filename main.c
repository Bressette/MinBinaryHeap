#include "stdlib.h"
#include "stdio.h"

struct minHeap
{
    int *arr;
    int heapSize;
    int numElements;
};

struct minHeap insertHeap(struct minHeap heap, int data)
{
    if(heap.heapSize == heap.numElements)
    {
        printf("The heap is full\n");
        return heap;
    }

    else
    {
        int index = heap.numElements;
        heap.arr[index] = data;
        int parentIndex = (index-1)/2;
        heap.numElements++;

        while(index != 0) && heap.arr[parentIndex] > heap.arr[index])
        {
            int temp = heap.arr[index];
            heap.arr[index] = heap.arr[parentIndex];
            heap.arr[parentIndex] = temp;
            index = parentIndex;
            parentIndex = (index-1)/2;
        }
        return heap;
    }

}



int main()
{

    return 0;
}
