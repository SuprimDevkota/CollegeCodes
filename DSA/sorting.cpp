#include <iostream>
#define size 5
using namespace std;



void swap (int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void printArray(int* arr, int n = size)
{
    for(int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int* arr, int n = size)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n - i; ++j)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int smallest(int* arr, int i, int n = size)
{
    int small = arr[i];
    int pos = i;

    for(int j = i + 1; j < n; ++j)
    {
        if(small > arr[j])
        {
            small = arr[j];
            pos = j;
        }
    }

    return pos;
}

void selectionSort(int* arr, int n = size)
{
    for(int i = 0; i < n; ++i)
    {
        int pos = smallest(arr, i, n);
        swap(arr[i], arr[pos]);
    }
}


int main()
{

    int arr[] = {8, 5, 7, 3, 2};
    cout << "\nThe unsorted array is : ";
    printArray(arr);

    //bubbleSort(arr);
    selectionSort(arr);

    cout << "\nThe sorted array is: ";
    printArray(arr);


}