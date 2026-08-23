/*
MERGE-INTERVALS(I, n)

1. Sort I according to starting point.

2. current = I[0]

3. For i = 1 to n-1:

       If I[i].start <= current.end:

            current.end = max(current.end, I[i].end)

       Else:

            Add current to output
            current = I[i]

4. Add current to output.

5. Return output.
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int start;
    int end;
}interval;
int compare(const void*a,const void*b){
    interval*i1 = (interval*)a;
    interval*i2 = (interval*)b;
    return i1->start-i2->start;
}
int main(){
    int n;
    printf("Enter the number of intervals : ");
    scanf("%d",&n);
    interval arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the start and end of interval %d :",i+1);
        scanf("%d %d",&arr[i].start,&arr[i].end);
    }
    qsort(arr,n,sizeof(interval),compare);
    printf("\n MERGED INTERVALS : ");
    int currentstart = arr[0].start;
    int currentend = arr[0].end;
    for(int i=1;i<n;i++){
        if(arr[i].start <= currentend){
            if(arr[i].end > currentend){
                currentend = arr[i].end;
            }
        }
        else{
            printf("(%d,%d)",currentstart,currentend);
            currentstart = arr[i].start;
            currentend = arr[i].end;
        }
    }
    printf("(%d,%d)\n",currentstart,currentend);
    return 0;
}