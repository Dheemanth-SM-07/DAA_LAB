#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int linearSearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}
int linearSearch2(int arr[], int n, int x)
{
    if (n == 0)
    {
        return -1;
    }
    if (arr[n - 1] == x)
    {
        return n - 1;
    }
    return linearSearch2(arr, n - 1, x);
}
int binarySearch(int arr[], int low, int high, int x)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        if (arr[mid] > x)
        {
            return binarySearch(arr, low, mid - 1, x);
        }
        else
        {
            return binarySearch(arr, mid + 1, high, x);
        }
    }
    return -1;
}
int binarySearch2(int arr[], int low, int high, int x)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    clock_t start, end;
    double time_taken, time_taken2, time_taken3, time_taken4;
    start = clock();
    int n, x, i;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements in the array:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the Key element");
    scanf("%d", &x);
    int result = linearSearch(arr, n, x);
    if (result == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found at index %d\n", result);
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("The time taken by the linear search iterative function is 
%f\n",time_taken); 
        start=clock(); 
        int result2=linearSearch2(arr,n,x); 
        if(result2==-1) 
        {
        printf("Element not found\n"); 
        } 
        else 
        {
        printf("Element found at index %d\n", result2); 
        } 
        end=clock(); 
        time_taken2=((double)(end-start))/CLOCKS_PER_SEC; 
        printf("The time taken by the linear search recursive function is 
%f\n",time_taken2); 
        start=clock(); 
        int result3=binarySearch(arr,0,n-1,x); 
        if(result3==-1) 
        {
        printf("Element not found\n"); 
        } 
        else 
        {
        printf("Element found at index %d\n", result3); 
        } 
        end=clock(); 
        time_taken3=((double)(end-start))/CLOCKS_PER_SEC; 
        printf("The time taken by the binary search recursive function is 
%f\n",time_taken3); 
        start=clock(); 
        int result4=binarySearch2(arr,0,n-1,x); 
        if(result4==-1) 
        {
        printf("Element not found\n"); 
        } 
        else 
        {
        printf("Element found at index %d\n", result4); 
        } 
        end=clock(); 
        time_taken4=((double)(end-start))/CLOCKS_PER_SEC; 
        printf("The time taken by the binary search recursive function is 
%f\n",time_taken4); 
}
