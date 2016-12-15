#include<iostream>
#include<algorithm>
#include<climits>
#include<time.h>
#include<stdio.h>
using namespace std;

int partition(int arr[], int l, int r, int k);

int findMedian(int arr[], int n)
{
	sort(arr, arr+n); 
	return arr[n/2]; 
}


int kthSmallest(int arr[], int l, int r, int k)
{
	
	if (k > 0 && k <= r - l + 1)
	{
		int n = r-l+1; 

		
		int i, median[(n+4)/5]; 
		for (i=0; i<n/5; i++)
			median[i] = findMedian(arr+l+i*5, 5);
		if (i*5 < n) 
		{
			median[i] = findMedian(arr+l+i*5, n%5); 
			i++;
		} 

		
		int medOfMed = (i == 1)? median[i-1]:
								kthSmallest(median, 0, i-1, i/2);

		
		int pos = partition(arr, l, r, medOfMed);

		
		if (pos-l == k-1)
			return arr[pos];
		if (pos-l > k-1) 
			return kthSmallest(arr, l, pos-1, k);

	
		return kthSmallest(arr, pos+1, r, k-pos+l-1);
	}

	
	return INT_MAX;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


int partition(int arr[], int l, int r, int x)
{
	
	int i;
	for (i=l; i<r; i++)
		if (arr[i] == x)
		break;
	swap(&arr[i], &arr[r]);

	
	i = l;
	for (int j = l; j <= r - 1; j++)
	{
		if (arr[j] <= x)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[r]);
	return i;
}


int main()
{clock_t t;
    t = clock();
   int arr[] = {12, 3, 5, 7, 4, 19, 26};
	//int arr[] = {18,19,20,21,22,23,24,25,10,11,12,13,14,15,16,17};
   //int arr[] = {10,12,14,16,18,20,22,24,11,13,15,17,19,21,23,25};
	int n = sizeof(arr)/sizeof(arr[0]), k = 5;
	 
	cout << "K'th smallest element is "
		<< kthSmallest(arr, 0, n-1, k);
		t = clock() - t;
    double time_taken = (((double)t)/CLOCKS_PER_SEC)*1000; 
    printf(" \nTime elapsed: %f millisec\n", time_taken);
   
	return 0;
}
