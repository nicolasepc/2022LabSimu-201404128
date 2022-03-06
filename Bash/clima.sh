#! /bin/bash
#Obtiene el clima y se guarda en la variable clima
clima=$(curl wttr.in/Guatemala)

#Agrega esta insformación al archivo tclima
echo $clima >> tclima

#Lee las primeras 7 lineas de tclima y lo guarda en la variable lineas
lineas=$(head -n7 archivoclima)


#Escribe en la consola lo guardado en líneas
echo $lineas

#Elimina el archivo tclima
rm tclima