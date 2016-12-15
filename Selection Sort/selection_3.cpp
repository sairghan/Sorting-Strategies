#include<iostream>
#include<climits>
#include<cstdlib>
#include<time.h>
#include<stdio.h>
using namespace std;

int randomPartition(int arr[], int l, int r);


int kthSmallest(int arr[], int l, int r, int k)
{
	if (k > 0 && k <= r - l + 1)
	{
		
		int pos = randomPartition(arr, l, r);

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


int partition(int arr[], int l, int r)
{
	int x = arr[r], i = l;
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


int randomPartition(int arr[], int l, int r)
{
	int n = r-l+1;
	int pivot = rand() % n;
	swap(&arr[l + pivot], &arr[r]);
	return partition(arr, l, r);
}


int main()
{
	 clock_t t;
    t = clock();
  int arr[] = {10,11,12,13,14,15,16,17,18,19,20,21,22,24,23,25}; /*Average Case*/  
  //int arr[] = {18,19,20,21,22,23,24,25,10,11,12,13,14,15,16,17};
   //int arr[] = {10,12,14,16,18,20,22,24,11,13,15,17,19,21,23,25};
	int n = sizeof(arr)/sizeof(arr[0]), k = 3;	
	cout << "K'th smallest element is " << kthSmallest(arr, 0, n-1, k);	
		t = clock() - t;
    double time_taken = (((double)t)/CLOCKS_PER_SEC)*1000; 
    printf(" \nTime elapsed: %f millisec\n", time_taken);
	return 0;
}

