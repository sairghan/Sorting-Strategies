#include<stdlib.h>
#include<stdio.h>
#include<time.h>

void merge(int arr[], int l, int m, int r);
int min(int x, int y) { return (x<y)? x :y; }
 
void mergeSort(int arr[], int n)
{
   int curr_size;  
   int left_start; 
    for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
   { 
       for (left_start=0; left_start<n-1; left_start += 2*curr_size)
       {           
           int mid = left_start + curr_size - 1;
           int right_end = min(left_start + 2*curr_size - 1, n-1);          
           merge(arr, left_start, mid, right_end);
       }
   }
}
 

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;   
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
} 

int main()
{
	clock_t t;
    t = clock();
    int arr[] = {10,11,12,13,14,15,16,17,18,19,20,21,22,24,23,25}; /*Average Case*/ 
   //int arr[] = {18,19,20,21,22,23,24,25,10,11,12,13,14,15,16,17}; /*Best Case*/
    //int arr[] = {10,12,14,16,18,20,22,24,11,13,15,17,19,21,23,25}; /*Worst Case*/
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Given array is \n");
    printArray(arr, n); 
    
    mergeSort(arr, n); 
    printf("\nSorted array is \n");
    printArray(arr, n);
    t = clock() - t;
    double time_taken = (((double)t)/CLOCKS_PER_SEC)*1000; 
    printf(" Time elapsed: %f millisec\n", time_taken);

}
