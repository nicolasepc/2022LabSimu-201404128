#!/bin/bash
#Pedir ingreso de nombre
echo Introduce tu nombre
#Leer el nombre introducido
read nombre
#Guardar este nombre en "archivo"
echo $nombre >> archivo
#Obtener la lista de archivos en la carpeta
nombres=$(ls)
#Agregar esta lista en archivo "nombresexist"
echo nombres >> nombresexist
#Verificar si existen archivos con el nombre introducido y
#guardar el numero de archivos con este nombre en una variable
exist=$(grep -c $nombre nombresexist)
#Si no existe archivo con este nombre se ejecuta el siguiente if
if [ "$exist" -eq 0 ]
    then
    #Crear un archivo llamado "nombre.c"
    touch $nombre.c
    #Obtener el nombre de la máquina
    uname=$(uname -n)
    #Agregar el nombre de la maquina al archivo "nombre.c"
    echo -e "/* \nAutor: $uname" >> $nombre.c
    #Obtener la version de gcc
    gcc=$(gcc --version)
    #Agregar la version de gcc al archivo "nombre.c"
    echo "Compilador: $gcc" >> $nombre.c
    #Agregar al archivo "nombre.c" información de como compilar
    echo "Compilado: gcc $nombre.c -o $nombre" >> $nombre.c
    #Obtener fecha
    date=$(date)
    #Agregar fecha al archivo "nombre.c"
    echo "Fecha: $date" >> $nombre.c
    #Agregar librerias utilizadas al archivo "nombre.c"
    echo "Librerias: stdio" >> $nombre.c
    #Solicitar el ingreso del resumen
    echo Ingrese el resumen
    #Leer el texto ingresado
    read resumen
    #Agregar el texto en "nombre.c"
    echo "Resumen: $resumen" >> $nombre.c
    #Solicitar el ingreso de las entradas
    echo Ingrese las entradas
    #Leer el texto ingresado 
    read entrada
    #Agregar este texto en "nombre.c"
    echo "Entrada: $entrada" >> $nombre.c
    #Solicitar el ingreso de las salidas
    echo Ingrese las salidas
    #Leer el texto ingresado
    read salida
    #Agregar el texto al archivo "nombre.c"
    echo -e "Salida: $salida \n*/ \n" >> $nombre.c
    #Agregar comentario a "nombre.c"
    echo "//Librerias" >> $nombre.c
    #Agregar librerias a "nombre.c"
    echo "#include <stdio.h>" >> $nombre.c
    #Agregar comentario a "nombre.c"
    echo "//numerar los pasos del pseudocodigo" >> $nombre.c
#Finalizar el if
fi
#Eliminar archivos creados anteriormente que son innecesarios
rm archivo
rm nombresexist