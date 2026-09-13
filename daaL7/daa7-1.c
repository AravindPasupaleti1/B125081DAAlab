#include<stdio.h>

int main(){
    int n;
    int total,moves;

    printf("no of rows: ");
    scanf("%d",&n);

    total = n*(n+1)/2;
    moves=total/3;
    
    printf("total: %d\n",total);
    printf("total moves: %d",moves);

    return 0;
}