/*
Algorithm K-SUM(S, n, k, T)

1. Sort S in ascending order

2. Call FIND(S, n, k, 0, 0, 0, T)

3. If FIND returns TRUE
       Print "YES"
   Else
       Print "NO"


FIND(S, n, k, index, count, sum, T)

1. If count = k − 1
       required ← T − sum

       If BinarySearch(S, required) = TRUE
            return TRUE
       Else
            return FALSE

2. For i ← index to n − 1
       If FIND(S, n, k, i + 1,
               count + 1,
               sum + S[i],
               T) = TRUE
            return TRUE

3. return FALSE
*/
#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b){
    return(*(int*)a - *(int*)b);
}
int binarysearch(int arr[],int n,int target){
    int low=0,high=n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==target){
            return 1;
        }
        else if(arr[mid]<target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return 0;
}
int findsum(int arr[],int n,int k,int index,int count,int sum,int t){
    if(count==k-1){
        int req = t-sum;
        return binarysearch(arr,n,req);
    }
    for(int i=index;i<n;i++){
        if(findsum(arr,n,k,i+1,count+1,sum+arr[i],t)){
            return 1;
        }
    }
    return 0;
}
int main(){
    int n,k,t;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the k : ");
    scanf("%d",&k);
    printf("Enter the t : ");
    scanf("%d",&t);
    qsort(arr,n,sizeof(int),compare);
    if(k<2 || k>n){
        printf("Invalid value of k ");
        return 0;
    }
    if(findsum(arr,n,k,0,0,0,t)){
        printf("Yes %d elements add upto %d",k,t);
    }
    else{
        printf("No %d elements do not add upto %d",k,t);
    }
    return 0;
}