#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int low, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid + 1;

    int x[n1], y[n2];

    for (int i = 0; i < n1; i++)
    {
        x[i] = arr[low + i];
    }

    for(int i = 0;  i < n2; i++)
    {
        y[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = low;

    while(i < n1 && j < n2)
    {
        if(x[i] < y[j])
        {
            arr[k] = x[i];
            i++;
        }
        else 
        {
            arr[k] = y[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        arr[k] = x[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = y[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int low, int high)
{
    if(low < high)
    {
        int mid = (low + high)/ 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() 
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Call your merge sort function
    mergeSort(arr, 0, n - 1);

    // Output the sorted array
    cout << "Sorted array: ";
    
    for (int num : arr) 
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
