/*
PAIR-SUM(S1, S2, n, x)

1. Sort S2 in ascending order.

2. For i = 0 to n-1:

       required = x - S1[i]

       If BinarySearch(S2, required) = TRUE:
            return YES

3. return NO
*/
#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int low,int mid,int high){
    int i=low;
    int j=mid+1;
    int k=0;
    int *temp = (int*)malloc((high-low+1)*sizeof(int));
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=high){
        temp[k++]=arr[j++];
    }
    for(int i=low,k=0;i<=high;i++,k++){
        arr[i]==temp[k];
    }
    free(temp);
}
void mergesort(int arr[],int low,int high){
    if(low<high){
        int mid = low + (high-low)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
void findpair(int s1[],int s2[],int n,int x){
    mergesort(s1,0,n-1);
    mergesort(s2,0,n-1);
    int i=0;
    int j=n-1;
    while(i<n && j>=0){
        int sum = s1[i]+s2[j];
        if(sum==x){
            return s1[i],s2[j];
        }
        else if(sum>x){
            j=j-1;
        }
        else{
            i=i+1;
        }
    }
    printf("No such pair exists");
}
int main(){
    int n,x;
    printf("Enter size of both sets : ");
    scanf("%d",&n);
    int *s1 = (int*)malloc(n*sizeof(int));
    int *s2 = (int*)malloc(n*sizeof(int));
    printf("Enter elements of s1 :\n");
    for(int i=0;i<n-1;i++){
        scanf("%d",&s1[i]);
    }
    printf("Enter the elements of s2: ");
    for(int i=0;i<n;i++){
        scanf("%d",&s2[i]);
    }
    printf("Enter target x: ");
    scanf("%d",&x);
    findpair(s1,s2,n,x);
    free(s1);
    free(s2);
    return 0;
}