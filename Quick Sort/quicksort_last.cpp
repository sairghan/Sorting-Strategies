#include<stdio.h>
#include<time.h>
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition (int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1); 

	for (int j = low; j <= high- 1; j++)
	{

		if (arr[j] <= pivot)
		{
			i++; 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
	
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{	int n;
    printf("Number of elements: ");
	scanf("%d",&n);
	int arr[n]; 
	printf("Enter the elements: ");
	for(int i=0;i<n;i++){
    	scanf("%d",&arr[i]);
    }
    
     printf("Given Array\n");
    for(int i=0;i<n;i++){
    	printf("%d ",arr[i]);
    }
    
    clock_t t;
    t = clock();
	quickSort(arr, 0, n-1);
	printf("\nSorted array: \n");
	printArray(arr, n);
	 t = clock() - t;
    double time_taken = (((double)t)/CLOCKS_PER_SEC)*1000; 
    printf(" \nTime elapsed: %f millisec\n", time_taken);
	return 0;
}

