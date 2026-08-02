#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
void bubbleEarly(int a[],int n,int* comparisions){
    int i,j,temp,swapped;
    *comparisions = 0;
    for(i=0;i<n-1;i++){
        swapped = 0;
        for(j=0;j<n-i-1;j++){
            (*comparisions)++;
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                swapped = 1;
            }
        }
        if(swapped == 0){
            break;
        }
    }   
}
void bubbleNormal(int a[],int n,int* comparisions){
    int i,j,temp;
    *comparisions = 0;
    for(i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++) {
            (*comparisions)++;
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1]>temp;
            }
        }
    }
}
int main(){
    FILE *fp;
    srand(time(NULL));
    fp = fopen("lab3.txt","w");
    fprintf(fp,"#n EarlyBubble NormalBubble\n");
    for(int n=0;n<=MAX;n+=10){
        int a[MAX],b[MAX];
        for(int i=0;i<n;i++){
            a[i] = rand() % 1000;
            b[i] = a[i];
        }
        int c1,c2;
        bubbleEarly(a,n,&c1);
        bubbleNormal(b,n,&c2);
        fprintf(fp,"%d %d %d\n",n,c1,c2);
    }
    fclose(fp);
    printf("Data is stored in lab3.txt\n");
    return 0;
}