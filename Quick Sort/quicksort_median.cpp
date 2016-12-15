 #include<iostream>
 #include<time.h>
 #include<stdio.h>
    using namespace std;
    void print_array(int *arr,int n)
    {
    	for(int i=0; i<n; i++)
    	{
    		cout<<arr[i]<<" ";
    	}
    	cout<<endl;
    }
    int median(int *arr,int low,int high,int mid)
    {
    	if((arr[low]>arr[high] && arr[low]<arr[mid]) || (arr[low]<arr[high] && arr[low]>arr[mid]));
    	return low;
    	if((arr[mid]>arr[high] && arr[low]>arr[mid]) || (arr[low]<arr[mid] && arr[high]>arr[mid]))
    	return mid;
    	return high;
    }
    int partition(int *arr,int low,int high)
    {
    	int index;
      if(high-low >1)
    	{
    		index=median(arr,low,high,(low+high)/2);
    		arr[index]=arr[low]+arr[index]-(arr[low]=arr[index]);
    	}
    	int pivot=arr[low];
    	int i;
    	int j=high;
    	for(i=high; i>low; i--)
    	{
    		if(arr[i]>=pivot)
    		{
    			arr[j]=arr[i]+arr[j]-(arr[i]=arr[j]);
    			j--;
    		}
    	}
    	arr[low]=arr[j]+arr[low]-(arr[j]=arr[low]);
    	return j;
     
    }
    void qssort(int *arr,int low,int high)
    {
    	if(low<high)
    	{
    		int index=partition(arr,low,high);
    		qssort(arr,low,index-1);
    		qssort(arr,index+1,high);
    	}
    }
    int main()
    {
    int n;
    printf("Number of elements: ");
	scanf("%d",&n);
	int arr[n]; 
	printf("Enter the elements: ");
	for(int i=0;i<n;i++)
    	{
    	scanf("%d",&arr[i]);
        }  	
        
        
    	printf("Given Array\n");
    for(int i=0;i<n;i++){
    	printf("%d ",arr[i]);
    }
    clock_t t;
    t = clock();
    	qssort(arr,0,n-1);
    	printf("\nSorted Array\n");
    	print_array(arr,n);
    	
    	 t = clock() - t;
    double time_taken = (((double)t)/CLOCKS_PER_SEC)*1000; 
    printf(" \nTime elapsed: %f millisec\n", time_taken);
    	return 0;
    }
