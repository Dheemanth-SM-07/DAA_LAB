#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition1(int arr[], int low, int high) 
{
    int pivot = arr[low];
    int k = high;
    for (int i = high; i > low; i--) 
    {
        if (arr[i] > pivot)
            swap(arr[i], arr[k--]);
    }
    swap(arr[low], arr[k]);
    return k;
}

void quickSort_first(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int idx = partition1(arr, low, high);
        quickSort_first(arr, low, idx - 1);
        quickSort_first(arr, idx + 1, high);
    }
}

int partition2(int arr[], int low, int high) 
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort_last(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition2(arr, low, high);
        quickSort_last(arr, low, pi - 1);
        quickSort_last(arr, pi + 1, high);
    }
}

void quicksort_middle(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    int pivot = arr[mid];
    int i = low, j = high;

    while (i <= j) 
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    quicksort_middle(arr, low, j);
    quicksort_middle(arr, i, high);
}

void arrangeBinaryArray(int arr[], int n) 
{
    int count0 = 0;
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] == 0)
            count0++;
    }
    for (int i = 0; i < count0; i++)
    {
        arr[i] = 0;
    }
    for (int i = count0; i < n; i++) 
    {
        arr[i] = 1;
    }
}

int main()
{
    int ch;
    int n, arr[50], i;
    cout << "Enter the number of input elements\n";
    cin >> n;
    cout << "Enter the input elements\n";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
     cout << "Entered elements is : ";
    for (i = 0; i < n; i++) 
    {
        cout << arr[i] <<" ";
    }
    while (1) 
    {
        cout << "\n1. Quick Sort using first element as pivot element";
        cout << "\n2. Quick Sort using last element as pivot element";
        cout << "\n3. Quick Sort using middle element as pivot element";
        cout << "\n4. Arrange binary array";
        cout << "\nEnter your choice\n";
        cin >> ch;
        switch (ch)
        {
            case 1: 
            {
                clock_t tStart1 = clock();
                quickSort_first(arr, 0, n - 1);
                clock_t tend1 = clock();
                cout << "Sorted array is: ";
                for (i = 0; i < n; i++) 
                {
                    cout << arr[i] << " ";
                }
                cout << "\nTime taken for Quick Sort using first element as pivot element is "<< fixed << (double)(tend1 - tStart1) / CLOCKS_PER_SEC << " seconds\n";
                break;
            }
            case 2: 
            {
                clock_t tStart2 = clock();
                quickSort_last(arr, 0, n - 1);
                clock_t tend2 = clock();
                cout << "Sorted array is: ";
                for (i = 0; i < n; i++) 
                {
                    cout << arr[i] << " ";
                }
                cout << "\nTime taken for Quick Sort using last element as pivot element is "<< fixed << (double)(tend2 - tStart2) / CLOCKS_PER_SEC << " seconds\n";
                break;
            }
            case 3: {
                clock_t tStart3 = clock();
                quicksort_middle(arr, 0, n - 1);
                clock_t tend3 = clock();
                cout << "Sorted array is: ";
                for (i = 0; i < n; i++) 
                {
                    cout << arr[i] << " ";
                }
                cout << "\nTime taken for Quick Sort using middle element as pivot element is "<< fixed << (double)(tend3 - tStart3) / CLOCKS_PER_SEC << " seconds\n";
                break;
            }
            case 4: {
                clock_t tStart4 = clock();
                arrangeBinaryArray(arr, n);
                clock_t tend4 = clock();
                cout << "Sorted binary array is: ";
                for (i = 0; i < n; i++) 
                {
                    cout << arr[i] << " ";
                }
                cout << "\nTime taken for arranging binary array is "<< fixed << (double)(tend4 - tStart4) / CLOCKS_PER_SEC << " seconds\n";
                break;
            }
            default:
                cout << "Invalid choice\n";
                break;
        }
    }
    return 0;
}
