set title "Growth of functions"
set xlabel "n"
set ylabel "Function value"
set grid 
set key outside
set logscale y

plot \
"lab1_1.txt" using 1:2 with lines title "nlog2n",\
"lab1_1.txt" using 1:3 with lines title "12sqrt(n)",\
"lab1_1.txt" using 1:4 with lines title "1/n",\
"lab1_1.txt" using 1:5 with lines title "n^(log2n)",\
"lab1_1.txt" using 1:6 with lines title "100n^2 + 6n",\
"lab1_1.txt" using 1:7 with lines title "n^0.51",\
"lab1_1.txt" using 1:8 with lines title "n^2-324",\
"lab1_1.txt" using 1:9 with lines title "50sqrt(n)",\
"lab1_1.txt" using 1:10 with lines title "2n^3",\
"lab1_1.txt" using 1:11 with lines title "3^n",\
"lab1_1.txt" using 1:12 with lines title "2^32 *n",\
"lab1_1.txt" using 1:13 with lines title "log2n"
pause -1













