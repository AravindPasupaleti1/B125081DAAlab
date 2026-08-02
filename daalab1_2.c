#include<stdio.h>
#include<math.h>
int main() {
    FILE *fp;
    fp = fopen("lab1_1.txt","w");
    fprintf(fp,"#n f1 f2 f3 f4 f5 f6 f7 f8 f9 f10 f11 f12\n");
    for(int n=2;n<=100;n++){
        double f1 = n*log2(n);
        double f2 = 12*sqrt(n);
        double f3 = 1.0/n;
        double f4 = pow(n,log2(n));
        double f5 = 100*n*n + 6*n;
        double f6 = pow(n,0.51);
        double f7 = n*n - 324;
        double f8 = 50*sqrt(n);
        double f9 = 2*pow(n,3);
        double f10 = pow(3,n);
        double f11 = pow(2.0,32.0)*n;
        double f12 = log2(n);
        fprintf(fp,"%d %.6lf %.6lf %.6lf %.6lf %.6lf %.6lf %.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n",n,f1,f2,f3,f4,f5,f6,f7,f7,f8,f9,f10,f11,f12);
    }
    fclose(fp);
    printf("Data stored in lab1_1.txt\n");
    return 0;
}
