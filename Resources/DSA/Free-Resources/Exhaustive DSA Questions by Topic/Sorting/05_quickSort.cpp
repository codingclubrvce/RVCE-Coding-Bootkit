// QUICK SORT - Divide and Conquer

/*
    Note on Time and Space Complexity:
        TC - O(NlogN)
        SC - O(1)
*/

#include <iostream>
using namespace std;

int pivotInsertion(int arr[], int low, int high)
{
    int pivot = arr[low]; // initialise a pivot about which we will create left and right half arrays. Left half consists of smaller elements and right half will contain larger elements.
    //marking the pointers
    int i = low;
    int j = high; 
    while (i < j) //low should always be less than high, i and j should not cross each other.
    {
        while (arr[i] <= pivot && i <= high-1)
        {
            i++; //gives as index of first element which is greater than pivot and is in the left half.
        }
        while (arr[j] > pivot && j >= low+1)
        {
            j--; //gives as index of first element which is smaller than pivot and is in the right half.
        }
        if (i < j)
        {
            //swapping the elements so that they are in the correct half
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //swapping pivot element to place it in between the left and right half
    int temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partition_index = pivotInsertion(arr, low, high);
        quickSort(arr, low, partition_index - 1);
        quickSort(arr, partition_index + 1, high);
    }
}

int main()
{
    int n;
    cout << "Enter number of array elements: " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter array elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n-1); // quickSort(arr, low, high);

    cout << "Sorted Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}