// C++ program for Merge Sort
#include <iostream>
using namespace std;
  
// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid, int const right, int & qComparacoes, int & qTrocas)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
  
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
  
    // Copy data to temp arrays leftArray[] 
    // and rightArray[]
    for (auto i = 0; i < subArrayOne; i++){
        qComparacoes++;
        leftArray[i] = array[left + i];
        qTrocas++;
    }
    for (auto j = 0; j < subArrayTwo; j++){
        qComparacoes++;
        rightArray[j] = array[mid + 1 + j];
        qTrocas++;
    }
  
    // Initial index of first sub-array
    // Initial index of second sub-array
    auto indexOfSubArrayOne = 0, 
         indexOfSubArrayTwo = 0; 
  
    // Initial index of merged array
    int indexOfMergedArray = left; 
  
    // Merge the temp arrays back into 
    // array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) 
    {
        qComparacoes+=2;
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) 
        {
            qComparacoes++;
            array[indexOfMergedArray] = 
            leftArray[indexOfSubArrayOne];
            qTrocas++;
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = 
            rightArray[indexOfSubArrayTwo];
            qTrocas++;
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
      
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne)
    {
        qComparacoes++;
        array[indexOfMergedArray] = 
        leftArray[indexOfSubArrayOne];
        qTrocas++;
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
  
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) 
    {
        qComparacoes++;
        array[indexOfMergedArray] = 
        rightArray[indexOfSubArrayTwo];
        qTrocas++;
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
  
// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[],  int const begin, int const end, int & qComparacoes, int & qTrocas)
{
    // Returns recursively
    qComparacoes++;
    if (begin >= end){
        return;
    }
  
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid, qComparacoes, qTrocas);
    mergeSort(array, mid + 1, end, qComparacoes, qTrocas);
    merge(array, begin, mid, end, qComparacoes, qTrocas);
}