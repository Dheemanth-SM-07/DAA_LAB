#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>  

using namespace std;


template <typename T>
void merge(vector<T>& arr, int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<T> leftArr(n1);
    vector<T> rightArr(n2);

    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) 
    {
        if (leftArr[i] <= rightArr[j]) 
        {
            arr[k] = leftArr[i];
            ++i;
        } 
        else 
        {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) 
    {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    while (j < n2) 
    {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}


template <typename T>
void mergeSort(vector<T>& arr, int left, int right)
{
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


template <typename T>
void printArray(const vector<T>& arr) 
{
    for (const T& element : arr)
        cout << element << " ";
    cout << endl;
}

int main()
{
    int ch;
    int n;

    while (1) {
        cout << "\nChoose the type of array you want to sort:";
        cout << "\n1. Integer Array";
        cout << "\n2. Character Array";
        cout << "\n3. Sort characters within a single string";
        cout << "\n4. Sort an array of strings";
        cout << "\n5. Exit";
        cout << "\nEnter your choice\n";
        cin >> ch;

        if (ch == 5)
        {
            cout << "Exiting the program.\n";
            break;
        }

        switch (ch)
        {
            case 1:
            {
                cout << "Enter the number of input elements\n";
                cin >> n;
                vector<int> arr(n);
                cout << "Enter the input elements\n";
                for (int i = 0; i < n; i++)
                {
                    cin >> arr[i];
                }

                cout << "Entered elements are: ";
                printArray(arr);

                clock_t tStart = clock();
                mergeSort(arr, 0, n - 1);
                clock_t tEnd = clock();

                cout << "Sorted array is: ";
                printArray(arr);

                cout << "Time taken for Merge Sort is " << fixed << setprecision(5) 
                     << (double)(tEnd - tStart) / CLOCKS_PER_SEC << " seconds\n";
                break;
            }
            case 2:
            {
                cout << "Enter the number of input elements\n";
                cin >> n;
                vector<char> arr(n);
                cout << "Enter the input elements\n";
                for (int i = 0; i < n; i++)
                {
                    cin >> arr[i];
                }

                cout << "Entered elements are: ";
                printArray(arr);

                clock_t tStart = clock();
                mergeSort(arr, 0, n - 1);
                clock_t tEnd = clock();

                cout << "Sorted array is: ";
                printArray(arr);

                cout << "Time taken for Merge Sort is " << fixed << setprecision(5) 
                     << (double)(tEnd - tStart) / CLOCKS_PER_SEC << " seconds\n";
                break;
            }
            case 3: 
            {
                string input;
                cout << "Enter a string\n";
                cin >> input;

                vector<char> arr(input.begin(), input.end());

                cout << "Entered string is: " << input << endl;

                clock_t tStart = clock();
                mergeSort(arr, 0, arr.size() - 1);
                clock_t tEnd = clock();

                cout << "Sorted string is: ";
                for (char c : arr) 
                {
                    cout << c;
                }
                cout << endl;

                cout << "Time taken for Merge Sort is " << fixed << setprecision(5) 
                     << (double)(tEnd - tStart) / CLOCKS_PER_SEC << " seconds\n";
                break;
            }
            case 4: 
            {
                cout << "Enter the number of input strings\n";
                cin >> n;
                vector<string> arr(n);
                cout << "Enter the input strings\n";
                for (int i = 0; i < n; i++) 
                {
                    cin >> arr[i];
                }

                cout << "Entered strings are: ";
                printArray(arr);

                clock_t tStart = clock();
                mergeSort(arr, 0, n - 1);
                clock_t tEnd = clock();

                cout << "Sorted array of strings is: ";
                printArray(arr);

                cout << "Time taken for Merge Sort is " << fixed << setprecision(5) 
                     << (double)(tEnd - tStart) / CLOCKS_PER_SEC << " seconds\n";
                break;
            }
            case 5: 
            {
                cout << "Exiting the program.\n";
                exit(0);
            }
            default:
                cout << "Invalid choice\n";
                break;
        }
    }

    return 0;
}
