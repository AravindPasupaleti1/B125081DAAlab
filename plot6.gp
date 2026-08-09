set title "Element Uniqueness"
set xlabel "Number of elements(n)"
set ylabel "comparisions"

set grid
plot "lab1_6.txt" using 1:2 with linespoints linewidth 2 title "comparisions"

pause -1