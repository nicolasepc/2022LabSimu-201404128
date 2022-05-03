unset label
clear
set terminal jpeg
set output "ondasEstacionarias.jpg"
set title "Experimento de ondas estacionarias con una cuerda"
set xlabel "Tension (N)"
set ylabel "Longitud de la onda (m)"
set grid
set style data linespoint
plot "datos", 0.511*x+0.653