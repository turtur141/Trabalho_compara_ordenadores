// C++ program for implementation of Heap Sort
#include <iostream>
using namespace std;
 
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i, int & qComparacoes, int & qTrocas)
{
    int largest = i; // Initialize largest as root Since we are using 0 based indexing
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    qComparacoes++;
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    qComparacoes++;
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    qComparacoes++;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        qTrocas++;
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest,qComparacoes, qTrocas);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n, int & qComparacoes, int & qTrocas)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--){
        qComparacoes++;
        heapify(arr, n, i, qComparacoes, qTrocas);
    }
 
    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        qComparacoes++;
        // Move current root to end
        swap(arr[0], arr[i]);
        qTrocas++;
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0, qComparacoes, qTrocas);
    }
}