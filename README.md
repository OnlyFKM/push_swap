# **Push_swap**

Este proyecto tiene como objetivo la implementación de dos programas en C: **push_swap** y **checker**.

## **push_swap**

**push_swap** es un programa que calcula y muestra en la salida estándar el programa más pequeño, creado con las instrucciones del lenguaje Push swap, que ordene los números enteros recibidos como argumentos. La principal dificultad de este proyecto radica en encontrar un algoritmo eficiente para ordenar los datos utilizando un conjunto limitado de instrucciones y el menor número de acciones posible.

## **checker**

**checker** es el segundo programa del bonus. Toma como argumento el stack "a" en forma de una lista de enteros. El primer argumento debe estar en la parte superior del stack (cuidado con el orden). Cuando se ejecuta **checker**, esperará y leerá una lista de instrucciones separadas por saltos de línea. Una vez que se hayan leído todas las instrucciones, **checker** las ejecutará en el stack "a".

- Si, después de ejecutar todas las instrucciones, el stack "a" está ordenado y el stack "b" está vacío, entonces el programa **checker** mostrará "OK" seguido de un salto de línea en la salida estándar.

- En cualquier otro caso, mostrará "KO" seguido de un salto de línea en la salida estándar.

- En caso de error, mostrará "Error" seguido de un salto de línea en la salida de errores. Los errores pueden incluir, por ejemplo, argumentos que no son números enteros, argumentos que son mayores que un número entero, duplicados, instrucciones que no existen o que no tienen el formato correcto.

## **Ejecución**

Para ejecutar el programa **push_swap**, sigue los siguientes pasos:

Compila el programa.

	make

Ejecuta el programa checker con la lista de números enteros como argumentos y proporciona las instrucciones a través de la entrada estándar. Ejemplo:

	./push_swap 5 2 8 4 1
	pb
	pb
	ra
	sa
 	...

Y para ejecutar el **checker:**

	./checker 5 2 8 4 1
	pb
	pb
	ra
	sa
	...
	(ctrl+D para finalizar la entrada)

Checker mostrará "OK" si la secuencia de instrucciones ordena correctamente los números y "KO" en caso contrario.

## **Conclusión**

Push_swap es un proyecto desafiante que te ayudará a comprender los algoritmos de ordenamiento y su complejidad. A través de la implementación de este programa, mejorarás tus habilidades de programación en C y aprenderás a encontrar soluciones eficientes para problemas de ordenación de datos. ¡Disfruta del desafío y sigue explorando el mundo de la algoritmia!
