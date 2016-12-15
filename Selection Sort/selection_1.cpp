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

int selection(int low,int high,int k,int s[]){
	int pivotpoint;
	if(low==high)
	return s[low];
	else{
		pivotpoint=partition(low,high,pivotpoint,s);
		if(k==pivotpoint)
		return s[pivotpoint];
		else if(k<pivotpoint)
		return selection(low, pivotpoint-1,k,s);
		else
		return selection(pivotpoint+1,high,k,s);
	}
}


int main()
{
    int i,size,k;
    printf("Number of Elements: ");
    scanf("%d",&size);
    printf("Kth Value of Key: ");
    scanf("%d",&k);
    int s[size+1];
    printf("Enter numbers: ");
    for(i=1;i<=size;i++){
    	scanf("%d",&s[i]);
    }
    clock_t t;
    t = clock();
    printf("Given Array: ");
    for(i=1;i<=size;i++){
    	printf("%d ",s[i]);
    }
    
    int key=selection(1,size,k,s);
    
    printf("\nSorted array\n");
    for(i=1;i<=size;i++){
    	printf("%d ",s[i]);
    }
    printf("\nKey is: %d",key);
    t = clock() - t;
    double time_taken = (((double)t)/CLOCKS_PER_SEC)*1000; 
    printf(" \nTime elapsed: %f millisec\n", time_taken);
    return 0;
}
