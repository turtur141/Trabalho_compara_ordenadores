// C++ Implementation of the Quick Sort Algorithm.
#include <iostream>
using namespace std;
void partition(int arr[], int start, int end,int & pivotIndex, float & qComparacoes, float & qTrocas)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {
        qComparacoes++;
        while (arr[i] <= pivot) {
            qComparacoes++;
            i++;
        }
        qComparacoes++;
        while (arr[j] > pivot) {
            qComparacoes++;
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
            qTrocas++;
        }
    }
}
 
void quickSort(int arr[], int start, int end, float & qComparacoes, float & qTrocas)
{
    int p;
    // base case
    if (start >= end)
        return;
    // partitioning the array
    partition(arr, start, end,p,qComparacoes,qTrocas);
 
    // Sorting the left part
    quickSort(arr, start, p - 1, qComparacoes, qTrocas);
 
    // Sorting the right part
    quickSort(arr, p + 1, end, qComparacoes, qTrocas);
}
