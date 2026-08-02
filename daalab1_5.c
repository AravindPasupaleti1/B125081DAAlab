#include<stdio.h>
int main(){
    int n;
    printf("Enter the no of elements in an array: ");
    scanf("%d",&n);
    int A[n];
    printf("Enter the array elements(0 or 1):");
    for(int i=0;i<n;i++){
        while(1){
            scanf("%d",&A[i]);
            if(A[i]==0 || A[i]==1){
                break;
            }
            else{
                printf("invalid input! enter only 0 or 1: ");
            }     
        } 
     }
     int low = 0;
     int high = n-1;
     int transition=-1;
     while(low<=high) {
        int mid = (low+high)/2;
        if(A[mid]==1){
            transition==mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
     }
     if(transition==-1){
        printf("No transistion point found\n");
     }
     else if(transition==0){
        printf("All the elements present in that array A are 1's so there is no transtion point \n");
     }
     else {
        printf("The transition point is at %d",transition);
     }
     return 0;
}