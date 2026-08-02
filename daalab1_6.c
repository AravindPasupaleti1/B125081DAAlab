#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int elementUnique(int arr[],int n,int* comparisions){
    *comparisions = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            (*comparisions)++;
            if(arr[i]==arr[j]){
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    FILE *fp;
    fp = fopen("lab1_6.txt","w");
    fprintf(fp,"#n comparisions");
    srand(time(NULL));
    for(int n=10;n<=100;n+=10){
        int arr[100];
        for(int i = 0;i<n;i++){
            arr[i] = i+1;
        }
        int comparisions;
        elementUnique(arr,n,&comparisions);
        fprintf(fp,"%d %d\n",n,comparisions);
    }
    fclose(fp);
    printf("data is stored in lab1_6.txt\n");

}