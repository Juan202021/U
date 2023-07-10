Algoritmo ejercicio8
	Definir num1, num2, aux, contador, pares, sumaimpa Como Entero;
	num1 = 0;
	num2 = 0; 
	aux = 0; 
	contador = 0; 
	pares = 0; 
	sumaimpa = 0;
	Borrar Pantalla;
	Escribir "Numero: ";
	Leer num1;
	Escribir "Numero: ";
	Leer num2;
	Si num1 > num2 Entonces
		aux = num1;
		num1 = num2;
		num2 = aux;
	FinSi
	Mientras num1 <= num2 Hacer
		Escribir num1;
		contador = contador + 1;
		Si num1%2==0 Entonces
			pares = pares + 1;
		SiNo 
			sumaimpa = sumaimpa + num1;
		FinSi
		num1 = num1 + 1;
	FinMientras
	Escribir "Numeros visualizados: ", contador;
	Escribir "Pares hay: ", pares;
	Escribir "La suma de los impares es: ", sumaimpa;
	
FinAlgoritmo
