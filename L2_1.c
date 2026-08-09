#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    FILE *data=fopen("dictionary.dat","w");
    FILE *plot=fopen("dictionary.gnu","w");
    if(data==NULL||plot==NULL)
    {
        printf("File error!\n");
        return 1;
    }
    for(int n=100;n<=5000;n+=100)
    {
        /* Search */
        fprintf(data,"%d %d %.2f %d %d %d %d\n",
                n,n,log2(n),n,n,n,n);

        /* Insert */
        fprintf(data,"%d %d %d %d %d %d %d\n",
                n,1,n,1,n,1,n);

        /* Delete */
        fprintf(data,"%d %d %d %d %d %d %d\n",
                n,n,n,n,n,1,1);

        /* Maximum */
        fprintf(data,"%d %d %d %d %d %d %d\n",
                n,n,1,n,n,n,1);

        /* Minimum */
        fprintf(data,"%d %d %d %d %d %d %d\n",
                n,n,1,n,1,n,1);

        /* Predecessor */
        fprintf(data,"%d %d %d %d %d %d %d\n",
                n,n,1,n,n,1,1);

        /* Successor */
        fprintf(data,"%d %d %d %d %d %d %d\n",
                n,n,1,1,1,1,1);
    }
    fclose(data);
    fprintf(plot,
        "set terminal wxt size 1600,1000\n"
        "set multiplot layout 4,2 rowsfirst\n"
        "set grid\n"
        "set logscale y\n"
        "set xlabel 'Input Size (n)'\n"
        "set ylabel 'Operations (log scale)'\n"
        "set key font ',7'\n"

        /* Search */
        "set title 'Search'\n"
        "plot 'dictionary.dat' every 7::0 using 1:2 with lines title 'UA',"
        "'dictionary.dat' every 7::0 using 1:3 with lines title 'SA',"
        "'dictionary.dat' every 7::0 using 1:4 with lines title 'SLU',"
        "'dictionary.dat' every 7::0 using 1:5 with lines title 'SLS',"
        "'dictionary.dat' every 7::0 using 1:6 with lines title 'DLU',"
        "'dictionary.dat' every 7::0 using 1:7 with lines title 'DLS'\n"

        /* Insert */
        "set title 'Insert'\n"
        "plot 'dictionary.dat' every 7::1 using 1:2 with lines title 'UA',"
        "'dictionary.dat' every 7::1 using 1:3 with lines title 'SA',"
        "'dictionary.dat' every 7::1 using 1:4 with lines title 'SLU',"
        "'dictionary.dat' every 7::1 using 1:5 with lines title 'SLS',"
        "'dictionary.dat' every 7::1 using 1:6 with lines title 'DLU',"
        "'dictionary.dat' every 7::1 using 1:7 with lines title 'DLS'\n"

        /* Delete */
        "set title 'Delete'\n"
        "plot 'dictionary.dat' every 7::2 using 1:2 with lines title 'UA',"
        "'dictionary.dat' every 7::2 using 1:3 with lines title 'SA',"
        "'dictionary.dat' every 7::2 using 1:4 with lines title 'SLU',"
        "'dictionary.dat' every 7::2 using 1:5 with lines title 'SLS',"
        "'dictionary.dat' every 7::2 using 1:6 with lines title 'DLU',"
        "'dictionary.dat' every 7::2 using 1:7 with lines title 'DLS'\n"

        /* Maximum */
        "set title 'Maximum'\n"
        "plot 'dictionary.dat' every 7::3 using 1:2 with lines title 'UA',"
        "'dictionary.dat' every 7::3 using 1:3 with lines title 'SA',"
        "'dictionary.dat' every 7::3 using 1:4 with lines title 'SLU',"
        "'dictionary.dat' every 7::3 using 1:5 with lines title 'SLS',"
        "'dictionary.dat' every 7::3 using 1:6 with lines title 'DLU',"
        "'dictionary.dat' every 7::3 using 1:7 with lines title 'DLS'\n"

        /* Minimum */
        "set title 'Minimum'\n"
        "plot 'dictionary.dat' every 7::4 using 1:2 with lines title 'UA',"
        "'dictionary.dat' every 7::4 using 1:3 with lines title 'SA',"
        "'dictionary.dat' every 7::4 using 1:4 with lines title 'SLU',"
        "'dictionary.dat' every 7::4 using 1:5 with lines title 'SLS',"
        "'dictionary.dat' every 7::4 using 1:6 with lines title 'DLU',"
        "'dictionary.dat' every 7::4 using 1:7 with lines title 'DLS'\n"

        /* Predecessor */
        "set title 'Predecessor'\n"
        "plot 'dictionary.dat' every 7::5 using 1:2 with lines title 'UA',"
        "'dictionary.dat' every 7::5 using 1:3 with lines title 'SA',"
        "'dictionary.dat' every 7::5 using 1:4 with lines title 'SLU',"
        "'dictionary.dat' every 7::5 using 1:5 with lines title 'SLS',"
        "'dictionary.dat' every 7::5 using 1:6 with lines title 'DLU',"
        "'dictionary.dat' every 7::5 using 1:7 with lines title 'DLS'\n"

        /* Successor */
        "set title 'Successor'\n"
        "plot 'dictionary.dat' every 7::6 using 1:2 with lines title 'UA',"
        "'dictionary.dat' every 7::6 using 1:3 with lines title 'SA',"
        "'dictionary.dat' every 7::6 using 1:4 with lines title 'SLU',"
        "'dictionary.dat' every 7::6 using 1:5 with lines title 'SLS',"
        "'dictionary.dat' every 7::6 using 1:6 with lines title 'DLU',"
        "'dictionary.dat' every 7::6 using 1:7 with lines title 'DLS'\n"

        "unset logscale y\n"
        "unset multiplot\n"
    );

    fclose(plot);
    printf("Data generated successfully!\n");
    printf("Opening GNU Plot...\n");
    system("gnuplot -persist dictionary.gnu");
    return 0;
}