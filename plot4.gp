set title "Tower of Hanoi"
set xlabel "Number of discs"
set ylabel "Number of moves"
set grid
plot "lab1_4.txt" using 1:2 with linespoints linewidth 2 title"moves"
pause -1
