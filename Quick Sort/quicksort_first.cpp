#include<stdio.h>
#include<time.h>
int partition(int low, int high, int pp,int s[]){
	int i,j,a;
	int pi=s[low];
	j=low;
	for(i=low+1;i<=high;i++){
		if(s[i]<pi){
			j++;
			a=s[i];
			s[i]=s[j];
			s[j]=a;
		}
	}
		pp=j;
		a=s[low];
		s[low]=s[pp];
		s[pp]=a;
		return(pp);
}

int quicksort(int low, int high,int s[]){
	int pp;
	if(high>low){
		pp=partition(low,high,pp,s);
		quicksort(low,pp-1,s);
		quicksort(pp+1,high,s);
	}
}


int main()
{
    int i,n;
   
    printf("Number of elements: ");
    scanf("%d",&n);
    int s[n];
    printf("Enter the elements: ");
    for(i=0;i<n;i++){
    	scanf("%d",&s[i]);
    }
    clock_t t;
    t = clock();
    printf("Numbers before sorting\n");
    for(i=0;i<n;i++){
    	printf("%d ",s[i]);
    }
     
    quicksort(0,n-1,s);
    printf("\nNumbers after sorting\n");
    for(i=0;i<n;i++){
    	printf("%d ",s[i]);
    }
     t = clock() - t;
    double time_taken = (((double)t)/CLOCKS_PER_SEC)*1000; 
    printf(" \nTime elapsed: %f millisec\n", time_taken);
    return 0;
}
