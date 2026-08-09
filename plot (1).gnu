set title 'Merge Sort vs 3-Way Merge Sort'
set xlabel 'Input Size (n)'
set ylabel 'Number of Comparisons'
set grid
set key left top
plot 'comparison.dat' using 1:2 with linespoints title 'Normal Merge Sort', 'comparison.dat' using 1:3 with linespoints title '3-Way Merge Sort'
