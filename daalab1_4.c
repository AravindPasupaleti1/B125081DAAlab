#include<stdio.h>

long long moves = 0;
void toh(int n,int l,int m,int r){
    if(n==1){
        moves++;
        return;
    }
    else{
        toh(n-1,l,r,m);
        moves++;
        toh(n-1,m,l,r);
    }
}
int main(){
    FILE *fp;
    fp = fopen("lab1_4.txt","w");
    fprintf(fp,"#n moves\n");
    for(int n=1;n<=20;n++){
        moves = 0;
        toh(n,'A','B','C');
        fprintf(fp,"%d %lld\n",n,moves);
    }
    fclose(fp);
    printf("Data is stored in lab1_4.txt\n");
    return 0;
}