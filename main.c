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

int min(int a, int b)
{
    if(a < b)
        return a;
    else
        return b;
}

struct minHeap deleteHeap(struct minHeap heap)
{
    if(heap.numElements == 0)
    {
        printf("There is nothing in the heap\n");
        return heap;
    }

    else if(heap.numElements == 1)
    {
        heap.numElements = 0;
        return heap;
    }

    else
    {
        heap.arr[0] = heap.arr[heap.numElements-1];
        heap.numElements--;
        int index = 0;

        int leftChildIndex = (index *2) + 1;
        int rightChildIndex = (index *2) + 2;

        while(leftChildIndex < heap.numElements)
        {
            if(rightChildIndex == heap.numElements)
            {
                if(heap.arr[index] > heap.arr[leftChildIndex])
                {
                    int temp = heap.arr[index];
                    heap.arr[index] = heap.arr[leftChildIndex];
                    heap.arr[leftChildIndex] = temp;
                }
                break;
            }

            else
            {
                int min = min(heap.arr[leftChildIndex], heap.arr[rightChildIndex]);
                if(heap.arr[index] > min)
                {
                    int temp = heap.arr[index];
                    heap.arr[index] = min;
                    if(heap.arr[leftChildIndex] == min)
                    {
                        heap.arr[leftChildIndex] = temp;
                        index = leftChildIndex;
                    }

                    else
                    {
                        heap.arr[rightChildIndex] = temp;
                        index = rightChildIndex;
                    }
                }
            }
        }
    }

}



int main()
{

    return 0;
}
