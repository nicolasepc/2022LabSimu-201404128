# Segundo Parcial

## Problema 1
Se realiza el experimento de ondas estacionarias con una cuerda. Obteniendo las siguientes mediciones

Tensión (N +- 0.001N): 4.694, 1,264, 0.578, 0.284, 0.196

Longitud de onda (m): 3, 1.5, 1, 0.75, 0.6

Se solicita generar un programa el cual cumpla con las siguientes condiciones

- Una gráfica que compare los valores tabulados y la recta que mejor aproxima el comportamiento
- Estimar el valor de la densidad lineal de la cuerda. La longitud de onda cuando la tensión sea de 6N.

### Metodología
Para resolver este problema se utilizó el método numérico de mínimos cuadrados. Con este método se obtiene la recta que mejor se aproxima a los datos tabulados.

La pendiente se calcula con la formula 
```
m = (n*sumaDeMultiplicaciones(x,y)-(suma(x)*suma(y)))/(n*sumaDeMultiplicaciones(x,x)-(suma(x)*suma(x)))
```

el intersecto se calcula con la formula:
```
b = (suma(y)-m*suma(x))/n
```

y el coeficiente de determinación:
```
r = (n*sumaDeMultiplicaciones(x,y)-(suma(x)*suma(y)))/sqrt((n*sumaDeMultiplicaciones(x,x)-(suma(x)*suma(x)))*(n*sumaDeMultiplicaciones(y,y)-(suma(y)*suma(y))))
```

Mientras el cuadrado del coefiente de determinación se aproxime mas a 1, esto indica que nuestros datos más se aproximan a una recta.

Por medio de una gráfica hecha con Gnuplot se compara la recta obtenida con los valores del problema.

A partir de la recta obtenida se calcula la longitud de onda cuando la tensión es de 6N.

### Variables de entrada y salida
#### Variables de entrada: 
- Vectores tipo float:
x: Valores de la tension

y: Valores de longitud de onda
variable tipo int:

n: número de elementos de los vectores


#### Variables de salida:
- variables tipo float:

m: Pendiente de la recta

b: Intersecto de la recta

r: Coeficiente de determinación

longitud: Longitud de la onda cuando la tension es 6N.

### Diagrama de Flujo
[Diagrama Problema 1](https://github.com/nicolasepc/2022LabSimu-201404128/blob/main/segundo%20parcial/parcial2problema1.png)

## Problema 2
Utilizando un método numérico, encuentre una raíz de la ecuacion: 
        f(x) = cos(x)/sin(x)
Debe de realizar la gráfica de la ecuación y comparar el resultado obtenido con el programa realizado.

### Metodología
Para resolver este problema se utilizó el método numérico de Newtn Raphson. Este método consiste en hacer sucesivas iteraciones para poder encontrar las raices de una función. La formúla de este método es la siguiente
x = xAnt - f(x)/f'(x)

La función para este problema es f(x) = cos(x)/sin(x) y para que el método funcione se debe escoger como x inicial un valor cercano a una raiz de la función. Para encontrar estos valores se realizó la Grafica de la función en Gnuplot.

### Variables de Entrada y Salida
#### Variables de entrada
- Variables de tipo float

xInicial: Es el valor de x con el que se inicia las iteraciones

tolerancia: Tolerancia máxima con el que queremos el resultado.

- Variables de tipo entero

iteraciones: Número de iteraciones máximas que queremos que realice el programa

#### Variables de salida
- Variables tipo float:

Aiteracion: número de iteraciones que realizó el programa para obtener la solución.

xS: Raíz de la función

- String

"Mensaje de error"

### Diagrama de Flujo
[Diagrama Problema 1](https://github.com/nicolasepc/2022LabSimu-201404128/blob/main/segundo%20parcial/parcial2problema2.png)