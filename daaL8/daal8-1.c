#include<stdio.h>
#include<stdlib.h>
#define INF 999999

int min(int a,int b){
    return (a<b)?a:b;
}
int minimumCoins(int coins[],int n,int amount){
    int dp[amount+1];
    dp[0]=0;
    for(int i=1;i<=amount;i++){
        dp[i]=INF;
    }
    for(int i=1;i<=amount;i++){
        for(int j=0;j<n;j++){
            if(coins[j]<=i){
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
    }
    return (dp[amount]==INF)?-1:dp[amount];
}

int main(){
    int n,v;
    printf("enter no of coin denoinations:");
    scanf("%d",&n);
    printf("enter the target amount:");
    scanf("%d",&v);
    int coins[n];
    printf("enter the coin denoinations:");
    for(int i=0;i<n;i++){
        scanf("%d",&coins[i]);
    }
    int result = minimumCoins(coins,n,v);
    if(result==-1){
        printf("it is not possible to make the target amount with the given coins\n");
    }
    else{
        printf("minimum number of coins required: %d\n",result);
    }
    return 0;
} 