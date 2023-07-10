Algoritmo Ejercicio7
	Definir suma, primero, d, n Como Entero;
	suma <- 0;
	primero <- 0;
	d <- 0;
	n <- -1;
	
	Escribir "Primer termino: ", Sin Saltar;
	Leer primero;
	Escribir "Diferencia entre dos terminos", Sin Saltar;
	Leer d;
	Escribir "Numero de terminos", Sin Saltar;
	Mientras n < 0 Hacer
		Leer n;
	FinMientras
	Mientras n >= 0 Hacer
		suma <- suma + primero;
		primero <- primero + d;
		n <- n - 1;
	FinMientras
	Escribir "La suma es: ", suma;
	
FinAlgoritmo
