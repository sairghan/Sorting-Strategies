#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
 #include<iostream>
 using namespace std;
int quicksort(int *ar,int start,int end);      
int  divide(int *ar,int start,int end,int pivot);

int main(){
        int size;
        int itr;
        printf("Number of elements: ");
        scanf("%d",&size);
        int a[size];
        printf("\nEnter the elements: \n");
        for(itr=0;itr<size;itr++){      
    scanf("%d",&a[itr]);
        }
          clock_t t;
    t = clock();
         printf("\nGiven Array: \n");
         for(itr=0;itr<size;itr++)
      cout<<a[itr]<<" ";
     
        quicksort(a,0,size-1);
        printf("\nSorted Array: \n");
    for(itr=size-1;itr>=0;itr--)
      cout<<a[itr]<<" ";
 t = clock() - t;
    double time_taken = (((double)t)/CLOCKS_PER_SEC)*1000; 
    printf(" \nTime elapsed: %f millisec\n", time_taken);
}

int quicksort(int *ar,int start,int end){
        if(start < end) {
        int pivot = start;
            pivot = rand() % (end - start) + start ;
            pivot = divide(ar,start,end,pivot);
            quicksort(ar,start,pivot-1);
            quicksort (ar,pivot+1,end);
    }
}      
int  divide(int *ar,int start,int end,int pivot){
        int itr,temp,next,next1;
        temp =ar[pivot];
        ar[pivot]=ar[start]; 
        ar[start]=temp;
        pivot =start;
        next =start+1;
        while(next<=end){
                if(ar[next]>ar[pivot]){
                        temp = ar[next];
            next1 = next;
                        while(next1!=pivot+1){
                               ar[next1]=ar[next1-1];
                                next1--;
                        }
                        ar[next1]=ar[pivot];
                        ar[pivot]=temp;
                        pivot++;
                }
            next++;
    }
return pivot;   
}
