// Merge Sort - Divide and Merge

// TC : O(N x log2(N)))

#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    vector<int> temp;
    //[low...mid]
    //[mid+1...high]
    int left = low;
    int right = mid + 1;
    while ((left <= mid) && (right <= high))
    {
        //pointer approach to check two elements in the first half and second half
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid) //in case of elements remaining in the left half
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) //in case of elements remaining in the right half
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid); //Left Divided Array
    mergeSort(arr, mid+1, high); //Right Divided Array
    merge(arr, low, mid, high); //Merge both arrays
}

int main()
{
    int n;
    cout << "Enter number of elements in the array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter array elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n-1);

    cout << "Sorted Array:-" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}