Algoritmo ejercicio7
	Borrar Pantalla;
	Definir cont, n, minimo, maximo Como Entero;
	cont = 0;
	n = 0;
	maximo = 0;
	minimo = 99999;
	Mientras cont < 5 Hacer
		Escribir "Numero: ";
		Leer n;
		Si n > maximo Entonces
			maximo = n;
		Fin Si
		Si n < minimo Entonces
			minimo = n;
		FinSi
		cont = cont + 1;
	Fin Mientras
	Escribir "El mayor de los numeros es: ", maximo;
	Escribir "El menor de los numeros es: ", minimo;
FinAlgoritmo