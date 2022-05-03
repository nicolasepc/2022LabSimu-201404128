unset label
clear
set terminal jpeg
set output "raicesCotangente.jpg"
set title "Gráfica de la función cotangente"
set xlabel "y"
set ylabel "x"
set xrange [-6:6]
set yrange [-10:10]
set grid
plot 1/tan(x)