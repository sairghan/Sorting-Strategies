#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int merge2(int low, int mid, int high,int arr[]);
int mergesort2(int low, int high, int arr[]);
	int main()
{
    int i,n;  
	printf("Number of elements: ");  
    scanf("%d",&n);
    int arr[n];   
	printf("Enter the elements: ");   
    for(i=0;i<n;i++){
    	scanf("%d",&arr[i]);
    } 
    
    printf("\nGiven Array: \n");
    for(i=0;i<n;i++){
    	printf("%d ",arr[i]);
    }
    clock_t t;
    t = clock(); 
    mergesort2(0,n-1,arr);
    printf("\nSorted Array: \n");
    for(i=0;i<n;i++){
    	printf("%d ",arr[i]);
    
    }
    	t = clock() - t;
    double time_taken = (((double)t)/CLOCKS_PER_SEC)*1000; 
    printf(" \nTime elapsed: %f millisec\n", time_taken);
    return 0;
}
	int mergesort2(int low, int high, int arr[]){
		int mid;
		if(low < high){
			mid = (low + high)/2;
			mergesort2(low, mid,arr);
			mergesort2(mid+1, high,arr);
			merge2(low, mid, high,arr);
		}
	}

	int merge2(int low, int mid, int high,int arr[]){
		int i, j, k;

		int U[high+1];
		i = low; j = mid+1; k = low;
		while(i <= mid && j <= high){
			if(arr[i] < arr[j]){
				U[k] = arr[i];
				i++;
			}
			else{
				U[k] = arr[j];
				j++;
			}
			k++;
		}

		if (i > mid){
			for(int index = j; index <= high; index++){
				U[k] = arr[index];
				k++;
			}
		}
		else{
			for(int index1 = i; index1 <= mid; index1++){
				U[k] =	arr[index1];
				k++;
			}
		}

		for(int p = low; p <= high; p++){
			arr[p] = U[p];
		}
	}


