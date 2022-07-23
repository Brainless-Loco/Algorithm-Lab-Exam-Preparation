#include <bits/stdc++.h>
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int merge_arr[], int begin, int mid, int end)
{
    int i,j,k,left_size,right_size;

    left_size=mid-begin+1;
    right_size=end-mid;

    int left[left_size],right[right_size];

    for(i=0;i<left_size;i++)
        left[i]=merge_arr[i+begin];
    for(i=0;i<right_size;i++)
        right[i]=merge_arr[i+mid+1];

    k = begin;
    i = j = 0;

    while(i<left_size && j<right_size){
        if(left[i]<=right[j]){
            merge_arr[k]=left[i];
            i++;
        }
        else{
            merge_arr[k]=right[j];
            j++;
        }
        k++;
    }

    while(i<left_size){
        merge_arr[k]=left[i];
        i++;
        k++;
    }

    while(j<right_size){
        merge_arr[k]=right[j];
        j++;
        k++;
    }
}

void merge_sort(int merge_arr[], int begin, int end)
{
    if(begin<end){
        int mid = (begin+end)/2;

        merge_sort(merge_arr, begin, mid);
        merge_sort(merge_arr, mid + 1, end);

        merge(merge_arr, begin, mid, end);
    }
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";
}

// Driver code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	auto arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);

	merge_sort(arr, 0, arr_size - 1);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);
	return 0;
}

// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes

