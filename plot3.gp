set title "Bubble Sort comparision"
set xlabel "Array size (n)"
set ylabel "Number of comparisions"

set grid
set key left top

plot \
"lab3.txt" using 1:2 with linespoints title "Early Bubble Sort",\
"lab3.txt" using 1:3 with linespoints title "Normal Bubble Sort"
pause -1